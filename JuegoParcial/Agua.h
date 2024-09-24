#pragma once
#include "Recurso.h"
#include <iostream>

using namespace std;
using namespace System;

class Agua : public Recurso
{
private:
    float purezaDelAgua; 
    int cantidadBotella; 

public:
    // Constructor
    Agua(int _id, int _x, int _y, bool _visible, bool recogido, float _purezaDelAgua, int _cantidadBotella);

    // Destructor
    ~Agua();

    // Getters y Setters adicionales
    float getPurezaDelAgua();
    void setPurezaDelAgua(float _purezaDelAgua);

    int getCantidadBotella();
    void setCantidadBotella(int _cantidadBotella);

    // Implementación de métodos polimórficos
    void dibujar() override;
    void borrar() override;
    void descripcion() override;
};
