#pragma once
#include "iostream"
#include "Juego.h"
#include "Enemigo.h"
#include <ctime>

using namespace System;
using namespace std;

class ContaminacionRadioactiva : public Enemigo {
private:
    int nivelRadiacion;
    int tipo;
    int x;
    int y;
    int dx;
    int dy;
    int alto;
    int ancho;
    bool visible;
    int vida;
    int intensidad;

public:
    ContaminacionRadioactiva(Juego* juego);
    ContaminacionRadioactiva(Juego* juego, int x, int y, int dx, int dy, int alto, int ancho, bool visible, int vida, int tipo, int intensidad, int _nivelRadiacion);
    ~ContaminacionRadioactiva();

    void quitarVida();
    void mostrarBarraContaminacionRadioactiva();
    void borrar();
    void mover();
    void dibujar();

    // Implementing pure virtual functions from Enemigo
    void actualizarEstado() override;
    void atacar() override;
};