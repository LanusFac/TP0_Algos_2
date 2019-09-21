#include <dft.h>

&Array _dft(const Array &x, int flag){

	int N=getSize(x);
	Array_complejo transf=new Array_complejo(N);
	Array_complejo w_nk=new Array_complejo(N);

	for(k=1, arg=2*PI*k/N;	k==N	; k++){
		for(n=1;k==N;n++){
			w_nk[k]+=x(n)*complejo(cos(arg*n),flag*cos(arg*n));
		}
	}

	return &transformada;
}

&Array dft(const Array &x){
	return _dft(const Array &x, 1);
}

&Array dft(const Array &x){
	return _idft(const Array &x, -1)/getSize(x); //conjuga W_nk
}