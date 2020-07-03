/* -*- c++ -*- */

#define METEOR_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "meteor_swig_doc.i"

%{
#include "meteor/meteor_decoder_sink.h"
%}

%include "meteor/meteor_decoder_sink.h"
GR_SWIG_BLOCK_MAGIC2(meteor, meteor_decoder_sink);
