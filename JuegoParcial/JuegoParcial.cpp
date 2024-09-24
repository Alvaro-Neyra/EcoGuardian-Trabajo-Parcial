#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include "Juego.h"

#define WIDTH Console::WindowWidth
#define HEIGHT Console::WindowHeight

using namespace System;
using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

int main() {
	srand(time(NULL));
	Console::SetWindowSize(WIDTH, HEIGHT);
	Console::CursorVisible = false;
	Juego* juego = new Juego();
	system("cls");
	juego->iniciar();
	delete juego;
	_getch();
    return 0;
}