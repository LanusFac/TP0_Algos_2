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

int main(int argc, char *argv[]) {
    complejo com;
    istream *iFile;
    ostream *oFile;
    ifstream iFileReferencia_dft("referencia_dft.txt");
    ifstream iFileReferencia_idft("referencia_idft.txt");
    Array<complejo> & (*transformada)(Array<complejo> &x);

    int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);

        if (metodo_elegido == 1)
            transformada = dft;
        else if (metodo_elegido == -1)
            transformada = idft;


    Array <complejo> arr_com;

    while(!(*iFile).eof()){

        arr_com.cargar_array(*iFile, &arr_com, *oFile);

        if ((*iFile).eof())
            break;

        Array<complejo>& arrayComplejosTransformados = transformada(arr_com);
        (*oFile) << arrayComplejosTransformados << endl;

        ostream *errFile;
        fstream eF;
        string arg = "errores.txt";
        eF.open(arg.c_str(), ios::out);
        errFile = &eF;

        if(metodo_elegido == 1)
            arr_com.cargar_array(iFileReferencia_dft, &arr_com, *errFile);
        else if(metodo_elegido == -1)
            arr_com.cargar_array(iFileReferencia_idft, &arr_com, *errFile);
        else
            cerr << "method not found" << endl;

        if(calculador_error(arrayComplejosTransformados, arr_com) == true)
        {
            (*oFile) << "good" << endl;
        }

        else{
            (*oFile) << "bad" << endl;
        }

        delete &arrayComplejosTransformados;
    }
    return 0;
}
