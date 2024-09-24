#pragma once
#include "pch.h"
#include <ctime>

using namespace System;
using namespace std;

class Juego;

class Enemigo {
protected:
    int salud;
    int ataque;
    int porcentajeContaminacion;
    int tiempoRestante;
    int tiempoRestanteTotal;
    clock_t inicioContador;
    clock_t tiempoUltimaContaminacion;
    clock_t inicioNivel;
    Juego* juego;

public:
    Enemigo(Juego* juego);
    virtual ~Enemigo() = default;

    int getSalud();
    void setSalud(int salud);

    int getAtaque();
    void setAtaque(int ataque);

    int getPorcentajeContaminacion();
    void setPorcentajeContaminacion(int porcentaje);

    int getTiempoRestante();
    void setTiempoRestante(int tiempo);

    int getTiempoRestanteTotal();
    void setTiempoRestanteTotal(int tiempo);

    void iniciarContaminacion();

    virtual void actualizarEstado() = 0;
    virtual void atacar() = 0;
};
