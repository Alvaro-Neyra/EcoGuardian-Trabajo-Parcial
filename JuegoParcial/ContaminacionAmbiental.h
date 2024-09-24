#pragma once
#include "iostream"
#include "Enemigo.h"
#include "Juego.h"
#include "Personaje.h"
#include <vector>
#include <ctime>

using namespace System;
using namespace System::Drawing;
using namespace std;

class Juego;
class Enemigo;

class ContaminacionAmbiental : public Enemigo {
private:
    int x;
    int y;
    int dx;
    int dy;
    int alto;
    int ancho;
    bool visible;
    bool colisionarConEnemigo;
    int vida;
    int tipo;
    int intensidad;
    int contadorResiduos;
    int numeroAleatorio(int min, int max);
    vector<pair<int, int>>* residuosGenerados;
    int tiempoUltimaGeneracion;

public:
    ContaminacionAmbiental(Juego* juego);
    ContaminacionAmbiental(Juego* juego, int x, int y, int dx, int dy, bool visible, int vida, int tipo, int intensidad);
    ~ContaminacionAmbiental();
    int getAlto();
    int getAncho();
    bool getColisionarConEnemigo();
    void setColisionarConEnemigo(bool _colision);
    void mostrarBarraContaminacionAmbiental();
    vector<pair<int, int>>* obtenerResiduosGenerados();
    void dibujarResiduo(int x, int y);
    void borrarResiduo(int x, int y);
    void dibujar();
    void mover();
    void borrar();
    void actualizarEstado() override;
    void atacar() override;
    void generarBasura();
    void eliminarResiduosColisionados();
    int getContadorResiduos();
};
