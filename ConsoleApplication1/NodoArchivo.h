#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>;

using namespace std;
class NodoArchivo
{

private:
	
	NodoArchivo* siguiente;
	string nombre;
	string ruta;
	int id;
public:

	NodoArchivo(int _id, string _nombre, string _ruta, NodoArchivo* _siguiente) {
		nombre = _nombre;
		ruta = _ruta;
		siguiente = _siguiente;
		id = _id;
	}


	string getNombre() {
		return nombre;
	}

	string getRuta() {
		return ruta;
	}

	int getId() {
		return id;
	}

	

	NodoArchivo* getSiguiente() {
		return siguiente;
	}


	void setId(int _id) {
		id = _id;
	}

	void setNombre(string _nombre) {
		nombre = _nombre;
	}
	void setRuta(string _ruta) {
		ruta = _ruta;
	}
	void setSiguiente(NodoArchivo* _siguiente) {
		siguiente = _siguiente;
	}

};

