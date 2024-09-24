#include "pch.h"
#include "GestorDeRecursos.h"
#include <iostream>

GestorDeRecursos::GestorDeRecursos(int capacidadMaxima)
    : cantidadDeRecursos(0) {
}

GestorDeRecursos::~GestorDeRecursos() {
    for (Recurso* recurso : recursos) {
        delete recurso;
    }
}

int GestorDeRecursos::getCapacidad() {
    return this->capacidad;
}
vector<Recurso*>* GestorDeRecursos::getRecursos() {
    return &this->recursos;
}
int GestorDeRecursos::getCantidadDeRecursos() {
    return this->cantidadDeRecursos;
}
void GestorDeRecursos::setCapacidad(int _nuevaCapacidad) {
    this->capacidad = _nuevaCapacidad;
}
void GestorDeRecursos::setCantidadDeRecursos(int _nuevaCantidadDeRecursos) {
    this->cantidadDeRecursos = _nuevaCantidadDeRecursos;
}

void GestorDeRecursos::agregarRecurso(Recurso* recurso) {
    if (recurso == nullptr) {
        return;
    }
    recursos.push_back(recurso);
    cantidadDeRecursos++;
}

void GestorDeRecursos::eliminarRecurso(Recurso* recurso) {
    for (int i = 0; i < recursos.size(); ++i) {
        if (recursos[i] == recurso) {
            delete recursos[i];
            recursos.erase(recursos.begin() + i);
            cantidadDeRecursos--;
            return;
        }
    }
}

void GestorDeRecursos::mostrarRecursos() {
    for (Recurso* recurso : recursos) {
        recurso->dibujar();
    }
}

void GestorDeRecursos::eliminarTodosLosRecursos() {
    for (Recurso* recurso : recursos) {
        recurso->borrar();
        delete recurso;
    }
    recursos.clear();

    cantidadDeRecursos = 0;
}

Recurso* GestorDeRecursos::obtenerRecurso(int idRecurso) {
    for (Recurso* recurso : recursos) {
        if (recurso->getId() == idRecurso) {
            return recurso;
        }
    }
    cout << "Recurso no encontrado." << endl;
    return nullptr;
}

void GestorDeRecursos::gestionarRecursos() {
    cout << "Gestionando recursos..." << endl;
}

void GestorDeRecursos::marcarRecursoRecogido(int idRecurso) {
    for (Recurso* recurso : recursos) {
        if (recurso->getId()  == idRecurso) {
            recurso->setRecogido(true);
            recurso->borrar();
            recurso->setVisible(false);
            return;
        }
    }
}
