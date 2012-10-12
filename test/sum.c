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

#include <stdio.h>
#include <stdlib.h>
#include <fp.h>

#define NUMBER_TESTS 1000000
#define TOLERANCE 0.0000001

int main(int argc, char** argv) {

  int success = 0;
  int tentative;
  
  for(tentative=0; tentative<NUMBER_TESTS; tentative++) {
    double number1 = (rand()/RAND_MAX-0.5)*20;
    double number2 = (rand()/RAND_MAX-0.5)*20;
    double sum_oracle = number1 + number2;

    fpNumber fpConverted1 = fpToFpNumber(number1);
    fpNumber fpConverted2 = fpToFpNumber(number2);
    fpNumber fpSumval     = fpSum(fpConverted1, fpConverted2, 128);
    double sum            = fpToDouble(fpSumval);

    if (fabs(sum_oracle - sum) < TOLERANCE)
      success++;
  }

  if (success==NUMBER_TESTS)
    printf("sum test                   [passed]\n");
  else
    printf("sum test                   [failed] %d/%d\n",success,NUMBER_TESTS);

  return 0;

}

