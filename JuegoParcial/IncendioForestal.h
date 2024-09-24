#pragma once
#include "iostream"
#include <ctime>
#include "Juego.h"
#include "Enemigo.h"

using namespace System;
using namespace std;

class Juego;

class IncendioForestal : public Enemigo {
private:
    int objetivoX = 0;
    int objetivoY = 0;
    int intensidad;
    int temperatura;
    int bolaDeFuegoX;
    int bolaDeFuegoY;
    int xCoordenadaVolcan;
    int yCoordenadaVolcan;
    int bolaDeFuegoXInicial;
    int bolaDeFuegoYInicial;
    bool activo;
    clock_t tiempoUltimaPropagacion;
    clock_t lastFireTime;
    clock_t lastMoveTime;
    int volcanWidth;
    int volcanHeight;
    int bolaDeFuegoHeight;
    int bolaDeFuegoWidth;
    bool colisionarConEnemigo; // booleano que detecta la colision de la bola de fuego con el enemigo
    void dibujarVolcan(int x, int y);
    void borrarVolcan(int x, int y);
    int calcular_distancia_entreDosPuntos(int x1, int y1, int x2, int y2);
    void dibujarBolaDeFuego(int x, int y);
    void borrarBolaDeFuego(int x, int y);
    int numeroAleatorio(int inicio, int final);
    int entidadObjetivo;
public:
    IncendioForestal(Juego* juego, int intensidad, int _temperatura);
    ~IncendioForestal();
    void dibujar();
    void borrar();
    int getCoordenadaBolaDeFuegoX();
    int getCoordenadaBolaDeFuegoY();
    void setCoordenadaBolaDeFuegoX(int _coordenada);
    void setCoordenadaBolaDeFuegoY(int _coordenada);
    int getCoordenadaObjetivoX();
    int getCoordenadaObjetivoY();
    bool getColisionarConEnemigo();
    void setCoordenadaObjetivoX(int _coordenada);
    void setCoordenadaObjetivoY(int _coordenada);
    void setColisionarConEnemigo(bool _colisiona);
    int getIntensidad();
    Rectangle obtenerVolcanRect();
    Rectangle bolaDeFuegoRectRango();
    Rectangle bolaDeFuegoRect();
    void moverBolaDeFuego();
    void generarBolaDeFuego();
    void detener();
    void propagar();
    bool esActivo();
    void generarObjetivo();
    void actualizarEstado() override;
    void atacar() override;
};
