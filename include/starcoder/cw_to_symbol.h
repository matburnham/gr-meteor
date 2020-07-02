/* -*- c++ -*- */
/* 
 * Copyright 2019 Infostellar, Inc..
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
 * gr-satnogs: SatNOGS GNU Radio Out-Of-Tree Module
 *
 *  Copyright (C) 2016-2018
 *  Libre Space Foundation <http://librespacefoundation.org/>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_METEOR_CW_TO_SYMBOL_H
#define INCLUDED_METEOR_CW_TO_SYMBOL_H

#include <meteor/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace meteor {

    /*!
     * \brief <+description of block+>
     * \ingroup meteor
     *
     */
    class METEOR_API cw_to_symbol : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<cw_to_symbol> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of meteor::cw_to_symbol.
       *
       * To avoid accidental use of raw pointers, meteor::cw_to_symbol's
       * constructor is in a private implementation
       * class. meteor::cw_to_symbol::make is the public interface for
       * creating new instances.
       */
      static cw_to_symbol::sptr
      make (double sampling_rate, float threshold, float conf_level = 0.9,
            size_t wpm = 20);

      virtual void
      set_act_threshold (float thrld) = 0;
    };

  } // namespace meteor
} // namespace gr

#endif /* INCLUDED_METEOR_CW_TO_SYMBOL_H */

