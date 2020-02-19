#pragma once
#include "NodoLog.h";
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h> 
class PilaLog
{

private:
	NodoLog* primero;
	int size;

public:

	PilaLog() {
		primero = NULL;
		size = 0;
	}

	bool isEmpty() {
		return primero == NULL;
	}

	int getSize() {
		return size;
	}


	void push(string buscada, string remplazada, string palabra, string accion, bool estado, int posX, int posY, NodoLog* siguiente) {

		NodoLog* nuevo = new NodoLog(buscada, remplazada, palabra, accion, estado, posX, posY, siguiente);
		if (isEmpty()) {
			primero = nuevo;
			size++;
		}
		else {
			nuevo->setSiguiente(primero);
			primero = nuevo;
			size++;
		}

	}

	void push(NodoLog* nodo) {
		NodoLog* nuevo = nodo;
		if (isEmpty()) {
			primero = nuevo;
			size++;
		}
		else {
			nuevo->setSiguiente(primero);
			primero = nuevo;
			size++;
		}
	}

	NodoLog* pop() {
		if (isEmpty()) {
			cout << "pila vacia";
			return NULL;
		}
		else {
			NodoLog* aux = primero;
			primero = primero->getSiguiente();
			aux->setSiguiente(NULL);
			size--;
			return aux;
		}
	}

	NodoLog* top() {
		return primero;
	}
	
	void mostrarPila() {
		NodoLog* aux = primero;
		if (!isEmpty()) {
		//	cout << "no vacia";
			while (aux != NULL) {
				cout << aux->getPalabra()<< aux->getAccion()<<aux->getBuscada() <<endl;
				aux = aux->getSiguiente();
			}
		}
		else {
			cout << "la pila está vacia";
		}

	}



};

