#include <iostream>
#include <math.h>
#include "dft.h"

Array<complejo> & _dft(const Array &x, int flag){

	int N = x.getSize();
	Array<complejo> *transf = new Array<complejo>(N);//constructor por tamano
	Array<complejo> w_nk (N);


	for(int k=0; k <= N-1; k++){
		double arg=2*PI*k/N;

		for(int n=0; n <= N-1; n++){
			w_nk[k] += x[n]*complejo(cos(arg*n),flag*sin(arg*n));
		}
		(*transf)[k] = w_nk[k];
	}

	return *transf;
}

Array<complejo> &dft(const Array &x){
	return _dft(const Array &x, 1);
}

Array<complejo> &idft(const Array &x){
	return _dft(const Array &x, -1)/getSize(x); //conjuga W_nk
}