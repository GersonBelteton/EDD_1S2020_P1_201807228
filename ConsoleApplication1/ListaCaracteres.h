#pragma once
#include "Nodo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h> 

using namespace std;
class ListaCaracteres
{
private: 
	Nodo<char>* primero;
	Nodo<char>* ultimo;
	int size;

public:
	ListaCaracteres() {
		primero = NULL;
		ultimo = NULL;
		size = 0;
	}

	bool isEmpty() {
		if (primero == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void insertar(char caracter, int x, int y) {
		
		if (isEmpty()) {
			primero = new Nodo<char>(caracter,x,y, NULL);
			ultimo = primero;
			size++;
		}
		else {
			Nodo<char>* nuevo;
			nuevo = new Nodo<char>(caracter,x,y, NULL);
			nuevo->setSiguiente(primero);
			primero->setAnterior(nuevo);
			primero = nuevo;
			size++;
		}
	}
	void eliminarPrimero() {
		if (!isEmpty()) {
		/*	Nodo<char>* aux;

			aux = primero->getSiguiente();
			primero->getSiguiente()->setAnterior(aux);
			primero = aux;
			
			*/
			if (size == 1) {
				primero = NULL;
				ultimo = NULL;
				size--;
			}
			else {
				primero = primero->getSiguiente();
				primero->setAnterior(NULL);
				size--;
			}
		
		}
	}

	void eliminarEnMedio(int x, int y) {

		Nodo<char>* aux = primero;
		if (x >= getLastPositionX() && y >= getLastPositionY()) {
			eliminarUltimo();
		}
		else {
			while (aux->getPosX() != x || aux->getPosY() != y) {

				aux = aux->getSiguiente();
			}

			aux->getAnterior()->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(aux->getAnterior());
			actualizarPosicion();

			size--;
		}

	}

	int getSize() {
		return size;
	}

	char getPenUltimoCaracter() {
		return ultimo->getAnterior()->getDato();
	}
	void eliminarUltimo() {
		if (!isEmpty()) {
			
			if (size == 1) {
				primero = NULL;
				ultimo = NULL;
				size--;
			}
			else {
				ultimo = ultimo->getAnterior();
				ultimo->setSiguiente(NULL);
				size--;
				actualizarPosicion();
			}
			
		}
	}

	char primerCaracter() {
		return primero->getDato();
	}
	char ultimoCaracter() {
		return ultimo->getDato();
	}

	void insertarEnMedio(char caracter, int x, int y) {
		if (isEmpty()) {
			primero = new Nodo<char>(caracter, x, y, NULL);
			ultimo = primero;
			size++;
		}
		else {
			Nodo<char>* nuevo = new Nodo<char>(caracter, x, y, NULL);
			Nodo<char>* aux2;
			Nodo<char>* aux = primero;
	

			while (aux->getPosX() != x || aux->getPosY() != y) {
				//aux->setPosX(aux->getPosX() + 1);
				aux = aux->getSiguiente();
			}
			aux2 = aux->getSiguiente();
			aux->setSiguiente(nuevo);
			nuevo->setAnterior(aux);
			nuevo->setSiguiente(aux2);
			aux2->setAnterior(nuevo);

			actualizarPosicion();
		/*	if (nuevo->getDato() != '\n') {
				nuevo->setPosX(aux->getPosX() + 1);
				aux2->setPosX(nuevo->getPosX() + 1);
				do {
					aux2 = aux2->getSiguiente();
					aux2->setPosX(aux2->getPosX() + 1);

				} while (aux2->getSiguiente() != NULL);
			}
			else {

				aux2->setPosY(nuevo->getPosY() + 1);
				aux2->setPosX(0);
				do {
					aux2 = aux2->getSiguiente();
					aux2->setPosY(aux2->getAnterior()->getPosY());
					aux2->setPosX(aux2->getAnterior()->getPosX() + 1);
				} while (aux2->getSiguiente() != NULL);
			}
			*/
			
			//system("cls");
		//	correrPosiciones(x, y);
		}
	}

	void imprimirListaPos() {

		Nodo<char>* aux2 = primero;
		while (aux2 != NULL) {

			cout << endl << aux2->getDato() << aux2->getPosX() << aux2->getPosY();
			aux2 = aux2->getSiguiente();
		}
	}
	
	void correrPosiciones(int x, int y) {
		Nodo<char>* aux = primero;
		while (aux->getPosX() != x || aux->getPosY() != y) {
			aux->setPosX(aux->getPosX() + 1);
			aux = aux->getSiguiente();
		}
	}
	void insertarFinal(char caracter, int x, int y) {

		if (isEmpty()) {
			primero = new Nodo<char>(caracter,x,y, NULL);
			ultimo = primero;
			size++;
		}
		else {
			/*Nodo<char>* aux;
			Nodo<char>* nuevo;
			nuevo = new Nodo<char>(caracter, NULL);
		    
			aux = primero;
		
			while (aux->getSiguiente() != NULL) {
				aux = aux->getSiguiente();
			}
			aux->setSiguiente(nuevo);
			nuevo->setAnterior(aux);
			*/
			Nodo<char>* nuevo = new Nodo<char>(caracter,x,y, NULL);
			ultimo->setSiguiente(nuevo);
			nuevo->setAnterior(ultimo);
			ultimo = nuevo;
			size++;
			actualizarPosicion();

		}
	}



	string toString() {
		string cadena = "";
		Nodo<char>* aux = primero;

		while (aux != NULL) {
			cadena = cadena + aux->getDato();
			aux = aux->getSiguiente();
		}


		return cadena;

	}

	void insertarFinalNodo(Nodo<char>* nuevo) {

		if (isEmpty()) {
			primero = nuevo;
			ultimo = primero;
			size++;
		}
		else {
			/*Nodo<char>* aux;
			Nodo<char>* nuevo;
			nuevo = new Nodo<char>(caracter, NULL);

			aux = primero;

			while (aux->getSiguiente() != NULL) {
				aux = aux->getSiguiente();
			}
			aux->setSiguiente(nuevo);
			nuevo->setAnterior(aux);
			*/
			
			ultimo->setSiguiente(nuevo);
			nuevo->setAnterior(ultimo);
			ultimo = nuevo;
			size++;
			actualizarPosicion();

		}
	}

	int getLastPositionX() {
		return ultimo->getPosX();
	}
	int getLastPositionY() {
		return ultimo->getPosY();
	}

	Nodo<char>* getPrimero() {
		return primero;
	}

	Nodo<char>* getUltimo() {
		return ultimo;
	}

	void actualizarPosicion() {
		Nodo<char>* aux = primero;
		int x = 0;
		int y = 4;
		while (aux != NULL) {

		
			if (aux->getDato() == '\n') {
				y++;
				x = 0;
				aux->setPosX(x);
				aux->setPosY(y);
			}
			else {
				aux->setPosX(x);
				aux->setPosY(y);
				x++;
			}
			aux = aux->getSiguiente();
		}
	}

	int buscarRemplazar(ListaCaracteres busc, ListaCaracteres remp) {
		
		insertarFinal(' ', 0, 0);
		insertar(' ', 0, 0);

		Nodo<char>* auxBusc = busc.ultimo;
		Nodo<char>* auxLista = primero;
		
		int contador = 0;
		int contIgual = 0;
		int contPalabras = 0;
		while (auxLista != NULL) {

			if (auxLista->getDato() == ' '|| auxLista->getDato() == '\n') {

			/*	cout << "holaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
				cout << busc.getSize()<<endl;
				cout << contador<<endl;*/
				if (contador == busc.getSize()) {
					
					while (auxBusc != NULL) {
						if (auxBusc->getDato() == auxLista->getAnterior()->getDato()) {
							contIgual++;
						}
					
						auxLista = auxLista->getAnterior();
						auxBusc = auxBusc->getAnterior();
					}

					if (contIgual == contador) {
						auxBusc = busc.ultimo;
						ListaCaracteres l = remp.clonarLista();

						auxLista->getAnterior()->setSiguiente(l.primero);
						l.primero->setAnterior(auxLista->getAnterior());
						
						for (int i = 0; i < contador; i++) {
							auxLista = auxLista->getSiguiente();
						}
				
						auxLista->setAnterior(l.ultimo);
						l.ultimo->setSiguiente(auxLista);
						contPalabras++;
					
						//break;
					}
				}
				auxBusc = busc.ultimo;
				contador = -1;
				contIgual = 0;
			}
			auxLista = auxLista->getSiguiente();
			contador++;
		}
		
		eliminarPrimero();
		eliminarUltimo();
		actualizarPosicion();

		return contPalabras;
	}

	ListaCaracteres clonarLista() {

		ListaCaracteres nueva = ListaCaracteres();
		Nodo<char>* aux = primero;

		while (aux != NULL) {
			//cout << aux->getDato();
			char p;
			p = aux->getDato();
			nueva.insertarFinal(p, 0,0);
			aux = aux->getSiguiente();
		}


		return nueva;
	}

	void mostrarLista() {
		string cadena="";
		Nodo<char>* actual;
		actual = primero;

		int x = 0;
		int y = 0;
		if (!isEmpty()) {
			while (actual != NULL) {
				x =  actual->getPosX();
				y = actual->getPosY();
				//cadena = cadena + actual->getDato();
				cout << actual->getDato();
					//cout<<"("<<x<<","<<y<<")";
				actual = actual->getSiguiente();
			}
		}
	}


};

