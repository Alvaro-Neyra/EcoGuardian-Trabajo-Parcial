#include "pch.h"
#include "ContaminacionHidrica.h"
#include "Grafico.h"

ContaminacionHidrica::ContaminacionHidrica(Juego* juego) : Enemigo(juego){}

void ContaminacionHidrica::atacar() {

}

void ContaminacionHidrica::actualizarEstado() {
    clock_t tiempoActual = clock();
    double tiempoDesdeUltimaContaminacion = (double)(tiempoActual - tiempoUltimaContaminacion) / CLOCKS_PER_SEC;

    if (tiempoDesdeUltimaContaminacion >= 10) {
        juego->setPorcentajeDeContaminacion(juego->getPorcentajeDeContaminacion() + ataque);

        if (juego->getPorcentajeDeContaminacion() > 100) {
            juego->setPorcentajeDeContaminacion(100);
        }

        tiempoUltimaContaminacion = clock();
    }

    if (juego->getAguaContaminada()) {
        juego->obtenerGrafico()->mostrarMarContaminado(19, 268, 7, 86, juego->getPorcentajeDeContaminacion());
        juego->setAguaContaminada(false);
        tiempoRestante = 5;
        juego->setContadorRondasContaminacion(juego->getContadorRondasContaminacion() + 1);
        juego->establecerPorcentajeDeContaminacion();
    }
}