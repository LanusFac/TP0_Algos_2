#include "complejo.h"
#include "array.h"
#include "dft_facu.h"
#include "leer_cmdline.h"
//#include "cargar_array.h"

/* #include "array.cpp"
#include "dft_facu.cpp"
#include "leer_cmdline.cpp"
#include "cargar_array.cpp"*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h>

#include "complejo.cc"
#include "array.cpp"
#include "dft.cc"
using namespace std;

#define CHOP_SIZE 1
#define SEPARADOR "--" // esto separa la entrada de la salida

int main(int argc, char *argv[]) {
    Array <complejo> arr_com; //la que voy a transformar
    complejo com;
    ifstream iFile("in.txt");
    ofstream oFile("out.txt");

   // int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);

    iFile>>arr_com;
    
    Array<complejo> arrayComplejosTransformados;

    Array<complejo> arrayComplejosAntiTransformados;

    arrayComplejosTransformados = dft(arr_com);

    arrayComplejosAntiTransformados = idft(arr_com);

    oFile<<"input:  "<<arr_com<<endl;
    oFile<<"output: "<<arrayComplejosTransformados<<endl;
    oFile<<"antitf: "<<arrayComplejosAntiTransformados<<endl;

}

//main de prueba:
//hacer dft/idft
//imprimir
//hacer idft/idft
//imprimir para verificar que sean iguales salvo errores numericos
