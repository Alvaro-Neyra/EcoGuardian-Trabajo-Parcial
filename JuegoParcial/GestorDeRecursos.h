#pragma once
#include <vector>
#include "Recurso.h"

using namespace std;

class GestorDeRecursos {
private:
    int cantidadDeRecursos;
    vector<Recurso*> recursos;
    int capacidad;
public:
    GestorDeRecursos(int capacidad);
    ~GestorDeRecursos();

    // Getters
    int getCapacidad();
    vector<Recurso*>* getRecursos();
    int getCantidadDeRecursos();
    // Setters
    void setCapacidad(int _nuevaCapacidad);
    void setCantidadDeRecursos(int _nuevaCantidadDeRecursos);
    // Métodos
    void agregarRecurso(Recurso* recurso);
    void eliminarRecurso(Recurso* recurso);
    void mostrarRecursos();
    void eliminarTodosLosRecursos();
    Recurso* obtenerRecurso(int idRecurso);
    void gestionarRecursos();
    void marcarRecursoRecogido(int idRecurso);
};
