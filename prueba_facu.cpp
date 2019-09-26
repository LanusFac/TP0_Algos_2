#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include "complejo.cc"
#include "array.cpp"
#include "dft_facu.cpp"
#include "types.h"
#include "mainFacu.h"

#define CHOP_SIZE 1


#define SALIDA oFile // flujo de salida. si es cout: por pantalla; si es oFile, es en archivo de texto. 
#define SEPARADOR "--" // esto separa la entrada de la salida

using namespace std;





int main (int argc, char const *argv[])

{
	Array<complejo> arr_com;
	complejo com;
	status_t st;

	if((st = validar_argumentos(argc, argv)) != OK)
	{
		errors_printer(st);

		return 1;
	}

	ifstream iFile(argv[INPUT_TEXT_FILE_POS]);

	if (!iFile.is_open())
	{
		errors_printer(ERROR_NO_EXISTE_ARCHIVO_ENTRADA);

		return 1;
	}

	while(iFile >> com){

		Array <complejo> arr_com_aux(arr_com.getSize() + CHOP_SIZE); 
		
		for (int i = 0; i < arr_com.getSize(); i++)
			arr_com_aux[i] = arr_com[i];

		arr_com_aux[arr_com.getSize()] = com;

		arr_com = arr_com_aux;
		// delete[] arr_com_aux; con & compila pero tira seg.f
	}

	ofstream oFile(argv[OUTPUT_TEXT_FILE_POS]);

	iFile.close();
	
	Array<complejo> arrayComplejosTransformados;

	if (!strcmp(argv[METHOD_OPTION_POS], METHOD_DFT))
		arrayComplejosTransformados = _dft(arr_com);


	for (int h = 0; h < arr_com.getSize(); h++) 
		SALIDA << arr_com[h] << endl;

	SALIDA << SEPARADOR << endl;


	for (int h = 0; h < arrayComplejosTransformados.getSize(); h++) 
		SALIDA << arrayComplejosTransformados[h] << endl;
	

	oFile.close();

	return 0;
}

void errors_printer (status_t st)
{
	string errors[] = {
		MSG_ERROR_CANTIDAD_ARGUMENTOS_INGRESADOS,
		MSG_ERROR_FLAG_SALIDA,
		MSG_ERROR_FLAG_ENTRADA,
		MSG_ERROR_FLAG_METODO,
		MSG_ERROR_NO_EXISTE_ARCHIVO_ENTRADA,
		MSG_ERROR_TIPO_TRANFORMADA
	};

	cerr << errors[st] << endl;
}

status_t validar_argumentos(int argc, char const *argv[])
{
	if (argc != MAX_ARGS)
		return ERROR_CANTIDAD_ARGUMENTOS_INGRESADOS;
	if (strcmp(argv[OUTPUT_ARG_POS], OUTPUT_ARG_1) && strcmp(argv[OUTPUT_ARG_POS], OUTPUT_ARG_2))
		return ERROR_FLAG_SALIDA;
	if (strcmp(argv[INPUT_ARG_POS], INPUT_ARG_1) && strcmp(argv[INPUT_ARG_POS], INPUT_ARG_2))
		return ERROR_FLAG_ENTRADA;
	if (strcmp(argv[METHOD_ARG_POS], METHOD_ARG_1) && strcmp(argv[METHOD_ARG_POS], METHOD_ARG_2))
		return ERROR_FLAG_METODO;
	if (strcmp(argv[METHOD_OPTION_POS], METHOD_DFT) && strcmp(argv[METHOD_OPTION_POS], METHOD_IDFT))
		return ERROR_TIPO_TRANFORMADA;

	return OK;
}

