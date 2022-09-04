/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "ber_b_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace bootstrap {

ber_b::sptr ber_b::make(int block_size, int blocks) {
  return gnuradio::make_block_sptr<ber_b_impl>(block_size, blocks);
}

/*
 * The private constructor
 */
ber_b_impl::ber_b_impl(int block_size, int blocks)
    : gr::sync_block(
          "ber_b",
          gr::io_signature::make(2, 2, sizeof(char)),
          gr::io_signature::make(0, 0, 0))
{
  d_block_size = block_size;
  d_blocks = blocks;
  d_samples_todo = block_size;
  d_blocks_todo = blocks;
  d_total = 0;
  d_subtotal = 0;
  d_sum_squares = 0;
}	

/*
 * Our virtual destructor.
 */
ber_b_impl::~ber_b_impl() {}

int ber_b_impl::work(int noutput_items, gr_vector_const_void_star &input_items,
                     gr_vector_void_star &output_items) {
  unsigned char *in0 = (unsigned char *) input_items[0];
  int i;
  double block_variance;
  double est_standard_error;

  for (i=0; i<noutput_items; i++)
  {
    d_subtotal += in0[i];
    d_samples_todo--;
    if (d_samples_todo == 0)
    {
      d_total += d_subtotal;
      d_sum_squares += d_subtotal*d_subtotal;
      d_samples_todo = d_block_size;
      d_subtotal = 0;
      d_blocks_todo--;
      if (d_blocks_todo == 0)
      {
       printf("sample mean = %lf\n",
         ((double) d_total)/((double) (d_blocks*d_block_size)));
       printf("sum of squares = %d\n", d_sum_squares);
       block_variance = (d_blocks*d_sum_squares - d_total*d_total)/
         (d_blocks*(d_blocks - 1.0));
       printf("block_variance = %lf\n", block_variance/
         ((double) (d_block_size*d_block_size)));
       est_standard_error = sqrt(block_variance/
         ((double) d_blocks*d_block_size*d_block_size));
       printf("estimated standard error = %lf\n", est_standard_error);
       d_total = 0;
       d_sum_squares = 0;
       d_blocks_todo = d_blocks;
      }
    } 
  }      
      
  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace bootstrap */
} /* namespace gr */
