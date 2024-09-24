#pragma once
#include "pch.h"
#include <iostream>

using namespace System;
using namespace System::Drawing;
using namespace std;

class Recurso
{
	protected:
		int id;
		int especieRecurso;
		int x;
		int y;
		int alto;
		int ancho;
		bool visible;
		bool recogido;
	public: 
		Recurso();
		Recurso(int id, int _x, int _y, bool _invisible, bool _recogido);
		~Recurso();
		//Getters
		int getId();
		int getX();
		int getY();
		int getAlto();
		int getAncho();
		int getEspecieRecurso();
		bool getVisible();
		bool getRecogido();
		//Setters
		void setX(float _x);
		void setY(float _y);
		void setAlto(int _alto);
		void setAncho(int _ancho);
		void setVisible(bool _visible);
		void setRecogido(bool _recogido);
		// Otros metodos
		// Polimorficos
		virtual void dibujar() = 0;
		virtual void borrar() = 0;
		virtual void descripcion() = 0;
		// No polimorficos
		Rectangle obtenerRectangulo();
		Rectangle obtenerRectanguloRango();
};