#ifndef ARRAY__H
#define ARRAY__H



template <class T>
class Array
{
public:
	Array();
	Array(const Array<T> &);
	~Array();

	int getSize();
	Array<T> & operator = (const Array<T> &);
	bool operator == (const Array<T> &);
	T & operator[](int);

private:
	int size;
	T * ptr;
};

template <class T>
Array<T>::Array()
{
	ptr = new T[10];
	size = 10;
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

			for (int i = 0; i < size; i++)
				ptr[i] = initArray.ptr[i];

			return *this;
		}
	}
	return *this;
}

template <class T>
bool Array<T>::operator == (const Array<T> & initArray)
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

#endif


