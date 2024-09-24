#include "pch.h"
#include "ResiduosReciclables.h"
#include <iostream>

using namespace std;

// Constructor
ResiduosReciclables::ResiduosReciclables(int id, int x, int y, bool visible, bool _recogido, int _tipoResiduo)
    : Recurso(id, x, y, visible, _recogido), tipo(_tipoResiduo) {
    if (tipo == 1) {
        ancho = 19;
        alto = 11;
    }
    else if (tipo == 2) {
        ancho = 10;
        alto = 10;
    }
}

// Destructor
ResiduosReciclables::~ResiduosReciclables() {}

// Getters y Setters
int ResiduosReciclables::getTipo() {
    return tipo;
}

void ResiduosReciclables::setTipo(int _tipoResiduo) {
    tipo = _tipoResiduo;
}

// Métodos propios
void ResiduosReciclables::verificarTipo() {
    cout << "Verificando el tipo de residuo." << std::endl;
}

void ResiduosReciclables::descontaminarAmbiente() {
    cout << "Ambiente descontaminado con éxito." << std::endl;
}

// Métodos polimórficos
void ResiduosReciclables::dibujar() {
    if (tipo == 1) {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(x, y + 1);  cout << "            @    ";
        Console::SetCursorPosition(x, y + 2);  cout << "  @@@    @@      ";
        Console::SetCursorPosition(x, y + 3);  cout << "@@     @@ @      ";
        Console::SetCursorPosition(x, y + 4);  cout << "@%@ @   @@@%     ";
        Console::SetCursorPosition(x, y + 5);  cout << "  @ @@@@   @@    ";
        Console::SetCursorPosition(x, y + 6);  cout << "   @  @@@@  @    ";
        Console::SetCursorPosition(x, y + 7);  cout << "   @    @@@@ @@@ ";
        Console::SetCursorPosition(x, y + 8);  cout << "   @@    @@@@@@@@";
        Console::SetCursorPosition(x, y + 8);  cout << "    @    @@@ @@  ";
        Console::SetCursorPosition(x, y + 10); cout << "     @ @@@@@     ";
        Console::SetCursorPosition(x, y + 11); cout << "       @         ";
        Console::ForegroundColor = ConsoleColor::White;
    }
    else if (tipo == 2) {
        Console::ForegroundColor = ConsoleColor::Gray;
        Console::SetCursorPosition(x, y + 1); cout << "@@@      @@@ ";
        Console::SetCursorPosition(x, y + 2); cout << "@@@      @@@ ";
        Console::SetCursorPosition(x, y + 3); cout << "@@@@@@@@@@@@ ";
        Console::SetCursorPosition(x, y + 4); cout << "@@@@@@@@@@@@ ";
        Console::SetCursorPosition(x, y + 5); cout << "@@@@@@@@@@@@ ";
        Console::SetCursorPosition(x, y + 6); cout << "@@@@@@@@@@@@ ";
        Console::ForegroundColor = ConsoleColor::White;
    }
}

void ResiduosReciclables::borrar() {
    if (tipo == 1) {
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(x, y + 1);  cout << "                 ";
        Console::SetCursorPosition(x, y + 2);  cout << "                 ";
        Console::SetCursorPosition(x, y + 3);  cout << "                 ";
        Console::SetCursorPosition(x, y + 4);  cout << "                 ";
        Console::SetCursorPosition(x, y + 5);  cout << "                 ";
        Console::SetCursorPosition(x, y + 6);  cout << "                 ";
        Console::SetCursorPosition(x, y + 7);  cout << "                 ";
        Console::SetCursorPosition(x, y + 8);  cout << "                 ";
        Console::SetCursorPosition(x, y + 8);  cout << "                 ";
        Console::SetCursorPosition(x, y + 10); cout << "                 ";
        Console::SetCursorPosition(x, y + 11); cout << "                 ";
        Console::ForegroundColor = ConsoleColor::White;
    }
    else if (tipo == 2) {
        Console::ForegroundColor = ConsoleColor::DarkCyan;
        Console::SetCursorPosition(x, y + 1); cout << "             ";
        Console::SetCursorPosition(x, y + 2); cout << "             ";
        Console::SetCursorPosition(x, y + 3); cout << "             ";
        Console::SetCursorPosition(x, y + 4); cout << "             ";
        Console::SetCursorPosition(x, y + 5); cout << "             ";
        Console::SetCursorPosition(x, y + 6); cout << "             ";
        Console::ForegroundColor = ConsoleColor::White;
    }
}

void ResiduosReciclables::descripcion() {
    cout << "Residuos reciclables de tipo " << getTipo() << "." << std::endl;
}
