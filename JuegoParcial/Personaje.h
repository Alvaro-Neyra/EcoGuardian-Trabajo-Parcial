#pragma once
#include "Recurso.h"
#include <vector>
#include <string>
#include <iostream>
#include "GestorDeRecursos.h"

using namespace std;
using namespace System::Drawing;

class Personaje
{
private: 
	string nombre;
	int x;
	int y;
	int dx;
	int dy;
	int posicionXAnterior;
	int posicionYAnterior;
	int alto;
	int ancho;
	int vida;
	int salud;
	int contadorInactividad;
	int framesParaInactividad;
	int contadorSemillas;
	int contadorSemillasAgua;
	int contadorAgua;
	int contadorPapel;
	int contadorPlastico;
	int contadorSemillasTotales;
	int contadorResiduosReciclables;
	bool contadorSemillasACambiado;
	bool contadorAguasACambiado;
	bool contadorResiduosACambiado;
	int contadorSemillasTotalesAntiguo;
	int contadorAguaAntiguo;
	int contadorResiduosReciclablesAntiguo;
	long energia;
	bool izquierda, derecha;
	bool interactuar;
	bool estaAtacando;
	bool colisionarRecurso = false;
	bool vidasCambiadas = false;
	bool descontaminarMar;
	bool plantarArbol;
	GestorDeRecursos* gestor;
	Recurso* recursoRecogido;
public:
	Personaje();
	Personaje(string _nombre, int _x, int _y, int _dx, int _dy, int _vida, int _salud, long _energia);
	~Personaje();

	// Getters
	string getNombre();
	int getX();
	int getY();
	int getDX();
	int getDY();
	int getAlto();
	int getAncho();
	int getVida();
	int getSalud();
	long getEnergia();
	bool getColisionarRecurso();
	bool getInteractuar();
	GestorDeRecursos* getGestorDeRecursos();

	// Setters
	void setNombre(string _nombre);
	void setX(int _x);
	void setY(int _y);
	void setDX(int _dx);
	void setDY(int _dy);
	int getPosicionXAnterior();
	int getPosicionYAnterior();
	int getContadorSemillas();
	int getContadorSemillasAgua();
	int getContadorAgua();
	int getContadorPapel();
	int getContadorPlastico();
	int getContadorSemillasTotales();
	int getContadorResiduosReciclables();
	bool getVidasCambiadas();
	bool getDescontaminarMar();
	bool getPlantarArbol();
	bool getContadorSemillasACambiado();
	bool getContadorAguasACambiado();
	bool getContadorResiduosACambiado();
	bool getEstaAtacando();
	void setVida(int _vida);
	void setSalud(int _salud);
	void setEnergia(long _energia);
	void setIzquierda(bool _izquierda);
	void setDerecha(bool _derecha);
	void setPosicionXAnterior(int posicionX);
	void setPosicionYAnterior(int posicionY);
	void setEstaAtacando(bool _atacando);
	void setEstaInteractuando(bool _interactuando);
	void setPlantarArbol(bool _plantar);
	void actualizarPosicionesAnteriores();
	void setColisionarRecurso(bool _colisionar);
	void setContadorSemillas(int cantidad);
	void setContadorSemillasAgua(int _cantidad);
	void setContadorAgua(int cantidad);
	void setContadorPapel(int _cantidad);
	void setContadorPlastico(int _cantidad);
	void setVidasCambiadas(bool _vidasCambiadas);
	void setDescontaminarMar(bool _descontaminar);
	void setContadorSemillasACambiado(bool _aCambiado);
	void setContadorAguasACambiado(bool _aCambiado);
	void setContadorResiduosACambiado(bool _aCambiado);
	void setContadorDeSemillasTotales(int _cantidad);
	void setContadorDeResiduosTotales(int _cantidad);
	void actualizarContadores();
	// Otros metodos
	void borrar(int x, int y);
	void dibujarGolemDerecha(int x, int y);
	void dibujarGolemIzquierda(int x, int y);
	void dibujarGolemJugador();
	void dibujarGolemJugadorDerecha();
	void dibujarGolemJugadorIzquierda();
	void borrarGolemJugador();
	void dibujar();
	void mover(char _tecla);
	void perderVida(int _cantidad);
	void ganarVida(int _cantidad);
	void incrementarContadorInactividad();
	void resetearContadorInactividad();
	bool haPasadoIntervalo();
	Rectangle obtenerRectangulo();
	void usarRecurso(int _idRecurso);
	void obtenerRecurso(int _idRecurso);
	void dibujarGolemJugadorAtaqueDerecha();
	void dibujarGolemAtaqueDerecha();
	void dibujarGolemAtaqueIzquierda();
	void dibujarGolemJugadorAtaqueIzquierda();
	Recurso* obtenerRecursoActual();
	void setRecursoActual(Recurso* recurso);
	void actualizarEstadoDeSalud();
};