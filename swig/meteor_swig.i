/* -*- c++ -*- */

#define METEOR_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "meteor_swig_doc.i"

%{
#include "meteor/ar2300_source.h"
#include "meteor/complex_to_msg_c.h"
#include "meteor/waterfall_heatmap.h"
#include "meteor/waterfall_plotter.h"
#include "meteor/enqueue_message_sink.h"
#include "meteor/ax25_decoder_bm.h"
#include "meteor/command_source.h"
#include "meteor/ax25_encoder_mb.h"
#include "meteor/noaa_apt_sink.h"
#include "meteor/meteor_decoder_sink.h"
#include "meteor/golay_decoder.h"
#include "meteor/cw_to_symbol.h"
#include "meteor/morse_decoder.h"
%}


%include "meteor/ar2300_source.h"
GR_SWIG_BLOCK_MAGIC2(meteor, ar2300_source);

%include "meteor/complex_to_msg_c.h"
GR_SWIG_BLOCK_MAGIC2(meteor, complex_to_msg_c);
%include "meteor/waterfall_heatmap.h"
GR_SWIG_BLOCK_MAGIC2(meteor, waterfall_heatmap);
%include "meteor/waterfall_plotter.h"
GR_SWIG_BLOCK_MAGIC2(meteor, waterfall_plotter);
%include "meteor/enqueue_message_sink.h"
GR_SWIG_BLOCK_MAGIC2(meteor, enqueue_message_sink);
%include "meteor/ax25_decoder_bm.h"
GR_SWIG_BLOCK_MAGIC2(meteor, ax25_decoder_bm);
%include "meteor/command_source.h"
GR_SWIG_BLOCK_MAGIC2(meteor, command_source);
%include "meteor/ax25_encoder_mb.h"
GR_SWIG_BLOCK_MAGIC2(meteor, ax25_encoder_mb);
%include "meteor/noaa_apt_sink.h"
GR_SWIG_BLOCK_MAGIC2(meteor, noaa_apt_sink);
%include "meteor/meteor_decoder_sink.h"
GR_SWIG_BLOCK_MAGIC2(meteor, meteor_decoder_sink);
%include "meteor/golay_decoder.h"
GR_SWIG_BLOCK_MAGIC2(meteor, golay_decoder);
%include "meteor/cw_to_symbol.h"
GR_SWIG_BLOCK_MAGIC2(meteor, cw_to_symbol);
%include "meteor/morse_decoder.h"
GR_SWIG_BLOCK_MAGIC2(meteor, morse_decoder);
