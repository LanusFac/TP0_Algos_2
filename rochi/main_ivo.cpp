#include "complejo.h"
#include "array.h"
#include "dft_facu.h"
#include "leer_cmdline.h"

#include "complejo.cc"
#include "array.cpp"
#include "dft.cc"
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
    ifstream iFile;
    ofstream oFile;

    int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);
    
    iFile>>arr_com;
    
    Array<complejo> arrayComplejosTransformados;

    if (metodo_elegido == 1)
        arrayComplejosTransformados = dft(arr_com);

    else if (metodo_elegido == -1)
        arrayComplejosTransformados = idft(arr_com);


    for (int h = 0; h < arr_com.getSize(); h++)
        oFile << arr_com[h] << endl;

    oFile << SEPARADOR << endl;


    for (int h = 0; h < arrayComplejosTransformados.getSize(); h++)
        oFile << arrayComplejosTransformados[h] << endl;

    return 0;

}

//main de prueba:
//hacer dft/idft
//imprimir
//hacer idft/idft
//imprimir para verificar que sean iguales salvo errores numericos
