// test1.cc - test de unidad para la clase complejo.
// 
// Este programa lee una secuencia de comandos por std::cin. Cada
// comando es procesado y su respuesta enviada por std::cout cuando
// sea conventiente.
//
// Los comandos están pensados para manipular instancias de la clase
// complejo, usando las operaciones estándard del tipo. La lista de
// comandos válidos, es:
//
// o +, suma de complejos;
//
// o -, resta de complejos;
//
// o *, producto;
//
// o /, cociente;
//
// o P, cambio de precisión;
//
// Se permiten comentarios: aquellas lineas que comiencen con el
// caracter ``#'' son copieadas sin alteraciones en la salita, pero
// se ignora completamente su contenido.
//
// Leandro Santi, $Date: 2011/09/09 11:02:19 $

#include <complejo.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
	complejo x;
	complejo y;
	char ch;
	int p;

	while (cin >> ch) {
		int skip = 0;

		switch (ch) {
		case '+':
			if (!(cin >> x)) {
				cout << "error: en el primer argumento.\n";
				skip = 1;
				break;
			}
			if (!(cin >> y)) {
				cout << "error: en el segundo argumento.\n";
				skip = 1;
				break;
			}

			cout << x
			     << " + "
			     << y
			     << " = "
			     << x + y 
			     << ".\n";
			break;
		case '-':
			if (!(cin >> x)) {
				cout << "error leyendo el primer argumento.\n";
				cout << "error: en el primer argumento.\n";
				skip = 1;
				break;
			}
			if (!(cin >> y)) {
				cout << "error: en el segundo argumento.\n";
				skip = 1;
				break;
			}

			cout << x
			     << " - "
			     << y
			     << " = "
			     << x - y 
			     << ".\n";
			break;
		case '*':
			if (!(cin >> x)) {
				cout << "error: en el primer argumento.\n";
				skip = 1;
				break;
			}
			if (!(cin >> y)) {
				cout << "error: en el segundo argumento.\n";
				skip = 1;
				break;
			}

			cout << x
			     << " * "
			     << y
			     << " = "
			     << x * y 
			     << ".\n";
			break;
		case '/':
			if (!(cin >> x)) {
				cout << "error: en el primer argumento.\n";
				skip = 1;
				break;
			}
			if (!(cin >> y)) {
				cout << "error: en el segundo argumento.\n";
				skip = 1;
				break;
			}

			cout << x
			     << " / "
			     << y
			     << " = "
			     << x / y 
			     << ".\n";
			break;
		case 'P':
			if (!(cin >> p)) {
				cout << "error: en el argumento.\n";
				skip = 1;
				break;
			}
			cout << "cout << setprecision(" 
			     << p 
			     << ");"
			     << "\n";
			cout << setprecision(p);
			break;
		case '#':
			cout << '#';
			while (cin.get(ch)) {
				cout << ch;
				if (ch == '\n')
					break;
			}
			break;
		default:
			cout << "fatal: comando invalido.\n";
			std::exit(1);
		}

		if (skip) {
			cin.clear();
			while (cin.get(ch) && ch != '\n')
				;
		}
	}
}
