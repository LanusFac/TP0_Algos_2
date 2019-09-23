#ifndef _DFT_H_INCLUDED
#define _DFT_H_INCLUDED

#include <math.h>
#include <iostream>
#include "complejo.cc"
#include "array.cpp"

#define PI 3.142


&Array _dft(const Array &x, int flag);

&Array dft(const Array &x);

&Array idft(const Array &x);


#endif
