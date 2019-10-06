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

using namespace std;

#define CHOP_SIZE 1
#define SEPARADOR "--" // esto separa la entrada de la salida

int main(int argc, char *argv[]) {
    complejo com;
    istream *iFile;
    ostream *oFile;

    int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);
    cout << metodo_elegido << endl;

    Array <complejo> arr_com;

    while(!(*iFile).eof()){

        arr_com.cargar_array (*iFile, &arr_com);

        (*oFile) << "input" << endl;

        for (int h = 0; h < arr_com.getSize(); h++)
            (*oFile) << arr_com[h] << endl;

        Array<complejo> arrayComplejosTransformados;

        if (metodo_elegido == 1)
            arrayComplejosTransformados = _dft(arr_com);

        //else if (metodo_elegido == -1)
            //arrayComplejosTransformados = _idft(arr_com); por ahora lo comento porque no tenemos idft

        (*oFile) << SEPARADOR << endl;

        (*oFile) << "output" << endl;
        for (int h = 0; h < arrayComplejosTransformados.getSize(); h++)
            (*oFile) << arrayComplejosTransformados[h] << endl;
    }

    (*oFile) << "End of Convertion" << endl;
    return 0;

}
