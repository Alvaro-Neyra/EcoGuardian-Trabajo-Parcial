#include "pch.h"
#include "Enemigo.h"
#include <iostream>
#include <ctime>
#include "Juego.h"
#include "Niveles.h"
#include "Grafico.h"
#include "IncendioForestal.h"
#include "ContaminacionAmbiental.h"

using namespace System;
using namespace std;

// Constructor

ContaminacionAmbiental::ContaminacionAmbiental(Juego* juego)
    : Enemigo(juego) {
    this->x = 0;
    this->y = 0;
    this->dx = 0;
    this->dy = 0;
    this->alto = 8;
    this->ancho = 21;
    this->visible = false;
    this->vida = 100;
    this->tipo = 0;
    this->intensidad = 100;
    this->tiempoUltimaGeneracion = clock();
    this->contadorResiduos = 0;
    this->residuosGenerados = new vector<pair<int, int>>();
}

ContaminacionAmbiental::ContaminacionAmbiental(Juego* juego, int x, int y, int dx, int dy, bool visible, int vida, int tipo, int intensidad)
    : Enemigo(juego) {
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->alto = 8;
    this->ancho = 21;
    this->visible = visible;
    this->vida = vida;
    this->tipo = tipo;
    this->intensidad = intensidad;
    this->tiempoUltimaGeneracion = clock();
    this->residuosGenerados = new vector<pair<int, int>>();
    this->contadorResiduos = 0;
}

ContaminacionAmbiental::~ContaminacionAmbiental() {
	delete residuosGenerados;
}

void ContaminacionAmbiental::mostrarBarraContaminacionAmbiental() {
}

int ContaminacionAmbiental::getAncho() {
    return this->alto;
}

int ContaminacionAmbiental::getAlto() {
    return this->alto;
}

void ContaminacionAmbiental::dibujar() {
}

void ContaminacionAmbiental::mover() {
}

bool ContaminacionAmbiental::getColisionarConEnemigo() {
    return this->colisionarConEnemigo;
}

void ContaminacionAmbiental::setColisionarConEnemigo(bool _colision) {
    this->colisionarConEnemigo = _colision;
}

void ContaminacionAmbiental::borrarResiduo(int x, int y) {
    Console::SetCursorPosition(x, y + 1); cout << "                    ";
    Console::SetCursorPosition(x, y + 2); cout << "                    ";
    Console::SetCursorPosition(x, y + 3); cout << "                    ";
    Console::SetCursorPosition(x, y + 4); cout << "                    ";
    Console::SetCursorPosition(x, y + 5); cout << "                    ";
    Console::SetCursorPosition(x, y + 6); cout << "                    ";
    Console::SetCursorPosition(x, y + 7); cout << "                    ";
}

void ContaminacionAmbiental::dibujarResiduo(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkGray;
    Console::SetCursorPosition(x, y + 1); cout << "           +        ";
    Console::SetCursorPosition(x, y + 2); cout << "        .:-=+==     ";
    Console::SetCursorPosition(x, y + 3); cout << "     --::.:+=#.-    ";
    Console::SetCursorPosition(x, y + 4); cout << "  --=-----:-==--:   ";
    Console::SetCursorPosition(x, y + 5); cout << " :-=----:::-:.:...  ";
    Console::SetCursorPosition(x, y + 6); cout << " --=+===::  :-+=++  ";
    Console::SetCursorPosition(x, y + 7); cout << "              *++   ";
    Console::ForegroundColor = ConsoleColor::White;
}

void ContaminacionAmbiental::atacar() {
    int tiempoActual = clock();

    if (tiempoActual - tiempoUltimaGeneracion >= 30000) {
        generarBasura();
        tiempoUltimaGeneracion = tiempoActual;
    }
}

void ContaminacionAmbiental::generarBasura() {
    int cantidadBasura = numeroAleatorio(1, 3);

    Rectangle plantarAreaRect = juego->obtenerGrafico()->getArbolesPlantarRango();
    vector<Recurso*>* gestorJuego = juego->obtenerGestor();

    for (int i = 0; i < cantidadBasura; ++i) {
        bool colisiona;

        do {
            x = numeroAleatorio(6, Console::WindowWidth - 150);
            y = numeroAleatorio(15, Console::WindowHeight - 35);
            colisiona = false;

            Rectangle nuevoRecursoRect = Rectangle(x, y, ancho, alto);

            Rectangle guardianRect = juego->obtenerPersonaje()->obtenerRectangulo();
            if (guardianRect.IntersectsWith(nuevoRecursoRect)) {
                colisiona = true;
            }

            Rectangle volcanRect = juego->obtenerNiveles()->obtenerIncendioForestal()->obtenerVolcanRect();
            if (volcanRect.IntersectsWith(nuevoRecursoRect)) {
                colisiona = true;
            }

            Rectangle bolaDeFuegoRect = juego->obtenerNiveles()->obtenerIncendioForestal()->bolaDeFuegoRect();
            if (bolaDeFuegoRect.IntersectsWith(nuevoRecursoRect)) {
                colisiona = true;
            }

            if (plantarAreaRect.IntersectsWith(nuevoRecursoRect)) {
                colisiona = true;
            }

            for (Recurso* recursoExistente : *gestorJuego) {
                if (recursoExistente->obtenerRectangulo().IntersectsWith(nuevoRecursoRect)) {
                    colisiona = true;
                    break;
                }
            }

            for (pair<int, int>& residuo : *residuosGenerados) {
                Rectangle residuoRect = Rectangle(residuo.first, residuo.second, ancho, alto);
                if (nuevoRecursoRect.IntersectsWith(residuoRect)) {
                    colisiona = true;
                    break;
                }
            }

        } while (colisiona);

        residuosGenerados->push_back(make_pair(x, y));
        dibujarResiduo(x, y);
    }
}

void ContaminacionAmbiental::actualizarEstado() {
    contadorResiduos = 0;

    for (pair<int, int>& residuo : *residuosGenerados) {
        if (residuo.first > 0 && residuo.second < Console::WindowHeight) {
            contadorResiduos++;
        }
    }
}

void ContaminacionAmbiental::borrar() {

}

int ContaminacionAmbiental::numeroAleatorio(int min, int max) {
    return min + (rand() % max - min + 1);
}

vector<pair<int, int>>* ContaminacionAmbiental::obtenerResiduosGenerados() {
	return residuosGenerados;
}

void ContaminacionAmbiental::eliminarResiduosColisionados() {
    int margen = max(alto, ancho) * 0.5;
    for (int i = 0; i < obtenerResiduosGenerados()->size(); i++) {
        Rectangle contaminacionRectActual = Rectangle(
            obtenerResiduosGenerados()->at(i).first - margen,
            obtenerResiduosGenerados()->at(i).second - margen,
            getAncho() + 2 * margen,
            getAlto() + 2 * margen
        );

        if (juego->obtenerPersonaje()->obtenerRectangulo().IntersectsWith(contaminacionRectActual) && juego->obtenerPersonaje()->getEstaAtacando()) {
            borrarResiduo(obtenerResiduosGenerados()->at(i).first, obtenerResiduosGenerados()->at(i).second);
            obtenerResiduosGenerados()->erase(obtenerResiduosGenerados()->begin() + i);
            i--;
        }
    }
}

int ContaminacionAmbiental::getContadorResiduos() {
    return this->contadorResiduos;
}