//-*-C++-*-
/***************************************************************************
 *
 *   Copyright (C) 2006 by Willem van Straten
 *   Licensed under the Academic Free License version 2.1
 *
 ***************************************************************************/

/* $Source: /cvsroot/dspsr/dspsr/Signal/General/dsp/BandpassMonitor.h,v $
   $Revision: 1.2 $
   $Date: 2008/10/02 02:10:24 $
   $Author: straten $ */

#ifndef __baseband_dsp_BandpassMonitor_h
#define __baseband_dsp_BandpassMonitor_h

#include "dsp/TimeSeries.h"

#include <vector>

namespace dsp
{
  //! Rescale all channels and polarizations
  class BandpassMonitor
  {

  public:
	  BandpassMonitor();

	  void append(uint64 start,uint64 end, int pol,int nchans, float* means, float* variances, float* rmss, float* freq, float* zerotime);

  private:
	  //FILE *file[4];
	  FILE *file[6];
	  float *mean_sum[4];
	  float *var_sum[4];
	  int count[4];
  };
}

#endif