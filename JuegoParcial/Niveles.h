#pragma once
#include <string>
#include <vector>
#include "IncendioForestal.h"
#include "ContaminacionAmbiental.h"
#include "ContaminacionHidrica.h"
#include "ContaminacionRadioactiva.h"


using namespace std;

class Personaje;
class Grafico;
class Juego;

class Niveles
{
private:
	int dificultad; // 1: facil  2: normal  3: dificil
	int tipo; // 1: IncendioForestal  2: ContaminacionHidrica  3: ContaminacionAmbiental  4: ContaminacionRadioactiva
	string descripcion;
	int nivelActual;
	int cantidadDeNiveles;
	int tiempoRestanteTotal;
	void primerNivel();
	void segundoNivel();
	void tercerNivel();
	void cuartoNivel();
	Juego* juego;
	ContaminacionAmbiental* contaminacionAmbiental;
	IncendioForestal* incendioForestal;
	ContaminacionRadioactiva* contaminacionRadioactiva;
	ContaminacionHidrica* contaminacionHidrica;
public:
	Niveles();
	Niveles(int _tipo, Juego* _juego, ContaminacionHidrica* contaminacionHidrica, IncendioForestal* incendioForestal, ContaminacionAmbiental* contaminacionAmbiental, ContaminacionRadioactiva* contaminacionRadioactiva);
	~Niveles();
	IncendioForestal* obtenerIncendioForestal();
	ContaminacionAmbiental* obtenerContaminacionAmbiental();
	ContaminacionHidrica* obtenerContaminacionHidrica();
	void iniciarNivel();
	void generar();
	void resuelto();
	void mostrarDesafio();
	void iniciarDesafio();
	void finDesafio();
	void getDescripcion(int _tipo);
	void getDificultad(int _tipo);
	void setNivel(int _nivel);
	int getNivelActual();
	int getTiempoRestanteTotal();
};