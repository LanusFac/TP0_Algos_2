// Funcion que lee los argumentos que se pasan por linea de comandos y devuelve
// por referencia el archivo del que se lee (iss), el archivo en el que se
// escribe (oss) y por referencia un flag que indica si se quiere DFT (1)
// o IDFT (-1).

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

#include "cmdline.h"

using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_method(string const &);

// Tabla de opciones de l�nea de comando. El formato de la tabla
// consta de un elemento por cada opci�n a definir. A su vez, en
// cada entrada de la tabla tendremos:
//
// o La primera columna indica si la opci�n lleva (1) o no (0) un
//   argumento adicional.
//
// o La segunda columna representa el nombre corto de la opci�n.
//
// o Similarmente, la tercera columna determina el nombre largo.
//
// o La cuarta columna contiene el valor por defecto a asignarle
//   a esta opci�n en caso que no est� expl�citamente presente
//   en la l�nea de comandos del programa. Si la opci�n no tiene
//   argumento (primera columna nula), todo esto no tiene efecto.
//
// o La quinta columna apunta al m�todo de parseo de la opci�n,
//   cuyo prototipo debe ser siempre void (*m)(string const &arg);
//
// o La �ltima columna sirve para especificar el comportamiento a
//   adoptar en el momento de procesar esta opci�n: cuando la
//   opci�n es obligatoria, deber� activarse OPT_MANDATORY. En este caso,
//   no hay casos obligatorios.
//
// Adem�s, la �ltima entrada de la tabla debe contener todos sus
// elementos nulos, para indicar el final de la misma.
//

/**************** Elementos globales ******************/
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "m", "method", "D", opt_method, OPT_DEFAULT},
	{0, },
};

static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)
static int metodo;


/*****************************************************/

static void opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void opt_output(string const &arg)
{
	// Si el nombre del archivo es "-", usaremos la salida
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);		// EXIT: Terminaci�n del programa en su totalidad
	}
}

static void opt_method(string const &arg) {
    // Si el metodo es D, se introduce 1 indicando DFT. De lo contrario,
    // -1 indicando IDFT.
    if (arg == "D" || arg == "dft" || arg == "DFT") //no se reconocen otras posibilidades
        metodo = 1;
    else if (arg == "idft" || arg == "IDFT")
        metodo = -1;
    else {
        cerr << "cannot recognize "
		     << arg
		     << "."
		     << endl;
		exit(1);
    }

}

int leer_cmdline (int argc, char * argv[], istream **file_in, ostream **file_out){
    cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente.
	cmdl.parse(argc, argv); // llama a opt_...
    (*file_in) = iss;
    (*file_out) = oss;
    return metodo;

}
