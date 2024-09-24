#pragma once
#include "iostream"
#include "Enemigo.h"
#include "Juego.h"
#include <ctime>

using namespace System;
using namespace System::Drawing;
using namespace std;

class Juego;

class ContaminacionHidrica : public Enemigo {
public:
    ContaminacionHidrica(Juego* juego);
    void actualizarEstado() override;
    void atacar() override;
};
