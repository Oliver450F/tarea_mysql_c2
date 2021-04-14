// mysql_c2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Cliente.h"


int main(){

	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	cout << " ingrese nit: ";
	getline(cin, nit);
	cout << " ingree nombres : ";
	getline(cin, nombres);
	cout << " ingree apellidos : ";
	getline(cin, apellidos);
	cout << " ingree direccion : ";
	getline(cin, direccion);
	cout << " ingree telefono : ";
	cin >> telefono;
	cin.ignore();
	cout << " ingree fecha nacimiento : ";
	cin >> fecha_nacimiento;
	

	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	c.crear();
	c.leer();
	c.modificar();
	c.eliminar();
	
	
	system("pause");

	return 0;
	}
