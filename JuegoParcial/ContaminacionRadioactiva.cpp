#include "pch.h"
#include <iostream>
#include "Personaje.h"
#include "Juego.h"
#include "IncendioForestal.h"
#include <ctime>
#include "Enemigo.h"

ContaminacionRadioactiva::ContaminacionRadioactiva(Juego* juego) : Enemigo(juego) {

}

ContaminacionRadioactiva::ContaminacionRadioactiva(Juego* juego,int x, int y, int dx, int dy, int alto, int ancho, bool visible, int vida, int tipo, int intensidad, int _nivelRadiacion)
    : Enemigo(juego), nivelRadiacion(_nivelRadiacion) {
    // Inicializar atributos heredados
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->alto = alto;
    this->ancho = ancho;
    this->visible = visible;
    this->vida = vida;
    this->tipo = tipo;
    this->intensidad = intensidad;
}

ContaminacionRadioactiva::~ContaminacionRadioactiva() {

}

void ContaminacionRadioactiva::quitarVida() {
    // Implementaci�n espec�fica para ContaminacionRadioactiva
}

void ContaminacionRadioactiva::mostrarBarraContaminacionRadioactiva() {
    // Implementaci�n espec�fica para ContaminacionRadioactiva
}

void ContaminacionRadioactiva::borrar() {
    // Implementaci�n espec�fica para ContaminacionRadioactiva
}

void ContaminacionRadioactiva::mover() {
    // Implementaci�n espec�fica para ContaminacionRadioactiva
}

void ContaminacionRadioactiva::dibujar() {
    // Implementaci�n espec�fica para ContaminacionRadioactiva
}

void ContaminacionRadioactiva::actualizarEstado() { }

void ContaminacionRadioactiva::atacar() {

}