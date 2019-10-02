#include <iostream>
#include <fstream>
#include <string>
#include "complejo.cc"
#include "array.cpp"
#include "dft.cc"

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
	cout<<dft(arr_com)<<endl;
	cout<<idft(arr_com)<<endl;
	output<<arr_com<<endl;

	input.close();
	output.close();


	return 0;
}


