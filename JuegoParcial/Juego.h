#pragma once

#include <vector>
#include "Personaje.h"
#include "GestorDeRecursos.h"
#include "IncendioForestal.h"
#include "ContaminacionAmbiental.h"
#include "ContaminacionHidrica.h"
#include "ContaminacionRadioactiva.h"
#include "Recurso.h"

class Personaje;  // Declaración adelantada
class Grafico;
class Enemigo;
class Niveles;
class Recurso;
class ContaminacionAmbiental;
class IncendioForestal;
class ContaminacionRadioactiva;
class ContaminacionHidrica;

using namespace std;

class Juego
{
private:
    Personaje* guardian;
    Grafico* grafico;
    vector<Recurso*>* gestor;
    vector<Enemigo*> enemigos;
    float nivelDeContaminacion;
    Niveles* niveles;
    vector<pair<int, int>>* partesAPlantar;
    vector<pair<int, int>>* partesContaminadas;
    IncendioForestal* incendioForestal;
    ContaminacionHidrica* contaminacionHidrica;
    ContaminacionAmbiental* contaminacionAmbiental;
    ContaminacionRadioactiva* contaminacionRadioactiva;
    int cantidadEnemigos;
    int capacidadEnemigos;
    int cantidadNiveles;
    int capacidadNiveles;
    bool aguaContaminada;
    bool primeraPlantada;
    bool segundaPlantada;
    bool terceraPlantada;
    int cantidadSemillas;
    int contadorDeRondasContaminacion;
    int contadorPartesContaminadas;
    int contadorPartesSinContaminar;
    int porcentajeDeContaminacionDelMar;
    int porcentajeDeContaminacion;
    int contadorPlantas;
    int partesContaminadasActuales = 0;
    int contadorSemillasGeneradas = 0;
    int maxSemillas = 6;
    bool coordenadasRepetidas(vector<pair<int, int>>& partesAPlantar, int x, int y);
public:
    Juego();
    ~Juego();

    void iniciar();
    void ganaste();
    void perdiste();
    void agregarObjetos();
    void eliminarObjetos();
    void borrarObjetos();
    void moverObjetos();
    void dibujarObjetos();
    void detectarColiciones();
    void detectarGanador();
    Personaje* obtenerPersonaje();
    Grafico* obtenerGrafico();
    vector<pair<int, int>>* getVectorPartesContaminadas();
    vector<pair<int, int>>* getVectorPartesAPlantar();
    vector<int>* indicesAEliminarDelVectorPlantas;
    Niveles* obtenerNiveles();
    vector<Recurso*>* obtenerGestor();
    bool agregarParteContaminada(int x, int y);
    void descontaminarMar(int porcentajeDescontaminacion);
    void plantarArboles(int _cantidad);
    void mostrarHistoria();
    void mostrarInterfaz();
    void jugar();
    void nivelesMenu();
    void ayuda();
    void creditos();
    void salir();
    void reducirContaminacion();
    void actualizarEstado();
    void actualizarContaminacion();
    void mostrarBarraContaminacionGeneral();
    void inicializarRecursos();
    void inicializarRecursosPorNivel(int _nivel);
    int numeroAleatorio(int inicio, int final);
    void setContadorRondasContaminacion(int _contador);
    void setPorcentajeDeContaminacion(int _porcentaje);
    void setPorcentajeDeContaminacionMar(int _porcentajeContaminacionMar);
    int getContadorRondasContaminacion();
    int getPorcentajeDeContaminacion();
    int getPorcentajeDeContaminacionMar();
    bool getAguaContaminada();
    void setAguaContaminada(bool _aguaContaminada);
    void establecerPorcentajeDeContaminacion();
    int getContadorPlantas();
    void setContadorPlantas(int _contador);
    void reiniciarPartesAPlantar();
    int getPartesContaminadasActuales();
    void setPartesContaminadasActuales(int _cantidad);
};
