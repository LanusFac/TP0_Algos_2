#include "complejo.h"
#include "array.h"
#include "dft.h"
#include "leer_cmdline.h"
#include "calcular_error.h"

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

int main(int argc, char *argv[]) {
    complejo com;
    istream *iFile;
    ostream *oFile;
    ifstream iFileReferencia("referencia.txt");
    Array<complejo> & (*transformada)(Array<complejo> &x);

    int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);

        if (metodo_elegido == 1)
            transformada = dft;
        else if (metodo_elegido == -1)
            transformada = idft;


    Array <complejo> arr_com;

    while(!(*iFile).eof()){

        arr_com.cargar_array(*iFile, &arr_com, *oFile);
  
        Array<complejo> arrayComplejosTransformados;

        arrayComplejosTransformados = transformada(arr_com);
        (*oFile) << arrayComplejosTransformados;

        arr_com.cargar_array(iFileReferencia, &arr_com, *oFile);

        if(calculador_error(arrayComplejosTransformados, arr_com) == true)
        {
            (*oFile) << "error chico" << endl;
        }

        else{
            (*oFile) << "error grande" << endl;
        }


    }
    return 0;
}
