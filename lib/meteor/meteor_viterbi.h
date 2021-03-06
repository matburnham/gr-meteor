/* -*- c++ -*- */
/*
 * Copyright 2018 Infostellar, Inc.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
/*
 * Copyright 2017 Artyom Litvinovich
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
// Ported from
// https://github.com/artlav/meteor_decoder/blob/master/viterbi27.pas

#ifndef INCLUDED_METEOR_VITERBI_H
#define INCLUDED_METEOR_VITERBI_H

#include <array>
#include <memory>

#include "meteor_bit_io.h"

namespace gr {
namespace meteor {
namespace meteor {

const unsigned int NUM_STATES = 128;
const unsigned int MIN_TRACEBACK = 5 * 7;
const unsigned int TRACEBACK_LENGTH = 15 * 7;

class viterbi {
 private:
  int ber_;

  bit_io writer_;

  std::array<std::array<uint16_t, 65536>, 4> dist_table_ {}
  ;
  std::array<unsigned char, NUM_STATES> table_ {}
  ;
  std::array<uint16_t, 4> distances_ {}
  ;

  std::array<uint32_t, 64> pair_keys_ {}
  ;
  std::array<uint32_t, 16> pair_outputs_ {}
  ;
  std::array<uint32_t, 5> pair_distances_ {}
  ;
  uint32_t pair_outputs_len_;

  std::array<std::array<unsigned char, NUM_STATES>,
             MIN_TRACEBACK + TRACEBACK_LENGTH> history_ {}
  ;
  std::array<unsigned char, MIN_TRACEBACK + TRACEBACK_LENGTH> fetched_ {}
  ;
  int hist_index_, len_, renormalize_counter_;

  int err_index_;
  std::array<uint16_t *, 2> errors_ {}
  ;
  std::unique_ptr<uint16_t[]> err_0_;
  std::unique_ptr<uint16_t[]> err_1_;
  uint16_t *read_errors_;
  uint16_t *write_errors_;

  uint16_t metric_soft_distance(unsigned char hard, unsigned char soft_y0,
                                unsigned char soft_y1);
  void pair_lookup_create();
  void vit_inner(const unsigned char *soft);
  void vit_tail(const unsigned char *soft);
  void error_buffer_swap();
  void pair_lookup_fill_distance();
  void history_buffer_process_skip(int skip);
  uint32_t history_buffer_search(int search_every);
  void history_buffer_renormalize(uint32_t min_register);
  void history_buffer_traceback(uint32_t bestpath, uint32_t min_traceback);

 public:
  viterbi();
  ~viterbi();

  int count_bits(uint32_t i);
  void vit_decode(const unsigned char *in, unsigned char *out);
  void vit_conv_decode(const unsigned char *soft_encoded,
                       unsigned char *decoded);
};

}  // namespace meteor
}  // namespace meteor
}  // namespace gr

#endif /* INCLUDED_METEOR_VITERBI_H */
