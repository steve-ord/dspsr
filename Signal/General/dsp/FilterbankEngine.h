//-*-C++-*-
/***************************************************************************
 *
 *   Copyright (C) 2011 by Willem van Straten
 *   Licensed under the Academic Free License version 2.1
 *
 ***************************************************************************/

#ifndef __FilterbankEngine_h
#define __FilterbankEngine_h

#include "dsp/Filterbank.h"
//#include "dsp/filterbank_engine.h"

class dsp::Filterbank::Engine : public Reference::Able
{
public:

  Engine () { scratch = output = 0; }

  //! If kernel is not set, then the engine should set up for benchmark only
  virtual void setup (Filterbank*) = 0;

  //! provide some scratch space for the engine
  virtual void set_scratch (float *) = 0;

  //! Perform the filterbank operation on the input data
  virtual void perform (const dsp::TimeSeries * in, 
                        dsp::TimeSeries * out,
                        uint64_t npart, 
                        const uint64_t in_step, 
                        const uint64_t out_step) = 0;

  //! Finish up
  virtual void finish () { }

  //! configure the engine
  void configure (unsigned _nchan, unsigned _nfilt_pos, unsigned _freq_res, unsigned _nkeep) {
    nchan = _nchan;
    nfilt_pos = _nfilt_pos;
    freq_res = _freq_res;
    nkeep = _nkeep;
  }


protected:

  float* scratch;

  float* output;
  unsigned output_span;

  unsigned nchan;
  unsigned freq_res;
  unsigned nfilt_pos;
  unsigned nkeep;

}; 

#endif
