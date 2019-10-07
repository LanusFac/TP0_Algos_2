#include <iostream>
#include <math.h>
#include "dft.h"

Array<complejo> * _dft(Array <complejo> &x, int flag){
//flag=1 	dft
//flag=-1 	idft	
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

	return transf;
}

Array<complejo> &dft(Array<complejo> &x){
	return *(_dft(x, 1));
}

Array<complejo> &idft(Array<complejo> &x){
	Array<complejo> *transf;
	transf=_dft(x, -1);

	(*(transf))*=(1.0/x.getSize()); //conjuga W_nk

	return *(transf);
}
