#ifndef _DFT_H_INCLUDED
#define _DFT_H_INCLUDED

#include <math.h>
#include <iostream>
#include "complejo.h"
#include "array.h"

#define PI 3.142

Array<complejo> & _dft(const Array &x, int flag);
Array<complejo> &  dft(const Array &x);
Array<complejo> & idft(const Array &x);


#endif