#pragma once

#include "ListaCaracteres.h";
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

class NodoLog
{

private:
	string buscada;
	string remplazada;
	string palabra;
	string accion;
	bool estado;
	int posX;
	int posY;
	NodoLog* siguiente;

public:

	 NodoLog(string _buscada, string _remplazada, string _palabra, string _accion, bool _estado, int _posX, int _posY, NodoLog* _siguiente) {
		 buscada = _buscada;
		 remplazada = _remplazada;
		 palabra = _palabra;
		 accion = _accion;
		 estado = _estado;
		 posX = _posX;
		 posY = _posY;
	}
	 string getAccion() {
		 return accion;
	 }
	 string getBuscada() {
		 return buscada;
	}

	 string getRemplazada() {
		 return remplazada;
	 }

	 string getPalabra() {
		 return palabra;
	 }
	 bool getEstado() {
		 return estado;
	 }
	 int getPosX() {
		 return posX;
	 }
	 int getPosY() {
		 return posY;
	 }
	 NodoLog* getSiguiente() {
		 return siguiente;
	 }

	 void setAccion(string _accion) {
		 accion = _accion;
	 }

	 void setBuscada(string _buscada) {
		 buscada = _buscada;
	 }
	 void setRemplazada(string _remplazada) {
		 remplazada = _remplazada;
	 }
	 void setPalabra(string _palabra) {
		 palabra = _palabra;
	 }
	 void setEstado(bool _estado) {
		 estado = _estado;
	 }
	 void setPosX(int _posX) {
		 posX = _posX;
	 }
	 void setPosY(int _posY) {
		 posY = _posY;
	 }
	 void setSiguiente(NodoLog* _siguiente) {
		 siguiente = _siguiente;
	 }







	
};

