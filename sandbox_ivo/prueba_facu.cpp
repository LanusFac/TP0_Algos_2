#include <iostream>
#include <fstream>
#include <string>
#include "complejo.cc"
#include "array.cpp"

#define INPUT_TEXT "prueba.txt"
#define CHOP_SIZE 1

using namespace std;

int main ()
{
	Array<complejo> arr_com;
	complejo com;

	ifstream input(INPUT_TEXT);
	ofstream output("output.txt");
	string str;

	input>>arr_com;
	output<<arr_com;

/*

	while(file >> com){

		cout << "pito" << endl;

		if(file.peek() == '\n')
			cout << "hola" << endl;

		Array <complejo> arr_com_aux(arr_com.getSize() + CHOP_SIZE); 
		
		for (int i = 0; i < arr_com.getSize(); i++)
			arr_com_aux[i] = arr_com[i];

		arr_com_aux[arr_com.getSize()] = com;

		arr_com = arr_com_aux;
		// delete[] arr_com_aux; con & compila pero tira seg.f

	}

	file.close();



	
	for (int h = 0; h < arr_com.getSize(); h++) 
		cout << arr_com[h];
	cout << arr_com.getSize() << endl;
*/


	return 0;
}


