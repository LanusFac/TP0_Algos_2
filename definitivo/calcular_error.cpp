#include<iostream>

#include"array.h"
#include"calcular_error.h"
#include "complejo.h"

bool calculador_error(Array<complejo> & transformados, Array<complejo> & referencia)
{
/*
	if(transformados.getSize() != referencia.getSize())
		return false;
*/
	for(int i = 0; i < transformados.getSize(); i++)
	{
		double modRef;
		if((transformados[i]).abs() == 0)
			modRef = 1;
		else
			modRef = (transformados[i]).abs();


		double error = (transformados[i] - referencia[i]).abs() / (modRef * 100);

		if (error > ERROR_TOLERADO)
			return false;
	}

	return true;

}
