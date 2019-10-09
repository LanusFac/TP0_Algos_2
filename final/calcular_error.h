#ifndef _CALCULAR_ERROR_H_INCLUDED_
#define _CALCULAR_ERROR_H_INCLUDED_

#include<iostream>
#include"complejo.h"

#define ERROR_TOLERADO 10e-10

bool calculador_error(Array<complejo> & transformados, Array<complejo> & referencia);

#endif
