/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_BOOTSTRAP_BER_B_H
#define INCLUDED_BOOTSTRAP_BER_B_H

#include <gnuradio/bootstrap/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace bootstrap {

/*!
 * \brief <+description of block+>
 * \ingroup bootstrap
 *
 */
class BOOTSTRAP_API ber_b : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<ber_b> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of bootstrap::ber_b.
   *
   * To avoid accidental use of raw pointers, bootstrap::ber_b's
   * constructor is in a private implementation
   * class. bootstrap::ber_b::make is the public interface for
   * creating new instances.
   */
  static sptr make(int block_size, int blocks);
};

} // namespace bootstrap
} // namespace gr

#endif /* INCLUDED_BOOTSTRAP_BER_B_H */
