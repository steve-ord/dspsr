/*

 */

#ifndef __dsp_CASPSRUnpackerCUDA_h
#define __dsp_CASPSRUnpackerCUDA_h

#include<stdint.h>
//#include "dsp/HistUnpacker.h"

void caspsr_unpack (const uint64_t nadt,unsigned char* stagingBufGPU,float* unpackBufGPU,int dimBlockUnpack,int dimGridUnpack,unsigned halfData, float* into_pola, float* into_polb);
  

#endif
