//funcion para leer de a un solo vector desde archivo de entrada
//recibe archivo del que debe leer y devuelve array de complejos leido
//devuelve NULL cuando se llega al final del archivo
//si encuentra un error en un vector imprime msj y pasa al siguiente

#include <iostream>
#include <fstream>
#include <string>

//#include "complejo.cc"
//#include "array.cpp"
#include "cargar_array.h"
#include "array.h"

void cargar_array(istream &iFile, Array<complejo> *arr){

    string s;

    while(getline(iFile, s)){

        fstream file_aux;
        file_aux << s << '\n';

        file_aux >> (*arr);

        if(file_aux.fail()){
            continue;
        }
    }
}
