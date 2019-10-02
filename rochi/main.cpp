//#include "complejo.h"
//#include "array.h"
//#include "dft_facu.h"
//#include "leer_cmdline.h"

#include "complejo.cc"
#include "array.cpp"
#include "dft_facu.cpp"
#include "leer_cmdline.cpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

#define CHOP_SIZE 1
#define SEPARADOR "--" // esto separa la entrada de la salida

int main(int argc, char *argv[]) {
    Array <complejo> arr_com; //la que voy a transformar
    complejo com;
    istream *iFile;
    ostream *oFile;

    int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);
    cout << metodo_elegido << endl;

    //iFile = (istream)(*iFilep);
    //oFile = (ostream)(*oFilep);

    string text;
    getline(*iFile, text);

    cout << text <<endl;

    while(*iFile >> com){ //inicializo array de complejos

        Array <complejo> arr_com_aux(arr_com.getSize() + CHOP_SIZE);

        for (int i = 0; i < arr_com.getSize(); i++)
            arr_com_aux[i] = arr_com[i];

        arr_com_aux[arr_com.getSize()] = com;

        arr_com = arr_com_aux;
        // delete[] arr_com_aux; con & compila pero tira seg.f

    }

    Array<complejo> arrayComplejosTransformados;

    if (metodo_elegido == 1)
        arrayComplejosTransformados = _dft(arr_com);

    else if (metodo_elegido == -1)
        //arrayComplejosTransformados = _idft(arr_com); por ahora lo comento porque no tenemos idft

    for (int h = 0; h < arr_com.getSize(); h++)
        (*oFile) << arr_com[h] << endl;

    (*oFile) << SEPARADOR << endl;


    for (int h = 0; h < arrayComplejosTransformados.getSize(); h++)
        (*oFile) << arrayComplejosTransformados[h] << endl;

    return 0;

}

//main de prueba:
//hacer dft/idft
//imprimir
//hacer idft/idft
//imprimir para verificar que sean iguales salvo errores numericos
