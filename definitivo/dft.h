#ifndef _DFT_H_INCLUDED
#define _DFT_H_INCLUDED

#include <math.h>
#include <iostream>
#include "complejo.h"
#include "array.h"

#define PI 3.14159265359

Array<complejo> & _dft( Array<complejo> &x, int flag); //funcion de uso interno/implementacion, no para el usuario
Array<complejo> &  dft( Array<complejo> &x);
Array<complejo> & idft( Array<complejo> &x);


#endif
