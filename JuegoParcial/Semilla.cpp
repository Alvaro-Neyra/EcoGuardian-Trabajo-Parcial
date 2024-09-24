#include "pch.h"
#include "Semilla.h"
#include <iostream>

// Constructor
Semilla::Semilla(int id, int x, int y, bool visible, bool recogido, int _especie)
    : Recurso(id, x, y, visible, recogido), especie(_especie) {
    if (especie == 1) {
        ancho = 12;
        alto = 7;
    }
    else if (especie == 2) {
        ancho = 23;
        alto = 6;
    }
}

// Destructor
Semilla::~Semilla() {}

// Getters y Setters
int Semilla::getTipo() {
    return especie;
}

void Semilla::setTipo(int _especie) {
    especie = _especie;
}

// Métodos propios
void Semilla::verificarEspecie() {
    cout << "Verificando la especie de la semilla." << std::endl;
}

void Semilla::plantarSemilla() {
    cout << "Semilla plantada exitosamente." << std::endl;
}

// Métodos polimórficos
void Semilla::dibujar() {
    if (this->especie == 1) {
        Console::ForegroundColor = ConsoleColor::DarkGreen;
        Console::SetCursorPosition(x, y + 1); cout << "   @@@@@  ";
        Console::SetCursorPosition(x, y + 2); cout << "  @@    @@";
        Console::SetCursorPosition(x, y + 3); cout << "  @@@   @@";
        Console::SetCursorPosition(x, y + 4); cout << " @@@@   @@";
        Console::SetCursorPosition(x, y + 5); cout << "@@      @@";
        Console::SetCursorPosition(x, y + 6); cout << "@@    @@@ ";
        Console::SetCursorPosition(x, y + 7); cout << " @@@@@@   ";
        Console::ForegroundColor = ConsoleColor::White;
    }
    else if (especie == 2) {
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(x, y + 1); cout << "         -----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "==== = ";
        Console::SetCursorPosition(x, y + 2); Console::ForegroundColor = ConsoleColor::Green;  cout << " -----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "======";  Console::ForegroundColor = ConsoleColor::Green; cout << "--"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "====== ";
        Console::SetCursorPosition(x, y + 3); Console::ForegroundColor = ConsoleColor::Green; cout << "-------"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "======";  Console::ForegroundColor = ConsoleColor::Green;  cout << "-"; Console::ForegroundColor = ConsoleColor::Cyan;  Console::ForegroundColor = ConsoleColor::Green; cout << "=======";
        Console::SetCursorPosition(x, y + 4); Console::ForegroundColor = ConsoleColor::Green; cout << "------"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=============  ";
        Console::SetCursorPosition(x, y + 5); Console::ForegroundColor = ConsoleColor::Green; cout << "  ----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=";  Console::ForegroundColor = ConsoleColor::Green; cout << "----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=====     ";
        Console::SetCursorPosition(x, y + 6); Console::ForegroundColor = ConsoleColor::Green; cout << "       ----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=====     ";
        Console::ForegroundColor = ConsoleColor::White;
    }
}

void Semilla::borrar() {
    if (this->especie == 1) {
        Console::SetCursorPosition(x, y + 1); cout << "          ";
        Console::SetCursorPosition(x, y + 2); cout << "          ";
        Console::SetCursorPosition(x, y + 3); cout << "          ";
        Console::SetCursorPosition(x, y + 4); cout << "          ";
        Console::SetCursorPosition(x, y + 5); cout << "          ";
        Console::SetCursorPosition(x, y + 6); cout << "          ";
        Console::SetCursorPosition(x, y + 7); cout << "          ";
    }
    else if (especie == 2) {
        Console::SetCursorPosition(x, y + 1); cout << "                     ";
        Console::SetCursorPosition(x, y + 2); cout << "                     ";
        Console::SetCursorPosition(x, y + 3); cout << "                     ";
        Console::SetCursorPosition(x, y + 4); cout << "                     ";
        Console::SetCursorPosition(x, y + 5); cout << "                     ";
        Console::SetCursorPosition(x, y + 6); cout << "                     ";
    }
}

void Semilla::descripcion() {
    cout << "Semilla de la especie " << getTipo() << "." << std::endl;
}
