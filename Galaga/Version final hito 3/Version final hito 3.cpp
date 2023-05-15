/*Integrantes:
- Leslie Torres U201914358

Profesor: El código emite sonido para lo cual se tiene que activar en propiedades-Vinculador-Entrada-Dependencias adicionales
al costado colocar winmm.lib.
El rango de tiempo de las tandas son 500 - 470 Tanda 1
469 - 440 Tanda 2
439 - 410 Tanda 3
y el tiempo que sobra aparece la Tanda 4
El nivel 2 y 4 esta en proceso
*/

#include<iostream>
#include<conio.h>
#include<windows.h>
#include <time.h>
#include<MMSystem.h>
#include<math.h>
#include <iostream>
#include <string> // string, stoi
#include <cctype> // isdigit
#include <cstdlib> // atoi


using namespace std;
using namespace System;
const int Max_Filas = 80;
const int Max_Columnas = 43;

/////////////////////////////////
int cantidad_comandantes;
int cantidad_mariposasT1;  int cantidad_mariposasT1circular;
int cantidad_mariposasT2;
int cantidad_mariposasT3;
int cantidad_de_enemigos;

int cantidad_avispasT1;
int cantidad_avispasT4;

int adicionales_nivel02 = 1;
int adicionales_nivel03 = 2;
int adicionales_nivel04 = 3;

/////////////////////////////////
int radio = 8;

const int maxdisp = 10;
int limite_disparo_nave = 5; //limite de la bala que no sobre pasa el marco superior

int tiempo_inicial = 180;
int Temporizador = 0;
int rapidez;
int tiempo_tanda = 30;
int segundos = 180;

int nivel = 1;
int ultimo_nivel = 6;
int vidas = 4;			//Numero de vidas
int energia = 15;		//Numero de salud
int puntos = 0;			//puntuacion del juego obtenido
int acumulador_puntos = 0;
int acumulador_tiempo = 0;

//Contador de enemigos eliminados para las estadisticas
int cont_comandantes = 0;
int cont_mariposas = 0;
int cont_avispas = 0;

void Nombre_Galaga() {
	cout << endl << endl << endl << endl << endl;
	cout << "              ______             __                               " << endl; Sleep(100);
	cout << "             /      " << (char)92 << "           /  |                              " << endl; Sleep(100);
	cout << "            /$$$$$$  |  ______  $$ |  ______    ______    ______  " << endl; Sleep(100);
	cout << "            $$ | _$$/  /      " << (char)92 << " $$ | /      " << (char)92 << "  /      " << (char)92 << "  /      " << (char)92 << " " << endl; Sleep(100);
	cout << "            $$ |/    | $$$$$$  |$$ | $$$$$$  |/$$$$$$  | $$$$$$  |" << endl; Sleep(100);
	cout << "            $$ |$$$$ | /    $$ |$$ | /    $$ |$$ |  $$ | /    $$ |" << endl; Sleep(100);
	cout << "            $$ " << (char)92 << "__$$ |/$$$$$$$ |$$ |/$$$$$$$ |$$ " << (char)92 << "__$$ |/$$$$$$$ |" << endl; Sleep(100);
	cout << "            $$    $$/ $$    $$ |$$ |$$    $$ |$$    $$ |$$    $$ |" << endl; Sleep(100);
	cout << "             $$$$$$/   $$$$$$$/ $$/  $$$$$$$/  $$$$$$$ | $$$$$$$/ " << endl; Sleep(100);
	cout << "                                              /  " << (char)92 << "__$$ |          " << endl; Sleep(100);
	cout << "                                              $$    $$/           " << endl; Sleep(100);
	cout << "                                               $$$$$$/            " << endl; Sleep(100);
}
void navecita() {
	char c = 219;
	char u = 223;
	char a = 220;

	Console::SetCursorPosition(34, 30); cout << "    " << a << c << a << endl;
	Console::SetCursorPosition(34, 31); cout << "   " << c << c << c << c << c << endl;
	Console::SetCursorPosition(34, 32); cout << "  " << c << c << c << " " << c << c << c << endl;
	Console::SetCursorPosition(34, 33); cout << "  " << c << c << "   " << c << c << endl;
	Console::SetCursorPosition(34, 34); cout << " " << c << c << c << c << c << c << c << c << c << endl;
	Console::SetCursorPosition(34, 35); cout << c << c << u << u << c << c << c << u << u << c << c << endl;
	Console::SetCursorPosition(34, 36); cout << c << "    " << c << "    " << c;
}
void integrantes() {
	Nombre_Galaga();

	Console::SetCursorPosition(18, 20); cout << "I"; Sleep(80);
	Console::SetCursorPosition(19, 20); cout << "N"; Sleep(80);
	Console::SetCursorPosition(20, 20); cout << "G"; Sleep(80);
	Console::SetCursorPosition(21, 20); cout << "."; Sleep(80);

	Console::SetCursorPosition(23, 20); cout << "D"; Sleep(80);
	Console::SetCursorPosition(24, 20); cout << "E"; Sleep(80);

	Console::SetCursorPosition(26, 20); cout << "S"; Sleep(80);
	Console::SetCursorPosition(27, 20); cout << "I"; Sleep(80);
	Console::SetCursorPosition(28, 20); cout << "S"; Sleep(80);
	Console::SetCursorPosition(29, 20); cout << "T"; Sleep(80);
	Console::SetCursorPosition(30, 20); cout << "E"; Sleep(80);
	Console::SetCursorPosition(31, 20); cout << "M"; Sleep(80);
	Console::SetCursorPosition(32, 20); cout << "A"; Sleep(80);
	Console::SetCursorPosition(33, 20); cout << "S"; Sleep(80);

	Console::SetCursorPosition(35, 20); cout << "D"; Sleep(80);
	Console::SetCursorPosition(36, 20); cout << "E"; Sleep(80);

	Console::SetCursorPosition(38, 20); cout << "I"; Sleep(80);
	Console::SetCursorPosition(39, 20); cout << "N"; Sleep(80);
	Console::SetCursorPosition(40, 20); cout << "F"; Sleep(80);
	Console::SetCursorPosition(41, 20); cout << "O"; Sleep(80);
	Console::SetCursorPosition(42, 20); cout << "R"; Sleep(80);
	Console::SetCursorPosition(43, 20); cout << "M"; Sleep(80);
	Console::SetCursorPosition(44, 20); cout << "A"; Sleep(80);
	Console::SetCursorPosition(45, 20); cout << "C"; Sleep(80);
	Console::SetCursorPosition(46, 20); cout << "I"; Sleep(80);
	Console::SetCursorPosition(47, 20); cout << "O"; Sleep(80);
	Console::SetCursorPosition(48, 20); cout << "N"; Sleep(80);

	Console::SetCursorPosition(50, 20); cout << "Y"; Sleep(80);

	Console::SetCursorPosition(52, 20); cout << "S"; Sleep(80);
	Console::SetCursorPosition(53, 20); cout << "O"; Sleep(80);
	Console::SetCursorPosition(54, 20); cout << "F"; Sleep(80);
	Console::SetCursorPosition(55, 20); cout << "T"; Sleep(80);
	Console::SetCursorPosition(56, 20); cout << "W"; Sleep(80);
	Console::SetCursorPosition(57, 20); cout << "A"; Sleep(80);
	Console::SetCursorPosition(58, 20); cout << "R"; Sleep(80);
	Console::SetCursorPosition(59, 20); cout << "E"; Sleep(80);
	//////////////////////created by///////////////////////////
	Console::SetCursorPosition(33, 22); cout << "C"; Sleep(80);
	Console::SetCursorPosition(34, 22); cout << "R"; Sleep(80);
	Console::SetCursorPosition(35, 22); cout << "E"; Sleep(80);
	Console::SetCursorPosition(36, 22); cout << "A"; Sleep(80);
	Console::SetCursorPosition(37, 22); cout << "T"; Sleep(80);
	Console::SetCursorPosition(38, 22); cout << "E"; Sleep(80);
	Console::SetCursorPosition(39, 22); cout << "D"; Sleep(80);

	Console::SetCursorPosition(41, 22); cout << "B"; Sleep(80);
	Console::SetCursorPosition(42, 22); cout << "Y"; Sleep(80);
	////////////////////leslie torres//////////////////////////
	Console::SetCursorPosition(25, 24); cout << "L"; Sleep(80);
	Console::SetCursorPosition(26, 24); cout << "E"; Sleep(80);
	Console::SetCursorPosition(27, 24); cout << "S"; Sleep(80);
	Console::SetCursorPosition(28, 24); cout << "L"; Sleep(80);
	Console::SetCursorPosition(29, 24); cout << "I"; Sleep(80);
	Console::SetCursorPosition(30, 24); cout << "E"; Sleep(80);

	Console::SetCursorPosition(32, 24); cout << "T"; Sleep(80);
	Console::SetCursorPosition(33, 24); cout << "O"; Sleep(80);
	Console::SetCursorPosition(34, 24); cout << "R"; Sleep(80);
	Console::SetCursorPosition(35, 24); cout << "R"; Sleep(80);
	Console::SetCursorPosition(36, 24); cout << "E"; Sleep(80);
	Console::SetCursorPosition(37, 24); cout << "S"; Sleep(80);

	Console::SetCursorPosition(42, 24); cout << "-"; Sleep(80);

	Console::SetCursorPosition(44, 24); cout << "U"; Sleep(80);
	Console::SetCursorPosition(45, 24); cout << "2"; Sleep(80);
	Console::SetCursorPosition(46, 24); cout << "0"; Sleep(80);
	Console::SetCursorPosition(47, 24); cout << "1"; Sleep(80);
	Console::SetCursorPosition(48, 24); cout << "9"; Sleep(80);
	Console::SetCursorPosition(49, 24); cout << "1"; Sleep(80);
	Console::SetCursorPosition(50, 24); cout << "4"; Sleep(80);
	Console::SetCursorPosition(51, 24); cout << "3"; Sleep(80);
	Console::SetCursorPosition(52, 24); cout << "5"; Sleep(80);
	Console::SetCursorPosition(53, 24); cout << "8"; Sleep(80);
	//////////////////mauricio padilla/////////////////////////
	/*Console::SetCursorPosition(25, 26); cout << "M"; Sleep(80);
	Console::SetCursorPosition(26, 26); cout << "A"; Sleep(80);
	Console::SetCursorPosition(27, 26); cout << "U"; Sleep(80);
	Console::SetCursorPosition(28, 26); cout << "R"; Sleep(80);
	Console::SetCursorPosition(29, 26); cout << "I"; Sleep(80);
	Console::SetCursorPosition(30, 26); cout << "C"; Sleep(80);
	Console::SetCursorPosition(31, 26); cout << "I"; Sleep(80);
	Console::SetCursorPosition(32, 26); cout << "O"; Sleep(80);

	Console::SetCursorPosition(34, 26); cout << "P"; Sleep(80);
	Console::SetCursorPosition(35, 26); cout << "A"; Sleep(80);
	Console::SetCursorPosition(36, 26); cout << "D"; Sleep(80);
	Console::SetCursorPosition(37, 26); cout << "I"; Sleep(80);
	Console::SetCursorPosition(38, 26); cout << "L"; Sleep(80);
	Console::SetCursorPosition(39, 26); cout << "L"; Sleep(80);
	Console::SetCursorPosition(40, 26); cout << "A"; Sleep(80);

	Console::SetCursorPosition(42, 26); cout << "-"; Sleep(80);

	Console::SetCursorPosition(44, 26); cout << "U"; Sleep(80);
	Console::SetCursorPosition(45, 26); cout << "2"; Sleep(80);
	Console::SetCursorPosition(46, 26); cout << "0"; Sleep(80);
	Console::SetCursorPosition(47, 26); cout << "1"; Sleep(80);
	Console::SetCursorPosition(48, 26); cout << "9"; Sleep(80);
	Console::SetCursorPosition(49, 26); cout << "1"; Sleep(80);
	Console::SetCursorPosition(50, 26); cout << "1"; Sleep(80);
	Console::SetCursorPosition(51, 26); cout << "3"; Sleep(80);
	Console::SetCursorPosition(52, 26); cout << "9"; Sleep(80);
	Console::SetCursorPosition(53, 26); cout << "3"; Sleep(80);*/
	Sleep(1000);
	System::Console::ForegroundColor = System::ConsoleColor::Red; Sleep(200); navecita();
	System::Console::ForegroundColor = System::ConsoleColor::Cyan; Sleep(200); navecita();
	System::Console::ForegroundColor = System::ConsoleColor::Green; Sleep(200); navecita();
}
void cargando() {
	char cua = 254;
	Console::ForegroundColor = ConsoleColor::White;
	Console::SetCursorPosition(35, 38); cout << "C"; Sleep(80);
	Console::SetCursorPosition(36, 38); cout << "A"; Sleep(80);
	Console::SetCursorPosition(37, 38); cout << "R"; Sleep(80);
	Console::SetCursorPosition(38, 38); cout << "G"; Sleep(80);
	Console::SetCursorPosition(39, 38); cout << "A"; Sleep(80);
	Console::SetCursorPosition(40, 38); cout << "N"; Sleep(80);
	Console::SetCursorPosition(41, 38); cout << "D"; Sleep(80);
	Console::SetCursorPosition(42, 38); cout << "O"; Sleep(500);
	Console::SetCursorPosition(43, 38); cout << " "; Sleep(500);
	Console::SetCursorPosition(44, 38); cout << cua; Sleep(500);  Beep(500, 500);
	Console::SetCursorPosition(45, 38); cout << " " << cua; Sleep(500);    Beep(700, 500);
	Console::SetCursorPosition(47, 38); cout << " " << cua; Sleep(500);    Beep(900, 500);

	Console::SetCursorPosition(43, 38); cout << "                       "; Sleep(500);
	Console::SetCursorPosition(44, 38); cout << cua;        Sleep(500);  Beep(500, 500);
	Console::SetCursorPosition(45, 38); cout << " " << cua; Sleep(500);   Beep(700, 500);
	Console::SetCursorPosition(47, 38); cout << " " << cua; Sleep(500);    Beep(900, 500);

	Console::SetCursorPosition(43, 38); cout << "                       "; Sleep(500);
	Console::SetCursorPosition(44, 38); cout << cua; Sleep(500);   Beep(500, 500);
	Console::SetCursorPosition(45, 38); cout << " " << cua; Sleep(500);   Beep(700, 500);
	Console::SetCursorPosition(47, 38); cout << " " << cua; Sleep(500);    Beep(900, 500);
	Console::SetCursorPosition(35, 38); cout << "                             "; Sleep(500);
	Console::SetCursorPosition(37, 38); cout << "LISTO "; Sleep(50);
	Beep(500, 500); Beep(700, 500); Beep(900, 500);
	Beep(1100, 1000);
}
void Game_Over() {
	PlaySound(TEXT("GameOver"), NULL, SND_ASYNC);
	System::Console::ForegroundColor = System::ConsoleColor::White;
	Console::SetCursorPosition(11, 13); cout << "  /$$$$$$                                    " << endl;
	Console::SetCursorPosition(11, 14); cout << " /$$__  $$                                   " << endl;
	Console::SetCursorPosition(11, 15); cout << "| $$  " << (char)92 << "__/   /$$$$$$   /$$$$$$/$$$$    /$$$$$$  " << endl;
	Console::SetCursorPosition(11, 16); cout << "| $$ /$$$$  |____  $$ | $$_  $$_  $$  /$$__  $$ " << endl;
	Console::SetCursorPosition(11, 17); cout << "| $$|_  $$   /$$$$$$$ | $$ " << (char)92 << " $$ " << (char)92 << " $$ | $$$$$$$$ " << endl;
	Console::SetCursorPosition(11, 18); cout << "| $$  " << (char)92 << " $$  /$$__  $$ | $$ | $$ | $$ | $$_____/ " << endl;
	Console::SetCursorPosition(11, 19); cout << "|  $$$$$$/ |  $$$$$$$ | $$ | $$ | $$ |  $$$$$$$ " << endl;
	Console::SetCursorPosition(11, 20); cout << " " << (char)92 << "______/   " << (char)92 << "_______/ |__/ |__/ |__/  " << (char)92 << "_______/ " << endl;
	Console::SetCursorPosition(27, 22); cout << "  /$$$$$$                               " << endl;
	Console::SetCursorPosition(27, 23); cout << " /$$__  $$                              " << endl;
	Console::SetCursorPosition(27, 24); cout << "| $$  " << (char)92 << " $$  /$$    /$$  /$$$$$$    /$$$$$$ " << endl;
	Console::SetCursorPosition(27, 25); cout << "| $$  | $$ |  $$  /$$/ /$$__  $$  /$$__  $$" << endl;
	Console::SetCursorPosition(27, 26); cout << "| $$  | $$  " << (char)92 << "  $$/$$/ | $$$$$$$$ | $$  " << (char)92 << "__/" << endl;
	Console::SetCursorPosition(27, 27); cout << "| $$  | $$   " << (char)92 << "  $$$/  | $$_____/ | $$      " << endl;
	Console::SetCursorPosition(27, 28); cout << "|  $$$$$$/    " << (char)92 << "  $/   |  $$$$$$$ | $$      " << endl;
	Console::SetCursorPosition(27, 29); cout << " " << (char)92 << "______/      " << (char)92 << "_/     " << (char)92 << "_______/ |__/      " << endl;
	Sleep(2000);
	system("cls");
}
void Win() {
	PlaySound(TEXT("Up"), NULL, SND_ASYNC);
	Console::SetCursorPosition(15, 16); cout << "         /$$      /$$|    /$$         " << endl;
	Console::SetCursorPosition(15, 17); cout << "        | $$  /$ | $$|   |__/          " << endl;
	Console::SetCursorPosition(15, 18); cout << "        | $$ /$$$| $$|    /$$    /$$$$$$$ " << endl;
	Console::SetCursorPosition(15, 19); cout << "        | $$/$$ $$ $$|   | $$   | $$__  $$" << endl;
	Console::SetCursorPosition(15, 20); cout << "        | $$$$_  $$$$|   | $$   | $$  " << (char)92 << " $$" << endl;
	Console::SetCursorPosition(15, 21); cout << "        | $$$/ " << (char)92 << "  $$$|   | $$   | $$  | $$" << endl;
	Console::SetCursorPosition(15, 22); cout << "        | $$/   " << (char)92 << "  $$|   | $$   | $$  | $$" << endl;
	Console::SetCursorPosition(15, 23); cout << "        |__/     " << (char)92 << "__/    |__/   |__/  |__/" << endl;
	Sleep(2000);
	system("cls");
}
void Finish() {
	Console::SetCursorPosition(12, 16); cout << "     /$$$$$$$$  /$$             /$$             /$$       " << endl;
	Console::SetCursorPosition(12, 17); cout << "    | $$_____/ |__/            |__/            | $$        " << endl;
	Console::SetCursorPosition(12, 18); cout << "    | $$        /$$  /$$$$$$$   /$$   /$$$$$$$ | $$$$$$$ " << endl;
	Console::SetCursorPosition(12, 19); cout << "    | $$$$$    | $$ | $$__  $$ | $$  /$$_____/ | $$__  $$" << endl;
	Console::SetCursorPosition(12, 20); cout << "    | $$__/    | $$ | $$  " << (char)92 << " $$ | $$ |  $$$$$$  | $$  " << (char)92 << " $$" << endl;
	Console::SetCursorPosition(12, 21); cout << "    | $$       | $$ | $$  | $$ | $$  " << (char)92 << "____  $$ | $$  | $$" << endl;
	Console::SetCursorPosition(12, 22); cout << "    | $$       | $$ | $$  | $$ | $$  /$$$$$$$/ | $$  | $$" << endl;
	Console::SetCursorPosition(12, 23); cout << "    |__/       |__/ |__/  |__/ |__/ |_______/  |__/  |__/" << endl;
	Sleep(2000);
	system("cls");
}
void Menu_principal() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "            ____________________MENU PRINCIPAL_______________________ " << endl;
	cout << "           |             .               .                           |" << endl;
	cout << "           |   .                            .        .               |" << endl;
	cout << "           |          .        1. Nuevo juego                        |" << endl;
	cout << "           |          .        2. Instrucciones                      |" << endl;
	cout << "           |                   3. Descripcion        .               |" << endl;
	cout << "           |   .                                                     |" << endl;
	cout << "           |           .           .                           .     |" << endl;
	cout << "           |                     .                                   |" << endl;
	cout << "           |_________________________________________________________|" << endl;

}
void Comenzar_juego() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "            _______________________SUB-MENU__________________________ " << endl;
	cout << "           |             .                                 .         |" << endl;
	cout << "           |             .                                 .         |" << endl;
	cout << "           |                 .                     .          .      |" << endl;
	cout << "           |    .              1. Comenzar juego                     |" << endl;
	cout << "           |       .           2. Volver            .             .  |" << endl;
	cout << "           |             .                                 .         |" << endl;
	cout << "           |                                                         |" << endl;
	cout << "           |             .                                 .         |" << endl;
	cout << "           |         .                                               |" << endl;
	cout << "           |_________________________________________________________|" << endl;
}
void Historia() {
	system("cls");
	Console::SetCursorPosition(15, 16); cout << "  ____    _                                  _ ";
	Console::SetCursorPosition(15, 17); cout << " |  _ " << (char)92 << "  | |  __ _   _   _   ___   _ __     / |";
	Console::SetCursorPosition(15, 18); cout << " | |_) | | | /  _ | | | | | / _ " << (char)92 << " | __ |    | |";
	Console::SetCursorPosition(15, 19); cout << " |  __/  | | | (_|| | |_| | | __/ | |       | |";
	Console::SetCursorPosition(15, 20); cout << " |_|     |_| " << (char)92 << "__,_|  " << (char)92 << "__, | " << (char)92 << "___| |_|       |_|";
	Console::SetCursorPosition(15, 21); cout << "                     |___/                    ";

	System::Console::ForegroundColor = System::ConsoleColor::White;
	Console::SetCursorPosition(24, 23); cout << "Comandantes   400 puntos";
	System::Console::ForegroundColor = System::ConsoleColor::Green;
	Console::SetCursorPosition(50, 23); cout << "]>o<[";

	System::Console::ForegroundColor = System::ConsoleColor::White;
	Console::SetCursorPosition(24, 24); cout << "Mariposas     160 puntos";
	System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
	Console::SetCursorPosition(51, 24); cout << ">m<";

	System::Console::ForegroundColor = System::ConsoleColor::White;
	Console::SetCursorPosition(24, 25); cout << "Avispas       100 puntos";
	System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
	Console::SetCursorPosition(51, 25); cout << ">a<";
}
void Marco(int Max_Filas, int Max_Columnas, int limite_izquierdo_arriba, int limite_intermedio, int color_nivel) {
	if (color_nivel == 1 || color_nivel == 3) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkCyan;
	}
	else if (color_nivel == 2 || color_nivel == 4) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkMagenta;
	}
	else if (color_nivel == 5) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
	}
	for (int i = 2; i < Max_Filas - 2; i++) {	//lineas hori
		System::Console::SetCursorPosition(i, limite_izquierdo_arriba);
		cout << (char)205;
		System::Console::SetCursorPosition(i, limite_intermedio);
		cout << (char)205;
		System::Console::SetCursorPosition(i, Max_Columnas - 2);
		cout << (char)205;
	}
	for (int i = 2; i < Max_Columnas - 2; i++) {	//lineas verti
		System::Console::SetCursorPosition(limite_izquierdo_arriba, i);
		cout << (char)186;
		System::Console::SetCursorPosition(Max_Filas - 2, i);
		cout << (char)186;
	}
	//INTERSECCIONES
	System::Console::SetCursorPosition(limite_izquierdo_arriba, limite_izquierdo_arriba);
	cout << (char)201;//izquierda arriba
	System::Console::SetCursorPosition(limite_izquierdo_arriba, limite_intermedio);
	cout << (char)204;//union izquierda
	System::Console::SetCursorPosition(limite_izquierdo_arriba, Max_Columnas - 2);
	cout << (char)200;//izquierda abajo

	System::Console::SetCursorPosition(Max_Filas - 2, limite_izquierdo_arriba);
	cout << (char)187;//derecha arriba
	System::Console::SetCursorPosition(Max_Filas - 2, limite_intermedio);
	cout << (char)185;//union derecha
	System::Console::SetCursorPosition(Max_Filas - 2, Max_Columnas - 2);
	cout << (char)188;//derecha abajo

}
void Banner_marco(int Max_Filas, int Max_Columnas, int limite_izquierdo_arriba, int limite_intermedio, int color_nivel) {
	if (color_nivel == 1 || color_nivel == 3) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkMagenta;
	}
	else {
		System::Console::ForegroundColor = System::ConsoleColor::DarkCyan;
	}
	for (int i = 15; i < Max_Filas - 2; i++) {	//lineas hori
		System::Console::SetCursorPosition(i, limite_izquierdo_arriba + 7);
		cout << (char)205;
		System::Console::SetCursorPosition(i, limite_intermedio + 9);
		cout << (char)205;
		System::Console::SetCursorPosition(i, Max_Columnas - 2);
		cout << (char)205;
	}
	for (int i = 9; i < Max_Columnas - 2; i++) {	//lineas verti
		System::Console::SetCursorPosition(15, i);
		cout << (char)186;
		System::Console::SetCursorPosition(Max_Filas - 2, i);
		cout << (char)186;
	}
	//INTERSECCIONES
	System::Console::SetCursorPosition(15, limite_izquierdo_arriba + 7);
	cout << (char)201;//izquierda arriba
	System::Console::SetCursorPosition(15, limite_intermedio + 9);
	cout << (char)204;//union izquierda
	System::Console::SetCursorPosition(15, Max_Columnas - 2);
	cout << (char)200;//izquierda abajo

	System::Console::SetCursorPosition(Max_Filas - 2, limite_izquierdo_arriba + 7);
	cout << (char)187;//derecha arriba
	System::Console::SetCursorPosition(Max_Filas - 2, limite_intermedio + 9);
	cout << (char)185;//union derecha
	System::Console::SetCursorPosition(Max_Filas - 2, Max_Columnas - 2);
	cout << (char)188;//derecha abajo

}
void Instrucciones() {
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "      _______________________________________________________________________ " << endl;
	cout << "     | .-.            .-.         .               _                   .      |" << endl;
	cout << "     | : :           .' `.                       :_;                     .   |" << endl;
	cout << "     | : :,-.,-. .--.`. .'.--. .-..-. .--.  .--. .-. .--. ,-.,-. .--.  .--.  |" << endl;
	cout << "     | : :: ,. :`._-.': : : ..': :; :'  ..''  ..': :' .; :: ,. :' '_.'`._-.' |" << endl;
	cout << "     | :_;:_;:_;`.__.':_; :_;  `.__.'`.__.'`.__.':_;`.__.':_;:_;`.__.'`.__.' |" << endl;
	cout << "     |                                                                       |" << endl;
	cout << "     |                 .                      .                              |" << endl;
	cout << "     |     .                                                                 |" << endl;
	cout << "     |      Durante el juego tendremos que mover nuestra nave de             |" << endl;
	cout << "     |       izquierda a derecha, con ayuda de las teclas direccionales      |" << endl;
	cout << "     |       para poder esquivar tanto los misiles como los ataques          |" << endl;
	cout << "     |       kamikaze de las naves enemigas.                                 |" << endl;
	cout << "     |                       .                                               |" << endl;
	cout << "     |   .                                                  .        .       |" << endl;
	cout << "     |                     <-                  ->                            |" << endl;
	cout << "     |                  Izquierda     .      Derecha                         |" << endl;
	cout << "     |         .                                                             |" << endl;
	cout << "     |                               |esp|                    .              |" << endl;
	cout << "     |                     con espacio disparo de balas                      |" << endl;
	cout << "     |             .                                                         |" << endl;
	cout << "     |            Z                     G                   E .              |" << endl;
	cout << "     |      Pierdes energia        Ganas puntos       Ganas energia          |" << endl;
	cout << "     |                                                                       |" << endl;
	cout << "     |                                                                       |" << endl;
	cout << "     |                             1. Volver                                 |" << endl;
	cout << "     |   .           .                                               .       |" << endl;
	cout << "     |                                                                       |" << endl;
	cout << "     |                                                                       |" << endl;
	cout << "     |_______________________________________________________________________|" << endl;
}
void Descripcion() {
	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "      ____________________________________________________________________" << endl;
	cout << "     |                 .--.        .-.                                    |" << endl;
	cout << "     |                : .--'       : :                                    |" << endl;
	cout << "     |                : : _  .--.  : :   .--.   .--.  .--.          .     |" << endl;
	cout << "     |        .       : :; :' .; ; : :_ ' .; ; ' .; :' .; ;               |" << endl;
	cout << "     |                `.__.'`.__,_;`.__;`.__,_;`._. ;`.__,_;              |" << endl;
	cout << "     |                                        .-. :              .        |" << endl;
	cout << "     |    .                                   `._.'                       |" << endl;
	cout << "     |                              .                                     |" << endl;
	cout << "     |      Este juego esta realizado con el lenguaje C++, en Visual      |" << endl;
	cout << "     |       Studio 2015.                 .                               |" << endl;
	cout << "     |                                                                    |" << endl;
	cout << "     |      El juego consiste en en eliminar las distintas naves enemigas |" << endl;
	cout << "     |       que nos van apareciendo en pantalla hasta quedarnos solos    |" << endl;
	cout << "     |       y asi poder pasar al siguiente nivel, en el cual veremos     |" << endl;
	cout << "     |       incrementada la dificultad, ya sea el numero de enemigos,    |" << endl;
	cout << "     |  .    su velocidad o la cantidad de misiles que son capaces de     |" << endl;
	cout << "     |       lanzarnos en su descenso suicida.                            |" << endl;
	cout << "     |                                                                    |" << endl;
	cout << "     |      El juego cuenta con un total de 4 niveles. El cambio de       |" << endl;
	cout << "     |       nivel se produce cuando se haya acumulado al menos 2500      |" << endl;
	cout << "     |       puntos.            .                                         |" << endl;
	cout << "     |                                                           .        |" << endl;
	cout << "     |            .                                 .                     |" << endl;
	cout << "     |                                .                         .         |" << endl;
	cout << "     |                             1. Volver                              |" << endl;
	cout << "     |                                                                    |" << endl;
	cout << "     |                                                                    |" << endl;
	cout << "     |         .                                                          |" << endl;
	cout << "     |____________________________________________________________________|" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Portada() {
	integrantes();
	cargando();
	Sleep(700);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Estructura general
struct Movimiento {
	int x, y, dx, dy, ndisparos, vidas_enemigos;
	bool vivo, enganche;
	int polarx, polary, ang;
};
///////////////////////////////////////////////---------NAVE-----------//////////////////////////////////////////////
void Iniciar_nave(Movimiento*nave) {
	nave->x = 34;
	nave->y = 38;
	nave->dx = nave->dy = 1;
	nave->ndisparos = 0;
}
void Mover_izquierda_nave(Movimiento*nave, int limite) {
	if (nave->x + nave->dx > limite) {
		nave->x += nave->dx;
	}
}
void Mover_derecha_nave(Movimiento*nave, int limite) {
	if (nave->x + nave->dx < limite) {
		nave->x += nave->dx;
	}
}
void Mover_arriba_nave(Movimiento*nave, int limite) {
	if (nave->y + nave->dy > limite) {
		nave->y += nave->dy;
	}
}
void Mover_abajo_nave(Movimiento*nave, int limite) {
	if (nave->y + nave->dy < limite) {
		nave->y += nave->dy;
	}
}
void Dibujar_nave(Movimiento*nave, int nivel) {
	if (nivel == 1 || nivel == 3) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
	}
	else {
		System::Console::ForegroundColor = System::ConsoleColor::Cyan;
	}
	System::Console::SetCursorPosition(nave->x, nave->y);		cout << "   *   ";
	System::Console::SetCursorPosition(nave->x, nave->y + 1);	cout << " !***! ";
	System::Console::SetCursorPosition(nave->x, nave->y + 2);	cout << "** " << (char)190 << " **";
}
void Borrar_nave(Movimiento*nave) {
	System::Console::SetCursorPosition(nave->x, nave->y);		cout << "       ";
	System::Console::SetCursorPosition(nave->x, nave->y + 1);	cout << "       ";
	System::Console::SetCursorPosition(nave->x, nave->y + 2);	cout << "       ";
}
///////////////////////////////////////////---------COMANDANTES-----------////////////////////////////////////////////
void Iniciar_comandantes(Movimiento*comandantes, Movimiento*balas_comandantes, int posicion) {
	int ancho, altura;
	for (int i = 0; i < cantidad_comandantes; i++) {
		if (posicion == 1) {	//izquierda - arriba
			ancho = 3 + rand() % (5 - 3);
			altura = 7 + rand() % (20 - 7);
		}
		else if (posicion == 2) {	//derecha - arriba
			ancho = 65 + rand() % (72 - 65);
			altura = 7 + rand() % (15 - 7);
		}
		else if (posicion == 3) {	// izquierda - abajo
			ancho = 4 + rand() % (30 - 4);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 4) {	//derecha - abajo 
			ancho = 65 + rand() % (72 - 65);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 5) {	//centro superior
			ancho = 35 + rand() % (40 - 35);
			altura = 6 + rand() % (18 - 6);
		}

		comandantes[i].x = ancho;
		comandantes[i].y = altura;
		comandantes[i].dx = comandantes[i].dy = 1;
		comandantes[i].vivo = true;
		comandantes[i].vidas_enemigos = 2;
		comandantes[i].enganche = false;

		balas_comandantes[i].x = comandantes[i].x;
		balas_comandantes[i].y = comandantes[i].y;
		balas_comandantes[i].dx = balas_comandantes[i].dy = 1;
		balas_comandantes[i].vivo = true;
	}
}
void Dibujar_balascomandante(Movimiento*balas_comandantes, Movimiento*comandantes) {
	for (int i = 0; i < cantidad_comandantes; i++) {
		if (balas_comandantes[i].vivo == true || comandantes[i].vivo == true) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			System::Console::SetCursorPosition(balas_comandantes[i].x + 3, balas_comandantes[i].y); cout << "1";
		}
		else {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			System::Console::SetCursorPosition(balas_comandantes[i].x + 3, balas_comandantes[i].y); cout << " ";
		}
	}
}
void Borrar_balas_comandante(Movimiento*balas_comandantes, Movimiento*comandantes) {
	for (int i = 0; i < cantidad_comandantes; i++) {
		System::Console::ForegroundColor = System::ConsoleColor::Black;
		System::Console::SetCursorPosition(balas_comandantes[i].x + 3, balas_comandantes[i].y); cout << " ";
	}
}
void Dibujar_comandantes(Movimiento*comandantes) {
	for (int i = 0; i < cantidad_comandantes; i++) {
		if (comandantes[i].vivo == true && comandantes[i].vidas_enemigos == 2) {
			System::Console::ForegroundColor = System::ConsoleColor::DarkGreen;
			System::Console::SetCursorPosition(comandantes[i].x, comandantes[i].y); cout << "]<o>[";
		}
		else if (comandantes[i].vivo == true && comandantes[i].vidas_enemigos == 1) {
			System::Console::ForegroundColor = System::ConsoleColor::Magenta;
			System::Console::SetCursorPosition(comandantes[i].x, comandantes[i].y); cout << "]<o>[";
		}
	}
}
void Borrar_comandantes(Movimiento*comandantes) {
	for (int i = 0; i < cantidad_comandantes; i++) {
		System::Console::SetCursorPosition(comandantes[i].x, comandantes[i].y); cout << "     ";
	}
}

void pintar_barra() {
	System::Console::ForegroundColor = System::ConsoleColor::White;
	System::Console::SetCursorPosition(55, 3);  cout << "     ";
	System::Console::SetCursorPosition(49, 3);	cout << "Naves: " << vidas;
	System::Console::SetCursorPosition(70, 3);  cout << "        ";
	System::Console::SetCursorPosition(61, 3);	cout << "Energia: ";

	if (energia >= 10 && energia <= 15) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkGreen;
	}
	else if (energia >= 5 && energia <= 9) {
		System::Console::ForegroundColor = System::ConsoleColor::Yellow;
	}
	else if (energia >= 0 && energia <= 4) {
		System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
	}
	int j = 1;
	for (int i = 0; i < energia; i++) {
		if (i % 3 == 0) {
			System::Console::SetCursorPosition(70 + j, 3); cout << (char)219;
			j++;
		}
	}

}
void explosion_del_jugador(Movimiento*nave) {
	PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
	Borrar_nave(nave);
	System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
	System::Console::SetCursorPosition(nave->x, nave->y);		cout << "   *   ";
	System::Console::SetCursorPosition(nave->x, nave->y + 1);	cout << "  ***  ";
	System::Console::SetCursorPosition(nave->x, nave->y + 2);	cout << "   *   ";
	Sleep(250);

	Borrar_nave(nave);
	System::Console::SetCursorPosition(nave->x, nave->y);		cout << "* * *";
	System::Console::SetCursorPosition(nave->x, nave->y + 1);	cout << " *** ";
	System::Console::SetCursorPosition(nave->x, nave->y + 2);	cout << "* * *";
	Sleep(300);

	Borrar_nave(nave);
	vidas--;
	energia = 15;



	System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
	System::Console::SetCursorPosition(1, 1); cout << "  ";
	System::Console::SetCursorPosition(1, 1); cout << energia;

	pintar_barra();
	//Despues de la explosion de la nave regresa a su posicion inicial
	Borrar_nave(nave);
	Iniciar_nave(nave);
	Dibujar_nave(nave, nivel);
}

void Mover_comandantes(Movimiento*nave, Movimiento*balas_comandantes, int limite, int limite_inferior_coman,
	Movimiento*comandantes, int limite_inferior_bala) {
	Borrar_comandantes(comandantes);
	Borrar_balas_comandante(balas_comandantes, comandantes);
	for (int i = 0; i < cantidad_comandantes; i++) {
		if (comandantes[i].y + comandantes[i].dy > limite_inferior_coman || comandantes[i].y + comandantes[i].dy < 5) {
			comandantes[i].dy = -1 * comandantes[i].dy;
		}
		comandantes[i].y += comandantes[i].dy;

		if (comandantes[i].y >= 6 && comandantes[i].y < 30) {
			if (balas_comandantes[i].y + balas_comandantes[i].dy < limite_inferior_bala) {
				balas_comandantes[i].y += balas_comandantes[i].dy;
			}
			else {
				balas_comandantes[i].x = comandantes[i].x - 1;
				balas_comandantes[i].y = comandantes[i].y;
			}
		}
		else {
			if (balas_comandantes[i].y + balas_comandantes[i].dy < 30) {
				balas_comandantes[i].y += balas_comandantes[i].dy;
			}
			else {
				balas_comandantes[i].x = comandantes[i].x - 1;
				balas_comandantes[i].y = comandantes[i].y;
			}
		}

		if (comandantes[i].vivo == true && balas_comandantes[i].vivo == true) {
			if ((balas_comandantes[i].x + 3 >= nave->x && balas_comandantes[i].x + 3 <= nave->x + 6) &&
				(balas_comandantes[i].y >= nave->y && balas_comandantes[i].y <= nave->y + 2)) {

				energia--;
				//comprobar corazones esquina superior izquierda
				System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				pintar_barra();
				if (energia == 0) {
					explosion_del_jugador(nave);
				}
			}
		}
		//Haz tractor
		if (comandantes[i].vivo == true) {
			if ((nave->x + 3) >= comandantes[i].x && (nave->x + 3) <= comandantes[i].x + 5 && nave->y - 2 == comandantes[i].y) {
				PlaySound(TEXT("Haztractor"), NULL, SND_ASYNC);
				Borrar_nave(nave);
				nave->dy = -1;
				comandantes[i].enganche = true;
				Mover_arriba_nave(nave, 4);
				Dibujar_nave(nave, nivel);
				if (nave->y <= 8 && nave->y >= 4) {
					energia = 0;
					explosion_del_jugador(nave);
				}
			}
		}

	}
	Dibujar_comandantes(comandantes);
	Dibujar_balascomandante(balas_comandantes, comandantes);
}
////////////////////////////////////////////---------MARIPOSAS TANDA 1-----------////////////////////////////////////////////
void Iniciar_mariposas_tanda1(Movimiento*mariposasT1, int posicion) {
	int ancho, altura;
	for (int i = 0; i < cantidad_mariposasT1; i++) {
		if (posicion == 1) {	//izquierda - arriba
			ancho = 3 + rand() % (5 - 3);
			altura = 7 + rand() % (20 - 7);
		}
		else if (posicion == 2) {	//derecha - arriba
			ancho = 65 + rand() % (72 - 65);
			altura = 7 + rand() % (15 - 7);
		}
		else if (posicion == 3) {	// izquierda - abajo
			ancho = 3 + rand() % (10 - 3);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 4) {	//derecha - abajo 
			ancho = 65 + rand() % (72 - 65);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 5) {	//centro superior
			ancho = 35 + rand() % (40 - 35);
			altura = 6 + rand() % (18 - 6);
		}

		mariposasT1[i].x = ancho;
		mariposasT1[i].y = altura;
		mariposasT1[i].dx = mariposasT1[i].dy = 1;
		mariposasT1[i].vivo = true;
		mariposasT1[i].vidas_enemigos = 1;
	}
}
void Dibujar_maríposas_tanda1(Movimiento*mariposasT1) {
	for (int i = 0; i < cantidad_mariposasT1; i++) {
		if (mariposasT1[i].vivo == true && mariposasT1[i].vidas_enemigos == 1) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			System::Console::SetCursorPosition(mariposasT1[i].x, mariposasT1[i].y); cout << ">m<";
		}
	}
}
void Borrar_mariposas_tanda1(Movimiento*mariposasT1) {
	for (int i = 0; i < cantidad_mariposasT1; i++) {
		System::Console::SetCursorPosition(mariposasT1[i].x, mariposasT1[i].y); cout << "   ";
	}
}
void Mover_mariposas_tanda1(Movimiento*nave, Movimiento*mariposasT1, int limite_derecho_mari, int limite_inferior_mari, int limite_izquierdo) {
	Borrar_mariposas_tanda1(mariposasT1);
	for (int i = 0; i < cantidad_mariposasT1; i++) {
		if (mariposasT1[i].x + mariposasT1[i].dx > limite_derecho_mari || mariposasT1[i].x + mariposasT1[i].dx < limite_izquierdo) {
			mariposasT1[i].dx = -1 * mariposasT1[i].dx;
		}
		mariposasT1[i].x += mariposasT1[i].dx;

		if (mariposasT1[i].y + mariposasT1[i].dy > limite_inferior_mari || mariposasT1[i].y + mariposasT1[i].dy < 7) {
			mariposasT1[i].dy = -1 * mariposasT1[i].dy;
		}
		mariposasT1[i].y += mariposasT1[i].dy;

		//COLISION DE LOS KAMIKAZES CON LA NAVE
		if (mariposasT1[i].vivo == true && mariposasT1[i].vidas_enemigos == 1) {
			if ((nave->x + 3) >= mariposasT1[i].x && (nave->x + 3) <= mariposasT1[i].x + 3 && nave->y - 1 == mariposasT1[i].y) {
				energia = energia - 3;
				//comprobar corazones esquina superior izquierda
				System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				pintar_barra();
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				mariposasT1[i].vidas_enemigos--;
				mariposasT1[i].vivo == false;
			}
		}
	}
	Dibujar_maríposas_tanda1(mariposasT1);
}

/////////////////////////////////////---------MARIPOSAS TANDA 1 CIRCULAR-----------/////////////////////////////////////
void Iniciar_mariposas_t1circular(Movimiento*mariposasT1circular) {
	for (int i = 0; i < cantidad_mariposasT1circular; i++) {
		mariposasT1circular[i].x = 35;
		mariposasT1circular[i].y = 20;
		mariposasT1circular[i].ang = rand() % 270;
		mariposasT1circular[i].polarx = mariposasT1circular[i].x + radio * sin((mariposasT1circular[i].ang*3.1416) / 180);
		mariposasT1circular[i].polary = mariposasT1circular[i].y + radio * cos((mariposasT1circular[i].ang*3.1416) / 180);
		mariposasT1circular[i].vivo = true;
		mariposasT1circular[i].vidas_enemigos = 1;
	}
}
void Dibujar_mariposas_t1circular(Movimiento*mariposasT1circular) {
	for (int i = 0; i < cantidad_mariposasT1circular; i++) {
		if (mariposasT1circular[i].vivo == true && mariposasT1circular[i].vidas_enemigos == 1) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			System::Console::SetCursorPosition(mariposasT1circular[i].polarx, mariposasT1circular[i].polary); cout << ">m<";
		}
	}
}
void Borrar_mariposas_t1circular(Movimiento*mariposasT1circular) {
	for (int i = 0; i < cantidad_mariposasT1circular; i++) {
		System::Console::SetCursorPosition(mariposasT1circular[i].polarx, mariposasT1circular[i].polary); cout << "   ";
	}
}
void Mover_mariposas_t1circular(Movimiento*nave, Movimiento*mariposasT1circular) {
	Borrar_mariposas_t1circular(mariposasT1circular);
	for (int i = 0; i < cantidad_mariposasT1circular; i++) {
		mariposasT1circular[i].ang = mariposasT1circular[i].ang + 1;
		mariposasT1circular[i].polarx = mariposasT1circular[i].x + radio * sin((mariposasT1circular[i].ang*3.1416) / 180);
		mariposasT1circular[i].polary = mariposasT1circular[i].y + radio * cos((mariposasT1circular[i].ang*3.1416) / 180);

		//COLISION DE LOS KAMIKAZES CON LA NAVE
		if (mariposasT1circular[i].vivo == true && mariposasT1circular[i].vidas_enemigos == 1) {
			if ((nave->x + 3) >= mariposasT1circular[i].polarx && (nave->x + 3) <= mariposasT1circular[i].polarx + 3 && nave->y - 1 == mariposasT1circular[i].polary) {
				energia = energia - 3;
				//comprobar corazones esquina superior izquierda
				System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				pintar_barra();
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				mariposasT1circular[i].vidas_enemigos--;
				mariposasT1circular[i].vivo == false;
			}
		}
	}
	Dibujar_mariposas_t1circular(mariposasT1circular);
}

////////////////////////////////////////////---------MARIPOSAS TANDA 2-----------////////////////////////////////////////////
void Iniciar_mariposas_tanda2(Movimiento*mariposasT2, int posicion) {
	int ancho, altura;
	for (int i = 0; i < cantidad_mariposasT2; i++) {
		if (posicion == 1) {	//izquierda - arriba
			ancho = 3 + rand() % (5 - 3);
			altura = 7 + rand() % (20 - 7);
		}
		else if (posicion == 2) {	//derecha - arriba
			ancho = 65 + rand() % (72 - 65);
			altura = 7 + rand() % (15 - 7);
		}
		else if (posicion == 3) {	// izquierda - abajo
			ancho = 3 + rand() % (15 - 3);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 4) {	//derecha - abajo 
			ancho = 65 + rand() % (72 - 65);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 5) {	//centro superior
			ancho = 35 + rand() % (40 - 35);
			altura = 6 + rand() % (18 - 6);
		}

		mariposasT2[i].x = ancho;
		mariposasT2[i].y = altura;
		mariposasT2[i].dx = mariposasT2[i].dy = 1;
		mariposasT2[i].vivo = true;
		mariposasT2[i].vidas_enemigos = 1;
	}
}
void Dibujar_maríposas_tanda2(Movimiento*mariposasT2) {
	for (int i = 0; i < cantidad_mariposasT2; i++) {
		if (mariposasT2[i].vivo == true && mariposasT2[i].vidas_enemigos == 1) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			System::Console::SetCursorPosition(mariposasT2[i].x, mariposasT2[i].y); cout << ">m<";
		}
	}
}
void Borrar_mariposas_tanda2(Movimiento*mariposasT2) {
	for (int i = 0; i < cantidad_mariposasT2; i++) {
		System::Console::SetCursorPosition(mariposasT2[i].x, mariposasT2[i].y); cout << "   ";
	}
}
void Mover_mariposas_tanda2(Movimiento*mariposasT2, int limite_derecho_mari, int limite_inferior_mari, int limite_izquierdo) {
	Borrar_mariposas_tanda2(mariposasT2);
	for (int i = 0; i < cantidad_mariposasT2; i++) {
		if (mariposasT2[i].x + mariposasT2[i].dx > limite_derecho_mari || mariposasT2[i].x + mariposasT2[i].dx < limite_izquierdo) {
			mariposasT2[i].dx = -1 * mariposasT2[i].dx;
		}
		mariposasT2[i].x += mariposasT2[i].dx;

		if (mariposasT2[i].y + mariposasT2[i].dy > limite_inferior_mari || mariposasT2[i].y + mariposasT2[i].dy < 7) {
			mariposasT2[i].dy = -1 * mariposasT2[i].dy;
		}
		mariposasT2[i].y += mariposasT2[i].dy;
	}
	Dibujar_maríposas_tanda2(mariposasT2);
}

////////////////////////////////////////////---------MARIPOSAS TANDA 3-----------////////////////////////////////////////////
void Iniciar_mariposas_tanda3(Movimiento*mariposasT3, int posicion) {
	int ancho, altura;
	for (int i = 0; i < cantidad_mariposasT3; i++) {
		if (posicion == 1) {	//izquierda - arriba
			ancho = 3 + rand() % (5 - 3);
			altura = 7 + rand() % (20 - 7);
		}
		else if (posicion == 2) {	//derecha - arriba
			ancho = 65 + rand() % (72 - 65);
			altura = 7 + rand() % (15 - 7);
		}
		else if (posicion == 3) {	// izquierda - abajo
			ancho = 3 + rand() % (10 - 3);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 4) {	//derecha - abajo 
			ancho = 63 + rand() % (72 - 63);
			altura = 30 + rand() % (40 - 30);
		}
		else if (posicion == 5) {	//centro superior
			ancho = 35 + rand() % (40 - 35);
			altura = 6 + rand() % (18 - 6);
		}

		mariposasT3[i].x = ancho;
		mariposasT3[i].y = altura;
		mariposasT3[i].dx = mariposasT3[i].dy = 1;
		mariposasT3[i].vivo = true;
		mariposasT3[i].vidas_enemigos = 1;
	}
}
void Dibujar_maríposas_tanda3(Movimiento*mariposasT3) {
	for (int i = 0; i < cantidad_mariposasT3; i++) {
		if (mariposasT3[i].vivo == true && mariposasT3[i].vidas_enemigos == 1) {
			System::Console::ForegroundColor = System::ConsoleColor::Red;
			System::Console::SetCursorPosition(mariposasT3[i].x, mariposasT3[i].y); cout << ">m<";
		}
	}
}
void Borrar_mariposas_tanda3(Movimiento*mariposasT3) {
	for (int i = 0; i < cantidad_mariposasT3; i++) {
		System::Console::SetCursorPosition(mariposasT3[i].x, mariposasT3[i].y); cout << "   ";
	}
}
void Mover_mariposas_tanda3(Movimiento*nave, Movimiento*mariposasT3, int limite_derecho_mari, int limite_inferior_mari, int limite_izquierdo) {
	Borrar_mariposas_tanda3(mariposasT3);
	for (int i = 0; i < cantidad_mariposasT3; i++) {
		if (mariposasT3[i].x + mariposasT3[i].dx > limite_derecho_mari || mariposasT3[i].x + mariposasT3[i].dx < limite_izquierdo) {
			mariposasT3[i].dx = -1 * mariposasT3[i].dx;
		}
		mariposasT3[i].x += mariposasT3[i].dx;

		if (mariposasT3[i].y + mariposasT3[i].dy > limite_inferior_mari || mariposasT3[i].y + mariposasT3[i].dy < 7) {
			mariposasT3[i].dy = -1 * mariposasT3[i].dy;
		}
		mariposasT3[i].y += mariposasT3[i].dy;
		//COLISION DE LOS KAMIKAZES CON LA NAVE
		if (mariposasT3[i].vivo == true) {
			if ((nave->x + 3) >= mariposasT3[i].x && (nave->x + 3) <= mariposasT3[i].x + 3 && nave->y - 1 == mariposasT3[i].y) {
				energia = energia - 3;
				//comprobar corazones esquina superior izquierda
				System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				pintar_barra();
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				mariposasT3[i].vidas_enemigos = 0;
				mariposasT3[i].vivo == false;
			}
		}
	}
	Dibujar_maríposas_tanda3(mariposasT3);
}

////////////////////////////////////////////-----------AVISPAS TANDA 1------------////////////////////////////////////////////
void Iniciar_avispas(Movimiento*avispasT1, int posicion) {
	int ancho, altura;
	for (int i = 0; i < cantidad_avispasT1; i++) {
		if (posicion == 1) {	//izquierda - arriba
			ancho = 3 + rand() % (5 - 3);
			altura = 7 + rand() % (20 - 7);
		}
		else if (posicion == 2) {	//derecha - arriba
			ancho = 65 + rand() % (72 - 65);
			altura = 7 + rand() % (15 - 7);
		}
		else if (posicion == 3) {	// izquierda - abajo
			ancho = 3 + rand() % (10 - 3);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 4) {	//derecha - abajo 
			ancho = 65 + rand() % (72 - 65);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 5) {	//centro superior
			ancho = 35 + rand() % (40 - 35);
			altura = 6 + rand() % (18 - 6);
		}

		avispasT1[i].x = ancho;
		avispasT1[i].y = altura;
		avispasT1[i].dx = avispasT1[i].dy = 1;
		avispasT1[i].vivo = true;
		avispasT1[i].vidas_enemigos = 1;
	}
}
void Dibujar_avispas(Movimiento*avispasT1) {
	for (int i = 0; i < cantidad_avispasT1; i++) {
		if (avispasT1[i].vivo == true && avispasT1[i].vidas_enemigos == 1) {
			if (i % 2 == 0) {
				System::Console::ForegroundColor = System::ConsoleColor::DarkBlue;
				System::Console::SetCursorPosition(avispasT1[i].x, avispasT1[i].y); cout << "]a[";
			}
			else if (i % 3 == 0) {
				System::Console::ForegroundColor = System::ConsoleColor::Yellow;
				System::Console::SetCursorPosition(avispasT1[i].x, avispasT1[i].y); cout << "]a[";
			}
			else {
				System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
				System::Console::SetCursorPosition(avispasT1[i].x, avispasT1[i].y); cout << "]a[";
			}
		}
	}
}
void Borrar_avispas(Movimiento*avispasT1) {
	for (int i = 0; i < cantidad_avispasT1; i++) {
		System::Console::SetCursorPosition(avispasT1[i].x, avispasT1[i].y); cout << "   ";
	}
}
void Mover_avispas(Movimiento*avispasT1, int limite_derecho_avispas, int limite_inferior_avispas, int limite_izquierdo) {
	Borrar_avispas(avispasT1);
	for (int i = 0; i < cantidad_avispasT1; i++) {
		if (avispasT1[i].x + avispasT1[i].dx > limite_derecho_avispas || avispasT1[i].x + avispasT1[i].dx < limite_izquierdo) {
			avispasT1[i].dx = -1 * avispasT1[i].dx;
		}
		avispasT1[i].x += avispasT1[i].dx;

		if (avispasT1[i].y + avispasT1[i].dy > limite_inferior_avispas || avispasT1[i].y + avispasT1[i].dy < 7) {
			avispasT1[i].dy = -1 * avispasT1[i].dy;
		}
		avispasT1[i].y += avispasT1[i].dy;
	}
	Dibujar_avispas(avispasT1);
}

////////////////////////////////////////////-----------AVISPAS TANDA 4------------////////////////////////////////////////////
void Iniciar_avispas_tanda4(Movimiento*avispasT4, int posicion) {
	int ancho, altura;
	for (int i = 0; i < cantidad_avispasT4; i++) {
		if (posicion == 1) {	//izquierda - arriba
			ancho = 3 + rand() % (5 - 3);
			altura = 7 + rand() % (20 - 7);
		}
		else if (posicion == 2) {	//derecha - arriba
			ancho = 65 + rand() % (72 - 65);
			altura = 7 + rand() % (15 - 7);
		}
		else if (posicion == 3) {	// izquierda - abajo
			ancho = 3 + rand() % (10 - 3);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 4) {	//derecha - abajo 
			ancho = 65 + rand() % (72 - 65);
			altura = 35 + rand() % (40 - 35);
		}
		else if (posicion == 5) {	//centro superior
			ancho = 33 + rand() % (46 - 33);
			altura = 6 + rand() % (20 - 6);
		}

		avispasT4[i].x = ancho;
		avispasT4[i].y = altura;
		avispasT4[i].dx = avispasT4[i].dy = 1;
		avispasT4[i].vivo = true;
		avispasT4[i].vidas_enemigos = 1;
	}
}
void Dibujar_avispas_tanda4(Movimiento*avispasT4) {
	for (int i = 0; i < cantidad_avispasT4; i++) {
		if (avispasT4[i].vivo == true && avispasT4[i].vidas_enemigos == 1) {
			if (i % 2 == 0) {
				System::Console::ForegroundColor = System::ConsoleColor::DarkBlue;
				System::Console::SetCursorPosition(avispasT4[i].x, avispasT4[i].y); cout << "]a[";
			}
			else if (i % 3 == 0) {
				System::Console::ForegroundColor = System::ConsoleColor::Yellow;
				System::Console::SetCursorPosition(avispasT4[i].x, avispasT4[i].y); cout << "]a[";
			}
			else {
				System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
				System::Console::SetCursorPosition(avispasT4[i].x, avispasT4[i].y); cout << "]a[";
			}
		}
	}
}
void Borrar_avispas_tanda4(Movimiento*avispasT4) {
	for (int i = 0; i < cantidad_avispasT4; i++) {
		System::Console::SetCursorPosition(avispasT4[i].x, avispasT4[i].y); cout << "   ";
	}
}
void Mover_avispas_tanda4(Movimiento*avispasT4, int limite_derecho_avispas, int limite_inferior_avispas, int limite_izquierdo) {
	Borrar_avispas_tanda4(avispasT4);
	for (int i = 0; i < cantidad_avispasT1; i++) {
		if (avispasT4[i].x + avispasT4[i].dx > limite_derecho_avispas || avispasT4[i].x + avispasT4[i].dx < limite_izquierdo) {
			avispasT4[i].dx = -1 * avispasT4[i].dx;
		}
		avispasT4[i].x += avispasT4[i].dx;

		if (avispasT4[i].y + avispasT4[i].dy > limite_inferior_avispas || avispasT4[i].y + avispasT4[i].dy < 7) {
			avispasT4[i].dy = -1 * avispasT4[i].dy;
		}
		avispasT4[i].y += avispasT4[i].dy;
	}
	Dibujar_avispas_tanda4(avispasT4);
}

////////////////////////////////////////////-----------ENEMIGO MAYOR------------////////////////////////////////////////////
void Inciar_enemigo_mayor(Movimiento*enemigo) {
	for (int i = 0; i < cantidad_de_enemigos; i++) {
		enemigo[i].x = 5;
		enemigo[i].y = 6;
		enemigo[i].dx = enemigo[i].dy = 1;
		enemigo[i].vivo = true;
		enemigo[i].vidas_enemigos = 10;
	}
}
void Dibujar_enemigo_mayor(Movimiento*enemigo) {
	for (int i = 0; i < cantidad_de_enemigos; i++) {
		if (enemigo[i].vivo == true) {
			if (enemigo[i].vidas_enemigos % 2 == 0) {
				System::Console::ForegroundColor = System::ConsoleColor::DarkGreen;
			}
			else {
				System::Console::ForegroundColor = System::ConsoleColor::DarkCyan;
			}
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y);		cout << "            /|                                           |" << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 1);	cout << "           /||             " << (char)94 << "               " << (char)94 << "             ||" << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 2);	cout << "          / " << (char)92 << (char)92 << "__          //               " << (char)92 << (char)92 << "          __// " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 3);	cout << "         /  |_  " << (char)92 << "         | " << (char)92 << "   /     " << (char)92 << "   / |         /  _|  " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 4); cout << "        /  /  " << (char)92 << "  " << (char)92 << "         " << (char)92 << "__" << (char)92 << "/ " << (char)92 << "---/ " << (char)92 << "/  /         /  /     " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 5);	cout << "       /  /     " << (char)92 << "   " << (char)92 << "__       " << (char)92 << " ( 0" << (char)92 << " /0 ) /       __/   /      " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 6);	cout << "      /  /       " << (char)92 << "     " << (char)92 << "___    " << (char)92 << " " << (char)92 << "_/|" << (char)92 << "_/ /    ___/     /" << (char)92 << "       " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 7);	cout << "     /  /         " << (char)92 << "_)      " << (char)92 << "___ " << (char)92 << "/-" << (char)92 << "|/-" << (char)92 << "/ ___/      (_/" << (char)92 << " \        " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 8);	cout << "    /  /           /" << (char)92 << "__)       " << (char)92 << "/  oVo  " << (char)92 << "/       (__/     " << (char)92 << "       " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 9);	cout << "   /  /           /,   " << (char)92 << "__)    (_/" << (char)92 << " _ /" << (char)92 << "_)    (__/              " << (char)92 << "  " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 10); cout << "  /  '           //       " << (char)92 << "__)  (__V_V__)  (__/                  " << (char)92 << "  " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 11); cout << " /  '  '        /'           " << (char)92 << "   |{___}|   /         .            " << (char)92 << "  " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 12); cout << "/     /                .      " << (char)92 << "/{_______}" << (char)92 << "/  " << (char)92 << "          " << (char)92 << "          " << (char)92 << "  " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 13); cout << "     /                ,       /{_________}" << (char)92 << "   " << (char)92 << "          " << (char)92 << "   " << (char)92 << "         " << (char)92;
			System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 14); cout << "                     /       /{____/_" << (char)92 << "____}" << (char)92 << "   `          " << (char)92 << "     ";
		}
	}
}
void Borrar_enemigo_mayor(Movimiento*enemigo) {
	for (int i = 0; i < cantidad_de_enemigos; i++) {
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y);		cout << "                                                           ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 1);	cout << "                                                            ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 2);	cout << "                                                             ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 3);	cout << "                                                              ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 4);	cout << "                                                               ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 5);	cout << "                                                                ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 6);	cout << "                                                                 ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 7);	cout << "                                                                  ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 8);	cout << "                                                                   ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 9);	cout << "                                                                    ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 10);cout << "                                                                     ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 11);cout << "                                                                      ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 12);cout << "                                                                       ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 13);cout << "                                                                        ";
		System::Console::SetCursorPosition(enemigo[i].x, enemigo[i].y + 14);cout << "                                                               ";
	}
}
void Mover_enemigo_mayor(Movimiento*enemigo) {
	Borrar_enemigo_mayor(enemigo);
	for (int i = 0; i < cantidad_de_enemigos; i++) {

		if (enemigo[i].y + enemigo[i].dy > 20 || enemigo[i].y + enemigo[i].dy < 5) {
			enemigo[i].dy = -1 * enemigo[i].dy;
		}
		enemigo[i].y += enemigo[i].dy;
	}
	Dibujar_enemigo_mayor(enemigo);
}

void Estadisticas() {
	Banner_marco(65, 36, 1, 4, nivel);
	System::Console::ForegroundColor = System::ConsoleColor::White;
	System::Console::SetCursorPosition(22, 9);	cout << "_   _  _       ___  _   _   _   _";
	System::Console::SetCursorPosition(22, 10); cout << "|) |_ (  | | |  |  |_| | " << (char)92 << " / " << (char)92 << " (";
	System::Console::SetCursorPosition(22, 11);	cout << "|" << (char)92 << " |_ _) |_| |_ |  | | |_/ " << (char)92 << "_/ _)";
	Console::SetCursorPosition(22, 15);
	cout << "Naves restantes:     ";
	if (vidas <= 0) {
		vidas = 0;
		cout << vidas;
	}
	else {
		cout << vidas;
	}
	Console::SetCursorPosition(22, 18);
	cout << "Tiempo Jugado        " << acumulador_tiempo << " seg";
	Console::SetCursorPosition(22, 21);
	cout << "Puntos acumulados:      " << acumulador_puntos;
	Console::SetCursorPosition(24, 24);
	cout << "- Comandantes muertos:  " << cont_comandantes;
	Console::SetCursorPosition(52, 24);	System::Console::ForegroundColor = System::ConsoleColor::DarkGreen;
	cout << "]<o>[";

	Console::SetCursorPosition(24, 26);	System::Console::ForegroundColor = System::ConsoleColor::White;
	cout << "- Mariposas muertas:    " << cont_mariposas;
	Console::SetCursorPosition(52, 26); System::Console::ForegroundColor = System::ConsoleColor::DarkRed;
	cout << ">m<";

	Console::SetCursorPosition(24, 28); 	System::Console::ForegroundColor = System::ConsoleColor::White;
	cout << "- Avispas muertas:      " << cont_avispas;
	Console::SetCursorPosition(52, 28); System::Console::ForegroundColor = System::ConsoleColor::DarkBlue;
	cout << ">a<";

	System::Console::ForegroundColor = System::ConsoleColor::White;
	if (nivel >= 1 && nivel <= 5 && vidas > 0) {
		Console::SetCursorPosition(32, 32); cout << "siguente nivel";
	}
	Console::SetCursorPosition(22, 31); system("pause");
	system("cls");
}
void Tiempo(int Tiempo, Movimiento*nave, Movimiento*comandantes, Movimiento*mariposasT1, Movimiento*mariposasT1circular, Movimiento*mariposasT2, Movimiento*mariposasT3, Movimiento*avispasT1, Movimiento*avispasT4) {
	if (nivel != ultimo_nivel) {
		System::Console::ForegroundColor = System::ConsoleColor::White;
		System::Console::SetCursorPosition(36, 2);	cout << "NIVEL " << nivel;
		System::Console::SetCursorPosition(20, 3);	cout << "Tiempo: ";
		System::Console::SetCursorPosition(3, 3);	cout << "Puntos: ";
		System::Console::SetCursorPosition(11, 3);	cout << "      ";
		System::Console::SetCursorPosition(11, 3);	cout << puntos;

		if (Tiempo % 1000 == 0) {
			segundos--;
			System::Console::SetCursorPosition(28, 3);
			cout << "   "; //borra los segundos antiguos
			if (segundos > 120 && segundos <= 180) {
				System::Console::ForegroundColor = System::ConsoleColor::Green;
			}
			else if (segundos > 60 && segundos <= 120) {
				System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
			}
			else if (segundos >= 0 && segundos <= 60) {
				System::Console::ForegroundColor = System::ConsoleColor::Red;
			}
			System::Console::SetCursorPosition(28, 3);
			cout << segundos;
		}

		if (segundos <= 0) {
			explosion_del_jugador(nave);
			segundos = tiempo_inicial;

			Borrar_comandantes(comandantes);
			Borrar_mariposas_tanda1(mariposasT1);	Borrar_mariposas_t1circular(mariposasT1circular);
			Borrar_mariposas_tanda2(mariposasT2);
			Borrar_mariposas_tanda3(mariposasT3);
			Borrar_avispas(avispasT1);
			Borrar_avispas_tanda4(avispasT4);

		}
		if (vidas == 0) { //Aquí establesco que si los corazones llegan a 0 se pierde y se acaba el juego
			explosion_del_jugador(nave);

			system("cLs");
			Game_Over();
			acumulador_puntos += puntos;
			if (nivel == 1) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 2) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 3) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 4) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 5) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			Estadisticas();
			exit(0);
		}

		else if (puntos >= 2500 && puntos <= 10000) {
			system("cls");
			Win();
			acumulador_puntos += puntos;
			if (nivel == 1) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 2) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 3) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 4) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}
			else if (nivel == 5) {
				acumulador_tiempo += (tiempo_inicial - segundos);
			}

			nivel++;

			if (nivel == 2) {
				puntos = 0;
				segundos = tiempo_inicial;
				system("cls");
				Sleep(1000);
			}
			if (nivel == 3) {
				puntos = 0;
				segundos = tiempo_inicial;
				system("cls");
				Sleep(1000);
			}
			if (nivel == 4) {
				puntos = 0;
				segundos = tiempo_inicial;
				system("cls");
				Sleep(1000);
			}
			if (nivel == 5) {
				puntos = 0;
				segundos = tiempo_inicial;
				system("cls");
				Sleep(1000);
			}
			if (nivel == ultimo_nivel) {
				system("cls");
				Finish();
				Estadisticas();
				exit(0);
			}
		}
	}
}
void velocidad() {
	if (nivel == 1) {
		rapidez = 50;
	}
	else if (nivel == 2) {
		rapidez = 40;
	}
	else if (nivel == 3) {
		rapidez = 30;
	}
	else if (nivel == 4) {
		rapidez = 30;
	}
	else if (nivel == 5) {
		rapidez = 2;
	}
}

void nivel01() {
	cantidad_comandantes = 4;
	cantidad_mariposasT1 = 4;		cantidad_mariposasT1circular = 4;
	cantidad_mariposasT2 = 4;
	cantidad_mariposasT3 = 4;
	cantidad_avispasT1 = 4;
	cantidad_avispasT4 = 4;

	Movimiento*nave = new Movimiento;
	Movimiento*comandantes = new Movimiento[cantidad_comandantes];
	Movimiento*balas_comandantes = new Movimiento[cantidad_comandantes];

	Movimiento*mariposasT1 = new Movimiento[cantidad_mariposasT1];	Movimiento*mariposasT1circular = new Movimiento[cantidad_mariposasT1circular];
	Movimiento*mariposasT2 = new Movimiento[cantidad_mariposasT2];
	Movimiento*mariposasT3 = new Movimiento[cantidad_mariposasT3];

	Movimiento*avispasT1 = new Movimiento[cantidad_avispasT1];
	Movimiento*avispasT4 = new Movimiento[cantidad_avispasT4];
	Movimiento*disparos = new Movimiento[maxdisp];

	Marco(Max_Filas, Max_Columnas, 1, 4, nivel);
	pintar_barra();

	Iniciar_nave(nave);
	int i = 450, dsw = 0, conta_pausa_balas = 0;


	Iniciar_comandantes(comandantes, balas_comandantes, 3);

	Iniciar_mariposas_tanda1(mariposasT1, 5);	Iniciar_mariposas_t1circular(mariposasT1circular);
	Iniciar_mariposas_tanda2(mariposasT2, 3);
	Iniciar_mariposas_tanda3(mariposasT3, 4);

	Iniciar_avispas(avispasT1, 5);
	Iniciar_avispas_tanda4(avispasT4, 5);

	while (true && nivel != ultimo_nivel) {
		if (nivel == 2) {
			break;
		}
		System::Console::CursorVisible = false;
		Dibujar_nave(nave, nivel);
		Mover_mariposas_t1circular(nave, mariposasT1circular);

		if (segundos >= 150 && segundos <= tiempo_inicial) {				//TANDA 1
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
		}
		else if (segundos >= 120 && segundos <= 150) {			//TANDA 2
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);

			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
		}
		else if (segundos >= 90 && segundos <= 120) {			//TANDA 3
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);

			Mover_mariposas_tanda3(nave, mariposasT3, 70, 40, 3);
		}
		else {													//TANDA 4
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
			Mover_mariposas_tanda3(nave, mariposasT3, 70, 38, 3);

			Mover_avispas_tanda4(avispasT4, 70, 37, 3);
		}

		if (_kbhit()) {
			char tecla = _getch();
			Borrar_nave(nave);

			switch (tecla) {
			case 75:
				nave->dx = -1;
				Mover_izquierda_nave(nave, 1);
				break;
			case 77:
				nave->dx = 1;
				Mover_derecha_nave(nave, 72);
				break;
			case 32:
				PlaySound(TEXT("disparodepistola"), NULL, SND_ASYNC);
				if (dsw == 0) {
					if (nave->ndisparos < maxdisp) {
						nave->ndisparos++;
						disparos[nave->ndisparos].x = nave->x + 3;
						disparos[nave->ndisparos].y = nave->y;
						disparos[nave->ndisparos].dx = 0;
						disparos[nave->ndisparos].dy = -1;
						dsw = 1;
					}
				}
				break;
			case 'Z':	case 'z':
				energia--;
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				break;

			case 'G':	case 'g':
				puntos += 1000;
				break;

			case'E':	case 'e':
				if (energia < 15) {
					energia++;
					//comprobar corazones esquina superior izquierda
					System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
					System::Console::SetCursorPosition(1, 1); cout << "  ";
					System::Console::SetCursorPosition(1, 1); cout << energia;
					pintar_barra();
				}
				break;

			}//swith


			pintar_barra();

		}	//fin del kbit


		if (conta_pausa_balas++ > 20) {     //iteracciones 
			dsw = 0; conta_pausa_balas = 0;
		}

		if (nave->ndisparos > 0) {
			for (int cont = 1; cont <= nave->ndisparos; cont++) {
				disparos[cont].x += disparos[cont].dx;
				disparos[cont].y += disparos[cont].dy;

				if (disparos[cont].y > limite_disparo_nave) {
					System::Console::ForegroundColor = System::ConsoleColor::White;
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y); cout << "*";
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}
				else if (disparos[cont].y == limite_disparo_nave || disparos[cont].y == limite_disparo_nave - 1) {
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}

				if (disparos[cont].y > Max_Filas || disparos[cont].y < limite_disparo_nave) {
					disparos[cont] = disparos[nave->ndisparos];
					nave->ndisparos--;
					if (nave->ndisparos < 0) {
						nave->ndisparos = 0;
					}

				}


				for (int i = 0; i <= cantidad_comandantes; i++) {
					if ((disparos[cont].x >= comandantes[i].x  && disparos[cont].x <= comandantes[i].x + 4) &&
						disparos[cont].y == comandantes[i].y && comandantes[i].vivo == true) {

						comandantes[i].vidas_enemigos--;
						if (comandantes[i].vidas_enemigos == 0) {
							PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
							cont_comandantes++;
							puntos += 400;
							balas_comandantes[i].vivo = false;
							comandantes[i].vivo = false;

							if (comandantes[i].enganche == true) {
								Borrar_nave(nave);
								Iniciar_nave(nave);
								Dibujar_nave(nave, nivel);
							}
						}
					}
				}
				//Muertes de Mariposas en las 3 tandas que aparece
				for (int i = 0; i < cantidad_mariposasT1; i++) {
					if ((disparos[cont].x >= mariposasT1[i].x  && disparos[cont].x <= mariposasT1[i].x + 3) &&
						disparos[cont].y == mariposasT1[i].y && mariposasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT1circular; i++) {
					if ((disparos[cont].x >= mariposasT1circular[i].polarx  && disparos[cont].x <= mariposasT1circular[i].polarx + 3) &&
						disparos[cont].y == mariposasT1circular[i].polary && mariposasT1circular[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1circular[i].vivo = false;
					}
				}

				for (int i = 0; i < cantidad_mariposasT2; i++) {
					if ((disparos[cont].x >= mariposasT2[i].x  && disparos[cont].x <= mariposasT2[i].x + 3) &&
						disparos[cont].y == mariposasT2[i].y && mariposasT2[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT2[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT3; i++) {
					if ((disparos[cont].x >= mariposasT3[i].x  && disparos[cont].x <= mariposasT3[i].x + 3) &&
						disparos[cont].y == mariposasT3[i].y && mariposasT3[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT3[i].vivo = false;

					}
				}
				//Muertes de Avispas en las 2 tandas que aparece
				for (int i = 0; i < cantidad_avispasT1; i++) {
					if ((disparos[cont].x >= avispasT1[i].x  && disparos[cont].x <= avispasT1[i].x + 3) &&
						disparos[cont].y == avispasT1[i].y && avispasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_avispasT4; i++) {
					if ((disparos[cont].x >= avispasT4[i].x  && disparos[cont].x <= avispasT4[i].x + 3) &&
						disparos[cont].y == avispasT4[i].y && avispasT4[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT4[i].vivo = false;

					}
				}
			}
		}
		Temporizador += 100;
		Tiempo(Temporizador, nave, comandantes, mariposasT1, mariposasT1circular, mariposasT2, mariposasT3, avispasT1, avispasT4);



		velocidad();
		Sleep(rapidez);
	} ////fin del juego
}
void nivel02() {
	cantidad_comandantes = 4;
	cantidad_mariposasT1 = 4 + adicionales_nivel02;		cantidad_mariposasT1circular = 4 + adicionales_nivel02;
	cantidad_mariposasT2 = 4 + adicionales_nivel02;
	cantidad_mariposasT3 = 4 + adicionales_nivel02;
	cantidad_avispasT1 = 4 + adicionales_nivel02;
	cantidad_avispasT4 = 4 + adicionales_nivel02;

	Movimiento*nave = new Movimiento;
	Movimiento*comandantes = new Movimiento[cantidad_comandantes];
	Movimiento*balas_comandantes = new Movimiento[cantidad_comandantes];

	Movimiento*mariposasT1 = new Movimiento[cantidad_mariposasT1];	Movimiento*mariposasT1circular = new Movimiento[cantidad_mariposasT1circular];
	Movimiento*mariposasT2 = new Movimiento[cantidad_mariposasT2];
	Movimiento*mariposasT3 = new Movimiento[cantidad_mariposasT3];

	Movimiento*avispasT1 = new Movimiento[cantidad_avispasT1];
	Movimiento*avispasT4 = new Movimiento[cantidad_avispasT4];
	Movimiento*disparos = new Movimiento[maxdisp];

	Marco(Max_Filas, Max_Columnas, 1, 4, nivel);
	pintar_barra();

	Iniciar_nave(nave);
	int i = 450, dsw = 0, conta_pausa_balas = 0;


	Iniciar_comandantes(comandantes, balas_comandantes, 3);

	Iniciar_mariposas_tanda1(mariposasT1, 5);	Iniciar_mariposas_t1circular(mariposasT1circular);
	Iniciar_mariposas_tanda2(mariposasT2, 3);
	Iniciar_mariposas_tanda3(mariposasT3, 4);

	Iniciar_avispas(avispasT1, 5);
	Iniciar_avispas_tanda4(avispasT4, 5);

	while (true && nivel != ultimo_nivel) {
		if (nivel == 3) {
			break;
		}
		System::Console::CursorVisible = false;

		Dibujar_nave(nave, nivel);
		Mover_mariposas_t1circular(nave, mariposasT1circular);

		if (segundos >= 150 && segundos <= tiempo_inicial) {				//TANDA 1
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
		}
		else if (segundos >= 120 && segundos <= 150) {			//TANDA 2
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);

			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
		}
		else if (segundos >= 90 && segundos <= 120) {			//TANDA 3
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);

			Mover_mariposas_tanda3(nave, mariposasT3, 70, 40, 3);
		}
		else {													//TANDA 4
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
			Mover_mariposas_tanda3(nave, mariposasT3, 70, 38, 3);

			Mover_avispas_tanda4(avispasT4, 70, 37, 3);
		}

		if (_kbhit()) {
			char tecla = _getch();
			Borrar_nave(nave);

			switch (tecla) {
			case 75:
				nave->dx = -1;
				Mover_izquierda_nave(nave, 1);
				break;
			case 77:
				nave->dx = 1;
				Mover_derecha_nave(nave, 72);
				break;
			case 32:
				PlaySound(TEXT("disparodepistola"), NULL, SND_ASYNC);
				if (dsw == 0) {
					if (nave->ndisparos < maxdisp) {
						nave->ndisparos++;
						disparos[nave->ndisparos].x = nave->x + 3;
						disparos[nave->ndisparos].y = nave->y;
						disparos[nave->ndisparos].dx = 0;
						disparos[nave->ndisparos].dy = -1;
						dsw = 1;
					}
				}
				break;
			case 'Z':	case 'z':
				energia--;
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				break;

			case 'G':	case 'g':
				puntos += 1000;
				break;

			case'E':	case 'e':
				if (energia < 15) {
					energia++;
					//comprobar corazones esquina superior izquierda
					System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
					System::Console::SetCursorPosition(1, 1); cout << "  ";
					System::Console::SetCursorPosition(1, 1); cout << energia;
					pintar_barra();
				}
				break;

			}//swith


			pintar_barra();

		}	//fin del kbit


		if (conta_pausa_balas++ > 15) {
			dsw = 0; conta_pausa_balas = 0;
		}

		if (nave->ndisparos > 0) {
			for (int cont = 1; cont <= nave->ndisparos; cont++) {
				disparos[cont].x += disparos[cont].dx;
				disparos[cont].y += disparos[cont].dy;

				if (disparos[cont].y > limite_disparo_nave) {
					System::Console::ForegroundColor = System::ConsoleColor::White;
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y); cout << "*";
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}
				else if (disparos[cont].y == limite_disparo_nave || disparos[cont].y == limite_disparo_nave - 1) {
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}

				if (disparos[cont].y > Max_Filas || disparos[cont].y < limite_disparo_nave) {
					disparos[cont] = disparos[nave->ndisparos];
					nave->ndisparos--;
					if (nave->ndisparos < 0) {
						nave->ndisparos = 0;
					}

				}


				for (int i = 0; i <= cantidad_comandantes; i++) {
					if ((disparos[cont].x >= comandantes[i].x  && disparos[cont].x <= comandantes[i].x + 4) &&
						disparos[cont].y == comandantes[i].y && comandantes[i].vivo == true) {

						comandantes[i].vidas_enemigos--;
						if (comandantes[i].vidas_enemigos == 0) {
							PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
							cont_comandantes++;
							puntos += 400;
							balas_comandantes[i].vivo = false;
							comandantes[i].vivo = false;

							if (comandantes[i].enganche == true) {
								Borrar_nave(nave);
								Iniciar_nave(nave);
								Dibujar_nave(nave, nivel);
							}
						}
					}
				}
				//Muertes de Mariposas en las 3 tandas que aparece
				for (int i = 0; i < cantidad_mariposasT1; i++) {
					if ((disparos[cont].x >= mariposasT1[i].x  && disparos[cont].x <= mariposasT1[i].x + 3) &&
						disparos[cont].y == mariposasT1[i].y && mariposasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT1circular; i++) {
					if ((disparos[cont].x >= mariposasT1circular[i].polarx  && disparos[cont].x <= mariposasT1circular[i].polarx + 3) &&
						disparos[cont].y == mariposasT1circular[i].polary && mariposasT1circular[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1circular[i].vivo = false;
					}
				}


				for (int i = 0; i < cantidad_mariposasT2; i++) {
					if ((disparos[cont].x >= mariposasT2[i].x  && disparos[cont].x <= mariposasT2[i].x + 3) &&
						disparos[cont].y == mariposasT2[i].y && mariposasT2[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT2[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT3; i++) {
					if ((disparos[cont].x >= mariposasT3[i].x  && disparos[cont].x <= mariposasT3[i].x + 3) &&
						disparos[cont].y == mariposasT3[i].y && mariposasT3[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT3[i].vivo = false;
					}
				}
				//Muertes de Avispas en las 2 tandas que aparece
				for (int i = 0; i < cantidad_avispasT1; i++) {
					if ((disparos[cont].x >= avispasT1[i].x  && disparos[cont].x <= avispasT1[i].x + 3) &&
						disparos[cont].y == avispasT1[i].y && avispasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_avispasT4; i++) {
					if ((disparos[cont].x >= avispasT4[i].x  && disparos[cont].x <= avispasT4[i].x + 3) &&
						disparos[cont].y == avispasT4[i].y && avispasT4[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT4[i].vivo = false;
					}
				}

			}
		}
		Temporizador += 100;
		Tiempo(Temporizador, nave, comandantes, mariposasT1, mariposasT1circular, mariposasT2, mariposasT3, avispasT1, avispasT4);

		velocidad();
		Sleep(rapidez);
	} ////fin del juego
}
void nivel03() {
	cantidad_comandantes = 4;
	cantidad_mariposasT1 = 4 + adicionales_nivel03;		cantidad_mariposasT1circular = 4 + adicionales_nivel03;
	cantidad_mariposasT2 = 4 + adicionales_nivel03;
	cantidad_mariposasT3 = 4 + adicionales_nivel03;
	cantidad_avispasT1 = 4 + adicionales_nivel03;
	cantidad_avispasT4 = 4 + adicionales_nivel03;

	Movimiento*nave = new Movimiento;
	Movimiento*comandantes = new Movimiento[cantidad_comandantes];
	Movimiento*balas_comandantes = new Movimiento[cantidad_comandantes];

	Movimiento*mariposasT1 = new Movimiento[cantidad_mariposasT1];	Movimiento*mariposasT1circular = new Movimiento[cantidad_mariposasT1circular];
	Movimiento*mariposasT2 = new Movimiento[cantidad_mariposasT2];
	Movimiento*mariposasT3 = new Movimiento[cantidad_mariposasT3];

	Movimiento*avispasT1 = new Movimiento[cantidad_avispasT1];
	Movimiento*avispasT4 = new Movimiento[cantidad_avispasT4];
	Movimiento*disparos = new Movimiento[maxdisp];

	Marco(Max_Filas, Max_Columnas, 1, 4, nivel);
	pintar_barra();

	Iniciar_nave(nave);
	int i = 450, dsw = 0, conta_pausa_balas = 0;


	Iniciar_comandantes(comandantes, balas_comandantes, 3);

	Iniciar_mariposas_tanda1(mariposasT1, 5);	Iniciar_mariposas_t1circular(mariposasT1circular);
	Iniciar_mariposas_tanda2(mariposasT2, 3);
	Iniciar_mariposas_tanda3(mariposasT3, 4);

	Iniciar_avispas(avispasT1, 5);
	Iniciar_avispas_tanda4(avispasT4, 5);

	while (true && nivel != ultimo_nivel) {
		if (nivel == 4) {
			break;
		}
		System::Console::CursorVisible = false;

		Dibujar_nave(nave, nivel);
		Mover_mariposas_t1circular(nave, mariposasT1circular);

		if (segundos >= 150 && segundos <= tiempo_inicial) {				//TANDA 1
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
		}
		else if (segundos >= 120 && segundos <= 150) {			//TANDA 2
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);

			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
		}
		else if (segundos >= 90 && segundos <= 120) {			//TANDA 3
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);

			Mover_mariposas_tanda3(nave, mariposasT3, 70, 40, 3);
		}
		else {													//TANDA 4
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
			Mover_mariposas_tanda3(nave, mariposasT3, 70, 38, 3);

			Mover_avispas_tanda4(avispasT4, 70, 37, 3);
		}

		if (_kbhit()) {
			char tecla = _getch();
			Borrar_nave(nave);

			switch (tecla) {
			case 75:
				nave->dx = -1;
				Mover_izquierda_nave(nave, 1);
				break;
			case 77:
				nave->dx = 1;
				Mover_derecha_nave(nave, 72);
				break;
			case 32:
				PlaySound(TEXT("disparodepistola"), NULL, SND_ASYNC);
				if (dsw == 0) {
					if (nave->ndisparos < maxdisp) {
						nave->ndisparos++;
						disparos[nave->ndisparos].x = nave->x + 3;
						disparos[nave->ndisparos].y = nave->y;
						disparos[nave->ndisparos].dx = 0;
						disparos[nave->ndisparos].dy = -1;
						dsw = 1;
					}
				}
				break;
			case 'Z':	case 'z':
				energia--;
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				break;

			case 'G':	case 'g':
				puntos += 1000;
				break;

			case'E':	case 'e':
				if (energia < 15) {
					energia++;
					//comprobar corazones esquina superior izquierda
					System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
					System::Console::SetCursorPosition(1, 1); cout << "  ";
					System::Console::SetCursorPosition(1, 1); cout << energia;
					pintar_barra();
				}
				break;

			}//swith


			pintar_barra();

		}	//fin del kbit


		if (conta_pausa_balas++ > 10) {
			dsw = 0; conta_pausa_balas = 0;
		}

		if (nave->ndisparos > 0) {
			for (int cont = 1; cont <= nave->ndisparos; cont++) {
				disparos[cont].x += disparos[cont].dx;
				disparos[cont].y += disparos[cont].dy;

				if (disparos[cont].y > limite_disparo_nave) {
					System::Console::ForegroundColor = System::ConsoleColor::White;
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y); cout << "*";
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}
				else if (disparos[cont].y == limite_disparo_nave || disparos[cont].y == limite_disparo_nave - 1) {
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}

				if (disparos[cont].y > Max_Filas || disparos[cont].y < limite_disparo_nave) {
					disparos[cont] = disparos[nave->ndisparos];
					nave->ndisparos--;
					if (nave->ndisparos < 0) {
						nave->ndisparos = 0;
					}

				}


				for (int i = 0; i <= cantidad_comandantes; i++) {
					if ((disparos[cont].x >= comandantes[i].x  && disparos[cont].x <= comandantes[i].x + 4) &&
						disparos[cont].y == comandantes[i].y && comandantes[i].vivo == true) {

						comandantes[i].vidas_enemigos--;
						if (comandantes[i].vidas_enemigos == 0) {
							PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
							cont_comandantes++;
							puntos += 400;
							balas_comandantes[i].vivo = false;
							comandantes[i].vivo = false;

							if (comandantes[i].enganche == true) {
								Borrar_nave(nave);
								Iniciar_nave(nave);
								Dibujar_nave(nave, nivel);
							}
						}
					}
				}
				//Muertes de Mariposas en las 3 tandas que aparece
				for (int i = 0; i < cantidad_mariposasT1; i++) {
					if ((disparos[cont].x >= mariposasT1[i].x  && disparos[cont].x <= mariposasT1[i].x + 3) &&
						disparos[cont].y == mariposasT1[i].y && mariposasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT1circular; i++) {
					if ((disparos[cont].x >= mariposasT1circular[i].polarx  && disparos[cont].x <= mariposasT1circular[i].polarx + 3) &&
						disparos[cont].y == mariposasT1circular[i].polary && mariposasT1circular[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1circular[i].vivo = false;
					}
				}


				for (int i = 0; i < cantidad_mariposasT2; i++) {
					if ((disparos[cont].x >= mariposasT2[i].x  && disparos[cont].x <= mariposasT2[i].x + 3) &&
						disparos[cont].y == mariposasT2[i].y && mariposasT2[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT2[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT3; i++) {
					if ((disparos[cont].x >= mariposasT3[i].x  && disparos[cont].x <= mariposasT3[i].x + 3) &&
						disparos[cont].y == mariposasT3[i].y && mariposasT3[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT3[i].vivo = false;
					}
				}
				//Muertes de Avispas en las 2 tandas que aparece
				for (int i = 0; i < cantidad_avispasT1; i++) {
					if ((disparos[cont].x >= avispasT1[i].x  && disparos[cont].x <= avispasT1[i].x + 3) &&
						disparos[cont].y == avispasT1[i].y && avispasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_avispasT4; i++) {
					if ((disparos[cont].x >= avispasT4[i].x  && disparos[cont].x <= avispasT4[i].x + 3) &&
						disparos[cont].y == avispasT4[i].y && avispasT4[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT4[i].vivo = false;
					}
				}
			}
		}
		Temporizador += 100;
		Tiempo(Temporizador, nave, comandantes, mariposasT1, mariposasT1circular, mariposasT2, mariposasT3, avispasT1, avispasT4);

		velocidad();
		Sleep(rapidez);
	} ////fin del juego
}
void nivel04() {
	cantidad_comandantes = 4;
	cantidad_mariposasT1 = 4 + adicionales_nivel04;		cantidad_mariposasT1circular = 4 + adicionales_nivel04;
	cantidad_mariposasT2 = 4 + adicionales_nivel04;
	cantidad_mariposasT3 = 4 + adicionales_nivel04;
	cantidad_avispasT1 = 4 + adicionales_nivel04;
	cantidad_avispasT4 = 4 + adicionales_nivel04;

	Movimiento*nave = new Movimiento;
	Movimiento*comandantes = new Movimiento[cantidad_comandantes];
	Movimiento*balas_comandantes = new Movimiento[cantidad_comandantes];

	Movimiento*mariposasT1 = new Movimiento[cantidad_mariposasT1];	Movimiento*mariposasT1circular = new Movimiento[cantidad_mariposasT1circular];
	Movimiento*mariposasT2 = new Movimiento[cantidad_mariposasT2];
	Movimiento*mariposasT3 = new Movimiento[cantidad_mariposasT3];

	Movimiento*avispasT1 = new Movimiento[cantidad_avispasT1];
	Movimiento*avispasT4 = new Movimiento[cantidad_avispasT4];
	Movimiento*disparos = new Movimiento[maxdisp];

	Marco(Max_Filas, Max_Columnas, 1, 4, nivel);
	pintar_barra();

	Iniciar_nave(nave);
	int i = 450, dsw = 0, conta_pausa_balas = 0;


	Iniciar_comandantes(comandantes, balas_comandantes, 3);

	Iniciar_mariposas_tanda1(mariposasT1, 5);	Iniciar_mariposas_t1circular(mariposasT1circular);
	Iniciar_mariposas_tanda2(mariposasT2, 3);
	Iniciar_mariposas_tanda3(mariposasT3, 4);

	Iniciar_avispas(avispasT1, 5);
	Iniciar_avispas_tanda4(avispasT4, 5);

	while (true && nivel != ultimo_nivel) {
		if (nivel == 5) {
			break;
		}
		System::Console::CursorVisible = false;

		Dibujar_nave(nave, nivel);
		Mover_mariposas_t1circular(nave, mariposasT1circular);

		if (segundos >= 150 && segundos <= tiempo_inicial) {				//TANDA 1
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
		}
		else if (segundos >= 120 && segundos <= 150) {			//TANDA 2
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);

			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
		}
		else if (segundos >= 90 && segundos <= 120) {			//TANDA 3
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);

			Mover_mariposas_tanda3(nave, mariposasT3, 70, 40, 3);
		}
		else {													//TANDA 4
			Mover_mariposas_tanda1(nave, mariposasT1, 70, 38, 36);
			Mover_avispas(avispasT1, 40, 37, 3);
			Mover_comandantes(nave, balas_comandantes, 1, 38, comandantes, 41);
			Mover_mariposas_tanda2(mariposasT2, 70, 38, 3);
			Mover_mariposas_tanda3(nave, mariposasT3, 70, 38, 3);

			Mover_avispas_tanda4(avispasT4, 70, 37, 3);
		}

		if (_kbhit()) {
			char tecla = _getch();
			Borrar_nave(nave);

			switch (tecla) {
			case 75:
				nave->dx = -1;
				Mover_izquierda_nave(nave, 1);
				break;
			case 77:
				nave->dx = 1;
				Mover_derecha_nave(nave, 72);
				break;
			case 32:
				PlaySound(TEXT("disparodepistola"), NULL, SND_ASYNC);
				if (dsw == 0) {
					if (nave->ndisparos < maxdisp) {
						nave->ndisparos++;
						disparos[nave->ndisparos].x = nave->x + 3;
						disparos[nave->ndisparos].y = nave->y;
						disparos[nave->ndisparos].dx = 0;
						disparos[nave->ndisparos].dy = -1;
						dsw = 1;
					}
				}
				break;
			case 'Z':	case 'z':
				energia--;
				if (energia <= 0) {
					PlaySound(TEXT("explosion"), NULL, SND_ASYNC);
					explosion_del_jugador(nave);
				}
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				break;

			case 'G':	case 'g':
				puntos += 1000;
				break;

			case'E':	case 'e':
				if (energia < 15) {
					energia++;
					//comprobar corazones esquina superior izquierda
					System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
					System::Console::SetCursorPosition(1, 1); cout << "  ";
					System::Console::SetCursorPosition(1, 1); cout << energia;
					pintar_barra();
				}
				break;

			}//swith
			pintar_barra();
		}	//fin del kbit
		if (conta_pausa_balas++ > 10) {
			dsw = 0; conta_pausa_balas = 0;
		}

		if (nave->ndisparos > 0) {
			for (int cont = 1; cont <= nave->ndisparos; cont++) {
				disparos[cont].x += disparos[cont].dx;
				disparos[cont].y += disparos[cont].dy;

				if (disparos[cont].y > limite_disparo_nave) {
					System::Console::ForegroundColor = System::ConsoleColor::White;
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y); cout << "*";
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}
				else if (disparos[cont].y == limite_disparo_nave || disparos[cont].y == limite_disparo_nave - 1) {
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}

				if (disparos[cont].y > Max_Filas || disparos[cont].y < limite_disparo_nave) {
					disparos[cont] = disparos[nave->ndisparos];
					nave->ndisparos--;
					if (nave->ndisparos < 0) {
						nave->ndisparos = 0;
					}

				}


				for (int i = 0; i <= cantidad_comandantes; i++) {
					if ((disparos[cont].x >= comandantes[i].x  && disparos[cont].x <= comandantes[i].x + 4) &&
						disparos[cont].y == comandantes[i].y && comandantes[i].vivo == true) {

						comandantes[i].vidas_enemigos--;
						if (comandantes[i].vidas_enemigos == 0) {
							PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
							cont_comandantes++;
							puntos += 400;
							balas_comandantes[i].vivo = false;
							comandantes[i].vivo = false;

							if (comandantes[i].enganche == true) {
								Borrar_nave(nave);
								Iniciar_nave(nave);
								Dibujar_nave(nave, nivel);
							}
						}
					}
				}
				//Muertes de Mariposas en las 3 tandas que aparece
				for (int i = 0; i < cantidad_mariposasT1; i++) {
					if ((disparos[cont].x >= mariposasT1[i].x  && disparos[cont].x <= mariposasT1[i].x + 3) &&
						disparos[cont].y == mariposasT1[i].y && mariposasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT1circular; i++) {
					if ((disparos[cont].x >= mariposasT1circular[i].polarx  && disparos[cont].x <= mariposasT1circular[i].polarx + 3) &&
						disparos[cont].y == mariposasT1circular[i].polary && mariposasT1circular[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT1circular[i].vivo = false;
					}
				}


				for (int i = 0; i < cantidad_mariposasT2; i++) {
					if ((disparos[cont].x >= mariposasT2[i].x  && disparos[cont].x <= mariposasT2[i].x + 3) &&
						disparos[cont].y == mariposasT2[i].y && mariposasT2[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT2[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_mariposasT3; i++) {
					if ((disparos[cont].x >= mariposasT3[i].x  && disparos[cont].x <= mariposasT3[i].x + 3) &&
						disparos[cont].y == mariposasT3[i].y && mariposasT3[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_mariposas++;
						puntos += 160;
						mariposasT3[i].vivo = false;
					}
				}
				//Muertes de Avispas en las 2 tandas que aparece
				for (int i = 0; i < cantidad_avispasT1; i++) {
					if ((disparos[cont].x >= avispasT1[i].x  && disparos[cont].x <= avispasT1[i].x + 3) &&
						disparos[cont].y == avispasT1[i].y && avispasT1[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT1[i].vivo = false;
					}
				}
				for (int i = 0; i < cantidad_avispasT4; i++) {
					if ((disparos[cont].x >= avispasT4[i].x  && disparos[cont].x <= avispasT4[i].x + 3) &&
						disparos[cont].y == avispasT4[i].y && avispasT4[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						cont_avispas++;
						puntos += 100;
						avispasT4[i].vivo = false;
					}
				}

			}
		}
		Temporizador += 100;
		Tiempo(Temporizador, nave, comandantes, mariposasT1, mariposasT1circular, mariposasT2, mariposasT3, avispasT1, avispasT4);

		velocidad();
		Sleep(rapidez);
	} ////fin del juego
}
void nivel05() {
	cantidad_comandantes = 4;
	cantidad_mariposasT1 = 4 + adicionales_nivel04;		cantidad_mariposasT1circular = 4 + adicionales_nivel04;
	cantidad_mariposasT2 = 4 + adicionales_nivel04;
	cantidad_mariposasT3 = 4 + adicionales_nivel04;
	cantidad_avispasT1 = 4 + adicionales_nivel04;
	cantidad_avispasT4 = 4 + adicionales_nivel04;

	cantidad_de_enemigos = 1;

	Movimiento*nave = new Movimiento;
	Movimiento*comandantes = new Movimiento[cantidad_comandantes];
	Movimiento*balas_comandantes = new Movimiento[cantidad_comandantes];

	Movimiento*mariposasT1 = new Movimiento[cantidad_mariposasT1];	Movimiento*mariposasT1circular = new Movimiento[cantidad_mariposasT1circular];
	Movimiento*mariposasT2 = new Movimiento[cantidad_mariposasT2];
	Movimiento*mariposasT3 = new Movimiento[cantidad_mariposasT3];

	Movimiento*avispasT1 = new Movimiento[cantidad_avispasT1];
	Movimiento*avispasT4 = new Movimiento[cantidad_avispasT4];
	Movimiento*disparos = new Movimiento[maxdisp];

	Movimiento*enemigo = new Movimiento[cantidad_de_enemigos];

	Marco(Max_Filas, Max_Columnas, 1, 4, nivel);
	pintar_barra();

	Iniciar_nave(nave);
	int i = 450, dsw = 0, conta_pausa_balas = 0;
	Inciar_enemigo_mayor(enemigo);

	while (true && nivel != ultimo_nivel) {
		if (nivel == 6) {
			break;
		}
		System::Console::CursorVisible = false;

		Dibujar_nave(nave, nivel);
		Mover_enemigo_mayor(enemigo);

		if (_kbhit()) {
			char tecla = _getch();
			Borrar_nave(nave);

			switch (tecla) {
			case 75:
				nave->dx = -1;
				Mover_izquierda_nave(nave, 1);
				break;
			case 77:
				nave->dx = 1;
				Mover_derecha_nave(nave, 72);
				break;
			case 32:
				PlaySound(TEXT("disparodepistola"), NULL, SND_ASYNC);
				if (dsw == 0) {
					if (nave->ndisparos < maxdisp) {
						nave->ndisparos++;
						disparos[nave->ndisparos].x = nave->x + 3;
						disparos[nave->ndisparos].y = nave->y;
						disparos[nave->ndisparos].dx = 0;
						disparos[nave->ndisparos].dy = -1;
						dsw = 1;
					}
				}
				break;
			case 'Z':	case 'z':
				energia--;
				if (energia <= 0) {
					explosion_del_jugador(nave);
				}
				System::Console::SetCursorPosition(1, 1); cout << "  ";
				System::Console::SetCursorPosition(1, 1); cout << energia;
				break;

			case 'G':	case 'g':
				puntos += 1000;
				break;

			case'E':	case 'e':
				if (energia < 15) {
					energia++;
					//comprobar corazones esquina superior izquierda
					System::Console::ForegroundColor = System::ConsoleColor::DarkYellow;
					System::Console::SetCursorPosition(1, 1); cout << "  ";
					System::Console::SetCursorPosition(1, 1); cout << energia;
					pintar_barra();
				}
				break;

			}//swith
			pintar_barra();
		}	//fin del kbit
		if (conta_pausa_balas++ > 10) {
			dsw = 0; conta_pausa_balas = 0;
		}

		if (nave->ndisparos > 0) {
			for (int cont = 1; cont <= nave->ndisparos; cont++) {
				disparos[cont].x += disparos[cont].dx;
				disparos[cont].y += disparos[cont].dy;

				if (disparos[cont].y > limite_disparo_nave) {
					System::Console::ForegroundColor = System::ConsoleColor::White;
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y); cout << "*";
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}
				else if (disparos[cont].y == limite_disparo_nave || disparos[cont].y == limite_disparo_nave - 1) {
					System::Console::SetCursorPosition(disparos[cont].x, disparos[cont].y + 1); cout << " ";
				}

				if (disparos[cont].y > Max_Filas || disparos[cont].y < limite_disparo_nave) {
					disparos[cont] = disparos[nave->ndisparos];
					nave->ndisparos--;
					if (nave->ndisparos < 0) {
						nave->ndisparos = 0;
					}

				}

				for (int i = 0; i < cantidad_de_enemigos; i++) {
					if ((disparos[cont].y == enemigo[i].y + 7) &&
						(disparos[cont].x >= enemigo[i].x + 30 && disparos[cont].x <= enemigo[i].x + 40) && enemigo[i].vivo == true) {
						PlaySound(TEXT("Coin"), NULL, SND_ASYNC);
						enemigo[i].vidas_enemigos--;
						puntos += 250;

						if (enemigo[i].vidas_enemigos <= 0) {
							PlaySound(TEXT("EXPLOBIG"), NULL, SND_ASYNC | SND_LOOP);
							enemigo[i].vivo = false;
							Borrar_enemigo_mayor(enemigo);
							Sleep(3000);
						}
					}
				}
			}
		}
		Temporizador += 100;
		Tiempo(Temporizador, nave, comandantes, mariposasT1, mariposasT1circular, mariposasT2, mariposasT3, avispasT1, avispasT4);

		velocidad();
		Sleep(rapidez);

	}////fin del juego
}

void Juego() {
	if (nivel == 1) {
		nivel01();		//Incia el Juego primer nivel
		Estadisticas();
	}
	if (nivel == 2) {
		nivel02();
		Estadisticas();
	}
	if (nivel == 3) {
		nivel03();
		Estadisticas();
	}
	if (nivel == 4) {
		nivel04();
		Estadisticas();
	}
	if (nivel == 5) {
		nivel05();
		Estadisticas();
	}
	if (nivel == 6) {
		exit(0);
	}
}

bool esNumerico(string linea) {
	bool b = true;
	int longitud = linea.size();

	if (longitud == 0) { // Cuando el usuario pulsa ENTER
		b = false;
	}
	else if (longitud == 1 && !isdigit(linea[0])) {
		b = false;
	}
	else {
		int i;
		if (linea[0] == '+' || linea[0] == '-')
			i = 1;
		else
			i = 0;

		while (i < longitud) {
			if (!isdigit(linea[i])) {
				b = false;
				break;
			}
			i++;
		}
	}

	return b;
}
void Menu() {
	string opcion_menu_principal;
	string opcion_comenzar_juego;
	string opcion_instrucciones;
	string opcion_descripcion;

	int opcion_menu1;
	int opcion_menu2;
	int opcion_menu3;
	int opcion_menu4;

	bool repite = true;

	while (1) {

		Menu_principal();
		do {
			System::Console::SetCursorPosition(30, 20); cout << "Ingrese opcion: "; getline(cin, opcion_menu_principal);
			if (esNumerico(opcion_menu_principal)) {
				opcion_menu1 = atoi(opcion_menu_principal.c_str());
				if (opcion_menu1 >= 1 && opcion_menu1 <= 3) {
					system("cls");
					repite = false;
				}
				else {
					system("cls");
					repite = true;
					Menu_principal();
				}
			}
			else {
				system("cls");
				repite = true;
				Menu_principal();
			}
		} while (repite);

		switch (opcion_menu1) {
		case 1:
			Comenzar_juego();
			do {
				System::Console::SetCursorPosition(30, 20); cout << "Ingrese opcion: "; getline(cin, opcion_comenzar_juego);
				if (esNumerico(opcion_comenzar_juego)) {
					opcion_menu2 = atoi(opcion_comenzar_juego.c_str());
					if (opcion_menu2 >= 1 && opcion_menu2 <= 2) {
						system("cls");
						repite = false;
					}
					else {
						system("cls");
						repite = true;
						Comenzar_juego();
					}
				}
				else {
					system("cls");
					repite = true;
					Comenzar_juego();
				}
			} while (repite);

			switch (opcion_menu2) {
			case 1:
				PlaySound(TEXT("Intro.wav"), NULL, SND_ASYNC);
				System::Console::ForegroundColor = System::ConsoleColor::Red; Sleep(200); Historia();
				System::Console::ForegroundColor = System::ConsoleColor::Cyan; Sleep(300); Historia();
				System::Console::ForegroundColor = System::ConsoleColor::Magenta; Sleep(300); Historia();
				System::Console::SetCursorPosition(22, 27); 	System::Console::ForegroundColor = System::ConsoleColor::White;
				system("pause");

				system("cls");
				Juego();
				break;

			case 2:
				system("cls");
				break;
			default:
				break;
			}
			break;
		case 2:
			Instrucciones();
			do {
				System::Console::SetCursorPosition(32, 33); cout << "Ingrese opcion: "; getline(cin, opcion_instrucciones);
				if (esNumerico(opcion_instrucciones)) {
					opcion_menu3 = atoi(opcion_instrucciones.c_str());
					if (opcion_menu3 == 1) {
						system("cls");
						repite = false;
					}
					else {
						system("cls");
						repite = true;
						Instrucciones();
					}
				}
				else {
					system("cls");
					repite = true;
					Instrucciones();
				}
			} while (repite);
			break;

		case 3:
			Descripcion();
			do {
				System::Console::SetCursorPosition(32, 33); cout << "Ingrese opcion: "; getline(cin, opcion_descripcion);
				if (esNumerico(opcion_descripcion)) {
					opcion_menu4 = atoi(opcion_descripcion.c_str());
					if (opcion_menu4 == 1) {
						system("cls");
						repite = false;
					}
					else {
						system("cls");
						repite = true;
						Descripcion();
					}
				}
				else {
					system("cls");
					repite = true;
					Descripcion();
				}
			} while (repite);
			break;
		default:
			break;
		}
	}
}

int main() {
	srand(time_t(NULL));
	System::Console::CursorVisible = false;
	System::Console::SetWindowSize(Max_Filas, Max_Columnas);   //TAMANO DE PANTALLA

   Portada();
    system("cls");
	Menu();

	_getch();
}