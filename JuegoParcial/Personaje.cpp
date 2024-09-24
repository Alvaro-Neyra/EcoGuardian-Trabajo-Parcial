#include "pch.h"
#include <iostream>
#include "Personaje.h"
#include "Recurso.h"
#include "Semilla.h"
#include "Agua.h"
#include "ResiduosReciclables.h"
#include <string>

using namespace System::Drawing;
using namespace System;
using namespace std;

Personaje::Personaje() {
	nombre = "";
	x = 0;
	y = 0;
	posicionXAnterior = 0;
	posicionYAnterior = 0;
	dx = 1;
	dy = 1;
	vida = 100;
	salud = 5;
	alto = 20;
	ancho = 44;
	energia = 100;
	this->descontaminarMar = false;
	this->estaAtacando = false;
	this->colisionarRecurso = false;
	this->plantarArbol = false;
	this->contadorSemillas = 0;
	this->contadorSemillasAgua = 0;
	this->contadorAgua = 0;
	this->contadorPapel = 0;
	this->contadorPlastico = 0;
	this->izquierda = false;
	this->derecha = false;
	this->interactuar = false;
	this->contadorInactividad = 0;
	this->framesParaInactividad = 20;
	this->estaAtacando = false;
	this->contadorSemillasACambiado = false;
	this->contadorAguasACambiado = false;
	this->contadorResiduosACambiado = false;
	this->contadorResiduosReciclables = 0;
	this->contadorSemillasTotales = 0;
	this->contadorSemillasTotalesAntiguo = 0;
	this->contadorAguaAntiguo = 0;
	this->contadorResiduosReciclablesAntiguo = 0;
	gestor = new GestorDeRecursos(10);
}

Personaje::Personaje(string _nombre, int _x, int _y, int _dx, int _dy, int _vida, int _salud, long _energia) {
	this->nombre = nombre; 
	this->x = _x; 
	this->y = _y; 
	this->dx = _dx; 
	this->dy = _dy;
	this->posicionXAnterior = _x;
	this->posicionYAnterior = _y;
	this->vida = _vida; 
	this->salud = _salud; 
	this->alto = 10;
	this->ancho = 21;
	this->energia = _energia;
	this->descontaminarMar = false;
	this->estaAtacando = false;
	this->colisionarRecurso = false;
	this->plantarArbol = false;
	this->contadorSemillas = 0;
	this->contadorSemillasAgua = 0;
	this->contadorAgua = 0;
	this->contadorPapel = 0;
	this->contadorPlastico = 0;
	this->izquierda = false;
	this->derecha = false;
	this->interactuar = false;
	this->contadorInactividad = 0;
	this->framesParaInactividad = 20;
	this->estaAtacando = false;
	this->contadorSemillasACambiado = false;
	this->contadorAguasACambiado = false;
	this->contadorResiduosACambiado = false;
	this->contadorResiduosReciclables = 0;
	this->contadorSemillasTotales = 0;
	this->contadorSemillasTotalesAntiguo = 0;
	this->contadorAguaAntiguo = 0;
	this->contadorResiduosReciclablesAntiguo = 0;
	gestor = new GestorDeRecursos(10);
}

Personaje::~Personaje() {
}

string Personaje::getNombre() { return this->nombre; }
int Personaje::getX() { return this->x; }
int Personaje::getY() { return this->y; }
int Personaje::getDX() { return this->dx; }
int Personaje::getDY() { return this->dy; }
int Personaje::getAlto() { return this->alto; }
int Personaje::getAncho() { return this->ancho; }
int Personaje::getVida() { return this->vida; }
int Personaje::getSalud() { return this->salud; }
long Personaje::getEnergia() { return this->energia; }
GestorDeRecursos* Personaje::getGestorDeRecursos() { return this->gestor; }
bool Personaje::getVidasCambiadas() { return this->vidasCambiadas; }
int Personaje::getPosicionXAnterior() { return this->posicionXAnterior; }
int Personaje::getPosicionYAnterior() { return this->posicionYAnterior; }
bool Personaje::getColisionarRecurso() { return this->colisionarRecurso; }
bool Personaje::getInteractuar() { return this->interactuar; }
int Personaje::getContadorSemillas() { return this->contadorSemillas; }
int Personaje::getContadorSemillasAgua() { return this->contadorSemillasAgua; }
int Personaje::getContadorAgua() { return this->contadorAgua; }
int Personaje::getContadorPapel() { return this->contadorPapel; }
int Personaje::getContadorPlastico() { return this->contadorPlastico; }

bool Personaje::getEstaAtacando() {
	return this->estaAtacando;
}
bool Personaje::getDescontaminarMar() {
	return this->descontaminarMar;
}

bool Personaje::getPlantarArbol() {
	return this->plantarArbol;
}

int Personaje::getContadorSemillasTotales() { return this->contadorSemillasTotales; }
int Personaje::getContadorResiduosReciclables() { return this->contadorResiduosReciclables; }
bool Personaje::getContadorSemillasACambiado() { return this->contadorSemillasACambiado; }
bool Personaje::getContadorAguasACambiado() { return this->contadorAguasACambiado; }
bool Personaje::getContadorResiduosACambiado() { return this->contadorResiduosACambiado; }

Recurso* Personaje::obtenerRecursoActual() { return this->recursoRecogido; }
void Personaje::setRecursoActual(Recurso* recurso) {
	if (recurso != nullptr) {
		this->recursoRecogido = recurso;
	}
}
void Personaje::setVidasCambiadas(bool _vidasCambiadas) {
	this->vidasCambiadas = _vidasCambiadas;
}
void Personaje::setNombre(string _nombre) { this->nombre = _nombre; }
void Personaje::setX(int _x) { this->x = _x; }
void Personaje::setY(int _y) { this->y = _y; }
void Personaje::setDX(int _dx) { this->dx = _dx; }
void Personaje::setDY(int _dy) { this->dy = _dy; }
void Personaje::setIzquierda(bool _moverIzquierda) { this->izquierda = _moverIzquierda; }
void Personaje::setDerecha(bool _moverDerecha) { this->derecha = _moverDerecha; }
void Personaje::setColisionarRecurso(bool _recurso) { this->colisionarRecurso = _recurso; }
void Personaje::setPosicionXAnterior(int posicionX) { this->posicionXAnterior = posicionX; }
void Personaje::setPosicionYAnterior(int posicionY) { this->posicionYAnterior = posicionY; }
void Personaje::setEstaAtacando(bool _atacando) { this->estaAtacando = _atacando; }
void Personaje::setEstaInteractuando(bool _interactuando) { this->interactuar = _interactuando; }
void Personaje::setPlantarArbol(bool _plantar) { this->plantarArbol = _plantar; }
void Personaje::actualizarPosicionesAnteriores() {
	posicionXAnterior = x;
	posicionYAnterior = y;
}

void Personaje::setVida(int _vida) { 
	if (this->vida > 0) {
		this->vida = _vida; 
	}
}

void Personaje::setSalud (int _salud) { 
	if (this->salud >= 0 && _salud <= 5) {
		this->salud = _salud; 
	}
}

void Personaje::setEnergia(long _energia) { this->energia = _energia; }

void Personaje::setContadorSemillas(int cantidad) { this->contadorSemillas = cantidad; }
void Personaje::setContadorSemillasAgua(int _cantidad) { this->contadorSemillasAgua = _cantidad; }
void Personaje::setContadorAgua(int cantidad) { this->contadorAgua = cantidad; }
void Personaje::setContadorPapel(int _cantidad) { this->contadorPapel = _cantidad; }
void Personaje::setContadorPlastico(int _cantidad) { this->contadorPlastico = _cantidad; }

void Personaje::setDescontaminarMar(bool _descontaminar) {
	this->descontaminarMar = _descontaminar;
}

void Personaje::setContadorSemillasACambiado(bool _aCambiado) { this->contadorAguasACambiado = _aCambiado; }
void Personaje::setContadorAguasACambiado(bool _aCambiado) { this->contadorAguasACambiado = _aCambiado; }
void Personaje::setContadorResiduosACambiado(bool _aCambiado) { this->contadorResiduosACambiado = _aCambiado; }
void Personaje::setContadorDeSemillasTotales(int _cantidad) { this->contadorSemillasTotales = _cantidad; }
void Personaje::setContadorDeResiduosTotales(int _cantidad) { this->contadorResiduosReciclables = _cantidad; }

void Personaje::borrar(int x, int y) {
	Console::SetCursorPosition(x, y + 1);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 2);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 3);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 4);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 5);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 6);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 7);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 8);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 9);  cout << "                                          ";
	Console::SetCursorPosition(x, y + 10); cout << "                                          ";
	Console::SetCursorPosition(x, y + 11); cout << "                                          ";
	Console::SetCursorPosition(x, y + 12); cout << "                                          ";
	Console::SetCursorPosition(x, y + 13); cout << "                                          ";
	Console::SetCursorPosition(x, y + 14); cout << "                                          ";
	Console::SetCursorPosition(x, y + 15); cout << "                                          ";
	Console::SetCursorPosition(x, y + 16); cout << "                                          ";
	Console::SetCursorPosition(x, y + 17); cout << "                                          ";
	Console::SetCursorPosition(x, y + 18); cout << "                                          ";
	Console::SetCursorPosition(x, y + 19); cout << "                                          ";
}
// Funciones para dibujar

void Personaje::dibujarGolemDerecha(int x, int y) {
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	Console::SetCursorPosition(x, y + 1);  cout << "                    #####                 ";
	Console::SetCursorPosition(x, y + 2);  cout << "                  #########               ";
	Console::SetCursorPosition(x, y + 3);  cout << "                  ###  #  ###             ";
	Console::SetCursorPosition(x, y + 4);  cout << "           ####  ###########   ####       ";
	Console::SetCursorPosition(x, y + 5);  cout << "     #### ############ # ##############   ";
	Console::SetCursorPosition(x, y + 6);  cout << "    #############  ### # ###  #########   ";
	Console::SetCursorPosition(x, y + 7);  cout << "    ### ######## # ### # # ####  #######  ";
	Console::SetCursorPosition(x, y + 8);  cout << "   ## # ######## #  #### ######  #######  ";
	Console::SetCursorPosition(x, y + 9);  cout << "  ###   ###### ####### # ### ##  ######## ";
	Console::SetCursorPosition(x, y + 10); cout << "###  ##########  ## ##  ######  ## #####  ";
	Console::SetCursorPosition(x, y + 11); cout << "## #### ############### # ########   #### ";
	Console::SetCursorPosition(x, y + 12); cout << "#   # ####  ###    ##### ####   ###    ## ";
	Console::SetCursorPosition(x, y + 13); cout << "#   ##  ##   #### #    #####    ###  ## # ";
	Console::SetCursorPosition(x, y + 14); cout << "#### # ###   # ############     ###  # ## ";
	Console::SetCursorPosition(x, y + 15); cout << "##  ######  ## #####   #####    ##  # ### ";
	Console::SetCursorPosition(x, y + 16); cout << " ###  ##    ## ###### ## ##      #######  ";
	Console::SetCursorPosition(x, y + 17); cout << "  #####       #############       #####   ";
	Console::SetCursorPosition(x, y + 18); cout << "               ###########                ";
	Console::SetCursorPosition(x, y + 19); cout << "                 ######                   ";
	Console::ForegroundColor = ConsoleColor::White;
}

void Personaje::dibujarGolemIzquierda(int x, int y) {
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	Console::SetCursorPosition(x, y + 1);  cout << "                 #####					  ";
	Console::SetCursorPosition(x, y + 2);  cout << "               #########				  ";
	Console::SetCursorPosition(x, y + 3);  cout << "               ###  #  ###				  ";
	Console::SetCursorPosition(x, y + 4);  cout << "        ####  ###########   ####		  ";
	Console::SetCursorPosition(x, y + 5);  cout << "     #### ############ # ##############   ";
	Console::SetCursorPosition(x, y + 6);  cout << "    #############  ### # ###  #########   ";
	Console::SetCursorPosition(x, y + 7);  cout << "    ### ######## # ### # # ####  #######  ";
	Console::SetCursorPosition(x, y + 8);  cout << "   ## # ######## #  #### ######  #######  ";
	Console::SetCursorPosition(x, y + 9);  cout << "  ###   ###### ####### # ### ##  ######## ";
	Console::SetCursorPosition(x, y + 10); cout << "###  ##########  ## ##  ######  ## #####  ";
	Console::SetCursorPosition(x, y + 11); cout << "## #### ############### # ########   #### ";
	Console::SetCursorPosition(x, y + 12); cout << "#   # ####  ###    ##### ####   ###    ## ";
	Console::SetCursorPosition(x, y + 13); cout << "#   ##  ##   #### #    #####    ###  ## # ";
	Console::SetCursorPosition(x, y + 14); cout << "#### # ###   # ############      ###  # ##";
	Console::SetCursorPosition(x, y + 15); cout << "##  ######  ## #####   #####     ##  # ###";
	Console::SetCursorPosition(x, y + 16); cout << " ###  ##    ## ###### ## ##       ####### ";
	Console::SetCursorPosition(x, y + 17); cout << "  #####       #############        #####  ";
	Console::SetCursorPosition(x, y + 18); cout << "               ###########                ";
	Console::SetCursorPosition(x, y + 19); cout << "                 ######                   ";
	Console::ForegroundColor = ConsoleColor::White;
}

void Personaje::dibujarGolemJugador() {
	Console::SetCursorPosition(x, y + 1); cout << "        ###        ";
	Console::SetCursorPosition(x, y + 2); cout << "       # # #       ";
	Console::SetCursorPosition(x, y + 3); cout << "       #####       ";
	Console::SetCursorPosition(x, y + 4); cout << "   ### ##### ###   ";
	Console::SetCursorPosition(x, y + 5); cout << "  ## ######### ##  ";
	Console::SetCursorPosition(x, y + 6); cout << " # ## ####### ## # ";
	Console::SetCursorPosition(x, y + 7); cout << "# ## # ##### # # ##";
	Console::SetCursorPosition(x, y + 8); cout << " ##   # ## #    ## ";
	Console::SetCursorPosition(x, y + 9); cout << "       ####        ";
}

void Personaje::dibujarGolemJugadorDerecha() {
	Console::SetCursorPosition(x, y + 1); cout << "         ###       ";
	Console::SetCursorPosition(x, y + 2); cout << "        # # #      ";
	Console::SetCursorPosition(x, y + 3); cout << "        #####      ";
	Console::SetCursorPosition(x, y + 4); cout << "   ### ##### ###   ";
	Console::SetCursorPosition(x, y + 5); cout << "  ## ######### ##  ";
	Console::SetCursorPosition(x, y + 6); cout << " # ## ####### ## # ";
	Console::SetCursorPosition(x, y + 7); cout << "# ## # ##### # # ##";
	Console::SetCursorPosition(x, y + 8); cout << " ##   # ## #    ## ";
	Console::SetCursorPosition(x, y + 9); cout << "     ####          ";
}

void Personaje::dibujarGolemJugadorIzquierda() {
	Console::SetCursorPosition(x, y + 1); cout << "       ###         ";
	Console::SetCursorPosition(x, y + 2); cout << "      # # #        ";
	Console::SetCursorPosition(x, y + 3); cout << "      #####        ";
	Console::SetCursorPosition(x, y + 4); cout << "   ### ##### ###   ";
	Console::SetCursorPosition(x, y + 5); cout << "  ## ######### ##  ";
	Console::SetCursorPosition(x, y + 6); cout << " # ## ####### ## # ";
	Console::SetCursorPosition(x, y + 7); cout << "# ## # ##### # # ##";
	Console::SetCursorPosition(x, y + 8); cout << " ##   # ## #    ## ";
	Console::SetCursorPosition(x, y + 9); cout << "         ####      ";
}

void Personaje::borrarGolemJugador() {
	Console::SetCursorPosition(x, y + 1); cout << "                   ";
	Console::SetCursorPosition(x, y + 2); cout << "                   ";
	Console::SetCursorPosition(x, y + 3); cout << "                   ";
	Console::SetCursorPosition(x, y + 4); cout << "                   ";
	Console::SetCursorPosition(x, y + 5); cout << "                   ";
	Console::SetCursorPosition(x, y + 6); cout << "                   ";
	Console::SetCursorPosition(x, y + 7); cout << "                   ";
	Console::SetCursorPosition(x, y + 8); cout << "                   ";
	Console::SetCursorPosition(x, y + 9); cout << "                   ";
}

void Personaje::dibujarGolemJugadorAtaqueDerecha() {
	Console::SetCursorPosition(x, y + 1); cout << "         ###       ";
	Console::SetCursorPosition(x, y + 2); cout << "        # # #      ";
	Console::SetCursorPosition(x, y + 3); cout << "        #####      ";
	Console::SetCursorPosition(x, y + 4); cout << "   ### ##### ###   ";
	Console::SetCursorPosition(x, y + 5); cout << "  ## ######### ##  ";
	Console::SetCursorPosition(x, y + 6); cout << " # ## ####### ## # ";
	Console::SetCursorPosition(x, y + 7); cout << "# ## # ##### ######";
	Console::SetCursorPosition(x, y + 8); cout << " ##   # ## #   ####";
	Console::SetCursorPosition(x, y + 9); cout << "     ####          ";
}

void Personaje::dibujarGolemJugadorAtaqueIzquierda() {
	Console::SetCursorPosition(x, y + 1); cout << "       ###         ";
	Console::SetCursorPosition(x, y + 2); cout << "      # # #        ";
	Console::SetCursorPosition(x, y + 3); cout << "      #####        ";
	Console::SetCursorPosition(x, y + 4); cout << "   ### ##### ###   ";
	Console::SetCursorPosition(x, y + 5); cout << "  ## ######### ##  ";
	Console::SetCursorPosition(x, y + 6); cout << "##### ####### ## # ";
	Console::SetCursorPosition(x, y + 7); cout << "#####  ##### # # ##";
	Console::SetCursorPosition(x, y + 8); cout << "      # ## #    ## ";
	Console::SetCursorPosition(x, y + 9); cout << "         ####      ";
}


void Personaje::dibujarGolemAtaqueDerecha() {
	Console::SetCursorPosition(x, y + 1);  cout << "                    #####					  ";
	Console::SetCursorPosition(x, y + 2);  cout << "                  #########					  ";
	Console::SetCursorPosition(x, y + 3);  cout << "                  ###  #  ###				  ";
	Console::SetCursorPosition(x, y + 4);  cout << "           ####  ###########   ####			  ";
	Console::SetCursorPosition(x, y + 5);  cout << "     #### ############ # ##############		  ";
	Console::SetCursorPosition(x, y + 6);  cout << "    #############  ### # ###  #########		  ";
	Console::SetCursorPosition(x, y + 7);  cout << "    ### ######## # ### # # ####  #######	  ";
	Console::SetCursorPosition(x, y + 8);  cout << "   ## # ######## #  #### ######  #######	  ";
	Console::SetCursorPosition(x, y + 9);  cout << "  ###   ###### ####### # ### ##  ########	  ";
	Console::SetCursorPosition(x, y + 10); cout << "###  ##########  ## ##  ######  ## #####	  ";
	Console::SetCursorPosition(x, y + 11); cout << "## #### ############### # ########   ######## ";
	Console::SetCursorPosition(x, y + 12); cout << "#   # ####  ###    ##### ####   ###    ##    #";
	Console::SetCursorPosition(x, y + 13); cout << "#   ##  ##   #### #    #####    ###  ## #    #";
	Console::SetCursorPosition(x, y + 14); cout << "#### # ###   # ############      ############ ";
	Console::SetCursorPosition(x, y + 15); cout << "##  ######  ## #####   #####                  ";
	Console::SetCursorPosition(x, y + 16); cout << " ###  ##    ## ###### ## ##                   ";
	Console::SetCursorPosition(x, y + 17); cout << "  #####       #############                   ";
	Console::SetCursorPosition(x, y + 18); cout << "               ###########                    ";
	Console::SetCursorPosition(x, y + 19); cout << "                 ######                       ";
}

void Personaje::dibujarGolemAtaqueIzquierda() {
	Console::SetCursorPosition(x, y + 1);  cout << "                      #####                    ";
	Console::SetCursorPosition(x, y + 2);  cout << "                    #########                  ";
	Console::SetCursorPosition(x, y + 3);  cout << "                    ###  #  ###                ";
	Console::SetCursorPosition(x, y + 4);  cout << "             ####  ###########   ####          ";
	Console::SetCursorPosition(x, y + 5);  cout << "          #### ############ # ##############   ";
	Console::SetCursorPosition(x, y + 6);  cout << "         #############  ### # ###  #########   ";
	Console::SetCursorPosition(x, y + 7);  cout << "         ### ######## # ### # # ####  #######  ";
	Console::SetCursorPosition(x, y + 8);  cout << "        ## # ######## #  #### ######  #######  ";
	Console::SetCursorPosition(x, y + 9);  cout << "       ###   ###### ####### # ### ##  ######## ";
	Console::SetCursorPosition(x, y + 10); cout << "     ###  ##########  ## ##  ######  ## #####  ";
	Console::SetCursorPosition(x, y + 11); cout << " ###### #### ############### # ########   #### ";
	Console::SetCursorPosition(x, y + 12); cout << "#    #   # ####  ###    ##### ####   ###    ## ";
	Console::SetCursorPosition(x, y + 13); cout << "#    #   ##  ##   #### #    #####    ###  ## # ";
	Console::SetCursorPosition(x, y + 14); cout << " ##############    # ############     ###  # ##";
	Console::SetCursorPosition(x, y + 15); cout << "                  ## #####   #####    ##  # ###";
	Console::SetCursorPosition(x, y + 16); cout << "                  ## ###### ## ##      ####### ";
	Console::SetCursorPosition(x, y + 17); cout << "                    #############       #####  ";
	Console::SetCursorPosition(x, y + 18); cout << "                    ###########                ";
	Console::SetCursorPosition(x, y + 19); cout << "                      ######                   ";
}

void Personaje::incrementarContadorInactividad() {
	contadorInactividad++;
}
void Personaje::resetearContadorInactividad() {
	contadorInactividad = 0;
}
bool Personaje::haPasadoIntervalo() {
	return contadorInactividad > framesParaInactividad;
}

void Personaje::dibujar() {
	Console::ForegroundColor = ConsoleColor::Cyan;

	if (haPasadoIntervalo()) {
		dibujarGolemJugador();
	}
	else if (estaAtacando) {
		if (this->izquierda) {
			dibujarGolemJugadorAtaqueIzquierda();
		}
		else if (this->derecha) {
			dibujarGolemJugadorAtaqueDerecha();
		}
	}
	else {
		if (!this->izquierda && !this->derecha) {
			dibujarGolemJugador();
		}
		else if (this->izquierda) {
			dibujarGolemJugadorIzquierda();
		}
		else if (this->derecha) {
			dibujarGolemJugadorDerecha();
		}
	}

	Console::ForegroundColor = ConsoleColor::White;
}

void Personaje::mover(char _tecla) {
	actualizarPosicionesAnteriores();
	this->estaAtacando = false;       
	this->interactuar = false;
	switch (_tecla) {
	case 'W'://Arriba
		if (y > Console::WindowTop + 7)
			y -= dy;
		break;
	case 'S'://Abajo
		if (y + alto < Console::WindowHeight - 22)
			y += dy;
		break;
	case 'A':  // Mover a la izquierda
		if (x > Console::WindowLeft + 10) {
			x -= dx;
			this->izquierda = true;
			this->derecha = false;
			resetearContadorInactividad();
		}
		break;

	case 'D':  // Mover a la derecha
		if (x + ancho < Console::WindowWidth - 100) {
			x += dx;
			this->derecha = true;
			this->izquierda = false;
			resetearContadorInactividad();
		}
		break;
	case 'F':  // Atacar
		borrarGolemJugador();
		this->estaAtacando = true;
		this->interactuar = false;
		resetearContadorInactividad();
		break;
	case 'E':
		if (colisionarRecurso) {
			Recurso* recursoActual = obtenerRecursoActual();
			if (recursoActual != nullptr && !recursoActual->getRecogido()) {
				// Marcar el recurso en el arreglo gestor como recogido
				recursoActual->setRecogido(true);
				recursoActual->setVisible(false);
				gestor->marcarRecursoRecogido(recursoActual->getId());
				
				// Aumentar contador de tipo de recursos
				// Si el recurso es de clase semilla le asignas a un puntero a semilla
				if (Semilla* semilla = dynamic_cast<Semilla*>(recursoActual)) {
					if (semilla->getTipo() == 1) {
						contadorSemillas++;
						contadorSemillasTotales++;
					}
					else if (semilla->getTipo() == 2) {
						contadorSemillasAgua++;
						contadorSemillasTotales++;
					}
				}
				// Contador Agua
				else if (Agua* agua = dynamic_cast<Agua*>(recursoActual)) {
					contadorAgua++;
				}
				// Contador Residuos Reciclables
				else if (ResiduosReciclables* residuos = dynamic_cast<ResiduosReciclables*>(recursoActual)) {
					if (residuos->getTipo() == 1) {
						contadorPapel++;
						contadorResiduosReciclables++;
					}
					else if (residuos->getTipo() == 2) {
						contadorPlastico++;
						contadorResiduosReciclables++;
					}
				}
				gestor->eliminarRecurso(recursoActual);
			}
		}

		if (descontaminarMar) {
			this->interactuar = true;
		}

		if (plantarArbol) {
			this->interactuar = true;
		}
		break;
	}
}

void Personaje::actualizarContadores() {
	if (contadorAgua != contadorAguaAntiguo) {
		contadorAguasACambiado = true;
		contadorAguaAntiguo = contadorAgua;
	}
	else {
		contadorAguasACambiado = false;
	}

	if (contadorSemillasTotales != contadorSemillasTotalesAntiguo) {
		contadorSemillasACambiado = true;
		contadorSemillasTotalesAntiguo = contadorSemillasTotales;
	}
	else {
		contadorSemillasACambiado = false;
	}

	if (contadorResiduosReciclablesAntiguo != contadorResiduosReciclables) {
		contadorResiduosACambiado = true;
		contadorResiduosReciclablesAntiguo = contadorResiduosReciclables;
	}
	else {
		contadorResiduosACambiado = false;
	}
}

void Personaje::perderVida(int _cantidad) {
	if (this->vida > 0) {
		this->vida -= _cantidad;
	}
}

void Personaje::ganarVida(int _cantidad) {
	if (this->vida >= 1) {
		this->vida += _cantidad;
	}
}

Rectangle Personaje::obtenerRectangulo() {
	return Rectangle(x, y, ancho, alto);
}

void Personaje::usarRecurso(int _idRecurso) {
	// Metodo en donde vamos a establecer que recurso usar
}

void Personaje::obtenerRecurso(int _idRecurso) {}

void Personaje::actualizarEstadoDeSalud() {
	if (vida < 0) {
		vida = 100;
		salud--;
		setVidasCambiadas(true);
	}
}