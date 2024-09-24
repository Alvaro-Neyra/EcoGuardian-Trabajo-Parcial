#include "pch.h"
#include "conio.h"
#include <iostream>
#include "Juego.h"
#include "Grafico.h"
#include "Personaje.h"
#include "Semilla.h"
#include "Agua.h"
#include "ResiduosReciclables.h"
#include "Niveles.h"
#include "ContaminacionAmbiental.h"
#include "ContaminacionHidrica.h"
#include "ContaminacionRadioactiva.h"
#include "IncendioForestal.h"

using namespace System;
using namespace std;

Juego::Juego() {
	string nombre = "Golem";
	int x = 10;
	int y = 10;
	int dx = 1;
	int dy = 1;
	int vida = 100;
	int salud = 5;
	long energia = 100;
	porcentajeDeContaminacionDelMar = 0;
	porcentajeDeContaminacion = 30;
	contadorPartesContaminadas = 0;
	contadorPartesSinContaminar = 0;	
	contadorPlantas = 0;
	aguaContaminada = false;
	primeraPlantada = false;
	segundaPlantada = false;
	terceraPlantada = false;
	partesContaminadasActuales = 0;
	guardian = new Personaje(nombre, x, y, dx, dy, vida, salud, energia);
	grafico = new Grafico(this);
	partesContaminadas = new vector<pair<int, int>>();
	partesAPlantar = new vector<pair<int, int>>();
	indicesAEliminarDelVectorPlantas = new vector<int>();
	gestor = guardian->getGestorDeRecursos()->getRecursos();
	cantidadSemillas = numeroAleatorio(1, 5);

	int intensidad = 10;
	int temperatura = 100;

    incendioForestal = new IncendioForestal(this, intensidad, temperatura);
	contaminacionHidrica = new ContaminacionHidrica(this);
	contaminacionAmbiental = new ContaminacionAmbiental(this);
	contaminacionRadioactiva = new ContaminacionRadioactiva(this);
	niveles = new Niveles(1, this, contaminacionHidrica, incendioForestal, contaminacionAmbiental, contaminacionRadioactiva);
}
Juego::~Juego() {
	for (Enemigo* enemigo : enemigos) {
		delete enemigo;
	}

	for (Recurso* recurso : (*gestor)) {
		delete recurso;
	}

	delete niveles;
	delete guardian;
	delete grafico;
	delete partesContaminadas;
}

void Juego::iniciar() {
	bool noSalirDelJuego = true;
	cout << "Cargando Juego..." << endl;
	getch();
	while (noSalirDelJuego) {
		int opcion = grafico->pantallaInicio();
		switch (opcion) {
			case 0: {
				grafico->chooseNameScreen();
				grafico->mostrarPantallaDeCarga();
				mostrarHistoria();
				system("cls");
				jugar();
				if (porcentajeDeContaminacionDelMar > 70 && niveles->getTiempoRestanteTotal() < 0) {
					system("cls");
					grafico->pantalla_perdedor_xd1();
					_getch();
				}
				else if (porcentajeDeContaminacionDelMar  < 70){
					system("cls");
					grafico->pantalla_ganador_xd1();
					_getch();
					_getch();
				}
				break;
			}
			case 1:
				nivelesMenu();
				break;
			case 2:
				ayuda();
				break;
			case 3:
				creditos();
				break;
			case 4:
				salir();
				noSalirDelJuego = false;
				break;
		}
	}
}

void Juego::jugar() {
	niveles->iniciarNivel();
}


void Juego::nivelesMenu() {
	int opcion = grafico->pantallaNiveles();
		switch (opcion) {
		case 0:
			system("cls");
			grafico->pantallaPrimerNivel();
			niveles->setNivel(1);
			niveles->iniciarNivel();
			break;
		case 1:
			system("cls");
			grafico->pantallaSegundoNivel();
			niveles->setNivel(2);
			niveles->iniciarNivel();
			break;
		case 2:
			system("cls");
			grafico->pantallaTercerNivel();
			niveles->setNivel(3);
			niveles->iniciarNivel();
			break;
		default:
			break;
		}
}
void Juego::ayuda() {
	grafico->pantallaAyuda();
	grafico->volverMenuPrincipal();
}
void Juego::creditos() {
	grafico->pantallaCreditos();
	grafico->volverMenuPrincipal();
}
void Juego::salir() {
	system("cls");
	cout << "Saliendo..." << endl;
}

void Juego::ganaste() {}
void Juego::perdiste() {}
void Juego::agregarObjetos() {}
void Juego::eliminarObjetos() {}
void Juego::borrarObjetos() {
	guardian->borrarGolemJugador();
	if (gestor->size() > 0) {		
		for (int i = 0; i < gestor->size(); i++) {
			if (!(*gestor)[i]->getVisible() && (*gestor)[i]->getRecogido()) {
				(*gestor)[i]->borrar();
			}
		}
	}
}
void Juego::moverObjetos() {}

void Juego::dibujarObjetos() {
	guardian->dibujar();

	if (gestor->size() > 0) {
		for (int i = 0; i < (*gestor).size(); i++) {
			if ((*gestor)[i]->getVisible() && !(*gestor)[i]->getRecogido()) {
				(*gestor)[i]->dibujar();
			}
		}
	}

	for (int i = 0; i < partesAPlantar->size(); i++) {
		int x = (*partesAPlantar)[i].first;
		int y = (*partesAPlantar)[i].second;
		grafico->dibujarPlanta(x, y);
	}
}

void Juego::detectarColiciones() {
	Rectangle guardianRect = guardian->obtenerRectangulo();
	bool colisionDetectada = false;
	bool rangoDeMarDetectada = false;
	bool rangoDePlantarDetectada = false;
	if (gestor->size() > 0) {
		for (int i = 0; i < gestor->size(); i++) {
			if (!(*gestor)[i]->getRecogido()) {
				Rectangle recursoRect = (*gestor)[i]->obtenerRectangulo();

				if (guardianRect.IntersectsWith(recursoRect)) {

					guardian->borrarGolemJugador();
					if (guardian->getX() > guardian->getPosicionXAnterior()) {
						guardian->setX(guardian->getPosicionXAnterior());
					}
					else if (guardian->getY() > guardian->getPosicionYAnterior()) {
						guardian->setY(guardian->getPosicionYAnterior());
					}
					else if (guardian->getX() < guardian->getPosicionXAnterior()) {
						guardian->setX(guardian->getPosicionXAnterior());
					}
					else if (guardian->getY() < guardian->getPosicionYAnterior()) {
						guardian->setY(guardian->getPosicionYAnterior());
					}
				}

				Rectangle recursoRectRango = (*gestor)[i]->obtenerRectanguloRango();
				if (guardianRect.IntersectsWith(recursoRectRango)) {
					colisionDetectada = true;
					guardian->setColisionarRecurso(true);
					guardian->setRecursoActual((*gestor)[i]);
					break;
				}
			}
		}
	}
	
	Rectangle marRango = grafico->getRectangleMarRango();
	if (guardianRect.IntersectsWith(marRango)) {
		rangoDeMarDetectada = true;
		guardian->setDescontaminarMar(true);
		Console::SetCursorPosition(250, 90);
	}


	Rectangle plantarAreaRect = grafico->getArbolesPlantarArea();
	if (guardianRect.IntersectsWith(plantarAreaRect)) {
		guardian->borrarGolemJugador();
		if (guardian->getX() > guardian->getPosicionXAnterior()) {
			guardian->setX(guardian->getPosicionXAnterior());
		}
		else if (guardian->getY() > guardian->getPosicionYAnterior()) {
			guardian->setY(guardian->getPosicionYAnterior());
		}
		else if (guardian->getX() < guardian->getPosicionXAnterior()) {
			guardian->setX(guardian->getPosicionXAnterior());
		}
		else if (guardian->getY() < guardian->getPosicionYAnterior()) {
			guardian->setY(guardian->getPosicionYAnterior());
		}
	}

	Rectangle plantarRango = grafico->getArbolesPlantarRango();

	if (guardianRect.IntersectsWith(plantarRango)) {
			rangoDePlantarDetectada = true;
			guardian->setPlantarArbol(true);
			Console::SetCursorPosition(250, 70);
	}

	if (niveles->getNivelActual() == 2 || niveles->getNivelActual() == 3) {
		Rectangle volcanRect = niveles->obtenerIncendioForestal()->obtenerVolcanRect();

		if (guardianRect.IntersectsWith(volcanRect)) {
			guardian->borrarGolemJugador();
			if (guardian->getX() > guardian->getPosicionXAnterior()) {
				guardian->setX(guardian->getPosicionXAnterior());
			}
			else if (guardian->getY() > guardian->getPosicionYAnterior()) {
				guardian->setY(guardian->getPosicionYAnterior());
			}
			else if (guardian->getX() < guardian->getPosicionXAnterior()) {
				guardian->setX(guardian->getPosicionXAnterior());
			}
			else if (guardian->getY() < guardian->getPosicionYAnterior()) {
				guardian->setY(guardian->getPosicionYAnterior());
			}
		}

		Rectangle bolaDeFuegoRect = niveles->obtenerIncendioForestal()->bolaDeFuegoRect();
		Rectangle bolaDeFuegoRectRango = niveles->obtenerIncendioForestal()->bolaDeFuegoRectRango();

		if (!partesAPlantar->empty()) {
			indicesAEliminarDelVectorPlantas->clear();

			for (int i = 0; i < partesAPlantar->size(); i++) {
				Rectangle plantaRect = Rectangle(partesAPlantar->at(i).first, partesAPlantar->at(i).second, 21, 14);
				if (bolaDeFuegoRect.IntersectsWith(plantaRect)) {
					grafico->borrarPlanta(partesAPlantar->at(i).first, partesAPlantar->at(i).second);
					indicesAEliminarDelVectorPlantas->push_back(i);
					niveles->obtenerIncendioForestal()->setColisionarConEnemigo(true);
				}
			}

			// Eliminando luego las coordenadas del vector plantas
			for (int i = indicesAEliminarDelVectorPlantas->size() - 1; i >= 0; i--) {
				partesAPlantar->erase(partesAPlantar->begin() + indicesAEliminarDelVectorPlantas->at(i));
			}
		}

		if (guardianRect.IntersectsWith(bolaDeFuegoRect)) {
			guardian->perderVida(niveles->obtenerIncendioForestal()->getIntensidad());
			niveles->obtenerIncendioForestal()->setColisionarConEnemigo(true);
		}

		if (guardianRect.IntersectsWith(bolaDeFuegoRectRango) && guardian->getEstaAtacando() && guardian->getContadorAgua() >= 1) {
			niveles->obtenerIncendioForestal()->generarBolaDeFuego();
			niveles->obtenerIncendioForestal()->setColisionarConEnemigo(false);
			guardian->setContadorAgua(guardian->getContadorAgua() - 1);
		}

		if (niveles->getNivelActual() == 3) {
			if (!niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->empty()) {
				for (int i = 0; i < niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->size(); i++) {
					int margen = max(niveles->obtenerContaminacionAmbiental()->getAncho(), niveles->obtenerContaminacionAmbiental()->getAlto());
					// Colision con el guardian
					Rectangle contaminacionRectActual = Rectangle(niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->at(i).first, niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->at(i).second, niveles->obtenerContaminacionAmbiental()->getAncho(), niveles->obtenerContaminacionAmbiental()->getAlto());
					Rectangle contaminacionRectActualRango = Rectangle(niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->at(i).first - margen, niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->at(i).second - margen, niveles->obtenerContaminacionAmbiental()->getAncho() + 2 * margen, niveles->obtenerContaminacionAmbiental()->getAlto() + 2 * margen);

					if (guardianRect.IntersectsWith(contaminacionRectActual)) {
						guardian->borrarGolemJugador();
						if (guardian->getX() > guardian->getPosicionXAnterior()) {
							guardian->setX(guardian->getPosicionXAnterior());
						}
						else if (guardian->getY() > guardian->getPosicionYAnterior()) {
							guardian->setY(guardian->getPosicionYAnterior());
						}
						else if (guardian->getX() < guardian->getPosicionXAnterior()) {
							guardian->setX(guardian->getPosicionXAnterior());
						}
						else if (guardian->getY() < guardian->getPosicionYAnterior()) {
							guardian->setY(guardian->getPosicionYAnterior());
						}
					}

					// Colision con el rango de eliminacion de basura

					if (guardianRect.IntersectsWith(contaminacionRectActualRango)) {
						if (guardian->getEstaAtacando() && (guardian->getContadorPapel() >= 1 || guardian->getContadorPlastico() >= 1)) {
							niveles->obtenerContaminacionAmbiental()->setColisionarConEnemigo(true);
							if (guardian->getContadorPlastico() >= 1) {
								guardian->setContadorPlastico(guardian->getContadorPlastico() - 1);
							}
							else {
								guardian->setContadorPapel(guardian->getContadorPapel() - 1);
							}
							niveles->obtenerContaminacionAmbiental()->borrarResiduo(niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->at(i).first, niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()->at(i).second);
							niveles->obtenerContaminacionAmbiental()->eliminarResiduosColisionados();
						}
					}
					else {
						niveles->obtenerContaminacionAmbiental()->setColisionarConEnemigo(false);
					}
				}
			}
		}
	}

	if (!colisionDetectada) {
		guardian->setColisionarRecurso(false);
		guardian->setRecursoActual(nullptr);
	}

	if (!rangoDeMarDetectada) {
		guardian->setDescontaminarMar(false);
	}

	if (!rangoDePlantarDetectada) {
		guardian->setPlantarArbol(false);
	}

	guardian->actualizarPosicionesAnteriores();
}

void Juego::detectarGanador() {}

Personaje* Juego::obtenerPersonaje() {
	return this->guardian;
}

Grafico* Juego::obtenerGrafico() {
	return this->grafico;
}

vector<pair<int, int>>* Juego::getVectorPartesContaminadas() {
	return this->partesContaminadas;
}

vector<pair<int, int>>* Juego::getVectorPartesAPlantar() {
	return this->partesAPlantar;
}

bool Juego::agregarParteContaminada(int x, int y) {
	pair<int, int> coordenada = make_pair(x, y);

	if (find(partesContaminadas->begin(), partesContaminadas->end(), coordenada) == partesContaminadas->end()) {
		partesContaminadas->push_back(coordenada);
		return true;
	}
	return false;
}

void Juego::descontaminarMar(int porcentajeDescontaminacion) {
	int partesADescontaminar = (porcentajeDescontaminacion * 268) / 100;

	for (int i = 0; i < partesADescontaminar; ++i) {
		pair<int, int> coordenada = partesContaminadas->back();

		Console::SetCursorPosition(coordenada.first, coordenada.second);
		Console::ForegroundColor = ConsoleColor::DarkBlue;
		cout << "~";

		partesContaminadas->pop_back();
	}

	setContadorRondasContaminacion(getContadorRondasContaminacion() - partesADescontaminar);
	establecerPorcentajeDeContaminacion();
}

bool Juego::coordenadasRepetidas(vector<pair<int, int>>& partesAPlantar, int x, int y) {
	for (int i = 0; i < partesAPlantar.size(); i++) {
		if (partesAPlantar[i].first == x && partesAPlantar[i].second == y) {
			return true;
		}
	}
	return false;
}

void Juego::plantarArboles(int _cantidad) {
	int yPlantarValor = 6;
	vector<pair<int, int>> coordenadas = {
		{148, yPlantarValor},
		{169, yPlantarValor},
		{190, yPlantarValor},
		{211, yPlantarValor},
		{232, yPlantarValor},
		{254, yPlantarValor}
	};

	if (partesAPlantar->size() >= coordenadas.size()) {
		return;
	}

	for (int i = 0; i < _cantidad && partesAPlantar->size() < coordenadas.size(); ++i) {
		if (!indicesAEliminarDelVectorPlantas->empty()) {
			int index = indicesAEliminarDelVectorPlantas->back();
			indicesAEliminarDelVectorPlantas->pop_back();
			partesAPlantar->push_back(coordenadas[index]);
			contadorPlantas++;
		}
		else {
			for (int j = 0; j < coordenadas.size(); j++) {
				if (!coordenadasRepetidas(*partesAPlantar, coordenadas[j].first, coordenadas[j].second)) {
					partesAPlantar->push_back(coordenadas[j]);
					contadorPlantas++;
					break;
				}
			}
		}
	}
}

void Juego::mostrarHistoria() {}

void Juego::mostrarInterfaz() {

}

void Juego::reducirContaminacion() {}
void Juego::actualizarEstado() {}
void Juego::actualizarContaminacion() {}
void Juego::mostrarBarraContaminacionGeneral() {}

void Juego::inicializarRecursos() {
	int cantidadRecursos = numeroAleatorio(1, 5);
	int x, y, alto = 1, ancho = 1, tipoRecurso, especie;
	bool visible = true;
	float purezaDelAgua = 0.0f;
	int cantidadBotella = 0;
	int tipoResiduo = 0;
	Rectangle plantarAreaRect = grafico->getArbolesPlantarRango();

	for (int i = 0; i < cantidadRecursos; ++i) {
		tipoRecurso = numeroAleatorio(1, 3);

		if (tipoRecurso == 1 && partesAPlantar->size() >= 6) {
			tipoRecurso = numeroAleatorio(2, 3);
		}

		switch (tipoRecurso) {
		case 1:
			especie = numeroAleatorio(1, 2);
			if (especie == 1) {
				ancho = 12;
				alto = 7;
			}
			else if (especie == 2) {
				ancho = 23;
				alto = 6;
			}
			break;
		case 2:
			especie = 0;
			alto = 7;
			ancho = 10;
			purezaDelAgua = numeroAleatorio(0, 100) / 100.0f;
			cantidadBotella = numeroAleatorio(1, 5);
			break;
		case 3:
			especie = 0;
			tipoResiduo = numeroAleatorio(1, 2);
			if (tipoResiduo == 1) {
				ancho = 19;
				alto = 11;
			}
			else if (tipoResiduo == 2) {
				ancho = 10;
				alto = 10;
			}
			break;
		}

		bool colisiona;
		do {
			x = numeroAleatorio(6, Console::WindowWidth - 145);
			y = numeroAleatorio(10, Console::WindowHeight - 25);
			colisiona = false;

			Rectangle nuevoRecursoRect = Rectangle(x, y, ancho, alto);
			Rectangle guardianRect = guardian->obtenerRectangulo();

			for (Recurso* recursoExistente : *gestor) {
				if (recursoExistente->obtenerRectangulo().IntersectsWith(nuevoRecursoRect)) {
					colisiona = true;
					break;
				}
			}

			if (plantarAreaRect.IntersectsWith(nuevoRecursoRect)) {
				colisiona = true;
			}

			if (guardianRect.IntersectsWith(nuevoRecursoRect)) {
				colisiona = true;
			}

		} while (colisiona);

		if (tipoRecurso == 1) {
			(*gestor).push_back(new Semilla(i, x, y, visible, false, especie));
		}
		else if (tipoRecurso == 2) {
			(*gestor).push_back(new Agua(i, x, y, visible, false, purezaDelAgua, cantidadBotella));
		}
		else if (tipoRecurso == 3) {
			(*gestor).push_back(new ResiduosReciclables(i, x, y, visible, false, tipoResiduo));
		}
	}
}

void Juego::inicializarRecursosPorNivel(int _nivel) {
	if (_nivel < 1 || _nivel > 4) {
		cout << "Tipo de recurso no válido." << endl;
		return;
	}

	int cantidadRecursos = numeroAleatorio(1, 5);
	int x, y, alto = 1, ancho = 1, especie;
	bool visible = true;
	float purezaDelAgua = 0.0f;
	int cantidadBotella = 0;
	int tipoResiduo = 0;
	int tipoDeRecurso = 0;
	Rectangle plantarAreaRect = grafico->getArbolesPlantarRango();

	for (int i = 0; i < cantidadRecursos; ++i) {
		switch (_nivel) {
		case 1:
			tipoDeRecurso = 1;
			especie = numeroAleatorio(1, 2);

			if (partesAPlantar->size() >= 6) {
				especie = 2;
			}

			if (especie == 1) {
				ancho = 12;
				alto = 7;
			}
			else if (especie == 2) {
				ancho = 23;
				alto = 6;
			}

			break;
		case 2: {
			tipoDeRecurso = numeroAleatorio(1, 2);
			if (tipoDeRecurso == 1) {
				especie = numeroAleatorio(1, 2);

				if (partesAPlantar->size() >= 6) {
					especie = 2;
				}

				if (especie == 1) {
					ancho = 12;
					alto = 7;
				}
				else if (especie == 2) {
					ancho = 23;
					alto = 6;
				}
			} else if (tipoDeRecurso == 2) {
				especie = 0;
				alto = 7;
				ancho = 10;
				purezaDelAgua = numeroAleatorio(0, 100) / 100.0f;
				cantidadBotella = numeroAleatorio(1, 5);
			}
			break;
		}
		case 3:
			tipoDeRecurso = numeroAleatorio(1, 3);
			if (tipoDeRecurso == 1) {
				especie = numeroAleatorio(1, 2);

				if (partesAPlantar->size() >= 6) {
					especie = 2;
				}

				if (especie == 1) {
					ancho = 12;
					alto = 7;
				}
				else if (especie == 2) {
					ancho = 23;
					alto = 6;
				}
			}
			else if (tipoDeRecurso == 2) {
				especie = 0;
				alto = 7;
				ancho = 10;
				purezaDelAgua = numeroAleatorio(0, 100) / 100.0f;
				cantidadBotella = numeroAleatorio(1, 5);
			}
			else if (tipoDeRecurso == 3) {
				tipoDeRecurso = numeroAleatorio(1, 3);
				especie = 0;
				tipoResiduo = numeroAleatorio(1, 2);
				alto = 10;
				ancho = 10;
			}
			break;
		}

		bool colisiona;
		do {
			x = numeroAleatorio(6, Console::WindowWidth - 150);
			y = numeroAleatorio(10, Console::WindowHeight - 29);
			colisiona = false;

			Rectangle nuevoRecursoRect = Rectangle(x, y, ancho, alto);
			Rectangle guardianRect = guardian->obtenerRectangulo();
			Rectangle volcanRect = niveles->obtenerIncendioForestal()->obtenerVolcanRect();
			Rectangle bolaDeFuegoRect = niveles->obtenerIncendioForestal()->bolaDeFuegoRect();

			for (Recurso* recursoExistente : *gestor) {
				if (recursoExistente->obtenerRectangulo().IntersectsWith(nuevoRecursoRect)) {
					colisiona = true;
					break;
				}
			}

			if (plantarAreaRect.IntersectsWith(nuevoRecursoRect)) {
				colisiona = true;
			}

			if (guardianRect.IntersectsWith(nuevoRecursoRect)) {
				colisiona = true;
			}

			if (volcanRect.IntersectsWith(nuevoRecursoRect)) {
				colisiona = true;
			}

			if (bolaDeFuegoRect.IntersectsWith(nuevoRecursoRect)) {
				colisiona = true;
			}

			if (_nivel == 3) {
				for (pair<int,int>& coordenadasResiduos : *niveles->obtenerContaminacionAmbiental()->obtenerResiduosGenerados()) {
					Rectangle residuoRect(coordenadasResiduos.first, coordenadasResiduos.second, ancho, alto);
					if (residuoRect.IntersectsWith(nuevoRecursoRect)) {
						colisiona = true;
						break;
					}
				}
			}

		} while (colisiona);

		if (_nivel == 1) {
			(*gestor).push_back(new Semilla(i, x, y, visible, false, especie));
		}
		else if (_nivel == 2) {
			if (tipoDeRecurso == 1) {
				(*gestor).push_back(new Semilla(i, x, y, visible, false, especie));
			}
			else {
				(*gestor).push_back(new Agua(i, x, y, visible, false, purezaDelAgua, cantidadBotella));
			}
		}
		else if (_nivel == 3) {
			if (tipoDeRecurso == 1) {
				(*gestor).push_back(new Semilla(i, x, y, visible, false, especie));
			}
			else if (tipoDeRecurso == 2) {
				(*gestor).push_back(new Agua(i, x, y, visible, false, purezaDelAgua, cantidadBotella));
			}
			else {
				(*gestor).push_back(new ResiduosReciclables(i, x, y, visible, false, tipoResiduo));
			}
		}
	}
}


int Juego::numeroAleatorio(int inicio, int final) {
    return inicio + rand() % (final - inicio + 1);
}

void Juego::setContadorRondasContaminacion(int _contador) {
	this->contadorDeRondasContaminacion = _contador;
}

int Juego::getContadorRondasContaminacion() {
	return this->contadorDeRondasContaminacion;
}

void Juego::setPorcentajeDeContaminacion(int _porcentaje) {
	this->porcentajeDeContaminacion = _porcentaje;
}

int Juego::getPorcentajeDeContaminacion() {
	return this->porcentajeDeContaminacion;
}

void Juego::setPorcentajeDeContaminacionMar(int _porcentajeContaminacionMar) {
	this->porcentajeDeContaminacionDelMar = _porcentajeContaminacionMar;
}

int Juego::getPorcentajeDeContaminacionMar() {
	return this->porcentajeDeContaminacionDelMar;
}

void Juego::establecerPorcentajeDeContaminacion() {
	int totalCaracteresMar = 19 * 268;

	partesContaminadasActuales = partesContaminadas->size() + (niveles->obtenerContaminacionAmbiental()->getContadorResiduos());

	porcentajeDeContaminacionDelMar = (partesContaminadasActuales * 100) / totalCaracteresMar;

	if (porcentajeDeContaminacionDelMar > 100) {
		porcentajeDeContaminacionDelMar = 100;
	}

	if (porcentajeDeContaminacionDelMar < 0) {
		porcentajeDeContaminacionDelMar = 0;
	}
	
	grafico->barraDeContaminacion();
}

bool Juego::getAguaContaminada() {
	return this->aguaContaminada;
}

void Juego::setAguaContaminada(bool _aguaContaminada) {
	this->aguaContaminada = _aguaContaminada;
}

int Juego::getContadorPlantas() {
	return this->contadorPlantas;
}

void Juego::setContadorPlantas(int _contador) {
	this->contadorPlantas = _contador;
}

void Juego::reiniciarPartesAPlantar() {
	partesAPlantar->clear();

	primeraPlantada = false;
	segundaPlantada = false;
	terceraPlantada = false;
}

Niveles* Juego::obtenerNiveles() {
	return niveles;
}

vector<Recurso*>* Juego::obtenerGestor() {
	return gestor;
}

int Juego::getPartesContaminadasActuales() {
	return this->partesContaminadasActuales;
}

void Juego::setPartesContaminadasActuales(int _cantidad) {
	this->partesContaminadasActuales = _cantidad;
}