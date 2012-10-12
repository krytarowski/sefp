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

#ifndef _FP_H
#define _FP_H

  #include <stdio.h>
  #include <math.h>
  #include <limits.h>

  #define INTEGER_DIMENSION 32
  #define MAX_MANTISSA_BITS 128
  #define MANTISSA_INTEGERS 4

  #define PI_MANTISSA1 2451551556
  #define PI_MANTISSA2 1121027111
  #define PI_MANTISSA3 4203919614
  #define PI_MANTISSA4 1037418366
  #define PI_EXPONENT  1

  typedef struct {
    // the number is:
    // ( 1, mantissa1 mantissa2 mantissa3 mantissa4 ) x 2^exponent
    unsigned int mantissa1;
    unsigned int mantissa2;
    unsigned int mantissa3;
    unsigned int mantissa4;
    int exponent;
    short isNegative; // 1 for true, 0 for false
  } fpNumber;

  double fpToDouble(fpNumber num);
  fpNumber fpToFpNumber(double num);

  fpNumber fpChangePrecision(fpNumber num, int precision);
  int fpIsBiggerAbs(fpNumber num1, fpNumber num2);
  int fpIsBigger(fpNumber num1, fpNumber num2);

  fpNumber fpSum(fpNumber num1, fpNumber num2, int precision);
  fpNumber fpSubtract(fpNumber num1, fpNumber num2, int precision);
  fpNumber fpProduct(fpNumber num1, fpNumber num2, int precision);

  fpNumber fpSin(fpNumber num, int precision);
  fpNumber fpCos(fpNumber num, int precision);

#endif
