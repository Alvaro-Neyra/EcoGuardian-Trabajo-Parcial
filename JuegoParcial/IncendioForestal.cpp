#include "pch.h"
#include <iostream>
#include <ctime>
#include "Juego.h"
#include "IncendioForestal.h"
#include "Enemigo.h"

using namespace System;
using namespace std;

IncendioForestal::IncendioForestal(Juego* juego, int intensidad, int _temperatura)
    : Enemigo(juego), lastFireTime(0), intensidad(intensidad), temperatura(_temperatura), activo(true)
{
    this->objetivoX = juego->obtenerPersonaje()->getX();
    this->objetivoY = juego->obtenerPersonaje()->getY();
    this->volcanWidth = 34;
    this->volcanHeight = 23;
    this->xCoordenadaVolcan = 7;
    this->bolaDeFuegoHeight = 12;
    this->bolaDeFuegoWidth = 6;
    this->yCoordenadaVolcan = Console::WindowHeight / 2;
    this->bolaDeFuegoXInicial = xCoordenadaVolcan + volcanWidth / 2;
    this->bolaDeFuegoYInicial = yCoordenadaVolcan - 10;
    this->bolaDeFuegoX = bolaDeFuegoXInicial;
    this->bolaDeFuegoY = bolaDeFuegoYInicial;
    this->tiempoUltimaPropagacion = clock();
    this->lastMoveTime = clock();
    this->colisionarConEnemigo = false;
    this->entidadObjetivo = 1;
}

IncendioForestal::~IncendioForestal() {

}

int IncendioForestal::numeroAleatorio(int inicio, int final) {
    return (inicio + rand() % (final - inicio + 1));
}

void IncendioForestal::dibujarBolaDeFuego(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(x, y + 1); cout << "    ++ *   ";
    Console::SetCursorPosition(x, y + 2); cout << "** ++++**  ";
    Console::SetCursorPosition(x, y + 3); cout << "***+++++** ";
    Console::SetCursorPosition(x, y + 4); cout << "++++===++++";
    Console::SetCursorPosition(x, y + 5); cout << " ==------= ";
    Console::SetCursorPosition(x, y + 6); cout << "  ==-----  ";
    Console::ForegroundColor = ConsoleColor::White;
}

void IncendioForestal::borrarBolaDeFuego(int x, int y) {
    Console::SetCursorPosition(x, y + 1); cout << "              ";
    Console::SetCursorPosition(x, y + 2); cout << "              ";
    Console::SetCursorPosition(x, y + 3); cout << "              ";
    Console::SetCursorPosition(x, y + 4); cout << "              ";
    Console::SetCursorPosition(x, y + 5); cout << "              ";
    Console::SetCursorPosition(x, y + 6); cout << "              ";
}

void IncendioForestal::dibujarVolcan(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkRed;
    Console::SetCursorPosition(x, y + 1); cout << "               @##@    @@@@@     ";
    Console::SetCursorPosition(x, y + 2); cout << "           @%==#@ @@+==*@        ";
    Console::SetCursorPosition(x, y + 3); cout << "  @@%%%@@@  @@+%@@@===+%@@@@@@@@ ";
    Console::SetCursorPosition(x, y + 4); cout << " @#======+%@@ @@ @#=*@@@@*+++++#@";
    Console::SetCursorPosition(x, y + 5); cout << " @@+==+*%@@@@@   @@@@ @@@@@@@@%%@";
    Console::SetCursorPosition(x, y + 6); cout << "   @@@       @       @@@         ";
    Console::SetCursorPosition(x, y + 7); cout << "           @@+=%@@@@@@           ";
    Console::SetCursorPosition(x, y + 8); cout << "          @%----------@@         ";
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    Console::SetCursorPosition(x, y + 9); cout << "         @@@%=----*@@%*%@        ";
    Console::SetCursorPosition(x, y + 10); cout << "         @*+*#-+@*+++++*@        ";
    Console::SetCursorPosition(x, y + 11); cout << "        @%+*%--*#+++++++%@       ";
    Console::SetCursorPosition(x, y + 12); cout << "        @*+@=--*#+++++++*@       ";
    Console::SetCursorPosition(x, y + 13); cout << "       @%+%*=@=##++++++++#@      ";
    Console::SetCursorPosition(x, y + 14); cout << "      @@++@=*%%%+*#+++++++%@     ";
    Console::SetCursorPosition(x, y + 15); cout << "     @%++*@-#*++++%%+++++++@@    ";
    Console::SetCursorPosition(x, y + 16); cout << "   @@*++++#%#+++++#@#+++++++%@   ";
    Console::SetCursorPosition(x, y + 17); cout << "  @#++++++++++++++##%*+++++++%@  ";
    Console::SetCursorPosition(x, y + 18); cout << " @*+++++++++++++++*%#*++++++++*@@";
    Console::SetCursorPosition(x, y + 19); cout << "@#++++++++++++++++*@#*+++++++++*@";
    Console::SetCursorPosition(x, y + 20); cout << "@%*+++++++++++++++*%+%+++++++#@@@";
    Console::SetCursorPosition(x, y + 21); cout << "  @@#+++++++++++++%+-+@*%@@@@@   ";
    Console::SetCursorPosition(x, y + 22); cout << "    @@%*+++++++++*@+--+@         ";
    Console::SetCursorPosition(x, y + 23); cout << "       @@###%@@@@  @@@@@         ";
    Console::ForegroundColor = ConsoleColor::White;
}

void IncendioForestal::borrarVolcan(int x, int y) {
    Console::SetCursorPosition(x, y + 1);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 2);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 3);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 4);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 5);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 6);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 7);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 8);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 9);  cout << "                                 ";
    Console::SetCursorPosition(x, y + 10); cout << "                                 ";
    Console::SetCursorPosition(x, y + 11); cout << "                                 ";
    Console::SetCursorPosition(x, y + 12); cout << "                                 ";
    Console::SetCursorPosition(x, y + 13); cout << "                                 ";
    Console::SetCursorPosition(x, y + 14); cout << "                                 ";
    Console::SetCursorPosition(x, y + 15); cout << "                                 ";
    Console::SetCursorPosition(x, y + 16); cout << "                                 ";
    Console::SetCursorPosition(x, y + 17); cout << "                                 ";
    Console::SetCursorPosition(x, y + 18); cout << "                                 ";
    Console::SetCursorPosition(x, y + 19); cout << "                                 ";
    Console::SetCursorPosition(x, y + 20); cout << "                                 ";
    Console::SetCursorPosition(x, y + 21); cout << "                                 ";
    Console::SetCursorPosition(x, y + 22); cout << "                                 ";
    Console::SetCursorPosition(x, y + 23); cout << "                                 ";
}

void IncendioForestal::dibujar() {
    dibujarVolcan(xCoordenadaVolcan, yCoordenadaVolcan);
}

Rectangle IncendioForestal::obtenerVolcanRect() {
    return Rectangle(xCoordenadaVolcan, yCoordenadaVolcan, volcanWidth, volcanHeight);
}

Rectangle IncendioForestal::bolaDeFuegoRect() {
    return Rectangle(bolaDeFuegoX, bolaDeFuegoY, bolaDeFuegoWidth, bolaDeFuegoHeight);
}

Rectangle IncendioForestal::bolaDeFuegoRectRango() {
    return Rectangle(bolaDeFuegoX - 2, bolaDeFuegoY - 2, bolaDeFuegoWidth + 4, bolaDeFuegoHeight + 4);
}

int IncendioForestal::getCoordenadaBolaDeFuegoX() {
    return this->bolaDeFuegoX;
}

int IncendioForestal::getCoordenadaBolaDeFuegoY() {
    return this->bolaDeFuegoY;
}

void IncendioForestal::setCoordenadaBolaDeFuegoX(int _coordenada) {
    this->bolaDeFuegoX = _coordenada;
}

void IncendioForestal::setCoordenadaBolaDeFuegoY(int _coordenada) {
    this->bolaDeFuegoY = _coordenada;
}

int IncendioForestal::getCoordenadaObjetivoX() {
    return this->objetivoX;
}

int IncendioForestal::getCoordenadaObjetivoY() {
    return this->objetivoY;
}

void IncendioForestal::setCoordenadaObjetivoX(int _coordenada) {
    this->objetivoX = _coordenada;
}

void IncendioForestal::setCoordenadaObjetivoY(int _coordenada) {
    this->objetivoY = _coordenada;
}

int IncendioForestal::getIntensidad() {
    return this->intensidad;
}

bool IncendioForestal::getColisionarConEnemigo() {
    return this->colisionarConEnemigo;
}

void IncendioForestal::setColisionarConEnemigo(bool _colisiona) {
    this->colisionarConEnemigo = _colisiona;
}

void IncendioForestal::borrar() {
    borrarVolcan(7, Console::WindowWidth / 3 + 10);
}

void IncendioForestal::atacar() {
    if (colisionarConEnemigo) {
        if (bolaDeFuegoX >= 0 && bolaDeFuegoY >= 0) {
            borrarBolaDeFuego(bolaDeFuegoX, bolaDeFuegoY);
        }
        generarObjetivo();
        generarBolaDeFuego();
        colisionarConEnemigo = false;
    }
    else {
        if (bolaDeFuegoX >= 0 && bolaDeFuegoY >= 0) {
            moverBolaDeFuego();
        }
    }
}

int IncendioForestal::calcular_distancia_entreDosPuntos(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}


void IncendioForestal::moverBolaDeFuego() {
    clock_t currentTime = clock();
    double moveInterval = 0.05 * CLOCKS_PER_SEC;

    if (double(currentTime - lastMoveTime) >= moveInterval) {
        int x = getCoordenadaBolaDeFuegoX();
        int y = getCoordenadaBolaDeFuegoY();

        // seguir objetivo que se vaya cambiando
        if (entidadObjetivo == 1) {
            objetivoX = juego->obtenerPersonaje()->getX();
            objetivoY = juego->obtenerPersonaje()->getY();
        }

        int dx = objetivoX - x;
        int dy = objetivoY - y;
        int steps = max(abs(dx), abs(dy));
        float xIncrement = dx / (float)steps;
        float yIncrement = dy / (float)steps;

        borrarBolaDeFuego(x, y);
        x += xIncrement;
        y += yIncrement;

        setCoordenadaBolaDeFuegoX((int)x);
        setCoordenadaBolaDeFuegoY((int)y);
        dibujarBolaDeFuego((int)x, (int)y);

        lastMoveTime = currentTime;
    }
}

void IncendioForestal::detener() {
    activo = false;
}

bool IncendioForestal::esActivo() {
    return activo;
}

void IncendioForestal::propagar() {
    if (activo) {
        intensidad++;
        temperatura += 20;
    }
}

void IncendioForestal::actualizarEstado() {
    clock_t tiempoActual = clock();
    double tiempoDesdeUltimaPropagacion = (double)(tiempoActual - tiempoUltimaPropagacion) / CLOCKS_PER_SEC;

    if (tiempoDesdeUltimaPropagacion >= 10) {
        propagar();
        tiempoUltimaPropagacion = clock();
    }

    if (activo && juego->obtenerPersonaje()->getContadorAgua() > 10) {
        detener();
        juego->obtenerPersonaje()->setContadorAgua(0);
    }
}

void IncendioForestal::generarBolaDeFuego() {
    borrarBolaDeFuego(bolaDeFuegoX, bolaDeFuegoY);
    setCoordenadaBolaDeFuegoX(bolaDeFuegoXInicial);
    setCoordenadaBolaDeFuegoY(bolaDeFuegoYInicial);
}

void IncendioForestal::generarObjetivo() {
    int xGuardian = juego->obtenerPersonaje()->getX();
    int yGuardian = juego->obtenerPersonaje()->getY();
    vector<pair<int, int>>* vectorPlantasPlantadas = juego->getVectorPartesAPlantar();

    entidadObjetivo = numeroAleatorio(1, 2); // planta o jugador

    if (entidadObjetivo == 2 && vectorPlantasPlantadas->empty()) {
        entidadObjetivo = 1;
    }

    if (entidadObjetivo == 1) {
        objetivoX = xGuardian;
        objetivoY = yGuardian;
    }
    else if (entidadObjetivo == 2) {
        int elementoAleatorio = (0, vectorPlantasPlantadas->size() - 1);

        objetivoX = vectorPlantasPlantadas->at(elementoAleatorio).first;
        objetivoY = vectorPlantasPlantadas->at(elementoAleatorio).second;
    }
}