#ifndef MAIN__FACU__H
#define MAIN__FACU__H

#include <iostream>
#include "types.h"

#define OUTPUT_ARG_1 "-o"
#define OUTPUT_ARG_2 "--output"

#define INPUT_ARG_1 "-i"
#define INPUT_ARG_2 "--input"

#define METHOD_ARG_1 "-m"
#define METHOD_ARG_2 "--method"

#define METHOD_DFT "dft"
#define METHOD_IDFT "idft"


#define OUTPUT_ARG_POS 1
#define OUTPUT_TEXT_FILE_POS 2

#define INPUT_ARG_POS 3
#define INPUT_TEXT_FILE_POS 4

#define METHOD_ARG_POS 5
#define METHOD_OPTION_POS 6

#define MAX_ARGS 7


#define MSG_ERROR_CANTIDAD_ARGUMENTOS_INGRESADOS "Error en la cantidad de argumentos."
#define MSG_ERROR_FLAG_SALIDA "Error en el flag de salida. debe ser -o o --output"
#define	MSG_ERROR_FLAG_ENTRADA "Error en el flag de entrada. debe ser -i o --input"
#define MSG_ERROR_FLAG_METODO "Error en el flag sobre el metodo. debe ser -m o --method"
#define MSG_ERROR_NO_EXISTE_ARCHIVO_ENTRADA "No existe el archivo de entrada, o no se pudo abrir."
#define MSG_ERROR_TIPO_TRANFORMADA "Transformada invalida. debe ser dft o idft."

void errors_printer (status_t st);
status_t validar_argumentos(int argc, char const *argv[]);

#endif
