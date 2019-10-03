#include <iostream>
#include <math.h>
#include "dft_facu.h"

Array<complejo> & _dft(Array<complejo> &x)
{

	int N = x.getSize();
	Array<complejo> *transf = new Array<complejo>(N);//constructor por tamano
	Array<complejo> w_nk (N);


	for(int k=0; k <= N-1; k++){
		double arg = -2 * PI * k / N;
 
		for(int n=0; n <= N-1; n++){
			w_nk[k] += x[n]*complejo(cos(arg*n),sin(arg*n));
		}
		(*transf)[k] = w_nk[k];
	}

	return *transf;
}

