#pragma once
#include <mysql.h>
#include "Persona.h"
#include <iostream>
#include "conexionBD.h"
#include <string>
using namespace std;
class Cliente : Persona{
	// atributos
private: string nit;
	   // metodo constructor
public:
	Cliente() {
	}

	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel,fn) {
		nit = n;
	}
	// metodos de modificar datos
	// set ( modificar)

	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	// get(mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	
	
	void crear() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_concexion();
		if (cn.getconectar()) {
			string T = to_string(telefono);
			string insert = " insert into clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)values('" + nit + "',  '"+ nombres + "','" + apellidos + "', '" + direccion + "','" + T + "', '" + fecha_nacimiento + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreso Exitoso..." << endl;

			}
			else {

				cout << "xxxxx error de  ingreso xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();
		


	}
	void leer() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_concexion();

		if (cn.getconectar()) {
			
			string consulta = " select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "----------------------------Clientes------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}

			}
			else {

				cout << "xxxxx error de  consulta xxxx" << endl;
			}



		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();
	}
	void modificar() {

		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_concexion();
		if (cn.getconectar()) {
			cout << " ingrese cliente a modificar :";
			cin >> cliente;
			string T = to_string(telefono);
			string update = " UPDATE clientes   SET nit='" + nit + "', nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "', telefono='" + T + "', fecha_nacimiento= '" + fecha_nacimiento + "' WHERE cliente= '" + cliente + "'";
			const char* o = update.c_str();
			q_estado = mysql_query(cn.getconectar(), o);
			if (!q_estado) {
				cout << " modificacion Exitosa..." << endl;

			}
			else {

				cout << "xxxxx error de  modificacion xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();



	}
	void eliminar() {

		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_concexion();
		if (cn.getconectar()) {
			string cliente;
			string sel = " DELETE FROM clientes   WHERE cliente= '" + cliente + "'";
			const char* u = sel.c_str();
			q_estado = mysql_query(cn.getconectar(), u);
			if (!q_estado) {
				cout << " eliminacion exitosa ..." << endl;

			}
			else {

				cout << "xxxxx error al eliminar xxxx" << endl;
			}





		}
		else {

			cout << " xxxxx error en la concexion xxxxx";
		}

		cn.cerrar_conexion();



	}
	

};

