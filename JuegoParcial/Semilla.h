#pragma once
#include "Recurso.h"

class Semilla : public Recurso
{
private:
    int especie;

public:
    // Constructor y Destructor
    Semilla(int id, int x, int y, bool visible, bool _recogido, int _especie);
    ~Semilla();

    // M�todos adicionales
    int getTipo();
    void setTipo(int _especie);

    // M�todos propios de la clase Semilla
    void verificarEspecie();
    void plantarSemilla();

    // Implementaci�n de m�todos polim�rficos
    void dibujar() override;
    void borrar() override;
    void descripcion() override;
};
