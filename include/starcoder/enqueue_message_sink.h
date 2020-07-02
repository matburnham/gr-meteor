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

#ifndef INCLUDED_METEOR_ENQUEUE_MESSAGE_SINK_H
#define INCLUDED_METEOR_ENQUEUE_MESSAGE_SINK_H

#include <meteor/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace meteor {

/*!
 * This block can be "observed" by outside objects using its `meteor_observe`
 * method.
 * Each PMT received by this block is serialized and queued internally.
 * Calling `meteor_observe` will let users retrieve the queued binary data as
 * std::string (or str in Python). If the queue is empty, `meteor_observe`
 * returns
 * an empty string.
 *
 */
class METEOR_API enqueue_message_sink : virtual public gr::sync_block {
 public:
  typedef boost::shared_ptr<enqueue_message_sink> sptr;

  static sptr make();
  virtual void register_meteor_queue(uint64_t ptr) = 0;
};

}  // namespace meteor
}  // namespace gr

#endif /* INCLUDED_METEOR_ENQUEUE_MESSAGE_SINK_H */
