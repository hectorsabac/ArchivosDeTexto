#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
para escribir:

- verificar que esta abierto
- escribir por medio de: fileName << att << delim << att << delim... etc etc
NOTA: el delim usado conviene ser ' ' ya que usaremos fileName >> var en la lectura

para leer:
- verificar que esta abierto
- asignar variables en el orden que esta escrito el registro
- leer por medio de un while de forma: while (fileName >> var1 >> var2 >> var3... etc etc)
- dentro del while, imprimir las variables en el formato deseado

en el main:
- verificar que el archivo exite por medio de una instancia ofstream con el nombre del archivo y modo ios::app, cerrar inmediatamente
- en el caso de querer sumar registros, instanciar ofstream con el nombre del archivo en modo ios::app
- en caso de no querer sumar registros y borrar el archivo, no es necesario ios::app.
	NOTA: se puede usar ios::trunc, pero este esta seleccionado por default

	EJEMPLO:
		ofstream fileOut("archivo.txt") es lo mismo que decir ofstream fileOut("archivo.txt", ios::trunc)
- usar el metodo escribir objeto
- usar el metodo fileOut.clear() para limpiar el archivo de error flags y limpiar el eof();
- cerrar el archivo cuando se termina de sumar los registros deseados
- instanciar ifstream con el nombre del archivo para leerlo
- usar el metodo leer con el archivo
- cerrar el archivo con .close();
*/

class Persona {
	string nombre;
	int edad;
public:
	Persona(string nombre = "Default", int edad = 0) {
		this->nombre = nombre;
		this->edad = edad;
	}
	void escribir(ofstream& outFile) {
		if (!outFile) {
			cerr << "Error al abrir para escribir!";
			exit(EXIT_FAILURE);
		}
		outFile << nombre << ' ' << edad << endl;
	}
};

void leer(ifstream& inFile) {
	cout << "Nombre\t\tEdad\n-------------------\n";
	if (!inFile) {
		cerr << "Error al abrir para leer!";
		exit(EXIT_FAILURE);
	}
	string nombre;
	int edad;
	while (inFile >> nombre >> edad) {
		cout << nombre << "\t\t" << edad << endl;
	}
}

int main() {
	ofstream fileOut0("personas.txt", ios::app);
	fileOut0.close();
	ofstream fileOut("personas.txt", ios::app);
	Persona p1("Juana", 15), p2("Hector", 18);
	p1.escribir(fileOut); p2.escribir(fileOut);
	fileOut.clear();
	fileOut.close();
	ifstream fileIn("personas.txt");
	leer(fileIn);
	fileIn.close();
}