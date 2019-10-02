#include "dft.h"

&Array _dft(const Array &x, int flag){

	int N=getSize(x);
	Array<complejo> transf=Array(N);//constructor por tamano
	Array<complejo> w_nk=Array(N);

	for(k=0, arg=2*PI*k/N;	k==N-1	; k++){
		for(n=0;n==N-1;n++){
			w_nk[k]+=x(n)*complejo(cos(arg*n),flag*cos(arg*n));
		}
	}

	return &transf;
}

&Array dft(const Array &x){
	return _dft(const Array &x, 1);
}

&Array idft(const Array &x){
	return _dft(const Array &x, -1)/getSize(x); //conjuga W_nk
}