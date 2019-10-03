#ifndef _ARRAY_H_INCLUDED_
#define _ARRAY_H_INCLUDED_

#include <iostream>

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

template <class Y>	friend std::istream & operator>>(std::istream &file, Array<Y> &x);

template <class Y> friend std::ostream & operator<<(std::ostream &os, Array<Y> &arr);

private:
	int size;
	T * ptr;
};

#endif
