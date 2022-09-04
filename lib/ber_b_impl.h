/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_BOOTSTRAP_BER_B_IMPL_H
#define INCLUDED_BOOTSTRAP_BER_B_IMPL_H

#include <gnuradio/bootstrap/ber_b.h>

namespace gr {
namespace bootstrap {

class ber_b_impl : public ber_b {
private:
  int d_blocks;
  int d_block_size;
  int d_subtotal;
  int d_total;
  int d_sum_squares;
  int d_samples_todo;
  int d_blocks_todo;

public:
  ber_b_impl(int block_size, int blocks);
  ~ber_b_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
};

} // namespace bootstrap
} // namespace gr

#endif /* INCLUDED_BOOTSTRAP_BER_B_IMPL_H */
