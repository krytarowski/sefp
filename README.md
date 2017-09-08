sefp: Software Emulation Floating Point precision
====
[![Build Status](https://travis-ci.org/martinamaggio/sefp.png)](https://travis-ci.org/martinamaggio/sefp)

SEFPp is a C library that allows to emulate floting point various precision.

The library implements some floating point operations with customizable precision. The precision level is achieved setting the operands mantissa, the mantissa dimension can span from 1 to 128 bits. The exponent is always encoded in a int value.
The library currently supports the precision change, comparison functionalities, sum, subtraction, multiplication, sine and cosine, together with the conversion to and from a generic double number. Together with some test cases, a program to calculate the pi value with the Taylor serie is provided as an example (it can be compiled with make pi and run with ./bin/pi). 

Usage examples: the library can be used to test if a double or single precision is needed in a given project.
In 2007 and 2008 it was used to analyze the effects of finite precision in the implementation of active noise and vibration cancellation control systems, the results of the study were published in International Conference Proceedings. The papers can be found in the docs directory.



Building instructions
====

Once you downloaded the release, type 'make' to build the library and 'make test' to build the library and to compile and execute test cases. Use 'make clean' to remove all the executable files.
The library requires you have a C compiler installed. It was tested under Linux and Mac OS.
