#include "pch.h"
#include <iostream>
#include "Agua.h"

using namespace System;

// Constructor de Agua
Agua::Agua(int _id, int _x, int _y, bool _visible,bool recogido, float _purezaDelAgua, int _cantidadBotella)
    : Recurso(_id, _x, _y, _visible, recogido) {
    purezaDelAgua = _purezaDelAgua;
    cantidadBotella = _cantidadBotella;
    alto = 7;
    ancho = 10;
}

Agua::~Agua() {}

float Agua::getPurezaDelAgua() {
    return purezaDelAgua;
}

void Agua::setPurezaDelAgua(float _purezaDelAgua) {
    purezaDelAgua = _purezaDelAgua;
}

int Agua::getCantidadBotella() {
    return cantidadBotella;
}

void Agua::setCantidadBotella(int _cantidadBotella) {
    cantidadBotella = _cantidadBotella;
}

void Agua::dibujar() {
    int x = getX();
    int y = getY();
    Console::ForegroundColor = ConsoleColor::Gray;
    Console::SetCursorPosition(x, y + 1);   cout << " @@@@@@ ";
    Console::SetCursorPosition(x, y + 2);   cout << "@"; Console::ForegroundColor = ConsoleColor::Blue; cout << "######"; Console::ForegroundColor = ConsoleColor::Gray; cout << "@";
    Console::SetCursorPosition(x, y + 3);   cout << "@@@@@@@@";
    Console::SetCursorPosition(x, y + 4);   cout << "@      @";
    Console::SetCursorPosition(x, y + 5);   cout << "@      @";
    Console::SetCursorPosition(x, y + 6);   cout << "@      @";
    Console::SetCursorPosition(x, y + 7);   cout << " @@@@@@ ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Agua::borrar() {
    int x = getX();
    int y = getY();
    Console::SetCursorPosition(x, y + 1);   cout << "        ";
    Console::SetCursorPosition(x, y + 2);   cout << "        ";
    Console::SetCursorPosition(x, y + 3);   cout << "        ";
    Console::SetCursorPosition(x, y + 4);   cout << "        ";
    Console::SetCursorPosition(x, y + 5);   cout << "        ";
    Console::SetCursorPosition(x, y + 6);   cout << "        ";
    Console::SetCursorPosition(x, y + 7);   cout << "        ";
}

void Agua::descripcion() {
    cout << "Descripción del recurso Agua: Pureza del agua: " << purezaDelAgua << "%, Cantidad en botella: " << cantidadBotella << "ml." << endl;
}
