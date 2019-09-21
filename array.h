#ifndef _ARRAY_H_INCLUDED_
#define _ARRAY_H_INCLUDED_

#include <iostream>

#ifndef _ARRAY_H_INCLUDED
#define _ARRAY_H_INCLUDED

template <class T>
class Array
{
public:
	Array();
	Array(const Array<T> &);
	~Array();

	int getSize();
	Array<T> & operator= (const Array<T> &);
	bool operator== (const Array<T> &);
	T & operator[](int);

private:
	int size;
	T * ptr;
};

#endif
