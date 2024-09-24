#include "pch.h"
#include "Agua.h"
#include "Recurso.h"
#include "ResiduosReciclables.h"
#include "Semilla.h"

// Constructor

Recurso::Recurso() {

}

Recurso::Recurso(int _id, int _x, int _y, bool _visible, bool _recogido) {
    id = _id;
    x = _x;
    y = _y;
    visible = _visible;
    recogido = _recogido;
    

    // Estableciendo el tipo de recurso dependiendo de la hija
    if (dynamic_cast<Semilla*>(this)) {
        especieRecurso = 1;
    }
    else if (dynamic_cast<Agua*>(this)) {
        especieRecurso = 2;
    }
    else if (dynamic_cast<ResiduosReciclables*>(this)) {
        especieRecurso = 3;
    }
}

// Destructor
Recurso::~Recurso() {
}

// Getters
int Recurso::getId() {
    return id;
}

int Recurso::getX() {
    return x;
}

int Recurso::getY() {
    return y;
}

int Recurso::getAlto() {
    return alto;
}

int Recurso::getAncho() {
    return ancho;
}

bool Recurso::getVisible() {
    return visible;
}

bool Recurso::getRecogido() {
    return recogido;
}

int Recurso::getEspecieRecurso() {
    return especieRecurso;
}

// Setters

void Recurso::setX(float _x) {
    x = _x;
}

void Recurso::setY(float _y) {
    y = _y;
}

void Recurso::setAlto(int _alto) {
    alto = _alto;
}

void Recurso::setAncho(int _ancho) {
    ancho = _ancho;
}

void Recurso::setVisible(bool _visible) {
    visible = _visible;
}

void Recurso::setRecogido(bool _recogido) {
    recogido = _recogido;
}

// Otros métodos no polimórficos
Rectangle Recurso::obtenerRectangulo() {
    return Rectangle((int)x, (int)y, ancho, alto);
}

Rectangle Recurso::obtenerRectanguloRango() {
    int margen = max(alto, ancho) * 0.5;
    return Rectangle(x - margen, y - margen, ancho + 2 * margen, alto + 2 * margen);
}