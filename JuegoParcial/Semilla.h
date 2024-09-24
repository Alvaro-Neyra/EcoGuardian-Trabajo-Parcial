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

    // Métodos adicionales
    int getTipo();
    void setTipo(int _especie);

    // Métodos propios de la clase Semilla
    void verificarEspecie();
    void plantarSemilla();

    // Implementación de métodos polimórficos
    void dibujar() override;
    void borrar() override;
    void descripcion() override;
};
