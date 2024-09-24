#include "pch.h"
#include <iostream>
#include "conio.h"
#include <ctime>
#include "Niveles.h"
#include <vector>
#include "Personaje.h"
#include "Grafico.h"
#include "Juego.h"
#include "ContaminacionHidrica.h"
#include "IncendioForestal.h"
#include "ContaminacionAmbiental.h"
#include "ContaminacionRadioactiva.h"

using namespace System;
using namespace std;


Niveles::Niveles() : tipo(0), juego(nullptr) {
	cantidadDeNiveles = 4;
    nivelActual = tipo;
    tiempoRestanteTotal = 150;
    switch (tipo) {
    case 1:
        dificultad = 1;
        descripcion = "Nivel de contaminación Hídrica";
        break;
    case 2:
        dificultad = 3;
        descripcion = "Nivel de contaminación Forestal";
        break;
    case 3:
        dificultad = 2;
        descripcion = "Nivel de contaminación Ambiental";
        break;
    case 4:
        dificultad = 3;
        descripcion = "Nivel de contaminación Radioactiva";
        break;
    default:
        dificultad = 0;
        descripcion = "Nivel no válido";
        break;
    }
}

Niveles::Niveles(int _tipo, Juego* _juego, ContaminacionHidrica* contaminacionHidrica, IncendioForestal* incendioForestal, ContaminacionAmbiental* contaminacionAmbiental, ContaminacionRadioactiva* contaminacionRadioactiva) 
    : tipo(_tipo), juego(_juego), contaminacionHidrica(contaminacionHidrica), incendioForestal(incendioForestal), contaminacionAmbiental(contaminacionAmbiental), contaminacionRadioactiva(contaminacionRadioactiva) {
	cantidadDeNiveles = 4;
    nivelActual = tipo;
    switch (tipo) {
    case 1:
        dificultad = 1;
        descripcion = "Nivel de contaminación Hídrica";
        break;
    case 2:
        dificultad = 3;
        descripcion = "Nivel de contaminación Forestal";
        break;
    case 3:
        dificultad = 2;
        descripcion = "Nivel de contaminación Ambiental";
        break;
    case 4:
        dificultad = 3;
        descripcion = "Nivel de contaminación Radioactiva";
        break;
    default:
        dificultad = 0;
        descripcion = "Nivel no válido";
        break;
    }
}

Niveles::~Niveles() {

}

IncendioForestal* Niveles::obtenerIncendioForestal() {
    return this->incendioForestal;
}

ContaminacionAmbiental* Niveles::obtenerContaminacionAmbiental() {
    return this->contaminacionAmbiental;
}

ContaminacionHidrica* Niveles::obtenerContaminacionHidrica() {
    return this->contaminacionHidrica;
}

int Niveles::getNivelActual() {
    return nivelActual;
}

void Niveles::primerNivel() {
    system("cls");
    nivelActual = 1;
    char tecla;
    int tiempoRestante = 5;
    tiempoRestanteTotal = 150;
    clock_t inicioContador = clock();
    clock_t tiempoUltimaContaminacion = clock();
    clock_t inicioNivel = clock();
    int contadorDeNuevosRecursos = 0;
    int rondasDeContador = 2;
    int porcentajeADescontaminar = 10;

    contaminacionHidrica->iniciarContaminacion();
    juego->obtenerGrafico()->mostrarEstadisticas();
    juego->obtenerPersonaje()->setVidasCambiadas(true);

    if (!juego->getAguaContaminada()) {
        juego->obtenerGrafico()->mostrarMar(7, 85);
    }

    juego->obtenerPersonaje()->setDerecha(false);
    juego->obtenerPersonaje()->setIzquierda(false);
    juego->inicializarRecursosPorNivel(1);

    double incrementoPorcentaje = 10.0;
    bool aumentoMedio = false;
    bool aumentoAlto = false;

    while (true) {
        juego->borrarObjetos();

        if (_kbhit()) {
            tecla = getch();
            tecla = toupper(tecla);
            juego->obtenerPersonaje()->mover(tecla);
        }

        juego->obtenerPersonaje()->actualizarEstadoDeSalud();
        juego->obtenerPersonaje()->dibujar();
        juego->moverObjetos();
        juego->dibujarObjetos();
        juego->detectarColiciones();
        juego->obtenerGrafico()->barraDeVida();
        juego->obtenerGrafico()->barraDeContaminacion();
        juego->obtenerPersonaje()->actualizarContadores();
        juego->obtenerGrafico()->mostrarContadoresRecursos();
        juego->obtenerGrafico()->dibujarCorazones(Console::WindowWidth - 76, 6, juego->obtenerPersonaje()->getSalud());
        juego->obtenerPersonaje()->incrementarContadorInactividad();

        clock_t tiempoActual = clock();
        double tiempoPasado = (double)(tiempoActual - inicioContador) / CLOCKS_PER_SEC;
        double tiempoTotalNivel = (double)(tiempoActual - inicioNivel) / CLOCKS_PER_SEC;

        if (tiempoRestanteTotal < 0) {
            if (juego->getPorcentajeDeContaminacionMar() < 70) {
                segundoNivel();
                break;
            }
            else {
                break;
            }
        }

        if (juego->obtenerPersonaje()->getSalud() <= 0) {
            break;
        }

        if (tiempoRestanteTotal >= 0) {
            juego->obtenerGrafico()->mostrarContador(tiempoRestanteTotal, 330, 90, inicioNivel);
        }

        if (tiempoRestante > -1) {
            juego->obtenerGrafico()->mostrarContador(tiempoRestante, 290, 90, inicioContador);
            juego->setAguaContaminada(false);
        }
        else {
            juego->setAguaContaminada(true);
            contadorDeNuevosRecursos++;
        }

        double tiempoDesdeUltimaContaminacion = (double)(tiempoActual - tiempoUltimaContaminacion) / CLOCKS_PER_SEC;

        if (tiempoDesdeUltimaContaminacion >= 10) {
            if (tiempoPasado >= 50) {
                incrementoPorcentaje = 50;
            }
            else if (tiempoPasado >= 20 && !aumentoMedio) {
                incrementoPorcentaje = 40;
                aumentoMedio = true;
            }

            juego->setPorcentajeDeContaminacion(juego->getPorcentajeDeContaminacion() + incrementoPorcentaje);

            if (juego->getPorcentajeDeContaminacion() > 80) {
                juego->setPorcentajeDeContaminacion(80);
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

        if (juego->obtenerPersonaje()->getDescontaminarMar() && juego->obtenerPersonaje()->getInteractuar()) {
            int guardianContadorSemillasAgua = juego->obtenerPersonaje()->getContadorSemillasAgua();

            if (juego->getContadorPlantas() >= 1) {
                porcentajeADescontaminar = 10 * juego->getContadorPlantas();
            }

            if (juego->getContadorPlantas() >= 6) {
                porcentajeADescontaminar = 60;
            }

            if (guardianContadorSemillasAgua > 0) {
                juego->descontaminarMar(porcentajeADescontaminar * guardianContadorSemillasAgua);
                juego->obtenerPersonaje()->setContadorDeSemillasTotales(juego->obtenerPersonaje()->getContadorSemillasTotales() - guardianContadorSemillasAgua);
                juego->obtenerPersonaje()->setContadorSemillasAgua(0);
                juego->obtenerPersonaje()->setContadorAguasACambiado(true);
            }
        }

        if (juego->obtenerPersonaje()->getPlantarArbol() && juego->obtenerPersonaje()->getInteractuar()) {
            int guardianContadorSemillas = juego->obtenerPersonaje()->getContadorSemillas();
            juego->plantarArboles(guardianContadorSemillas);
            juego->obtenerPersonaje()->setContadorDeSemillasTotales(juego->obtenerPersonaje()->getContadorSemillasTotales() - guardianContadorSemillas);
            juego->obtenerPersonaje()->setContadorSemillas(0);
            juego->obtenerPersonaje()->setContadorAguasACambiado(true);
        }

        if (contadorDeNuevosRecursos >= rondasDeContador) {
            contadorDeNuevosRecursos = 0;
            juego->obtenerPersonaje()->getGestorDeRecursos()->eliminarTodosLosRecursos();
            juego->inicializarRecursosPorNivel(1);
        }

        contaminacionHidrica->actualizarEstado();

        _sleep(4);
    }
}


void Niveles::segundoNivel() {
    system("cls");
    juego->reiniciarPartesAPlantar();
    nivelActual = 2;
    char tecla;
    int tiempoRestante = 5;
    tiempoRestanteTotal = 150;
    clock_t inicioContador = clock();
    clock_t tiempoUltimaContaminacion = clock();
    clock_t inicioNivel = clock();
    int contadorDeNuevosRecursos = 0;
    int rondasDeContador = 2;
    int porcentajeADescontaminar = 10;

    juego->obtenerPersonaje()->setContadorAgua(0);
    juego->obtenerPersonaje()->setContadorDeSemillasTotales(0);
    juego->obtenerPersonaje()->setContadorSemillasAgua(0);
    juego->obtenerPersonaje()->setContadorSemillas(0);
    juego->obtenerPersonaje()->setContadorPapel(0);
    juego->obtenerPersonaje()->setContadorPlastico(0);
    juego->obtenerPersonaje()->setContadorDeResiduosTotales(0);
    juego->setPorcentajeDeContaminacionMar(0);

    contaminacionHidrica->iniciarContaminacion();
    juego->obtenerGrafico()->mostrarEstadisticas();
    juego->obtenerPersonaje()->setVidasCambiadas(true);
    incendioForestal->dibujar();

    if (!juego->getAguaContaminada()) {
        juego->obtenerGrafico()->mostrarMar(7, 85);
    }

    juego->obtenerPersonaje()->setDerecha(false);
    juego->obtenerPersonaje()->setIzquierda(false);
    juego->inicializarRecursosPorNivel(2);

    double incrementoPorcentaje = 10.0;
    bool aumentoMedio = false;
    bool aumentoAlto = false;

    while (true) {
        juego->borrarObjetos();

        if (_kbhit()) {
            tecla = getch();
            tecla = toupper(tecla);
            juego->obtenerPersonaje()->mover(tecla);
        }

        juego->obtenerPersonaje()->actualizarEstadoDeSalud();
        juego->obtenerPersonaje()->dibujar();
        juego->moverObjetos();
        juego->dibujarObjetos();
        juego->detectarColiciones();
        juego->obtenerGrafico()->barraDeVida();
        juego->obtenerGrafico()->barraDeContaminacion();
        juego->obtenerPersonaje()->actualizarContadores();
        juego->obtenerGrafico()->mostrarContadoresRecursos();
        juego->obtenerGrafico()->dibujarCorazones(Console::WindowWidth - 76, 6, juego->obtenerPersonaje()->getSalud());
        juego->obtenerPersonaje()->incrementarContadorInactividad();

        clock_t tiempoActual = clock();
        double tiempoPasado = (double)(tiempoActual - inicioContador) / CLOCKS_PER_SEC;
        double tiempoTotalNivel = (double)(tiempoActual - inicioNivel) / CLOCKS_PER_SEC;


        incendioForestal->atacar();
        incendioForestal->actualizarEstado();

        if (tiempoRestanteTotal < 0) {
            if (juego->getPorcentajeDeContaminacionMar() < 70) {
                tercerNivel();
                break;
            }
            else {
                break;
            }
        }

        if (juego->obtenerPersonaje()->getSalud() <= 0) {
            break;
        }

        if (tiempoRestanteTotal >= 0) {
            juego->obtenerGrafico()->mostrarContador(tiempoRestanteTotal, 330, 90, inicioNivel);
        }

        if (tiempoRestante > -1) {
            juego->obtenerGrafico()->mostrarContador(tiempoRestante, 290, 90, inicioContador);
            juego->setAguaContaminada(false);
        }
        else {
            juego->setAguaContaminada(true);
            contadorDeNuevosRecursos++;
        }

        double tiempoDesdeUltimaContaminacion = (double)(tiempoActual - tiempoUltimaContaminacion) / CLOCKS_PER_SEC;

        if (tiempoDesdeUltimaContaminacion >= 10) {
            if (tiempoPasado >= 50) {
                incrementoPorcentaje = 50;
            }
            else if (tiempoPasado >= 20 && !aumentoMedio) {
                incrementoPorcentaje = 40;
                aumentoMedio = true;
            }

            juego->setPorcentajeDeContaminacion(juego->getPorcentajeDeContaminacion() + incrementoPorcentaje);

            if (juego->getPorcentajeDeContaminacion() > 80) {
                juego->setPorcentajeDeContaminacion(80);
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

        if (juego->obtenerPersonaje()->getDescontaminarMar() && juego->obtenerPersonaje()->getInteractuar()) {
            int guardianContadorSemillasAgua = juego->obtenerPersonaje()->getContadorSemillasAgua();

            if (juego->getContadorPlantas() >= 1) {
                porcentajeADescontaminar = 10 * juego->getContadorPlantas();
            }

            if (juego->getContadorPlantas() >= 6) {
                porcentajeADescontaminar = 60;
            }

            if (guardianContadorSemillasAgua > 0) {
                juego->descontaminarMar(porcentajeADescontaminar * guardianContadorSemillasAgua);
                juego->obtenerPersonaje()->setContadorDeSemillasTotales(juego->obtenerPersonaje()->getContadorSemillasTotales() - guardianContadorSemillasAgua);
                juego->obtenerPersonaje()->setContadorSemillasAgua(0);
                juego->obtenerPersonaje()->setContadorAguasACambiado(true);
            }
        }

        if (juego->obtenerPersonaje()->getPlantarArbol() && juego->obtenerPersonaje()->getInteractuar()) {
            int guardianContadorSemillas = juego->obtenerPersonaje()->getContadorSemillas();
            juego->plantarArboles(guardianContadorSemillas);
            juego->obtenerPersonaje()->setContadorDeSemillasTotales(juego->obtenerPersonaje()->getContadorSemillasTotales() - guardianContadorSemillas);
            juego->obtenerPersonaje()->setContadorSemillas(0);
            juego->obtenerPersonaje()->setContadorAguasACambiado(true);
        }

        if (contadorDeNuevosRecursos >= rondasDeContador) {
            contadorDeNuevosRecursos = 0;
            juego->obtenerPersonaje()->getGestorDeRecursos()->eliminarTodosLosRecursos();
            juego->inicializarRecursosPorNivel(2);
        }

        contaminacionHidrica->actualizarEstado();

        _sleep(4);
    }
}

void Niveles::tercerNivel() {
    system("cls");
    juego->reiniciarPartesAPlantar();
    nivelActual = 3;
    char tecla;
    int tiempoRestante = 5;
    tiempoRestanteTotal = 100;
    clock_t inicioContador = clock();
    clock_t tiempoUltimaContaminacion = clock();
    clock_t inicioNivel = clock();
    int contadorDeNuevosRecursos = 0;
    int rondasDeContador = 2;
    int porcentajeADescontaminar = 10;

    juego->obtenerPersonaje()->setContadorAgua(0);
    juego->obtenerPersonaje()->setContadorDeSemillasTotales(0);
    juego->obtenerPersonaje()->setContadorSemillasAgua(0);
    juego->obtenerPersonaje()->setContadorSemillas(0);
    juego->obtenerPersonaje()->setContadorPapel(2);
    juego->obtenerPersonaje()->setContadorPlastico(2);
    juego->obtenerPersonaje()->setContadorDeResiduosTotales(0);
    juego->setPorcentajeDeContaminacionMar(0);

    contaminacionHidrica->iniciarContaminacion();
    juego->obtenerGrafico()->mostrarEstadisticas();
    juego->obtenerPersonaje()->setVidasCambiadas(true);
    incendioForestal->dibujar();

    if (!juego->getAguaContaminada()) {
        juego->obtenerGrafico()->mostrarMar(7, 85);
    }

    juego->obtenerPersonaje()->setDerecha(false);
    juego->obtenerPersonaje()->setIzquierda(false);
    juego->inicializarRecursosPorNivel(3);

    double incrementoPorcentaje = 10.0;
    bool aumentoMedio = false;
    bool aumentoAlto = false;

    while (true) {
        juego->borrarObjetos();

        if (_kbhit()) {
            tecla = getch();
            tecla = toupper(tecla);
            juego->obtenerPersonaje()->mover(tecla);
        }

        juego->obtenerPersonaje()->actualizarEstadoDeSalud();
        juego->obtenerPersonaje()->dibujar();
        juego->moverObjetos();
        juego->dibujarObjetos();
        juego->detectarColiciones();
        juego->obtenerGrafico()->barraDeVida();
        juego->obtenerGrafico()->barraDeContaminacion();
        juego->obtenerPersonaje()->actualizarContadores();
        juego->obtenerGrafico()->mostrarContadoresRecursos();
        juego->obtenerGrafico()->dibujarCorazones(Console::WindowWidth - 76, 6, juego->obtenerPersonaje()->getSalud());
        juego->obtenerPersonaje()->incrementarContadorInactividad();

        clock_t tiempoActual = clock();
        double tiempoPasado = (double)(tiempoActual - inicioContador) / CLOCKS_PER_SEC;
        double tiempoTotalNivel = (double)(tiempoActual - inicioNivel) / CLOCKS_PER_SEC;


        incendioForestal->atacar();
        incendioForestal->actualizarEstado();
        contaminacionAmbiental->atacar();
        contaminacionAmbiental->actualizarEstado();

        if (tiempoRestanteTotal < 0) {
            if (juego->getPorcentajeDeContaminacionMar() < 90) {
                juego->obtenerGrafico()->mostrarPantallaGanador();
                _getch();
                system("cls");
                system(0);
            }
            else {
                break;
            }
        }

        if (juego->obtenerPersonaje()->getSalud() <= 0) {
            break;
        }

        if (tiempoRestanteTotal >= 0) {
            juego->obtenerGrafico()->mostrarContador(tiempoRestanteTotal, 330, 90, inicioNivel);
        }

        if (tiempoRestante > -1) {
            juego->obtenerGrafico()->mostrarContador(tiempoRestante, 290, 90, inicioContador);
            juego->setAguaContaminada(false);
        }
        else {
            juego->setAguaContaminada(true);
            contadorDeNuevosRecursos++;
        }

        double tiempoDesdeUltimaContaminacion = (double)(tiempoActual - tiempoUltimaContaminacion) / CLOCKS_PER_SEC;

        if (tiempoDesdeUltimaContaminacion >= 10) {
            if (tiempoPasado >= 50) {
                incrementoPorcentaje = 50;
            }
            else if (tiempoPasado >= 20 && !aumentoMedio) {
                incrementoPorcentaje = 40;
                aumentoMedio = true;
            }

            juego->setPorcentajeDeContaminacion(juego->getPorcentajeDeContaminacion() + incrementoPorcentaje);

            if (juego->getPorcentajeDeContaminacion() > 80) {
                juego->setPorcentajeDeContaminacion(80);
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

        if (juego->obtenerPersonaje()->getDescontaminarMar() && juego->obtenerPersonaje()->getInteractuar()) {
            int guardianContadorSemillasAgua = juego->obtenerPersonaje()->getContadorSemillasAgua();
            int guardianContadorAgua = juego->obtenerPersonaje()->getContadorAgua();

            if (juego->getContadorPlantas() >= 1) {
                porcentajeADescontaminar = 10 * juego->getContadorPlantas();
            }

            if (juego->getContadorPlantas() >= 6) {
                porcentajeADescontaminar = 60;
            }

            if (guardianContadorSemillasAgua > 0 || guardianContadorAgua > 0) {
                juego->descontaminarMar(porcentajeADescontaminar * guardianContadorSemillasAgua + guardianContadorAgua);
                juego->obtenerPersonaje()->setContadorDeSemillasTotales(juego->obtenerPersonaje()->getContadorSemillasTotales() - guardianContadorSemillasAgua);
                juego->obtenerPersonaje()->setContadorSemillasAgua(0);
                juego->obtenerPersonaje()->setContadorAgua(0);
                juego->obtenerPersonaje()->setContadorAguasACambiado(true);
            }
        }

        if (juego->obtenerPersonaje()->getPlantarArbol() && juego->obtenerPersonaje()->getInteractuar()) {
            int guardianContadorSemillas = juego->obtenerPersonaje()->getContadorSemillas();
            juego->plantarArboles(guardianContadorSemillas);
            juego->obtenerPersonaje()->setContadorDeSemillasTotales(juego->obtenerPersonaje()->getContadorSemillasTotales() - guardianContadorSemillas);
            juego->obtenerPersonaje()->setContadorSemillas(0);
            juego->obtenerPersonaje()->setContadorAguasACambiado(true);
        }

        if (contadorDeNuevosRecursos >= rondasDeContador) {
            contadorDeNuevosRecursos = 0;
            juego->obtenerPersonaje()->getGestorDeRecursos()->eliminarTodosLosRecursos();
            juego->inicializarRecursosPorNivel(3);
        }

        contaminacionHidrica->actualizarEstado();

        _sleep(4);
    }
}
void Niveles::cuartoNivel() {

}

void Niveles::iniciarNivel() {
	if (tipo == 1) {
        primerNivel();
	}
	else if (tipo == 2) {
        segundoNivel();
	}
	else if (tipo == 3) {
        tercerNivel();
	}
	else if (tipo == 4) {
        cuartoNivel();
	}
}

void Niveles::getDescripcion(int _tipo) {

}

void Niveles::getDificultad(int _tipo) {

}

void Niveles::setNivel(int _nivel) {
	this->tipo = _nivel;
}

int Niveles::getTiempoRestanteTotal() {
    return this->tiempoRestanteTotal;
}

void Niveles::generar() {}
void Niveles::resuelto() {}
void Niveles::mostrarDesafio() {}
void Niveles::iniciarDesafio() {}
void Niveles::finDesafio() {}