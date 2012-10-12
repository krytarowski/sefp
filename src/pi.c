/*****************************************************************************
 *  Copyright (C) 2007-2012 Martina Maggio - maggio.martina@gmail.com        *
 *                                                                           *
 *  Permission is hereby granted, free of charge, to any person obtaining    *
 *  a copy of this software and associated documentation files (the          *
 *  "Software"), to deal in the Software without restriction, including      *
 *  without limitation the rights to use, copy, modify, merge, publish,      *
 *  distribute, sublicense, and/or sell copies of the Software, and to       *
 *  permit persons to whom the Software is furnished to do so, subject       *
 *  to the following conditions:                                             *
 *                                                                           *
 *  The above copyright notice and this permission notice shall be included  *
 *  in all copies or substantial portions of the Software.                   *
 *                                                                           *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY                *
 *  KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE               *
 *  WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND      *
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE   *
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION   *
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION    *
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE           *
 *****************************************************************************/

// The aim of this program is to find the value of pi
// with the maximum of the library using Taylor series

#include <stdio.h>
#include "fp.h"

#define MAX_PRECISION 128

int main(int argc, char** argv) {

  fpNumber piOverSix;
  fpNumber increment;
  fpNumber six;
  fpNumber pi;

  int num = 0;

  increment = fpToFpNumber(0.5);
  piOverSix = fpToFpNumber(0.5);

  while(increment.exponent > (-MAX_PRECISION-1)) {
    num=num+1;
    int numerator = ((2*num)-1);
    fpNumber numConvert = fpToFpNumber((double)numerator);
    increment = fpProduct(increment,numConvert,MAX_PRECISION);
    increment = fpProduct(increment,numConvert,MAX_PRECISION);

    int denominator = ((8*num)*((2*num)+1));
    fpNumber denConvert = fpToFpNumber(1/((double)denominator));
    increment = fpProduct(increment,denConvert,MAX_PRECISION);

    piOverSix = fpSum(piOverSix,increment,MAX_PRECISION);
  }

  six = fpToFpNumber(6.0);
  pi  = fpProduct(six, piOverSix, MAX_PRECISION);

  fprintf(stdout,"Pi:\n");
  if (pi.isNegative==1) fprintf(stdout,"- ");
  else fprintf(stdout, "+ ");
  fprintf(stdout,"1, (%u) (%u) (%u) (%u) x 2^(%d)\n",
          pi.mantissa1,
	  pi.mantissa2,
	  pi.mantissa3,
	  pi.mantissa4,
	  pi.exponent); 
  fprintf(stdout, "Conversion: %f\n",fpToDouble(pi));

  return 0;
}
