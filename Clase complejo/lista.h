// lista.h - Implementación de listas doblemente enlazadas, no circulares,
// usando templates e iteradores.
//


#ifndef _LISTA_H_
#define _LISTA_H_

#include <cstdlib>

template<typename T>
class lista
{
	// Ponemos la clase nodo dentro de la parte privada de la lista, con la
	// idea de ocultar su existencia. La idea es reemplazar las funciones
	// normalmente destinadas a los nodos por operaciones provistas por
	// el TDA iterador. Ver más abajo.
	//
	class nodo
	{
		// Debido al fuerte acople entre iteradores y la estructura a
		// la cual iteran (es decir, el iterador necesita conocer los
		// detalles de implementación del TDA para poder abstraer el
		// recorrido), permitimos que la clase iterador tenga acceso
		// directo a los detalles internos del TDA.
		friend class iterador;
		friend class lista;

		nodo *sig_;
		nodo *ant_;
		T dato_;

	public:
		nodo(T const&);
		~nodo();
	};

	// Los atributos de cada instancia de la clase lista son enlaces a
	// dos nodos distinguidos de la secuencia: primero y último. Esto es
	// necesario para poder tener acceso inmediato, en todo momento, a
	// estos elementos, y reducir la complejidad de las operaciones que
	// necesiten hacerlo (por ejemplo, lista::primero y lista::ultimo).
	//
	nodo *pri_;
	nodo *ult_;
	size_t tam_;

public:
	// Iterador de lista. Buscamos proveer una metodología eficiente para
	// recorrer, uno a uno, los elementos de la estructura, evitando la
	// manipulación explícita de la misma. En este caso, además, queremos
	// usarlos como cursores, indicando los elementos a insertar o borrar
	// de la lista.
	//
	class iterador
	{
		friend class lista;

		nodo *actual_;
		iterador(nodo*);

	public:
		iterador();
		iterador(lista<T> const &);
		iterador(iterador const &);
		~iterador();

		T& dato();
		T const &dato() const;
		iterador &avanzar();
		iterador &retroceder();
		bool extremo() const;

		bool operator==(const iterador &) const;
		bool operator!=(const iterador &) const;
		iterador const &operator=(iterador const &);
	};

	typedef T t_dato;
	typedef nodo t_nodo;
	typedef iterador t_iter;

	lista();
	lista(const lista &);
	~lista();

	// Métodos públicos, específicos del TDA lista.
	//
	size_t tamano() const;
	bool contiene(const T &) const;
	bool vacia() const;
	void insertar(const T &);
	void insertar_antes(const T &, iterador const &);
	void insertar_despues(const T &, iterador const &);
	void borrar(const T &);
	lista const &operator=(lista const &);

	// Esta clase provee métodos para generar iteradores preposicionados
	// en los nodos distinguidos (i.e. inicial y final) de la secuencia.
	// Combinando esto con las operaciones de comparación provistas por
	// el TDA iterador, buscamos facilitar las expresiones de corte o
	// continuación de los ciclos de iteración. Por ejemplo,
	//
	// lista<int>::iterador it;
	// ...
	// for( it = L.ultimo(); !it.extremo(); it.retroceder()) {
	// 	// ...
	// }
	// 
	// También,
	//
	// lista<int>::iterador it;
	// lista<int>::iterador mitad;
	// ...
	// for(it = L.primero(); it != mitad; it.avanzar()) {
	// 	// ...
	// }
	//
	iterador primero() const;
	iterador ultimo() const;
	
};

template<typename T>
lista<T>::iterador::iterador() : actual_(0)
{
}

template<typename T>
lista<T>::iterador::iterador(nodo *actual) : actual_(actual)
{
}

template<typename T>
lista<T>::iterador::iterador(lista<T> const &l) : actual_(l.pri_)
{
}

template<typename T>
lista<T>::iterador::iterador(iterador const &it) : actual_(it.actual_)
{
}

template<typename T>
lista<T>::iterador::~iterador()
{
}

template<typename T>
T &lista<T>::iterador::dato()
{
	return actual_->dato_;
}

template<typename T>
T const &lista<T>::iterador::dato() const
{
	return actual_->dato_;
}

template<typename T>
typename lista<T>::iterador &lista<T>::iterador::avanzar()
{
	if (actual_)
		actual_ = actual_->sig_;
	return *this;
}

template<typename T>
typename lista<T>::iterador &lista<T>::iterador::retroceder()
{
	if (actual_)
		actual_ = actual_->ant_;
	return *this;
}

template<typename T>
bool lista<T>::iterador::extremo() const
{
	return actual_ == 0 ? true : false;
}

template<typename T>
bool lista<T>::iterador::operator==(const typename lista<T>::iterador &it2) const
{
	return actual_ == it2.actual_;
}

template<typename T>
bool lista<T>::iterador::operator!=(const typename lista<T>::iterador &it2) const
{
        return actual_ != it2.actual_;
}

template<typename T>
typename lista<T>::iterador const &lista<T>::iterador::operator=(iterador const &orig)
{
        if (this != &orig)
		actual_ = orig.actual_;
	return *this;
}

template<typename T>
lista<T>::nodo::nodo(const T &t) : sig_(0), ant_(0), dato_(t)
{
}

template<typename T>
lista<T>::nodo::~nodo()
{
}

template<typename T>
lista<T>::lista() : pri_(0), ult_(0), tam_(0)
{
}

template<typename T>
lista<T>::lista(const lista &orig) : pri_(0), ult_(0), tam_(orig.tam_)
{
	nodo *iter;
	nodo *ant;

	// Recorremos la secuencia original en sentido directo. En cada paso,
	// creamos un nodo, copiando el dato correspondiente, y lo enganchamos
	// al final de nuestra nueva lista.
	//
	for (iter = orig.pri_, ant = 0; iter != 0; iter = iter->sig_)
	{
		// Creamos un nodo, copiando el dato, y lo enganchamos en e
		// final de nuestra lista.
		//
		nodo *nuevo = new nodo(iter->dato_);
		nuevo->ant_ = ant;
		nuevo->sig_ = 0;

		// Si ésta no es la primera pasada, es decir, si no se trata
		// del primer nodo de la lista, ajustamos el enlace sig_ del
		// nodo anterior.
		//
		if (ant != 0)
			ant->sig_ = nuevo;

		// Además, tenemos que ajustar los punteros a los elementos
		// distinguidos de la secuencia, primero y último. En el caso
		// de pri_ (enlace al primer elemento), esto lo vamos a
		// hacer una única vez; para el caso de ult_, iremos tomando
		// registro del último nodo procesado, para ajustarlo antes
		// de retornar.
		//
		if (pri_ == 0)
			pri_ = nuevo;
		ant = nuevo;
	}
	
	// Ajustamos el puntero al último elemento de la copia.
	ult_ = ant;
}

template<typename T>
lista<T>::~lista()
{
	for (nodo *p = pri_; p; )
	{
		nodo *q = p->sig_;
		delete p;
		p = q;
	}
}

template<typename T>
size_t lista<T>::tamano() const
{
	return tam_;
}

template<typename T>
bool lista<T>::contiene(const T &elem) const
{
	nodo *iter;
        
	for (iter = pri_; iter != 0; iter = iter->sig_)
		if (elem == iter->dato_)
			return true;
	return false;
}

template<typename T>
bool lista<T>::vacia() const
{
	return pri_ ? false : true;
}

template<typename T>
void lista<T>::insertar(const T &t)
{
	nodo *p = new nodo(t);
	p->sig_ = pri_;
	p->ant_ = 0;

	if (pri_)
		pri_->ant_ = p;
	pri_ = p;
	if (!ult_)
		ult_ = p;

	tam_++;
}

template<typename T>
void lista<T>::insertar_despues(const T &t, iterador const &it)
{
	nodo *nuevo = new nodo(t);
	nodo *actual = it.actual_;

	if (actual == 0)
	{
		if (pri_ != 0)
			std::abort();
		pri_ = nuevo;
		ult_ = nuevo;
	}
	else
	{
		if (actual->sig_ != 0)
			actual->sig_->ant_ = nuevo;
		nuevo->sig_ = actual->sig_;
		nuevo->ant_ = actual;
		actual->sig_ = nuevo;
		if (ult_ == actual)
			ult_ = nuevo;
	}

	tam_++;
}

template<typename T>
void lista<T>::insertar_antes(const T &t, iterador const &it)
{
        nodo *nuevo = new nodo(t);
        nodo *actual = it.actual_;

        if (actual == 0)
        {
                if (pri_ != 0)
                        std::abort();
                pri_ = nuevo;
                ult_ = nuevo;
        }
        else
        {
                if (actual->ant_ != 0)
                        actual->ant_->sig_ = nuevo;
                nuevo->sig_ = actual;
                nuevo->ant_ = actual->ant_;
                actual->ant_ = nuevo;
                if (pri_ == actual)
                        pri_ = nuevo;
        }

	tam_++;
}

template<typename T>
void lista<T>::borrar(const T &t)
{
	nodo *iter, *sig=0;

	for (iter = pri_; iter != 0; iter = sig)
	{
		sig = iter->sig_;
		if (t == iter->dato_)
		{
			nodo *ant = iter->ant_;
			if (ant == 0)
				pri_ = sig;
			else
				ant->sig_ = sig;
			if (sig == 0)
				ult_ = ant;
			else
				sig->ant_ = ant;
			delete iter;

			tam_--;
		}
	}
}

template<typename T>
typename lista<T>::iterador lista<T>::ultimo() const
{
	return typename lista<T>::iterador(ult_);
}

template<typename T>
typename lista<T>::iterador lista<T>::primero() const
{
        return typename lista<T>::iterador(pri_);
}

template<typename T>
lista<T> const &lista<T>::operator=(lista const &orig)
{
	nodo *iter;
	nodo *sig;
	nodo *ant;

	if (this != &orig)
	{
		for (iter = pri_; iter != 0; )
		{
			sig = iter->sig_;
			delete iter;
			iter = sig;	
		}

		pri_ = 0;
		ult_ = 0;

		for (iter = orig.pri_, ant = 0; iter != 0; iter = iter->sig_)
		{
			nodo *nuevo = new nodo(iter->dato_);
			nuevo->ant_ = ant;
			nuevo->sig_ = 0;
			if (ant != 0)
				ant->sig_ = nuevo;
			if (pri_ == 0)
				pri_ = nuevo;
			ant = nuevo;
		}
		ult_ = ant;
		tam_ = orig.tam_;
	}

	return *this;
}


#endif
