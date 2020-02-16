#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <WinUser.h>
#include "Nodo.h";
#include "ListaCaracteres.h";
#include <vector>


using namespace std;

void menu();
void prueba();
void imprimir(string);
void crearArchivo();
void encabezadoCrearArchivo();
int main() {

		system("color 1f");
		ListaCaracteres l;
		//l.buscarRemplazar("Hola Mundo");
		menu();


	system("pause");
	return 0;
}
void gotoxy(short x, short y) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}

int WhereX()
{
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	return sbi.dwCursorPosition.X;
}

int WhereY()
{
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	return sbi.dwCursorPosition.Y;
}
void imprimir(string cadena, ListaCaracteres lc) {
	system("cls");
	encabezadoCrearArchivo();
	//string a = "hola";
	//cout << cadena;
	lc.mostrarLista();
}
void menu() {
	int var = 0;

	do {
		cout << "Elige una opcion" << endl << endl;
		cout << "1. Crear Archivo" << endl;
		cout << "2. Abrir Archivo" << endl;
		cout << "3. Archivos Recientes" << endl;
		cout << "4. Salir" << endl;
		cin >> var;
		system("cls");
	} while (var != 1 && var != 2 && var != 3 && var != 4);


	switch (var) {
	case 1:

		crearArchivo();
		break;
	case 2:
		prueba();
		break;
	case 3:

		break;
	case 4:

		break;
	}



}

void prueba() {
	int a;
	system("cls");
	cout << "digite un numero"<<endl;
	
	a = _getch();
	cout <<a<<"---"<< WhereX()<<WhereY();
	

}
void encabezadoCrearArchivo() {

	cout << "Crear Archivo" << endl << endl;
	cout << "Buscar y remplazar (ctrl+w) "<< endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	
}
void crearArchivo() {
	ListaCaracteres lc;
	string var="";
	char caracter=' ';
	int ascii=0;
	bool flechas = false;
	string cadena="", anterior="";

	encabezadoCrearArchivo();


	while (caracter != '/') {

		caracter = _getch();
		ascii = caracter;
		cadena = cadena + caracter;

		
		
		//https://elrincondelc.com/foros/viewtopic.php?t=3047
		//cout << ascii;
		if (ascii == 8) {
			//cout << "borrar";
	
			if (!lc.isEmpty()) {
				if (WhereY() > lc.getLastPositionY()) {
				//	cadena.erase(cadena.length() - 2);
					lc.eliminarUltimo();
					imprimir(cadena, lc);
				}
				else if (WhereY() == lc.getLastPositionY()) {
					if (WhereX() >= lc.getLastPositionX()) {
						cadena.erase(cadena.length() - 2);
						lc.eliminarUltimo();
						imprimir(cadena, lc);
					}
					else {
						int x = WhereX();
						int y = WhereY();
						lc.eliminarEnMedio(x, y);
						imprimir(cadena, lc);
						gotoxy(x-1, y);
					}
				}
				else {
					int x = WhereX();
					int y = WhereY();
					lc.eliminarEnMedio(x, y);
					imprimir(cadena, lc);
					gotoxy(x - 1, y);
				}

				
			}
			
			//cout << cadena;
			
		}
		else if (ascii == 13) {
			if (lc.isEmpty()) {
				lc.insertarFinal('\n', WhereX(), WhereY());
				cadena = cadena + "\n";
				imprimir(cadena, lc);
			}
			else {
				if (WhereY() > lc.getLastPositionY()) {
					gotoxy( 0, lc.getLastPositionY()+1);
					lc.insertarFinal('\n', WhereX(), WhereY());
					imprimir(cadena, lc);
				}
				else if (WhereY() == lc.getLastPositionY()) {
					if (WhereX() >= lc.getLastPositionX()) {
						gotoxy( 0, lc.getLastPositionY()+1);
						lc.insertarFinal('\n', WhereX(), WhereY());
						imprimir(cadena, lc);
					}
					else {
						//cout << " x menor y igual";
						int x = WhereX();
						int y = WhereY();
						lc.insertarEnMedio('\n', WhereX(), WhereY());
						imprimir(cadena, lc);
						gotoxy(0, y+1);
					}
				}
				else {
					//cout << " y menor";
					int x = WhereX();
					int y = WhereY();
					lc.insertarEnMedio('\n', WhereX(), WhereY());
					imprimir(cadena, lc);
					gotoxy(0, y + 1);
				}
			}
			
			//cout << endl
			//cout << "enter";
		}
		else if (ascii == -32) {
			flechas = true;
		}
		else if (ascii == 80 && flechas) {
			
				//flecha abajo
				//cout << "abajo";
				gotoxy(WhereX(), WhereY() + 1);
				flechas = false;
	
		}
		else if (ascii == 72 && flechas) {

			//flecha arriba
			//cout << "arriba";
			gotoxy(WhereX(), WhereY() - 1);
			flechas = false;

		}
		else if (ascii == 77 && flechas) {

			//flecha derecha
			//cout << "derecha";
			gotoxy(WhereX()+1, WhereY());
			flechas = false;

		}
		else if (ascii == 75 && flechas) {

			//flecha izquierda
			//cout << "izquierda";
			gotoxy(WhereX()-1, WhereY());
			flechas = false;

		}
		else if (ascii == 23) {
			cout << endl << endl << "Buscar y remplazar: ";
			ListaCaracteres busc;
			ListaCaracteres remp =  ListaCaracteres();
	

			char caracter = ' ';
			int ascii = 0;
		
			bool salir = false;
			bool opcion = true;
			while (salir == false) {
				caracter = _getch();
				ascii = caracter;
				cout << caracter;
				if (caracter == ';') {
					opcion = false;
				}
				
				else if (ascii == 13) {
					salir = true;
					//cout << "enter";
				}
				else {
					if (opcion) {
						busc.insertarFinal(caracter, 0, 0);
					}
					else {
						remp.insertarFinal(caracter, 0, 0);
					}
					
				}
		
			}

			
		
			//for (int i = 0; i < 2; i++) {
		/*	system("cls");
			ListaCaracteres l= remp.clonarLista();
			
				remp.eliminarUltimo();

				l.mostrarLista();
				cout << endl;
				remp.mostrarLista();
				_getch();*/
				int contPalabras = lc.buscarRemplazar(busc, remp);

		
			//}


		
			imprimir(" ", lc);
			
			cout <<endl<< "Se cambiaron " << contPalabras << " palabras";


		}
		else {

			if (lc.isEmpty()) {
				lc.insertarFinal(caracter, WhereX(), WhereY());
				imprimir(cadena, lc);
			}
			else {
				if (WhereY() > lc.getLastPositionY()) {
					gotoxy(lc.getLastPositionX()+1, lc.getLastPositionY());
					lc.insertarFinal(caracter, WhereX(), WhereY());
					imprimir(cadena, lc);
				}
				else if (WhereY() == lc.getLastPositionY()) {
					if (WhereX() >= lc.getLastPositionX()) {
						gotoxy(lc.getLastPositionX()+1, lc.getLastPositionY());
						lc.insertarFinal(caracter, WhereX(), WhereY());
						imprimir(cadena, lc);
					}
					else {
						//cout << " x menor y igual";
						//gotoxy(lc.getLastPositionX() + 1, lc.getLastPositionY());
						int x = WhereX();
						int y = WhereY();
						lc.insertarEnMedio(caracter, x, y);
						imprimir(cadena, lc);				
						gotoxy(x+1, y);
						

					}
				}
				else {
					//cout << " y menor";
					int x = WhereX();
					int y = WhereY();
					lc.insertarEnMedio(caracter, x, y);
					imprimir(cadena, lc);
					gotoxy(x+1, y);
				}
			}

		
		}
		//cout << ascii;
		if (caracter == '*') {
			system("cls");
			lc.mostrarLista();
			cout << lc.primerCaracter()<<lc.ultimoCaracter();
		}
		if (caracter == '+') {
			lc.imprimirListaPos();
		}
		//system("cls");
		//lc.mostrarLista();

	}
}

