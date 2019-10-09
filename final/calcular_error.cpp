#include<iostream>

#include"array.h"
#include"calcular_error.h"
#include "complejo.h"

bool calculador_error(Array<complejo> & transformados, Array<complejo> & referencia)
{
	double error = 0;

	if(transformados.getSize() != referencia.getSize())
		return false;

	for(int i = 0; i < transformados.getSize(); i++)
	{
		double modRef;
		if((transformados[i]).abs() == 0 && (referencia[i]).abs() == 0)
			return true;
		else if ((referencia[i]).abs() == 0){
			error = (transformados[i]).abs();
		}
		else if ((transformados[i]).abs() == 0){
			error = (referencia[i]).abs();
		}
		else{
			modRef = (transformados[i]).abs();
			error = ((transformados[i] - referencia[i]).abs() / modRef) * 100;
		}

		if (error > ERROR_TOLERADO)
			return false;
	}

	return true;

}
