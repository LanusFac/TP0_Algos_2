#include <complejo.h>
#include <array.h>
#include <dft.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    Array <complejo> x; //la que voy a transformar
    ifstream is = cin; //borrar cuando tengamos hecho el stream
    ofstream os = cout; //borrar cuando tengamos hecho el stream
    is>>x;//is es el input stream

    //cuando tengamos cmdline hacemos que se decida si se hace dft o idft
    
    Array <complejo> X = dft(x);
    os<<X;
    delete []x;
    delete []X;
    return 0;
}

//main de prueba:
//hacer dft/idft
//imprimir
//hacer idft/idft
//imprimir para verificar que sean iguales salvo errores numericos
