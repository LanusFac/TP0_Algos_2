#include "array.h"
#include <iostream>
#include <cstring>

using namespace std;

#define INIT_SIZE 0

template <class T>
Array<T>::Array()
{
	ptr = new T[INIT_SIZE];
	size = INIT_SIZE;
    memset (ptr, 0, INIT_SIZE*sizeof(T));
}

template <class T>
Array<T>::Array(const int sz)
{
	ptr = new T[sz];
	size = sz;
    memset (ptr, 0, sz*sizeof(T));
}

template <class T>
Array<T>::Array(const Array<T> & initArray)
{
	size = initArray.size;
	ptr = new T[size];

	for (int i = 0; i < size; i++)
		ptr[i] = initArray[i];
}

template <class T>
Array<T>::~Array()
{
	if(ptr)
		delete[] ptr;
}

template <class T>
int Array<T>::getSize()
{
	return size;
}

template <class T>
Array<T> & Array<T>::operator=(const Array<T> & initArray)
{
	if(&initArray != this)
	{
		if (size != initArray.size)
		{
			T * aux;
			aux = new T[initArray.size];
			delete[] ptr;
			size = initArray.size;
			ptr = aux;
        }
		for (int i = 0; i < size; i++)
			ptr[i] = initArray.ptr[i];
	}
	return *this;
}

template <class T>
bool Array<T>::operator== (const Array<T> & initArray)
{
	if(size != initArray.size)
		return false;

	for (int i = 0; i < size; i++)
		if (ptr[i] != initArray.ptr[i])
			return false;

	return true;
}

template <class T>
T & Array<T>::operator[](int subscript)
{
	return ptr[subscript];
}

template <class T>
std::istream & operator>>(std::istream &file, Array<T> &x)
{
	T data ;

	while(file >> data){

		Array <T> x_aux(x.getSize() + 1); 
		
		for (int i = 0; i < x.getSize(); i++)
			x_aux[i] = x[i];

		x_aux[x.getSize()] = data;

		x = x_aux;
	}

	return file;
}


//falta leer del archivo/pantalla y guardarlo en el array
