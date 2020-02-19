#include <iostream>;
#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <windows.h>;
#include <WinUser.h>;
#include "Nodo.h";
#include "NodoLog.h";
#include "ListaCaracteres.h";
#include "PilaLog.h";
#include <vector>;
#include <fstream>;
#include <string>;


using namespace std;

void menu();
void abrirArchivo();
void prueba();
void imprimir(string);
void crearArchivo(ListaCaracteres);
void encabezadoCrearArchivo();
ListaCaracteres toList(string);
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
	ListaCaracteres lc;
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

		crearArchivo(lc);
		break;
	case 2:
		abrirArchivo();
		break;
	case 3:
		prueba();
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
	cout << "Buscar y remplazar (ctrl+w)           Generar Reporte(ctrl+c)           Guardar(ctrl+s)"<< endl;             
	cout << "------------------------------------------------------------------------------------------------------------" << endl;

	
}

void abrirArchivo(){
	ifstream archivo;
	string texto;
	string linea;
	string ruta;

	cout <<endl << "Escribe la ruta del Archivo: ";
	cin >> ruta;

	archivo.open(ruta,ios::in);
	if (archivo.fail()) {
		cout << "Archivo no encontrado";
		exit(1);
	}
	texto = "";
	linea = "";
	while (!archivo.eof()) {
		getline(archivo, linea);
		texto = texto + linea + "\n";
	
	}
//	cout << texto << endl;
	

	archivo.close();
	ListaCaracteres l = toList(texto);
	//imprimir("", l);
	crearArchivo(l);


}
void crearArchivo(ListaCaracteres lc) {
	//ListaCaracteres lc;

	PilaLog rev, nrev;
	string var = "";
	char caracter = ' ';
	int ascii = 0;
	bool flechas = false, quitarEsp = false;
	string cadena = "", anterior = "";

	encabezadoCrearArchivo();


	while (ascii != 24) {

		caracter = _getch();
		ascii = caracter;



		



		//https://elrincondelc.com/foros/viewtopic.php?t=3047
		//cout << ascii;
		if (ascii == 8) {
			//cout << "borrar";

			if (!lc.isEmpty()) {
				if (WhereY() > lc.getLastPositionY()) {
					if (cadena != "") { cadena.erase(cadena.length() - 1); }
					nrev.push("", "", cadena, "borrar", false, WhereX(), WhereY(), NULL);

					lc.eliminarUltimo();
					imprimir(cadena, lc);
				}
				else if (WhereY() == lc.getLastPositionY()) {
					if (WhereX() >= lc.getLastPositionX()) {
						if (cadena != "") {cadena.erase(cadena.length() - 1); }
						nrev.push("", "", cadena, "borrar", false, WhereX(), WhereY(), NULL);
						lc.eliminarUltimo();
						imprimir(cadena, lc);
					}
					else {
						int x = WhereX();
						int y = WhereY();
						if (cadena != "") { cadena.erase(cadena.length() - 1); }
						nrev.push("", "", cadena, "borrar", false, WhereX(), WhereY(), NULL);
						lc.eliminarEnMedio(x, y);
						imprimir(cadena, lc);
						gotoxy(x - 1, y);
					}
				}
				else {
					int x = WhereX();
					int y = WhereY();
					if (cadena != "") { cadena.erase(cadena.length() - 1); }
					nrev.push("", "", cadena, "borrar", false, WhereX(), WhereY(), NULL);
					lc.eliminarEnMedio(x, y);
					imprimir(cadena, lc);
					gotoxy(x - 1, y);
				}


			}

			//cout << cadena;

		}
		else if (ascii == 19) {
			//ctrl+s guardar archivo
			ofstream archivo;
			string texto;
			string nombre;
			cout << endl << "Escribe el nombre del archivo: ";
			cin >> nombre;
			texto = "";

			archivo.open(nombre, ios::out);
			if (archivo.fail()) {
				cout << "no se pudo abrir";
				exit(1);
			}
			texto = lc.toString();
			archivo << texto;
			archivo.close();

		}
		else if (ascii == 13) {
			if (lc.isEmpty()) {
				nrev.push("", "", "\n", "agregar", false, WhereX(), WhereY(), NULL);
				cadena = "";
				lc.insertarFinal('\n', WhereX(), WhereY());

				imprimir(cadena, lc);
			}
			else {
				if (WhereY() > lc.getLastPositionY()) {
					gotoxy(0, lc.getLastPositionY() + 1);
					nrev.push("", "", "\n", "agregar", false, WhereX(), WhereY(), NULL);
					cadena = "";
					lc.insertarFinal('\n', WhereX(), WhereY());
					imprimir(cadena, lc);
				}
				else if (WhereY() == lc.getLastPositionY()) {
					if (WhereX() >= lc.getLastPositionX()) {
						gotoxy(0, lc.getLastPositionY() + 1);
						nrev.push("", "", "\n", "agregar", false, WhereX(), WhereY(), NULL);
						cadena = "";
						lc.insertarFinal('\n', WhereX(), WhereY());
						imprimir(cadena, lc);
					}
					else {
						//cout << " x menor y igual";
						int x = WhereX();
						int y = WhereY();
						nrev.push("", "", "\n", "agregar", false, WhereX(), WhereY(), NULL);
						cadena = "";
						lc.insertarEnMedio('\n', WhereX(), WhereY());
						imprimir(cadena, lc);
						gotoxy(0, y + 1);
					}
				}
				else {
					//cout << " y menor";
					int x = WhereX();
					int y = WhereY();
					nrev.push("", "", "\n", "agregar", false, WhereX(), WhereY(), NULL);
					cadena = "";
					lc.insertarEnMedio('\n', WhereX(), WhereY());
					imprimir(cadena, lc);
					gotoxy(0, y + 1);
				}
			}

			//cout << endl
			//cout << "enter";
		}
		else if (ascii == 26) {
			// ctrl+z
			rev.push(nrev.pop());

			if (rev.top()->getAccion() == "BR") {
				ListaCaracteres l1 = toList(rev.top()->getRemplazada());
				ListaCaracteres l2 = toList(rev.top()->getBuscada());

			/*	l1.mostrarLista();
				cout << endl << endl;
				l2.mostrarLista();*/
					lc.buscarRemplazar(l1,l2);
					imprimir(cadena, lc);
			
			}
			else if (rev.top()->getAccion() == "agregar") {
				gotoxy(rev.top()->getPosX(), rev.top()->getPosY());



				int contador = rev.top()->getPalabra().length() - 1;
				for (int i = 0; i < rev.top()->getPalabra().length(); i++) {
					lc.eliminarEnMedio(WhereX(), WhereY());
					//lc.eliminarUltimo();
				//	nrev.pop();
					
				}
		
			

				for (int i = 0; i < contador; i++) {
					nrev.pop();
				}
				imprimir(cadena, lc);
			}
			else if (rev.top()->getAccion() == "borrar") {
				
				string palabra = nrev.top()->getPalabra();
				//cout << palabra;
				lc.insertarFinal(palabra[palabra.length() - 1], 0,0);

				imprimir(cadena, lc);
			}

		}
			else if (ascii == 25) {
				//ctrl+y
				nrev.push(rev.pop());

				if (nrev.top()->getAccion() == "BR") {
					ListaCaracteres l1 = toList(nrev.top()->getRemplazada());
					ListaCaracteres l2 = toList(nrev.top()->getBuscada());

					/*	l1.mostrarLista();
						cout << endl << endl;
						l2.mostrarLista();*/
					lc.buscarRemplazar(l2, l1);
					imprimir(cadena, lc);
				}
				else if (nrev.top()->getAccion() == "agregar") {
					ListaCaracteres l1 = toList(nrev.top()->getPalabra());
					Nodo<char>* nodo = l1.getPrimero();
					while (nodo != NULL) {
						lc.insertarFinal(nodo->getDato(), 0, 0);
						nodo = nodo->getSiguiente();
					}
					
					
					imprimir(cadena, lc);
				}
				else if (nrev.top()->getAccion() == "borrar") {

				
					lc.eliminarUltimo();
					imprimir(cadena, lc);
				}
				                     


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
				gotoxy(WhereX() + 1, WhereY());
				flechas = false;

			}
			else if (ascii == 75 && flechas) {

				//flecha izquierda
				//cout << "izquierda";
				gotoxy(WhereX() - 1, WhereY());
				flechas = false;

			}
			else if (ascii == 23) {
				cout << endl << endl << "Buscar y remplazar: ";
				ListaCaracteres busc;
				ListaCaracteres remp = ListaCaracteres();


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
				nrev.push(busc.toString(), remp.toString(), "", "BR", false, 0, 0, NULL);
				int contPalabras = lc.buscarRemplazar(busc, remp);


				//}



				imprimir(" ", lc);

				cout << endl << "Se cambiaron " << contPalabras << " palabras";


			}
			else if (ascii == 3) {
				//Generar reportes
				int opcion = 0;
				cout << endl << "reportes: 1) lista        2) Palabras Buscadas         3) Palabras ordenadas";
				cin >> opcion;

				if (opcion == 1) {
					ofstream archivo;
					Nodo<char>* nodo = lc.getPrimero();
					//cout << nodo->getDato();
					//cout << nodo->getSiguiente()->getDato();
					string a;

					a = "";

					archivo.open("grafoLista.txt", ios::out);
					if (archivo.fail()) {
						cout << "no se pudo abrir";
						exit(1);
					}



					a = a + "digraph G {";
					for (int i = 0; i < lc.getSize(); i++) {
						a = a + "nodo" + to_string(i) + "[label = \" " + nodo->getDato() + "\"];\n";
						nodo = nodo->getSiguiente();
					}

					for (int i = 0; i < lc.getSize() - 1; i++) {
						a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";
						a = a + "nodo" + to_string(i + 1) + "->nodo" + to_string(i) + ";\n";
					}

					a = a + "}";
					cout << a;
					archivo << a;

					archivo.close();
					system("dot.exe -Tjpg grafoLista.txt -o grafoLista.jpg");
					system("grafoLIsta.jpg");
				}
				else if (opcion == 2) {
					ofstream archivo;
					NodoLog* auxnrev = nrev.top();
					NodoLog* auxrev = rev.top();
					string a;

					a = "";

					archivo.open("grafoPila.txt", ios::out);
					if (archivo.fail()) {
						cout << "no se pudo abrir";
						exit(1);
					}


					a = a + "digraph G {\n node[shape = box];";
					int contador1 = 0;
					int contador2 = 0;
					for (int i = 0; i < nrev.getSize(); i++) {

						if (auxnrev->getAccion() == "BR") {
							a = a + "nodo" + to_string(contador1) + "[label = \" " + auxnrev->getBuscada() + "\"];\n";
							contador1++;
						}
					
						auxnrev = auxnrev->getSiguiente();
					}
		
					for (int i = 0; i < rev.getSize(); i++) {

						if (auxrev->getAccion() == "BR") {
							a = a + "nodo2" + to_string(contador2) + "[label = \" " + auxrev->getBuscada() + "\"];\n";
							contador2++;
						}
						
						auxrev = auxrev->getSiguiente();
					}
					auxnrev = nrev.top();
					auxrev = rev.top();

					for (int i = 0; i < contador1; i++) {
		
							a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";
				
					}

					for (int i = 0; i < contador2; i++) {
	
							a = a + "nodo2" + to_string(i) + "->nodo2" + to_string(i + 1) + ";\n";


					}

					a = a + "}";

					archivo << a;

					archivo.close();
					system("dot.exe -Tjpg grafoPila.txt -o grafoPila.jpg");
					system("grafoPila.jpg");




				}
				else {

				}


			}
			else if (caracter == '*') {
				system("cls");
				lc.mostrarLista();
				cout << lc.primerCaracter() << lc.ultimoCaracter();
			}
			else if (caracter == '+') {
				//lc.imprimirListaPos();

				cout << endl << "no revertido" << endl;
				nrev.mostrarPila();


				cout << endl << "revertido" << endl;
				rev.mostrarPila();
			}
			else {

				cadena = cadena + caracter;

				if (lc.isEmpty()) {
					//cadena = llenarPila(cadena, caracter);
					if (caracter == ' ') {
						cadena = " ";
						nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
						cadena = "";
						//		nrev.mostrarPila();
					}

					else {
						nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
					}
					lc.insertarFinal(caracter, WhereX(), WhereY());
					imprimir(cadena, lc);
				}
				else {
					if (WhereY() > lc.getLastPositionY()) {
						gotoxy(lc.getLastPositionX() + 1, lc.getLastPositionY());
						//cadena = llenarPila(cadena, caracter);
						if (caracter == ' ') {
							cadena = " ";
							nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
							cadena = "";
							//		nrev.mostrarPila();
						}
						
						else {
							nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
						}
						lc.insertarFinal(caracter, WhereX(), WhereY());
						imprimir(cadena, lc);
					}
					else if (WhereY() == lc.getLastPositionY()) {
						if (WhereX() >= lc.getLastPositionX()) {
							gotoxy(lc.getLastPositionX() + 1, lc.getLastPositionY());
							//cadena = llenarPila(cadena, caracter);
							if (caracter == ' ') {
								cadena = " ";
								nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
								cadena = "";
								//		nrev.mostrarPila();
							}

							else {
								nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
							}
							lc.insertarFinal(caracter, WhereX(), WhereY());
							imprimir(cadena, lc);
						}
						else {
							//cout << " x menor y igual";
							//gotoxy(lc.getLastPositionX() + 1, lc.getLastPositionY());
							int x = WhereX();
							int y = WhereY();
							//	cadena = llenarPila(cadena, caracter);
							if (caracter == ' ') {
								cadena = " ";
								nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
								cadena = "";
								//		nrev.mostrarPila();
							}

							else {
								nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
							}
							lc.insertarEnMedio(caracter, x, y);
							imprimir(cadena, lc);
							gotoxy(x + 1, y);


						}
					}
					else {
						//cout << " y menor";
						int x = WhereX();
						int y = WhereY();
						//	cadena = llenarPila(cadena, caracter);
						if (caracter == ' ') {
							cadena = " ";
							nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
							cadena = "";
							//		nrev.mostrarPila();
						}

						else {
							nrev.push("", "", cadena, "agregar", false, WhereX(), WhereY(), NULL);
						}
						lc.insertarEnMedio(caracter, x, y);
						imprimir(cadena, lc);
						gotoxy(x + 1, y);
					}
				}
				//imprimir(cadena, lc);

			}
			//cout << ascii;

			//system("cls");
			//lc.mostrarLista();

		}

		system("cls");
		menu();
	}

ListaCaracteres toList(string cadena){
	ListaCaracteres l;

	for (int i = 0; i < cadena.length(); i++) {
		l.insertarFinal(cadena[i], 0, 0);
	}

	return l;
}


