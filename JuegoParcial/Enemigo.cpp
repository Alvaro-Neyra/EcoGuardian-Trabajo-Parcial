#include "pch.h"
#include "Enemigo.h"
#include "Juego.h"

Enemigo::Enemigo(Juego* juego)
    : juego(juego), salud(100), ataque(10), porcentajeContaminacion(0), tiempoRestante(5), tiempoRestanteTotal(150) {
    inicioContador = clock();
    tiempoUltimaContaminacion = clock();
    inicioNivel = clock();
}

int Enemigo::getSalud(){
    return salud;
}

void Enemigo::setSalud(int salud) {
    this->salud = salud;
}

int Enemigo::getAtaque(){
    return ataque;
}

void Enemigo::setAtaque(int ataque) {
    this->ataque = ataque;
}

int Enemigo::getPorcentajeContaminacion(){
    return porcentajeContaminacion;
}

void Enemigo::setPorcentajeContaminacion(int porcentaje) {
    porcentajeContaminacion = porcentaje;
}

int Enemigo::getTiempoRestante() {
    return tiempoRestante;
}

void Enemigo::setTiempoRestante(int tiempo) {
    tiempoRestante = tiempo;
}

int Enemigo::getTiempoRestanteTotal() {
    return tiempoRestanteTotal;
}

void Enemigo::setTiempoRestanteTotal(int tiempo) {
    tiempoRestanteTotal = tiempo;
}

void Enemigo::iniciarContaminacion() {
    inicioContador = clock();
    tiempoUltimaContaminacion = clock();
    inicioNivel = clock();
}