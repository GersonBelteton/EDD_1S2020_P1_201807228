#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>






using namespace std;
template <class T> class Nodo
{

private:
	int posX;
	int posY;
	T dato;
	Nodo<T>* siguiente;
	Nodo<T>* anterior;
public:


	Nodo(T t, int _posX, int _posY, Nodo<T>* _sig) {
		dato = t;
		posX = _posX;
		posY = _posY;
		siguiente = _sig;
	}



	T getDato() {
		return dato;
	}

	int getPosX() {
		return posX;
	}

	int getPosY() {
		return posY;
	}

	Nodo<T>* getSiguiente() {
		return siguiente;
	}

	Nodo<T>* getAnterior() {
		return anterior;
	}


	void setAnterior(Nodo<T>* _ant) {
		anterior = _ant;
	}
	void setDato(T t) {
		dato = t;
	}

	void setPosX(int _posX) {
		posX = _posX;
	}

	void setPosY(int _posY) {
		posY = _posY;
	}

	void setSiguiente(Nodo<T>* _sig) {
		siguiente = _sig;
	}



};

