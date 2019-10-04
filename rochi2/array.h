#ifndef _ARRAY_H_INCLUDED_
#define _ARRAY_H_INCLUDED_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <math.h>
#include <cstring>

#define INIT_SIZE 0

using namespace std;


template <class T>
class Array
{
public:
	Array();
	Array(const Array<T> &);
    Array(const int);
	~Array();

	int getSize();
	Array<T> & operator= (const Array<T> &);
	bool operator== (const Array<T> &);
	T & operator[](int);

	Array<T>& operator*(const T f);
	Array<T>& operator+=(const Array<T> &initArray);
	Array<T>& operator+(const Array<T> &initArray);
	Array<T>& operator*=(const T f);
	Array <T> cargar_array(std::istream &iFile);

template <class Y>	friend std::istream & operator>>(std::istream &file, Array<Y> &x);

template <class Y> friend std::ostream & operator<<(std::ostream &os, Array<Y> &arr);

private:
	int size;
	T * ptr;
};


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

// Agregado por Facu

template <class T>
Array<T>& Array<T>::operator+(const Array<T> &initArray)
{
	Array<T> outArr = Array(size);

	if(size == initArray.size)
	{
		for(int i = 0; i < size; i++)
		{
			outArr[i] = ptr[i] + initArray.ptr[i];
		}
	}

	return outArr;
}

template <class T>
Array<T>& Array<T>::operator+=(const Array<T> &initArray)
{
	if(size == initArray.size)
	{
		for (int i = 0; i < size; i++)
		{
			ptr[i] = ptr[i] + initArray.ptr[i];
		}
	}

	return *this;
}

template <class T>
Array<T>& Array<T>::operator*(const T f)
{
	Array<T> outArr = Array(size);

	for (int i = 0; i < size; i++)
	{
		outArr[i] = ptr[i] * f;
	}

	return outArr;
}

template <class T>
Array<T>& Array<T>::operator*=(const T f)
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = ptr[i] * f;
	}

	return *this;
}

// termina agragado por Facu

template <class T>
T & Array<T>::operator[](int subscript)
{
	return ptr[subscript];
}

template <class T>
std::istream & operator>>(std::istream &file, Array<T> &x)
{
	T data ;

	while(file >> data){ //lee de a un complejo y ve que no haya error

		if(!file.fail()){

			Array <T> x_aux(x.getSize() + 1);

			for (int i = 0; i < x.getSize(); i++)
				x_aux[i] = x[i];

			x_aux[x.getSize()] = data;

			x = x_aux;
		}

		else{
			file.clear(ios::badbit);
			cerr << "error al leer el vector";
			return file;
		}
	}

	return file;
}


template <class T>
std::ostream & operator<<(std::ostream &os, Array<T> &arr) { //para imprimir sobrecargo <<
    for (int i = 0; i<arr.getSize(); i++)
        os<<arr[i];
    return os<<'\n';
}

template <class T>
Array <T> Array<T>::cargar_array(std::istream &iFile){

	string s;

    while(getline(iFile, s)){

        fstream file_aux;
        file_aux << s << '\n';

        Array <T> arr_aux;
        file_aux >> arr_aux;

        if(file_aux.fail()){
            continue;
        }

        return arr_aux;
    }
    //return NULL;

}

#endif