#pragma once
#include "iostream"
#include "Enemigo.h"
#include "Juego.h"
#include <ctime>

using namespace System;
using namespace std;

class ResiduosReciclables : public Recurso
{
private:
    int tipo;

public:
    ResiduosReciclables(int id, int x, int y, bool visible, bool _recogido, int _tipoResiduo);
    ~ResiduosReciclables();

    int getTipo();
    void setTipo(int _tipoResiduo);

    void verificarTipo();
    void descontaminarAmbiente();

    void dibujar() override;
    void borrar() override;
    void descripcion() override;
};
