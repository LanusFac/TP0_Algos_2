#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "complejo.cc"
#include "array.cpp"
#include "dft_facu.cpp"

#define INPUT_TEXT "prueba.txt"
#define OUTPUT_TEXT "oprueba.txt"
#define CHOP_SIZE 1
#define SALIDA oFile // flujo de salida. si es cout: por pantalla; si es oFile, es en archivo de texto. 
#define SEPARADOR "--" // esto separa la entrada de la salida

using namespace std;


int main ()


{
	Array<complejo> arr_com;
	complejo com;

	ifstream iFile(INPUT_TEXT);
	ofstream oFile(OUTPUT_TEXT);

	while(iFile >> com){

		Array <complejo> arr_com_aux(arr_com.getSize() + CHOP_SIZE); 
		
		for (int i = 0; i < arr_com.getSize(); i++)
			arr_com_aux[i] = arr_com[i];

		arr_com_aux[arr_com.getSize()] = com;

		arr_com = arr_com_aux;
		// delete[] arr_com_aux; con & compila pero tira seg.f

	}
	
	iFile.close();

	Array<complejo> arrayComplejosTransformados;
	arrayComplejosTransformados = _dft(arr_com);

	for (int h = 0; h < arr_com.getSize(); h++) 
		SALIDA << arr_com[h] << endl;

	SALIDA << SEPARADOR << endl;

	for (int h = 0; h < arrayComplejosTransformados.getSize(); h++) 
		SALIDA << arrayComplejosTransformados[h] << endl;
	

	oFile.close();

	return 0;
}
