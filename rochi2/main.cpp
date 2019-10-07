#include "complejo.h"
#include "array.h"
#include "dft.h"
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
    Array<complejo> & (*transformada)(Array<complejo> &x);



    int metodo_elegido = leer_cmdline (argc, argv, &iFile, &oFile);
    cout << metodo_elegido << endl;

        if (metodo_elegido == 1)
            transformada = dft;
        else if (metodo_elegido == -1)
            transformada = idft; 


    Array <complejo> arr_com;

    while(!(*iFile).eof()){

        arr_com.cargar_array (*iFile, &arr_com);

        if ((*iFile).eof())
            break;

        (*oFile) << "input" << endl;

        (*oFile)<<arr_com<<endl;

        Array<complejo> arrayComplejosTransformados;

        arrayComplejosTransformados=transformada(arr_com);

        (*oFile) << SEPARADOR << endl;

        (*oFile) << "output" << endl;
        
        (*oFile) << arrayComplejosTransformados<<endl;
    }

    (*oFile) << "End of Convertion" << endl;
    return 0;

}
