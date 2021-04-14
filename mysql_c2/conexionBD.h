#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class conexionBD{
private: MYSQL* conectar;
public:
	void abrir_concexion() {

		conectar = mysql_init(0);

		conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "empresa1234%", "db_empresa", 3306, NULL, 0);


	}
	void cerrar_conexion() {
		mysql_close(conectar);
	}
	MYSQL * getconectar() {

		return conectar;
	}
};

