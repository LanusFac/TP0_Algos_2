#include <iostream>
#include <math.h>
#include "dft.h"

Array<complejo> _dft(Array <complejo> &x, int flag){ //funcion de uso interno/implementacion, no para el usuario
//recibe un array de complejos y un flag que conjuga W_nk
//realiza dft (1) o idft(-1) según el flag.

	int N = x.getSize();
	Array<complejo> transf;
	transf = Array<complejo>(N);//constructor por tamano
	Array<complejo> w_nk (N);
	double arg;
	complejo aux;

	for(int k=0; k <= N-1; k++){
		arg=2*PI*k/N;

		for(int n=0; n <= N-1; n++){
			aux=
			w_nk[k] += x[n]*complejo(cos(arg*n),flag*sin(arg*n));
		}
		transf [k] = w_nk[k];
	}
	return transf;
}

Array<complejo> dft(Array<complejo> &x){
	return _dft(x, 1);
}

Array<complejo> idft(Array<complejo> &x){
	Array<complejo> transf=_dft(x, -1);

	transf*=(1.0/x.getSize());
	return transf;
}
