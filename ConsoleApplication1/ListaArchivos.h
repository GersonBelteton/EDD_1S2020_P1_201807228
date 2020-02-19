#pragma once
/////////////////////////////// Lista circular
#include "NodoArchivo.h";
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>;
class ListaArchivos
{

private:
	NodoArchivo* primero;
	NodoArchivo* ultimo;
	int size;
	int id;

public:
	ListaArchivos() {
		primero = NULL;
		ultimo = NULL;
		size = 0;
		id = 1;
	}


	bool isEmpty() {
		return primero == NULL;
	}

	int getSize() {
		return size;
	}

	void insertarUltimo(string nombre, string ruta) {
		NodoArchivo* nuevo = new NodoArchivo(id, nombre, ruta, NULL);

		if (isEmpty()) {
			primero = nuevo;
			ultimo = nuevo;
			ultimo->setSiguiente(primero);
			size++;
			id++;
		}
		else {
			ultimo->setSiguiente(nuevo);
			nuevo->setSiguiente(primero);
			ultimo = nuevo;
			size++;
			id++;
		}
	}


	NodoArchivo* buscar(int id) {

		NodoArchivo* aux = primero;
		do {
			if (aux->getId() == id) {
				break;
			}
			aux = aux->getSiguiente();
		} while (aux != primero);

		return aux;
	}

	NodoArchivo* getPrimero() {
		return primero;
	}
	void mostarLista() {
		NodoArchivo* aux = primero;
		do {

			cout << to_string(aux->getId()) <<"- "<< aux->getNombre() << "          " << aux->getRuta()<<endl;
			aux = aux->getSiguiente();

		} while (aux != primero);

	}


};

