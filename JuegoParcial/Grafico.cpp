#include "pch.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <ctime>
#include "Grafico.h"
#include "Juego.h"
#include "Personaje.h"

using namespace System;
using namespace std;

// Funciones de abajo
void Grafico::gotoXY(int x, int y) {

    Console::SetCursorPosition(x, y);
}

void Grafico::dibujarLineaH(int x, int y, int tam) {
    for (int i = 1; i <= tam * 2; i += 2) {
        gotoXY(x + i, y);
        cout << "* ";
    }
}

void Grafico::dibujarLineaIncompleta(int x, int y, int tamanho) {
    for (int i = 1; i <= tamanho * 2; i += 2) {

        gotoXY(x + i, y);
        if (i == 1 || i == ((tamanho * 2) - 1)) {
            cout << "*";
        }
        else {
            cout << " ";
        }


    }
}

void Grafico::dibujarRectanguloHueco(int x, int y, int largo, int ancho) {
    for (int i = 1; i < ancho; i++) {
        if (i == 1) {
            dibujarLineaH(x, y + i, largo);
        }
        else {
            dibujarLineaIncompleta(x, y + i, largo);
        }
    }
    dibujarLineaH(x, y + ancho, largo);
}


//letras
void Grafico::dibujarletraA(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@@@@@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraB(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@@@@ ";
}

void Grafico::dibujarletraC(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@    ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void Grafico::dibujarletraD(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@@@@ ";
}

void Grafico::dibujarletraE(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

void Grafico::dibujarletraF(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@    ";
}

void Grafico::dibujarletraG(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@ @@@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void Grafico::dibujarletraH(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@@@@@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraI(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "  @  ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << "  @  ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

void Grafico::dibujarletraJ(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "    @";
    gotoXY(x, y + 3); cout << "    @";
    gotoXY(x, y + 4); cout << "    @";
    gotoXY(x, y + 5); cout << " @  @";
    gotoXY(x, y + 6); cout << " @@@@";
}

void Grafico::dibujarletraK(int x, int y) {
    gotoXY(x, y + 1); cout << "@  @ ";
    gotoXY(x, y + 2); cout << "@ @  ";
    gotoXY(x, y + 3); cout << "@@   ";
    gotoXY(x, y + 4); cout << "@ @  ";
    gotoXY(x, y + 5); cout << "@  @ ";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraL(int x, int y) {
    gotoXY(x, y + 1); cout << "@    ";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << "@    ";
    gotoXY(x, y + 4); cout << "@    ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

void Grafico::dibujarletraM(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@@ @@";
    gotoXY(x, y + 3); cout << "@ @ @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraN(int x, int y) {
    gotoXY(x, y + 1); cout << "@@  @";
    gotoXY(x, y + 2); cout << "@ @ @";
    gotoXY(x, y + 3); cout << "@  @@";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraO(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void Grafico::dibujarletraP(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@@@@ ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@    ";
}

void Grafico::dibujarletraQ(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@ @ @";
    gotoXY(x, y + 5); cout << "@  @@";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void Grafico::dibujarletraR(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@@@@ ";
    gotoXY(x, y + 5); cout << "@  @ ";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraS(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@";
    gotoXY(x, y + 2); cout << "@    ";
    gotoXY(x, y + 3); cout << " @@@ ";
    gotoXY(x, y + 4); cout << "    @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void Grafico::dibujarletraT(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "  @  ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << "  @  ";
    gotoXY(x, y + 6); cout << "  @  ";
}

void Grafico::dibujarletraU(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << "@   @";
    gotoXY(x, y + 6); cout << " @@@ ";
}

void Grafico::dibujarletraV(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@   @";
    gotoXY(x, y + 5); cout << " @ @ ";
    gotoXY(x, y + 6); cout << "  @  ";
}

void Grafico::dibujarletraW(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << "@   @";
    gotoXY(x, y + 4); cout << "@ @ @";
    gotoXY(x, y + 5); cout << "@@ @@";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraX(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << " @ @ ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << " @ @ ";
    gotoXY(x, y + 6); cout << "@   @";
}

void Grafico::dibujarletraY(int x, int y) {
    gotoXY(x, y + 1); cout << "@   @";
    gotoXY(x, y + 2); cout << "@   @";
    gotoXY(x, y + 3); cout << " @ @ ";
    gotoXY(x, y + 4); cout << "  @  ";
    gotoXY(x, y + 5); cout << "  @  ";
    gotoXY(x, y + 6); cout << "  @  ";
}

void Grafico::dibujarletraZ(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@@";
    gotoXY(x, y + 2); cout << "   @ ";
    gotoXY(x, y + 3); cout << "  @  ";
    gotoXY(x, y + 4); cout << " @   ";
    gotoXY(x, y + 5); cout << "@    ";
    gotoXY(x, y + 6); cout << "@@@@@";
}

//numeros
void Grafico::dibujarnumero0(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |    |  ";
    gotoXY(x, y + 4); cout << "  |    |  ";
    gotoXY(x, y + 5); cout << "  |____|  ";
}

void Grafico::dibujarnumero1(int x, int y) {
    gotoXY(x, y + 1); cout << "          ";
    gotoXY(x, y + 2); cout << "    |     ";
    gotoXY(x, y + 3); cout << "    |     ";
    gotoXY(x, y + 4); cout << "    |     ";
    gotoXY(x, y + 5); cout << "    |     ";
}

void Grafico::dibujarnumero2(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "       |  ";
    gotoXY(x, y + 3); cout << "   ____|  ";
    gotoXY(x, y + 4); cout << "  |       ";
    gotoXY(x, y + 5); cout << "  |____   ";
}

void Grafico::dibujarnumero3(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "       |  ";
    gotoXY(x, y + 3); cout << "   ____|  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "   ____|  ";
}

void Grafico::dibujarnumero4(int x, int y) {
    gotoXY(x, y + 1); cout << "          ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |____|  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "       |  ";
}

void Grafico::dibujarnumero5(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |       ";
    gotoXY(x, y + 3); cout << "  |____   ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "   ____|  ";
}

void Grafico::dibujarnumero6(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |       ";
    gotoXY(x, y + 3); cout << "  |____   ";
    gotoXY(x, y + 4); cout << "  |    |  ";
    gotoXY(x, y + 5); cout << "  |____|  ";
}

void Grafico::dibujarnumero7(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "       |  ";
    gotoXY(x, y + 3); cout << "       |  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "       |  ";
}

void Grafico::dibujarnumero8(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |____|  ";
    gotoXY(x, y + 4); cout << "  |    |  ";
    gotoXY(x, y + 5); cout << "  |____|  ";
}

void Grafico::dibujarnumero9(int x, int y) {
    gotoXY(x, y + 1); cout << "   ____   ";
    gotoXY(x, y + 2); cout << "  |    |  ";
    gotoXY(x, y + 3); cout << "  |____|  ";
    gotoXY(x, y + 4); cout << "       |  ";
    gotoXY(x, y + 5); cout << "       |  ";
}

//caracteres
void Grafico::flechitajsjsjs(int x, int y) {
    gotoXY(x, y + 1); cout << "      @    ";
    gotoXY(x, y + 2); cout << "        @  ";
    gotoXY(x, y + 3); cout << "  @@@@@   @";
    gotoXY(x, y + 4); cout << "  @@@@@   @";
    gotoXY(x, y + 5); cout << "        @  ";
    gotoXY(x, y + 6); cout << "      @    ";
}

void Grafico::borrarflechitajsjsjs(int x, int y) {
    gotoXY(x, y + 1); cout << "           ";
    gotoXY(x, y + 2); cout << "           ";
    gotoXY(x, y + 3); cout << "           ";
    gotoXY(x, y + 4); cout << "           ";
    gotoXY(x, y + 5); cout << "           ";
    gotoXY(x, y + 6); cout << "           ";
}

void Grafico::fleschitajsjajsja(int x, int y) {
    gotoXY(x, y + 2); cout << "  @  ";
    gotoXY(x, y + 3); cout << "@@  @";
    gotoXY(x, y + 4); cout << "@@  @";
    gotoXY(x, y + 5); cout << "  @  ";
}

void Grafico::borrar_fleschitajsjajsja(int x, int y) {
    gotoXY(x, y + 2); cout << "     ";
    gotoXY(x, y + 3); cout << "     ";
    gotoXY(x, y + 4); cout << "     ";
    gotoXY(x, y + 5); cout << "     ";
}

void Grafico::dibujarparentesisabierto(int x, int y) {
    gotoXY(x, y + 1); cout << " @";
    gotoXY(x, y + 2); cout << "@ ";
    gotoXY(x, y + 3); cout << "@ ";
    gotoXY(x, y + 4); cout << "@ ";
    gotoXY(x, y + 5); cout << "@ ";
    gotoXY(x, y + 6); cout << " @";
}

void Grafico::dibujarparentesiscerrado(int x, int y) {
    gotoXY(x, y + 1); cout << "@ ";
    gotoXY(x, y + 2); cout << " @";
    gotoXY(x, y + 3); cout << " @";
    gotoXY(x, y + 4); cout << " @";
    gotoXY(x, y + 5); cout << " @";
    gotoXY(x, y + 6); cout << "@ ";
}


void Grafico::number9(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << " _|";
}
void Grafico::number8(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "|_|";
}
void Grafico::number7(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "  |";
    gotoXY(x, y + 3); cout << "  |";
}
void Grafico::number6(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_ ";
    gotoXY(x, y + 3); cout << "|_|";
}
void Grafico::number5(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_ ";
    gotoXY(x, y + 3); cout << " _|";
}
void Grafico::number4(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "  |";
}
void Grafico::number3(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << " _|";
    gotoXY(x, y + 3); cout << " _|";
}
void Grafico::number2(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << " _|";
    gotoXY(x, y + 3); cout << "|_ ";
}
void Grafico::number1(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "  |";
    gotoXY(x, y + 3); cout << "  |";
}
void Grafico::number0(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "| |";
    gotoXY(x, y + 3); cout << "|_|";
}

void Grafico::dibujarnumeroMejor0(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@ ";
    gotoXY(x, y + 2); cout << "@    @";
    gotoXY(x, y + 3); cout << "@    @";
    gotoXY(x, y + 4); cout << "@    @";
    gotoXY(x, y + 5); cout << "@    @";
    gotoXY(x, y + 6); cout << " @@@@ ";
}

void Grafico::dibujarnumeroMejor1(int x, int y) {
    gotoXY(x, y + 1); cout << "@";
    gotoXY(x, y + 2); cout << "@";
    gotoXY(x, y + 3); cout << "@";
    gotoXY(x, y + 4); cout << "@";
    gotoXY(x, y + 5); cout << "@";
    gotoXY(x, y + 6); cout << "@";
}

void Grafico::dibujarnumeroMejor2(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@ ";
    gotoXY(x, y + 2); cout << "@   @@";
    gotoXY(x, y + 3); cout << "   @@ ";
    gotoXY(x, y + 4); cout << " @@   ";
    gotoXY(x, y + 5); cout << "@@    ";
    gotoXY(x, y + 6); cout << "@@@@@@";
}

void Grafico::dibujarnumeroMejor3(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "    @";
    gotoXY(x, y + 3); cout << "@@@@ ";
    gotoXY(x, y + 4); cout << "    @";
    gotoXY(x, y + 5); cout << "    @";
    gotoXY(x, y + 6); cout << "@@@@ ";
}

void Grafico::dibujarnumeroMejor4(int x, int y) {
    gotoXY(x, y + 1); cout << "@    @";
    gotoXY(x, y + 2); cout << "@    @";
    gotoXY(x, y + 3); cout << " @@@@@";
    gotoXY(x, y + 4); cout << "     @";
    gotoXY(x, y + 5); cout << "     @";
    gotoXY(x, y + 6); cout << "     @";
}

void Grafico::dibujarnumeroMejor5(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@ ";
    gotoXY(x, y + 2); cout << "@     ";
    gotoXY(x, y + 3); cout << " @@@@ ";
    gotoXY(x, y + 4); cout << "     @";
    gotoXY(x, y + 5); cout << "     @";
    gotoXY(x, y + 6); cout << " @@@@ ";
}

void Grafico::dibujarnumeroMejor6(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@ ";
    gotoXY(x, y + 2); cout << "@     ";
    gotoXY(x, y + 3); cout << " @@@@ ";
    gotoXY(x, y + 4); cout << "@    @";
    gotoXY(x, y + 5); cout << "@    @";
    gotoXY(x, y + 6); cout << " @@@@ ";
}

void Grafico::dibujarnumeroMejor7(int x, int y) {
    gotoXY(x, y + 1); cout << "@@@@ ";
    gotoXY(x, y + 2); cout << "    @";
    gotoXY(x, y + 3); cout << "    @";
    gotoXY(x, y + 4); cout << "    @";
    gotoXY(x, y + 5); cout << "    @";
    gotoXY(x, y + 6); cout << "    @";
}

void Grafico::dibujarnumeroMejor8(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@ ";
    gotoXY(x, y + 2); cout << "@    @";
    gotoXY(x, y + 3); cout << " @@@@ ";
    gotoXY(x, y + 4); cout << "@    @";
    gotoXY(x, y + 5); cout << "@    @";
    gotoXY(x, y + 6); cout << " @@@@ ";
}

void Grafico::dibujarnumeroMejor9(int x, int y) {
    gotoXY(x, y + 1); cout << " @@@@ ";
    gotoXY(x, y + 2); cout << "@    @";
    gotoXY(x, y + 3); cout << " @@@@@";
    gotoXY(x, y + 4); cout << "     @";
    gotoXY(x, y + 5); cout << "     @";
    gotoXY(x, y + 6); cout << "     @";
}

void Grafico::borrarnumeroMejor0(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

void Grafico::borrarnumeroMejor1(int x, int y) {
    gotoXY(x, y + 1); cout << " ";
    gotoXY(x, y + 2); cout << " ";
    gotoXY(x, y + 3); cout << " ";
    gotoXY(x, y + 4); cout << " ";
    gotoXY(x, y + 5); cout << " ";
    gotoXY(x, y + 6); cout << " ";
}

void Grafico::borrarnumeroMejor2(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

void Grafico::borrarnumeroMejor3(int x, int y) {
    gotoXY(x, y + 1); cout << "     ";
    gotoXY(x, y + 2); cout << "     ";
    gotoXY(x, y + 3); cout << "     ";
    gotoXY(x, y + 4); cout << "     ";
    gotoXY(x, y + 5); cout << "     ";
    gotoXY(x, y + 6); cout << "     ";
}

void Grafico::borrarnumeroMejor4(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

void Grafico::borrarnumeroMejor5(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

void Grafico::borrarnumeroMejor6(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

void Grafico::borrarnumeroMejor7(int x, int y) {
    gotoXY(x, y + 1); cout << "     ";
    gotoXY(x, y + 2); cout << "     ";
    gotoXY(x, y + 3); cout << "     ";
    gotoXY(x, y + 4); cout << "     ";
    gotoXY(x, y + 5); cout << "     ";
    gotoXY(x, y + 6); cout << "     ";
}

void Grafico::borrarnumeroMejor8(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

void Grafico::borrarnumeroMejor9(int x, int y) {
    gotoXY(x, y + 1); cout << "      ";
    gotoXY(x, y + 2); cout << "      ";
    gotoXY(x, y + 3); cout << "      ";
    gotoXY(x, y + 4); cout << "      ";
    gotoXY(x, y + 5); cout << "      ";
    gotoXY(x, y + 6); cout << "      ";
}

//letras pequeñas
void Grafico::a(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "| |";
}

void Grafico::b(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_)";
    gotoXY(x, y + 3); cout << "|_)";
}

void Grafico::c(int x, int y) {
    gotoXY(x, y + 1); cout << " __";
    gotoXY(x, y + 2); cout << "|  ";
    gotoXY(x, y + 3); cout << "|__";
}

void Grafico::d(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "| \\";
    gotoXY(x, y + 3); cout << "|_/";
}

void Grafico::e(int x, int y) {
    gotoXY(x, y + 1); cout << " __";
    gotoXY(x, y + 2); cout << "|__";
    gotoXY(x, y + 3); cout << "|__";
}

void Grafico::f(int x, int y) {
    gotoXY(x, y + 1); cout << " __";
    gotoXY(x, y + 2); cout << "|__";
    gotoXY(x, y + 3); cout << "|  ";
}

void Grafico::g(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << " _|";
}

void Grafico::h(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "| |";
}

void Grafico::ii(int x, int y) {
    gotoXY(x, y + 1); cout << "_ _";
    gotoXY(x, y + 2); cout << " | ";
    gotoXY(x, y + 3); cout << "_|_";
}

void Grafico::j(int x, int y) {
    gotoXY(x, y + 1); cout << "__ ";
    gotoXY(x, y + 2); cout << "  |";
    gotoXY(x, y + 3); cout << "\\_|";
}

void Grafico::k(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|/ ";
    gotoXY(x, y + 3); cout << "|\\ ";
}

void Grafico::l(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|  ";
    gotoXY(x, y + 3); cout << "|__";
}

void Grafico::m(int x, int y) {
    gotoXY(x, y + 1); cout << "    ";
    gotoXY(x, y + 2); cout << "|\\/|";
    gotoXY(x, y + 3); cout << "|  |";
}

void Grafico::n(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "|\\|";
    gotoXY(x, y + 3); cout << "| |";
}

void Grafico::o(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "| |";
    gotoXY(x, y + 3); cout << "|_|";
}

void Grafico::p(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "|  ";
}

void Grafico::q(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "  |";
}

void Grafico::r(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_|";
    gotoXY(x, y + 3); cout << "|\\ ";
}

void Grafico::s(int x, int y) {
    gotoXY(x, y + 1); cout << " _ ";
    gotoXY(x, y + 2); cout << "|_ ";
    gotoXY(x, y + 3); cout << " _|";
}

void Grafico::t(int x, int y) {
    gotoXY(x, y + 1); cout << "___";
    gotoXY(x, y + 2); cout << " | ";
    gotoXY(x, y + 3); cout << " | ";
}

void Grafico::u(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "| |";
    gotoXY(x, y + 3); cout << "|_|";
}

void Grafico::v(int x, int y) {
    gotoXY(x, y + 1); cout << "    ";
    gotoXY(x, y + 2); cout << "|  |";
    gotoXY(x, y + 3); cout << " \\/ ";
}

void Grafico::w(int x, int y) {
    gotoXY(x, y + 1); cout << "    ";
    gotoXY(x, y + 2); cout << "|  |";
    gotoXY(x, y + 3); cout << "|/\\|";
}

void Grafico::xx(int x, int y) {
    gotoXY(x, y + 1); cout << "   ";
    gotoXY(x, y + 2); cout << "\\/ ";
    gotoXY(x, y + 3); cout << "/\\";
}

void Grafico::yy(int x, int y) {
    gotoXY(x, y + 1); cout << "  ";
    gotoXY(x, y + 2); cout << "\\/";
    gotoXY(x, y + 3); cout << "/ ";
}

void Grafico::z(int x, int y) {
    gotoXY(x, y + 1); cout << "__ ";
    gotoXY(x, y + 2); cout << " / ";
    gotoXY(x, y + 3); cout << "/_ ";
}

void Grafico::coma(int x, int y) {
    gotoXY(x, y + 3); cout << "|";
}

void Grafico::puntoycoma(int x, int y) {
    gotoXY(x, y + 1); cout << "|-|";
    gotoXY(x, y + 2); cout << "   ";
    gotoXY(x, y + 3); cout << "|  ";
}

void Grafico::dospuntos(int x, int y) {
    gotoXY(x, y + 1); cout << "|-|";
    gotoXY(x, y + 2); cout << "   ";
    gotoXY(x, y + 3); cout << "|-|";
}

void Grafico::dospuntosGrande(int x, int y) {
    gotoXY(x, y + 2); cout << "/\\";
    gotoXY(x, y + 3); cout << "\\/";
    gotoXY(x, y + 4); cout << "/\\";
    gotoXY(x, y + 5); cout << "\\/";
}

void Grafico::porcentaje(int x, int y) {
    gotoXY(x, y + 1); cout << " @   @";
    gotoXY(x, y + 2); cout << "@@@ @ ";
    gotoXY(x, y + 3); cout << " @ @  ";
    gotoXY(x, y + 4); cout << "  @ @ ";
    gotoXY(x, y + 5); cout << " @ @@@";
    gotoXY(x, y + 6); cout << "@   @ ";
}

void Grafico::admiracion(int x, int y) {
    gotoXY(x, y + 2); cout << "|";
    gotoXY(x, y + 3); cout << "-";
}

void Grafico::punto(int x, int y) {
    gotoXY(x, y + 3); cout << "|-|";
}

void Grafico::guion(int x, int y) {
    gotoXY(x, y + 2); cout << "--";
}

void Grafico::textoPequenio(string tex, int x, int y) {
    for (int i = 0; i < tex.length(); i++) {
        switch (tex[i]) {
        case 'A': case 'a': a(x, y); break;
        case 'Á': case 'á': a(x, y); break;
        case 'B': case 'b': b(x, y); break;
        case 'C': case 'c': c(x, y); break;
        case 'D': case 'd': d(x, y); break;
        case 'E': case 'e': e(x, y); break;
        case 'É': case 'é': e(x, y); break;
        case 'F': case 'f': f(x, y); break;
        case 'G': case 'g': g(x, y); break;
        case 'H': case 'h': h(x, y); break;
        case 'I': case 'i': ii(x, y); break;
        case 'Í': case 'í': ii(x, y); break;
        case 'J': case 'j': j(x, y); break;
        case 'K': case 'k': k(x, y); break;
        case 'L': case 'l': l(x, y); break;
        case 'M': case 'm': m(x, y); break;
        case 'N': case 'n': n(x, y); break;
        case 'O': case 'o': o(x, y); break;
        case 'Ó': case 'ó': o(x, y); break;
        case 'P': case 'p': p(x, y); break;
        case 'Q': case 'q': q(x, y); break;
        case 'R': case 'r': r(x, y); break;
        case 'S': case 's': s(x, y); break;
        case 'T': case 't': t(x, y); break;
        case 'U': case 'u': u(x, y); break;
        case 'Ú': case 'ú': u(x, y); break;
        case 'V': case 'v': v(x, y); break;
        case 'W': case 'w': w(x, y); break;
        case 'X': case 'x': xx(x, y); break;
        case 'Y': case 'y': yy(x, y); break;
        case 'Z': case 'z': z(x, y); break;
        case '0': number0(x, y); break;
        case '1': number1(x, y); break;
        case '2': number2(x, y); break;
        case '3': number3(x, y); break;
        case '4': number4(x, y); break;
        case '5': number5(x, y); break;
        case '6': number6(x, y); break;
        case '7': number7(x, y); break;
        case '8': number8(x, y); break;
        case '9': number9(x, y); break;
        case ',': coma(x, y); break;
        case '!': admiracion(x, y); break;
        case ':': dospuntos(x, y); break;
        case ';': puntoycoma(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case ' ':
            break;
        default: break;
        }
        if (tex[i] == '0') {
            x += 4;
        }
        else if (tex[i] == '1') {
            x += 4;
        }
        else if (tex[i] == '2') {
            x += 4;
        }
        else if (tex[i] == '3') {
            x += 4;
        }
        else if (tex[i] == '4') {
            x += 4;
        }
        else if (tex[i] == '5') {
            x += 4;
        }
        else if (tex[i] == '6') {
            x += 4;
        }
        else if (tex[i] == '7') {
            x += 4;
        }
        else if (tex[i] == '8') {
            x += 4;
        }
        else if (tex[i] == '9') {
            x += 4;
        }
        else if (tex[i] == 'a') {
            x += 4;
        }
        else if (tex[i] == 'b') {
            x += 4;
        }
        else if (tex[i] == 'c') {
            x += 4;
        }
        else if (tex[i] == 'd') {
            x += 4;
        }
        else if (tex[i] == 'e') {
            x += 4;
        }
        else if (tex[i] == 'f') {
            x += 4;
        }
        else if (tex[i] == 'g') {
            x += 4;
        }
        else if (tex[i] == 'h') {
            x += 4;
        }
        else if (tex[i] == 'i') {
            x += 4;
        }
        else if (tex[i] == 'j') {
            x += 4;
        }
        else if (tex[i] == 'k') {
            x += 4;
        }
        else if (tex[i] == 'l') {
            x += 4;
        }
        else if (tex[i] == 'm') {
            x += 5;
        }
        else if (tex[i] == 'n') {
            x += 4;
        }
        else if (tex[i] == 'o') {
            x += 4;
        }
        else if (tex[i] == 'p') {
            x += 4;
        }
        else if (tex[i] == 'q') {
            x += 4;
        }
        else if (tex[i] == 'r') {
            x += 4;
        }
        else if (tex[i] == 's') {
            x += 4;
        }
        else if (tex[i] == 't') {
            x += 4;
        }
        else if (tex[i] == 'u') {
            x += 4;
        }
        else if (tex[i] == 'v') {
            x += 5;
        }
        else if (tex[i] == 'w') {
            x += 5;
        }
        else if (tex[i] == 'x') {
            x += 4;
        }
        else if (tex[i] == 'y') {
            x += 3;
        }
        else if (tex[i] == 'z') {
            x += 3;
        }
        else if (tex[i] == '!') {
            x += 2;
        }
        else if (tex[i] == '.') {
            x += 4;
        }
        else if (tex[i] == ':') {
            x += 4;
        }
        else if (tex[i] == ';') {
            x += 4;
        }
        else if (tex[i] == ',') {
            x += 2;
        }
        else if (tex[i] == '-') {
            x += 3;
        }
        else if (tex[i] == ' ') {
            x += 1;
        }
        else if (tex[i] != ' ') {
            x += 4; // Espacio entre caracteres
        }
        _sleep(60);
    }

}
void Grafico::textoGrande(string instruccion, int x, int y) {
    for (int i = 0; i < instruccion.length(); i++) {
        switch (instruccion[i]) {
        case 'A': dibujarletraA(x, y); break;
        case 'B': dibujarletraB(x, y); break;
        case 'C': dibujarletraC(x, y); break;
        case 'D': dibujarletraD(x, y); break;
        case 'E': dibujarletraE(x, y); break;
        case 'F': dibujarletraF(x, y); break;
        case 'G': dibujarletraG(x, y); break;
        case 'H': dibujarletraH(x, y); break;
        case 'I': dibujarletraI(x, y); break;
        case 'J': dibujarletraJ(x, y); break;
        case 'K': dibujarletraK(x, y); break;
        case 'L': dibujarletraL(x, y); break;
        case 'M': dibujarletraM(x, y); break;
        case 'N': dibujarletraN(x, y); break;
        case 'O': dibujarletraO(x, y); break;
        case 'P': dibujarletraP(x, y); break;
        case 'Q': dibujarletraQ(x, y); break;
        case 'R': dibujarletraR(x, y); break;
        case 'S': dibujarletraS(x, y); break;
        case 'T': dibujarletraT(x, y); break;
        case 'U': dibujarletraU(x, y); break;
        case 'V': dibujarletraV(x, y); break;
        case 'W': dibujarletraW(x, y); break;
        case 'X': dibujarletraX(x, y); break;
        case 'Y': dibujarletraY(x, y); break;
        case 'Z': dibujarletraZ(x, y); break;
        case '(': dibujarparentesisabierto(x, y); break;
        case ')': dibujarparentesiscerrado(x, y); break;
        case ',': coma(x, y + 1); break;
        case ':': dospuntos(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case '%': porcentaje(x, y); break;
        case '0': dibujarnumeroMejor0(x, y); break;
        case '1': dibujarnumeroMejor1(x, y); break;
        case '2': dibujarnumeroMejor2(x, y); break;
        case '3': dibujarnumeroMejor3(x, y); break;
        case '4': dibujarnumeroMejor4(x, y); break;
        case '5': dibujarnumeroMejor5(x, y); break;
        case '6': dibujarnumeroMejor6(x, y); break;
        case '7': dibujarnumeroMejor7(x, y); break;
        case '8': dibujarnumeroMejor8(x, y); break;
        case '9': dibujarnumeroMejor9(x, y); break;
        case ' ': break;
        default: break;
        }

        if (instruccion[i] == '(' || instruccion[i] == ')') {
            x += 3;
        }
        else if (instruccion[i] != ' ') {
            x += 6;
        }
        else if (instruccion[i] == '%') {
            x += 7;
        }
        else if (instruccion[i] == '0') {
            x += 7;
        }
        else if (instruccion[i] == '1') {
            x += 2;
        }
        else if (instruccion[i] == '2') {
            x += 7;
        }
        else if (instruccion[i] == '3') {
            x += 6;
        }
        else if (instruccion[i] == '4') {
            x += 7;
        }
        else if (instruccion[i] == '5') {
            x += 7;
        }
        else if (instruccion[i] == '6') {
            x += 7;
        }
        else if (instruccion[i] == '7') {
            x += 6;
        }
        else if (instruccion[i] == '8') {
            x += 7;
        }
        else if (instruccion[i] == '9') {
            x += 7;
        }
        else {
            x += 2;
        }
        _sleep(60);
    }
}

void Grafico::textoGrandeSinSleep(string instruccion, int x, int y) {
    for (int i = 0; i < instruccion.length(); i++) {
        switch (instruccion[i]) {
        case 'A': dibujarletraA(x, y); break;
        case 'B': dibujarletraB(x, y); break;
        case 'C': dibujarletraC(x, y); break;
        case 'D': dibujarletraD(x, y); break;
        case 'E': dibujarletraE(x, y); break;
        case 'F': dibujarletraF(x, y); break;
        case 'G': dibujarletraG(x, y); break;
        case 'H': dibujarletraH(x, y); break;
        case 'I': dibujarletraI(x, y); break;
        case 'J': dibujarletraJ(x, y); break;
        case 'K': dibujarletraK(x, y); break;
        case 'L': dibujarletraL(x, y); break;
        case 'M': dibujarletraM(x, y); break;
        case 'N': dibujarletraN(x, y); break;
        case 'O': dibujarletraO(x, y); break;
        case 'P': dibujarletraP(x, y); break;
        case 'Q': dibujarletraQ(x, y); break;
        case 'R': dibujarletraR(x, y); break;
        case 'S': dibujarletraS(x, y); break;
        case 'T': dibujarletraT(x, y); break;
        case 'U': dibujarletraU(x, y); break;
        case 'V': dibujarletraV(x, y); break;
        case 'W': dibujarletraW(x, y); break;
        case 'X': dibujarletraX(x, y); break;
        case 'Y': dibujarletraY(x, y); break;
        case 'Z': dibujarletraZ(x, y); break;
        case '(': dibujarparentesisabierto(x, y); break;
        case ')': dibujarparentesiscerrado(x, y); break;
        case ',': coma(x, y + 1); break;
        case ':': dospuntosGrande(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case '%': porcentaje(x, y); break;
        case '0': dibujarnumeroMejor0(x, y); break;
        case '1': dibujarnumeroMejor1(x, y); break;
        case '2': dibujarnumeroMejor2(x, y); break;
        case '3': dibujarnumeroMejor3(x, y); break;
        case '4': dibujarnumeroMejor4(x, y); break;
        case '5': dibujarnumeroMejor5(x, y); break;
        case '6': dibujarnumeroMejor6(x, y); break;
        case '7': dibujarnumeroMejor7(x, y); break;
        case '8': dibujarnumeroMejor8(x, y); break;
        case '9': dibujarnumeroMejor9(x, y); break;
        case ' ': break;
        default: break;
        }

        if (instruccion[i] == '(' || instruccion[i] == ')') {
            x += 3;
        }
        else if (instruccion[i] != ' ') {
            x += 6;
        }
        else if (instruccion[i] == '%') {
            x += 7;
        }
        else if (instruccion[i] == '0') {
            x += 7;
        }
        else if (instruccion[i] == '1') {
            x += 2;
        }
        else if (instruccion[i] == '2') {
            x += 7;
        }
        else if (instruccion[i] == '3') {
            x += 6;
        }
        else if (instruccion[i] == '4') {
            x += 7;
        }
        else if (instruccion[i] == '5') {
            x += 7;
        }
        else if (instruccion[i] == '6') {
            x += 7;
        }
        else if (instruccion[i] == '7') {
            x += 6;
        }
        else if (instruccion[i] == '8') {
            x += 7;
        }
        else if (instruccion[i] == '9') {
            x += 7;
        }
        else {
            x += 2;
        }
    }
}

void Grafico::textoPequenioSinSleep(string tex, int x, int y) {
    for (int i = 0; i < tex.length(); i++) {
        switch (tex[i]) {
        case 'A': case 'a': a(x, y); break;
        case 'Á': case 'á': a(x, y); break;
        case 'B': case 'b': b(x, y); break;
        case 'C': case 'c': c(x, y); break;
        case 'D': case 'd': d(x, y); break;
        case 'E': case 'e': e(x, y); break;
        case 'É': case 'é': e(x, y); break;
        case 'F': case 'f': f(x, y); break;
        case 'G': case 'g': g(x, y); break;
        case 'H': case 'h': h(x, y); break;
        case 'I': case 'i': ii(x, y); break;
        case 'Í': case 'í': ii(x, y); break;
        case 'J': case 'j': j(x, y); break;
        case 'K': case 'k': k(x, y); break;
        case 'L': case 'l': l(x, y); break;
        case 'M': case 'm': m(x, y); break;
        case 'N': case 'n': n(x, y); break;
        case 'O': case 'o': o(x, y); break;
        case 'Ó': case 'ó': o(x, y); break;
        case 'P': case 'p': p(x, y); break;
        case 'Q': case 'q': q(x, y); break;
        case 'R': case 'r': r(x, y); break;
        case 'S': case 's': s(x, y); break;
        case 'T': case 't': t(x, y); break;
        case 'U': case 'u': u(x, y); break;
        case 'Ú': case 'ú': u(x, y); break;
        case 'V': case 'v': v(x, y); break;
        case 'W': case 'w': w(x, y); break;
        case 'X': case 'x': xx(x, y); break;
        case 'Y': case 'y': yy(x, y); break;
        case 'Z': case 'z': z(x, y); break;
        case '0': number0(x, y); break;
        case '1': number1(x, y); break;
        case '2': number2(x, y); break;
        case '3': number3(x, y); break;
        case '4': number4(x, y); break;
        case '5': number5(x, y); break;
        case '6': number6(x, y); break;
        case '7': number7(x, y); break;
        case '8': number8(x, y); break;
        case '9': number9(x, y); break;
        case ',': coma(x, y); break;
        case '!': admiracion(x, y); break;
        case ':': dospuntos(x, y); break;
        case ';': puntoycoma(x, y); break;
        case '.': punto(x, y); break;
        case '-': guion(x, y); break;
        case '(': dibujarparentesisabierto(x, y); break;
        case ')': dibujarparentesiscerrado(x, y); break;
        case ' ': break;
        default: break;
        }
        if (tex[i] == '0') {
            x += 4;
        }
        else if (tex[i] == '1') {
            x += 4;
        }
        else if (tex[i] == '2') {
            x += 4;
        }
        else if (tex[i] == '3') {
            x += 4;
        }
        else if (tex[i] == '4') {
            x += 4;
        }
        else if (tex[i] == '5') {
            x += 4;
        }
        else if (tex[i] == '6') {
            x += 4;
        }
        else if (tex[i] == '7') {
            x += 4;
        }
        else if (tex[i] == '8') {
            x += 4;
        }
        else if (tex[i] == '9') {
            x += 4;
        }
        else if (tex[i] == 'a') {
            x += 4;
        }
        else if (tex[i] == 'b') {
            x += 4;
        }
        else if (tex[i] == 'c') {
            x += 4;
        }
        else if (tex[i] == 'd') {
            x += 4;
        }
        else if (tex[i] == 'e') {
            x += 4;
        }
        else if (tex[i] == 'f') {
            x += 4;
        }
        else if (tex[i] == 'g') {
            x += 4;
        }
        else if (tex[i] == 'h') {
            x += 4;
        }
        else if (tex[i] == 'i') {
            x += 4;
        }
        else if (tex[i] == 'j') {
            x += 4;
        }
        else if (tex[i] == 'k') {
            x += 4;
        }
        else if (tex[i] == 'l') {
            x += 4;
        }
        else if (tex[i] == 'm') {
            x += 5;
        }
        else if (tex[i] == 'n') {
            x += 4;
        }
        else if (tex[i] == 'o') {
            x += 4;
        }
        else if (tex[i] == 'p') {
            x += 4;
        }
        else if (tex[i] == 'q') {
            x += 4;
        }
        else if (tex[i] == 'r') {
            x += 4;
        }
        else if (tex[i] == 's') {
            x += 4;
        }
        else if (tex[i] == 't') {
            x += 4;
        }
        else if (tex[i] == 'u') {
            x += 4;
        }
        else if (tex[i] == 'v') {
            x += 5;
        }
        else if (tex[i] == 'w') {
            x += 5;
        }
        else if (tex[i] == 'x') {
            x += 4;
        }
        else if (tex[i] == 'y') {
            x += 3;
        }
        else if (tex[i] == 'z') {
            x += 3;
        }
        else if (tex[i] == '!') {
            x += 2;
        }
        else if (tex[i] == '.') {
            x += 4;
        }
        else if (tex[i] == ':') {
            x += 4;
        }
        else if (tex[i] == ';') {
            x += 4;
        }
        else if (tex[i] == ',') {
            x += 2;
        }
        else if (tex[i] == '-') {
            x += 3;
        }
        else if (tex[i] == ' ') {
            x += 1;
        }
        else if (tex[i] != ' ') {
            x += 4;
        }
    }
}

void Grafico::dibujarLlave(int x, int y) {
    gotoXY(x, y + 1);   cout << "     @@@   ";
    gotoXY(x, y + 2);   cout << "     @     ";
    gotoXY(x, y + 3);   cout << "     @@@   ";
    gotoXY(x, y + 4);   cout << "     @     ";
    gotoXY(x, y + 5);   cout << "    @@@    ";
    gotoXY(x, y + 6);   cout << "   @   @   ";
    gotoXY(x, y + 7);   cout << "    @@@    ";
}

void Grafico::dibujarMoldeLlave(int x, int y) {
    gotoXY(x, y + 1);   cout << "@@@@@@@@@@@";
    gotoXY(x, y + 2);   cout << "@@@@@   @@@";
    gotoXY(x, y + 3);   cout << "@@@@@ @@@@@";
    gotoXY(x, y + 4);   cout << "@@@@@   @@@";
    gotoXY(x, y + 5);   cout << "@@@@@ @@@@@";
    gotoXY(x, y + 6);   cout << "@@@@   @@@@";
    gotoXY(x, y + 7);   cout << "@@@ @@@ @@@";
    gotoXY(x, y + 8);   cout << "@@@@   @@@@";
    gotoXY(x, y + 9);   cout << "@@@@@@@@@@@";
}



void Grafico::drawScreenTitle(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkCyan;
    dibujarRectanguloHueco(x + 2, y + 2, 116, 8);
    textoGrandeSinSleep("ECOGUARDIAN: EL ULTIMO DEFENSOR DE LA VIDA", x + 5, y + 3);
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::drawIniciarInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    textoGrandeSinSleep ("INICIAR", x + 5, y + 3);
}

void Grafico::drawNivelesInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 23, 8);
    textoGrandeSinSleep("NIVELES", x + 5, y + 3);
}

void Grafico::drawAyudaInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 17, 8);
    textoGrandeSinSleep("AYUDA", x + 5, y + 3);
}

void Grafico::drawCreditosInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 26, 8);
    textoGrandeSinSleep("CREDITOS", x + 5, y + 3);
}

void Grafico::drawSalirInput(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 17, 8);
    textoGrandeSinSleep("SALIR", x + 5, y + 3);
}

void Grafico::drawScreenStart() {
    drawScreenTitle(Console::WindowWidth / 5 , 1);
    drawIniciarInput(20, 10);
    drawNivelesInput(20, 20);
    drawAyudaInput(20, 30);
    drawCreditosInput(20, 40);
    drawSalirInput(20, 50);
}

void Grafico::drawScreenNameTitle(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkCyan;
    dibujarRectanguloHueco(x + 2, y + 2, 33, 8);
    textoGrandeSinSleep("CHOOSE NAME", x+5, y+3);
    Console::ForegroundColor = ConsoleColor::White;
}

Grafico::Grafico(Juego* juego) {
    this->juego = juego;
}

Grafico::~Grafico() {}

void Grafico::chooseNameScreen() {
    system("cls");
    bool nombreValidado = false;
    while (!nombreValidado) {
        string nombre;
        bool esSoloLetras = true;
        drawScreenNameTitle(Console::WindowWidth / 3 + 10, 1);
        dibujarRectanguloHueco(Console::WindowWidth / 3 + 20, 16, 20, 3);
        juego->obtenerPersonaje()->dibujarGolemIzquierda(Console::WindowWidth / 2 + 15, 40);
        gotoXY(Console::WindowWidth / 3 + 28, 18);
        cin >> nombre;
        for (char c : nombre) {
            if (!isalpha(c)) {
                esSoloLetras = false;
                break;
            }
        }

        gotoXY(Console::WindowWidth / 3 + 22, 30);
        if (esSoloLetras && !nombre.empty() && nombre.size() <= 20) {
            juego->obtenerPersonaje()->setNombre(nombre);
            cout << "Nombre ingresado correctamente: " << juego->obtenerPersonaje()->getNombre() << endl;
            nombreValidado = true;
        }
        else {
            cout << "Nombre invalido. Solo se permiten letras y un maximo de 20 caracteres." << endl;
            _getch();
            system("cls");
        }
    }
}

int Grafico::screenStart() {
    int opcion = 0;
    int opcionAnterior = -1;
    char key;
    int etapa = 0;
    int casee = 8;

    drawScreenStart();

    flechitajsjsjs(8, 13 + opcion * 10);

    while (true) {
        key = _getch();      
        switch (key) {
            case 72:
                opcionAnterior = opcion;
                opcion = (opcion - 1 + 5) % 5; // mueve hacia arriba
                break;
            case 80:
                opcionAnterior = opcion;
                opcion = (opcion + 1 + 5) % 5; // Mueve hacia abajo
                break;
        }

        // Si se cambio la opcion, cambia la posicion de la flecha
        if (opcionAnterior != opcion) {
            borrarflechitajsjsjs(8, 13 + opcionAnterior * 10);
            flechitajsjsjs(8, 13 + opcion * 10);
        }

        if (key == 13) {
            system("cls");
            switch (opcion) {
                case 0:
                    return 0;
                case 1:
                    return 1;
                case 2:
                    return 2;
                case 3:
                    return 3;
                case 4:
                    return 4;
            }
        }
    }
}

int Grafico::nivelesStart() {
    int opcion = 0;
    int opcionAnterior = -1;
    char key;
    bool pintarBoton = false;

    flechitajsjsjs(8, 20 + opcion * 10);
    pantallaNivelesTexto();

    while (true) {
        if (pintarBoton) {
            Console::ForegroundColor = ConsoleColor::Yellow;
            botonMenu(Console::WindowWidth / 3 + 20, 80);
            Console::ForegroundColor = ConsoleColor::White;
        }
        else {
            botonMenu(Console::WindowWidth / 3 + 20, 80);
        }
        key = _getch();
        key = toupper(key);
        switch (key) {
        case 72:
            opcionAnterior = opcion;
            opcion = (opcion - 1 + 3) % 3;
            pintarBoton = false;
            break;
        case 80:
            opcionAnterior = opcion;
            opcion = (opcion + 1 + 3) % 3;
            pintarBoton = false;
            break;
        }

        if (opcionAnterior != opcion) {
            borrarflechitajsjsjs(8, 20 + opcionAnterior * 10);
            flechitajsjsjs(8, 20 + opcion * 10);
        }

        if (key == 13 && pintarBoton == false) {
            system("cls");
            switch (opcion) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 2;
            }
        }

        if (key == 'M') {
            pintarBoton = true;
        }

        if (pintarBoton && key == 13) {
            opcion = -1;
            return opcion;
        }
    }
}

int Grafico::pantallaInicio() {
    system("cls");
    int opcion = screenStart();
    return opcion;
}

void Grafico::pantallaNivelesTexto() {
    textoGrandeSinSleep("NIVELES", 160, 5);
    dibujarRectanguloHueco(38, 19, 62, 8);
    textoGrandeSinSleep("CONTAMINACION HIDRICA", 40, 20);
    dibujarRectanguloHueco(38, 29, 50, 8);
    textoGrandeSinSleep("INCENDIO FORESTAL", 40, 30);
    dibujarRectanguloHueco(38, 39, 68, 8);
    textoGrandeSinSleep("CONTAMINACION AMBIENTAL", 40, 40);
}

int Grafico::pantallaNiveles() {
    system("cls");
    int opcion = nivelesStart();
    return opcion;
}

void Grafico::pantallaAyuda() {
    system("cls");
    pantallaAyudaMision();

    _getch();
    system("cls");
    pantallaAyudaPersonajePrincipal();

    _getch();
    system("cls");
    pantallaAyudaRecursos();

}

void Grafico::pantallaCreditos() {
    system("cls");
    textoGrandeSinSleep("CREDITOS", 160, 5);

    textoGrandeSinSleep("DIBUJAR: ", 260, 20);

    textoGrandeSinSleep("- ALVARO NEYRA", 260, 30);
    textoGrandeSinSleep("- IVAN CARRILLO", 260, 37);
    textoGrandeSinSleep("- JOAO JIMENEZ", 260, 44);

    textoGrandeSinSleep("CODIGO: ", 140, 20);

    textoGrandeSinSleep("- ALVARO NEYRA", 140, 30);
    textoGrandeSinSleep("- IVAN CARRILLO", 140, 37);
    textoGrandeSinSleep("- JOAO JIMENEZ", 140, 44);

    textoGrandeSinSleep("DIAGRAMA DE CLASES:", 5, 20);

    textoGrandeSinSleep("- ALVARO NEYRA", 5, 30);
    textoGrandeSinSleep("- IVAN CARRILLO", 5, 37);
    textoGrandeSinSleep("- JOAO JIMENEZ", 5, 44);
}

void Grafico::pantallaSalir(){
    cout << "Saliendo del Juego..." << endl;
    _getch();
    Console::Clear();
}

void Grafico::mostrarPantallaDeCarga() {
    animateLoadingBar(Console::WindowWidth - 100, Console::WindowHeight - 20, 1, 25);
}

void Grafico::mostrarPantallaGanador() {

}

void Grafico::mostrarPantallaPerdedor() {

}

void Grafico::dibujarBarraStats(int x, int y, int vida, int MAX_STAT, string titulo, ConsoleColor color) {
    gotoXY(x + 2, y + 2); cout << "  " << titulo << "    ";
    gotoXY(x + 20, y + 2);
    for (int i = 0; i < MAX_STAT; ++i) {
        if (i < vida) {
            Console::ForegroundColor = color;
            cout << "/";
            Console::ForegroundColor = ConsoleColor::White;
        }
        else {
            cout << " ";
        }
    }
}

void Grafico::animateLoadingBar(int x, int y, int repeticiones, int tamanio) {
    int contador = 1;
    int coordenadaBarraX = x + 2;
    int coordenadaBarraY = y + 2;
    gotoXY(x + 1, y); cout << "LOADING....";
    while (contador <= repeticiones) {
        dibujarRectanguloHueco(x, y, tamanio, 3);
        gotoXY(coordenadaBarraX, coordenadaBarraY);
        for (int i = 0; i < (tamanio + 20); i++) {
            gotoXY(coordenadaBarraX + i, coordenadaBarraY);
            cout << " ";
        }
        Console::ForegroundColor = ConsoleColor::Cyan;
        for (int i = 0; i < (tamanio + 20); i++) {
            gotoXY(coordenadaBarraX + i, coordenadaBarraY);
            cout << "/";
            _sleep(100);
        }
        contador++;
        Console::ForegroundColor = ConsoleColor::White;
    }
}

void Grafico::mostrarEstadisticas() {
    // Mostrar las estadisticas restantes en la parte derecha abajo de la consola
    // Adaptarlo a diferentes tamanios de pantalla -----> (falta esto)
    // Sector jugador y animacion
    textoPequenioSinSleep(juego->obtenerPersonaje()->getNombre(), Console::WindowWidth - 99, 0);
    dibujarRectanguloHueco(Console::WindowWidth - 100, 5, 50, 50);
    juego->obtenerPersonaje()->dibujarGolemDerecha(Console::WindowWidth - 70, 20);
    textoPequenioSinSleep("VIDAS ", Console::WindowWidth - 96, 7);
    // Sector estadisticas
    // Recursos:
    dibujarRectanguloHueco(Console::WindowWidth - 100, 55, 50, 50);
    textoPequenioSinSleep("Recursos: ", Console::WindowWidth - 96, 57);
    textoPequenioSinSleep("Semillas: ", Console::WindowWidth - 96, 62);
    textoPequenioSinSleep("Agua: ", Console::WindowWidth - 96, 68);
    textoPequenioSinSleep("Residuos: ", Console::WindowWidth - 96, 74);
    // Sector campo de juego
    dibujarRectanguloHueco(5,5, 135, 100);
    // Sector de plantar
    //dibujarRectanguloHueco(148, 5, 64, 15);
}

void Grafico::mostrarContadoresRecursos() {
    int posX = Console::WindowWidth - 40;
    int decenas, unidades;

    if (juego->obtenerPersonaje()->getContadorSemillasACambiado()) {
        int numero = juego->obtenerPersonaje()->getContadorSemillasTotales();
        decenas = numero / 10;
        unidades = numero % 10;
        dibujarNumeroPequenio(decenas, posX, 62);
        dibujarNumeroPequenio(unidades, posX + 5, 62);
    }

    if (juego->obtenerPersonaje()->getContadorAguasACambiado()) {
        int numero = juego->obtenerPersonaje()->getContadorAgua();
        decenas = numero / 10;
        unidades = numero % 10;
        dibujarNumeroPequenio(decenas, posX, 68);
        dibujarNumeroPequenio(unidades, posX + 5, 68);
    }

    if (juego->obtenerPersonaje()->getContadorResiduosACambiado()) {
        int numero = juego->obtenerPersonaje()->getContadorResiduosReciclables();
        decenas = numero / 10;
        unidades = numero % 10;
        dibujarNumeroPequenio(decenas, posX, 73);
        dibujarNumeroPequenio(unidades, posX + 5, 73);
    }

    juego->obtenerPersonaje()->setContadorAguasACambiado(false);
    juego->obtenerPersonaje()->setContadorSemillasACambiado(false);
    juego->obtenerPersonaje()->setContadorResiduosACambiado(false);
}


void Grafico::dibujarCorazones(int x, int y, int vidas) {
    // Conseguir las vidas del personaje:
    //int vidas = juego->obtenerPersonaje()->getSalud();
    //dibujarCorazon(Console::WindowWidth - 73, 6);

    if (juego->obtenerPersonaje()->getVidasCambiadas()) {
        for (int i = 0; i < 5; i++) {  // Maximo de vidas 5
            borrarCorazon(x + i * 15, y);
        }

        for (int i = 0; i < vidas; i++) {
            dibujarCorazon(x + i * 15, y);
        }

        juego->obtenerPersonaje()->setVidasCambiadas(false);
    }
}

void Grafico::barraDeVida() {
    // Mostrar estadisticas del jugador
    int vida = juego->obtenerPersonaje()->getVida();
    dibujarBarraStats(0, 0, vida, 100, "EcoGuardian", ConsoleColor::Cyan);
}

void Grafico::barraDeContaminacion() {
    int contaminacion = juego->getPorcentajeDeContaminacionMar();

    dibujarBarraStats(150, 0, contaminacion, 100, "Contaminacion %", ConsoleColor::DarkGreen);
}

void Grafico::botonMenu(int x, int y) {
    dibujarRectanguloHueco(x + 2, y + 2, 21, 8);
    textoGrandeSinSleep("MENU (M)", x + 5, y + 3);
}

void Grafico::volverMenuPrincipal() {
    char tecla;
    bool pintarBoton = false;
    while (true) {
        if (pintarBoton) {
            Console::ForegroundColor = ConsoleColor::Yellow;
            botonMenu(Console::WindowWidth / 3 + 20, 80);
            Console::ForegroundColor = ConsoleColor::White;
        }
        else {
            botonMenu(Console::WindowWidth / 3 + 20, 80);
        }
        tecla = _getch();
        tecla = toupper(tecla);
        if (tecla == 'M') {
            pintarBoton = true;
        }

        if (pintarBoton && tecla == 13) {
            break;
        }
    }
}

Rectangle Grafico::getRectangleMarRango() {
    // 5 de altura porque es suficiente para esta funcionalidad no es necesario conseguir todo el rectangulo del mar
    return Rectangle(7, 84, 268, 5);
}

Rectangle Grafico::getArbolesPlantarRango() {
    return Rectangle(144, 5, 61 * 2, 17);
}

Rectangle Grafico::getArbolesPlantarArea() {
    return Rectangle(147, 5, 64 * 2, 16);
}


void Grafico::dibujarCaracter(int x, int y, char caracter, ConsoleColor color) {
    Console::SetCursorPosition(x, y);
    Console::ForegroundColor = color;
    cout << caracter;
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::mostrarMar(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkBlue;
    Console::SetCursorPosition(x, y + 1);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 2);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 3);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 4);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 5);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 6);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 7);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 8);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 9);  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 10); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 11); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 12); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 13); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 14); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 15); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 16); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 17); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 18); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::SetCursorPosition(x, y + 19); cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    Console::ForegroundColor = ConsoleColor::White;

}

void Grafico::mostrarMarContaminado(int alto, int ancho, int x, int y, int porcentajeContaminacion) {
    int columnasContaminadas = (porcentajeContaminacion * ancho) / 100;
    int contadorPartesContaminadas = 0;

    while (contadorPartesContaminadas < columnasContaminadas) {
        int numeroAleatorioX = juego->numeroAleatorio(x, ancho + x);
        int numeroAleatorioY = juego->numeroAleatorio(y, alto + y);

        bool coordenadaAgregada = juego->agregarParteContaminada(numeroAleatorioX, numeroAleatorioY);
        if (coordenadaAgregada) {
            dibujarCaracter(numeroAleatorioX, numeroAleatorioY, '#', ConsoleColor::DarkGreen);
            contadorPartesContaminadas++;
        }
    }
}

void Grafico::pantallaAyudaMision() {
    textoGrandeSinSleep("MISION", 170, 5);

    textoGrandeSinSleep("RESTAURAR EL ECOSISTEMA PARA REFORESTAR EL TERRENO AFECTADO", 13, 20);
    textoGrandeSinSleep("POR LA CONTAMINACION", 130, 30);
    textoGrandeSinSleep("EL OBJETIVO ES AL MENOS EL 70 % DEL MAPA ANTES DE QUE SE", 25, 45);
    textoGrandeSinSleep("ACABEN LOS RECURSOS O EL TIEMPO", 95, 55);

    flechitajsjsjs(280, 80);
    dibujarRectanguloHueco(296, 78, 30, 10);
    textoGrandeSinSleep("CONTINUAR", 300, 80);
}

void Grafico::pantallaAyudaPersonajePrincipal() {
    textoGrandeSinSleep("PERSONAJE PRINCIPAL", 150, 5);

    juego->obtenerPersonaje()->dibujarGolemDerecha(30, 40);

    textoGrandeSinSleep("CANTIDAD DE VIDA", 100, 20);
    textoGrandeSinSleep("CANTIDAD DE ENERGIA", 235, 20);
    textoGrandeSinSleep("BOTELLAS DE AGUA: 0", 115, 40);
    textoGrandeSinSleep("SEMILLA DE ALGA: 0", 115, 50);
    textoGrandeSinSleep("PLASTICO: 0", 255, 40);
    textoGrandeSinSleep("PAPEL: 0", 255, 50);
    flechitajsjsjs(280, 80);
    dibujarRectanguloHueco(296, 78, 30, 10);
    textoGrandeSinSleep("CONTINUAR", 300, 80);
}

void Grafico::dibujarCubetaAgua(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Gray;
    Console::SetCursorPosition(x, y + 1);   cout << " @@@@@@ ";
    Console::SetCursorPosition(x, y + 2);   cout << "@"; Console::ForegroundColor = ConsoleColor::Blue; cout << "######"; Console::ForegroundColor = ConsoleColor::Gray; cout << "@";
    Console::SetCursorPosition(x, y + 3);   cout << "@@@@@@@@";
    Console::SetCursorPosition(x, y + 4);   cout << "@      @";
    Console::SetCursorPosition(x, y + 5);   cout << "@      @";
    Console::SetCursorPosition(x, y + 6);   cout << "@      @";
    Console::SetCursorPosition(x, y + 7);   cout << " @@@@@@ ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::dibujarSemilla1(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkGreen;
    Console::SetCursorPosition(x, y + 1); cout << "   @@@@@  ";
    Console::SetCursorPosition(x, y + 2); cout << "  @@    @@";
    Console::SetCursorPosition(x, y + 3); cout << "  @@@   @@";
    Console::SetCursorPosition(x, y + 4); cout << " @@@@   @@";
    Console::SetCursorPosition(x, y + 5); cout << "@@      @@";
    Console::SetCursorPosition(x, y + 6); cout << "@@    @@@ ";
    Console::SetCursorPosition(x, y + 7); cout << " @@@@@@   ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::dibujarSemilla2(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(x, y + 1); cout << "         -----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "==== = ";
    Console::SetCursorPosition(x, y + 2); Console::ForegroundColor = ConsoleColor::Green;  cout << " -----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "======";  Console::ForegroundColor = ConsoleColor::Green; cout << "--"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "====== ";
    Console::SetCursorPosition(x, y + 3); Console::ForegroundColor = ConsoleColor::Green; cout << "-------"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "======";  Console::ForegroundColor = ConsoleColor::Green;  cout << "-"; Console::ForegroundColor = ConsoleColor::Cyan;  Console::ForegroundColor = ConsoleColor::Green; cout << "=======";
    Console::SetCursorPosition(x, y + 4); Console::ForegroundColor = ConsoleColor::Green; cout << "------"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=============  ";
    Console::SetCursorPosition(x, y + 5); Console::ForegroundColor = ConsoleColor::Green; cout << "  ----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=";  Console::ForegroundColor = ConsoleColor::Green; cout << "----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=====     ";
    Console::SetCursorPosition(x, y + 6); Console::ForegroundColor = ConsoleColor::Green; cout << "       ----"; Console::ForegroundColor = ConsoleColor::Cyan; cout << "=====     ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::dibujarPapel(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Yellow;
    Console::SetCursorPosition(x, y + 1);  cout << "            @    ";
    Console::SetCursorPosition(x, y + 2);  cout << "  @@@    @@      ";
    Console::SetCursorPosition(x, y + 3);  cout << "@@     @@ @      ";
    Console::SetCursorPosition(x, y + 4);  cout << "@%@ @   @@@%     ";
    Console::SetCursorPosition(x, y + 5);  cout << "  @ @@@@   @@    ";
    Console::SetCursorPosition(x, y + 6);  cout << "   @  @@@@  @    ";
    Console::SetCursorPosition(x, y + 7);  cout << "   @    @@@@ @@@ ";
    Console::SetCursorPosition(x, y + 8);  cout << "   @@    @@@@@@@@";
    Console::SetCursorPosition(x, y + 8);  cout << "    @    @@@ @@  ";
    Console::SetCursorPosition(x, y + 10); cout << "     @ @@@@@     ";
    Console::SetCursorPosition(x, y + 11); cout << "       @         ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::dibujarBolsa(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Gray;
    Console::SetCursorPosition(x, y + 1); cout << "@@@      @@@ ";
    Console::SetCursorPosition(x, y + 2); cout << "@@@      @@@ ";
    Console::SetCursorPosition(x, y + 3); cout << "@@@@@@@@@@@@ ";
    Console::SetCursorPosition(x, y + 4); cout << "@@@@@@@@@@@@ ";
    Console::SetCursorPosition(x, y + 5); cout << "@@@@@@@@@@@@ ";
    Console::SetCursorPosition(x, y + 6); cout << "@@@@@@@@@@@@ ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::dibujarCorazon(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(x, y + 1);  cout << " @@@@    @@@@ ";
    Console::SetCursorPosition(x, y + 2);  cout << "@@@@@@  @@@@@@";
    Console::SetCursorPosition(x, y + 3);  cout << " @@@@@@@@@@@@ ";
    Console::SetCursorPosition(x, y + 4);  cout << "  @@@@@@@@@@  ";
    Console::SetCursorPosition(x, y + 5);  cout << "    @@@@@@    ";
    Console::SetCursorPosition(x, y + 6);  cout << "     @@@@     ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::borrarCorazon(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(x, y + 1);  cout << "              ";
    Console::SetCursorPosition(x, y + 2);  cout << "              ";
    Console::SetCursorPosition(x, y + 3);  cout << "              ";
    Console::SetCursorPosition(x, y + 4);  cout << "              ";
    Console::SetCursorPosition(x, y + 5);  cout << "              ";
    Console::SetCursorPosition(x, y + 6);  cout << "              ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::dibujarPlanta(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Green;
    gotoXY(x, y + 1);  cout << "::.    :..       ..:";
    gotoXY(x, y + 2);  cout << ": .=:   =.-  .:--..=";
    gotoXY(x, y + 3);  cout << ".: ..    :     .. + ";
    gotoXY(x, y + 4);  cout << " :   : .=*+: :.  =. ";
    gotoXY(x, y + 5);  cout << "  ::  .  =*   .:    ";
    gotoXY(x, y + 6);  cout << "   ..-:.-+#-.-...   ";
    gotoXY(x, y + 7);  cout << "-.-=:.:  =::.::::   ";
    gotoXY(x, y + 8);  cout << " =  -..+ -++.       ";
    gotoXY(x, y + 9);  cout << "  =... *..          ";
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    gotoXY(x, y + 10); cout << "---=-:...:.....:-=--";
    gotoXY(x, y + 11); cout << "                  :.";
    gotoXY(x, y + 12); cout << "+                 = ";
    gotoXY(x, y + 13); cout << ".=              .-  ";
    gotoXY(x, y + 14); cout << "::------::::-----:  ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::borrarPlanta(int x, int y) {
    gotoXY(x, y + 1);  cout << "                    ";
    gotoXY(x, y + 2);  cout << "                    ";
    gotoXY(x, y + 3);  cout << "                    ";
    gotoXY(x, y + 4);  cout << "                    ";
    gotoXY(x, y + 5);  cout << "                    ";
    gotoXY(x, y + 6);  cout << "                    ";
    gotoXY(x, y + 7);  cout << "                    ";
    gotoXY(x, y + 8);  cout << "                    ";
    gotoXY(x, y + 9);  cout << "                    ";
    gotoXY(x, y + 10); cout << "                    ";
    gotoXY(x, y + 11); cout << "                    ";
    gotoXY(x, y + 12); cout << "                    ";
    gotoXY(x, y + 13); cout << "                    ";
    gotoXY(x, y + 14); cout << "                    ";
}

void Grafico::dibujarNumero(int numero, int x, int y) {
    switch (numero) {
        case 0: dibujarnumeroMejor0(x, y); break;
        case 1: dibujarnumeroMejor1(x, y); break;
        case 2: dibujarnumeroMejor2(x, y); break;
        case 3: dibujarnumeroMejor3(x, y); break;
        case 4: dibujarnumeroMejor4(x, y); break;
        case 5: dibujarnumeroMejor5(x, y); break;
        case 6: dibujarnumeroMejor6(x, y); break;
        case 7: dibujarnumeroMejor7(x, y); break;
        case 8: dibujarnumeroMejor8(x, y); break;
        case 9: dibujarnumeroMejor9(x, y); break;
    }
}

void Grafico::dibujarNumeroPequenio(int numero, int x, int y) {
    switch (numero) {
    case 0: number0(x, y); break;
    case 1: number1(x, y); break;
    case 2: number2(x, y); break;
    case 3: number3(x, y); break;
    case 4: number4(x, y); break;
    case 5: number5(x, y); break;
    case 6: number6(x, y); break;
    case 7: number7(x, y); break;
    case 8: number8(x, y); break;
    case 9: number9(x, y); break;
    }
}

void Grafico::borrarNumeros(int x, int y) {
    gotoXY(x, y + 1); cout << "                             ";
    gotoXY(x, y + 2); cout << "                             ";
    gotoXY(x, y + 3); cout << "                             ";
    gotoXY(x, y + 4); cout << "                             ";
    gotoXY(x, y + 5); cout << "                             ";
    gotoXY(x, y + 6); cout << "                             ";
}

void Grafico::mostrarContador(int& segundos, int x, int y, clock_t& inicio) {
    int centenas, decenas, unidades;
    clock_t tiempoActual = clock();
    double tiempoTranscurrido = double(tiempoActual - inicio) / CLOCKS_PER_SEC;

    if (tiempoTranscurrido >= 1.0) {
        if (segundos >= 0) {
            borrarNumeros(x, y);

            centenas = segundos / 100;
            decenas = (segundos / 10) % 10;
            unidades = segundos % 10;

            dibujarNumero(centenas, x, y);
            dibujarNumero(decenas, x + 10, y);
            dibujarNumero(unidades, x + 20, y);

            segundos--;

            inicio = clock();
        }

        if (segundos <= -1) {
            borrarNumeros(x, y);
        }
    }
}


void Grafico::pantallaAyudaRecursos() {
    textoGrandeSinSleep("RECURSOS", 160, 5);

    textoGrandeSinSleep("CUBETA DE AGUA: ", 270, 20);
    dibujarCubetaAgua(310, 35);

    textoGrandeSinSleep("SEMILLA: ", 170, 20);
    dibujarSemilla1(185, 35);
    dibujarSemilla2(185, 75);

    textoGrandeSinSleep("RESIDUOS RECICLABLES:", 5, 20);
    dibujarPapel(65, 35);
    dibujarBolsa(65, 75);
}

void Grafico::sol(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Yellow;
    gotoXY(x, y + 1);   cout << "           ##    ##   ##           ";
    gotoXY(x, y + 2);   cout << "      #    ###   ##  ###           ";
    gotoXY(x, y + 3);   cout << "       ##   ### ### ###   ###      ";
    gotoXY(x, y + 4);   cout << "        ### ##### ##### ####       ";
    gotoXY(x, y + 5);   cout << "   #### ###################  ####  ";
    gotoXY(x, y + 6);   cout << "     #######           ########    ";
    gotoXY(x, y + 7);   cout << " ########                 #########";
    gotoXY(x, y + 8);   cout << "     ###                   ###     ";
    gotoXY(x, y + 9);   cout << "########                   ########";
    gotoXY(x, y + 10);  cout << "  ######                   ###     ";
    gotoXY(x, y + 11);  cout << "   #####                   ######  ";
    gotoXY(x, y + 12);  cout << "#########                 #########";
    gotoXY(x, y + 13);  cout << "    #########         #########    ";
    gotoXY(x, y + 14);  cout << "  ###   ###################   ###  ";
    gotoXY(x, y + 15);  cout << "       ###  ### ### ###  ###       ";
    gotoXY(x, y + 16);  cout << "      ##   ###  ###  ###   ##      ";
    gotoXY(x, y + 17);  cout << "           ###   ##  ###           ";
    gotoXY(x, y + 18);  cout << "                 #                 ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::arbusto(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Green;
    gotoXY(x, y + 1);  cout << "            ##########            ";
    gotoXY(x, y + 2);  cout << "       ######        #######      ";
    gotoXY(x, y + 3);  cout << "  #####    ##    ##         ##    ";
    gotoXY(x, y + 4);  cout << "  ##   ##                ##   ##  ";
    gotoXY(x, y + 5);  cout << "##        ###        ###       ###";
    gotoXY(x, y + 6);  cout << " ###        ##      ##        ### ";
    gotoXY(x, y + 7);  cout << "   ############################   ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::arbol(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Green;
    gotoXY(x, y + 1);   cout << "         ##########    ######       ";
    gotoXY(x, y + 2);   cout << "        #          ####      ##     ";
    gotoXY(x, y + 3);   cout << " #######                     #      ";
    gotoXY(x, y + 4);   cout << "#              ##           ######  ";
    gotoXY(x, y + 5);   cout << "#          #####                  # ";
    gotoXY(x, y + 6);   cout << " ####       ####      ##          ##";
    gotoXY(x, y + 7);   cout << "  ##        # #      ##          ## ";
    gotoXY(x, y + 8);   cout << " #     ###  ####    ##   #   ###    ";
    gotoXY(x, y + 9);   cout << " #    # ###### #   # #####     ##   ";
    gotoXY(x, y + 10);  cout << " ####    ####  #####          ##    ";
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    gotoXY(x, y + 11);  cout << "           #     ##                 ";
    gotoXY(x, y + 12);  cout << "           ##    #                  ";
    gotoXY(x, y + 13);  cout << "            #   #                   ";
    gotoXY(x, y + 14);  cout << "            #   ##                  ";
    gotoXY(x, y + 15);  cout << "           ##    #                  ";
    gotoXY(x, y + 16);  cout << "           #     ##                 ";
    gotoXY(x, y + 17);  cout << "           #      #                 ";
    gotoXY(x, y + 18);  cout << "          #        #                ";
    gotoXY(x, y + 19);  cout << "         ############               ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::bloque1(int x, int y) {
    gotoXY(x, y + 1); cout << " _____ ";
    gotoXY(x, y + 2); cout << "|__|__|";
}

void Grafico::bloque2(int x, int y) {
    gotoXY(x, y + 1); cout << "L_L_L";
    gotoXY(x, y + 2); cout << "_L_L_";
}

void Grafico::bloque3(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Green;
    gotoXY(x, y + 1); cout << " _______ ";
    gotoXY(x, y + 2); cout << "]_______]";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::piso1(int x, int y, int longitud) {

    for (int i = 0; i < longitud; i++) {
        bloque1(x, y);
        x += 8;
    }
}

void Grafico::piso2(int x, int y, int longitud) {

    for (int i = 0; i < longitud; i++) {
        bloque2(x, y);
        x += 5;
    }
}

void Grafico::piso3(int x, int y, int longitud) {

    for (int i = 0; i < longitud; i++) {
        bloque3(x, y);
        x += 9;
    }
}

void Grafico::corazon(int x, int y) {
    Console::ForegroundColor = ConsoleColor::Red;
    gotoXY(x, y + 1); cout << " @@  @@ ";
    gotoXY(x, y + 2); cout << "@@@@@@@@";
    gotoXY(x, y + 3); cout << " @@@@@@ ";
    gotoXY(x, y + 4); cout << "  @@@@  ";
    gotoXY(x, y + 5); cout << "   @@   ";
    Console::ForegroundColor = ConsoleColor::White;
}

void Grafico::aguilaxd1(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkYellow;
    gotoXY(x, y + 1);  cout << "@@@                                                                                   @@@@";
    gotoXY(x, y + 2);  cout << "@  @@@                                                                              @@   @";
    gotoXY(x, y + 3);  cout << " @    @@@@@@                                                                  @@@@@@    @ ";
    gotoXY(x, y + 4);  cout << " @          @@@@@@                                                      @@@@@@          @ ";
    gotoXY(x, y + 5);  cout << " @                @@@@@@                   @@@@                    @@@@@                @ ";
    gotoXY(x, y + 6);  cout << "  @                     @@@@             @@    @@             @@@@@                   @@  ";
    gotoXY(x, y + 7);  cout << "   @                        @@@@@@      @  _  _  @      @@@@@@                        @   ";
    gotoXY(x, y + 8);  cout << "   @                              @@@@@@@ |_||_|  @@@@@@@                             @   ";
    gotoXY(x, y + 9);  cout << "    @@                                  \\      /                                  @@    ";
    gotoXY(x, y + 10); cout << "      @                                  \\    /                                  @      ";
    gotoXY(x, y + 11); cout << "       @                                  \\  /                                 @@       ";
    gotoXY(x, y + 12); cout << "         @@@                               \\/                               @@@         ";
    gotoXY(x, y + 13); cout << "            @                                                               @@            ";
    gotoXY(x, y + 14); cout << "              @@                                                          @@              ";
    gotoXY(x, y + 15); cout << "                @@@                                                    @@@                ";
    gotoXY(x, y + 16); cout << "                   @@@@@@@                                      @@@@@@@                   ";
    gotoXY(x, y + 17); cout << "                          @@@@@@@                        @@@@@@@@                         ";
    gotoXY(x, y + 18); cout << "                                 @@@@                @@@@                                 ";
    gotoXY(x, y + 19); cout << "                                    @                @                                    ";
    gotoXY(x, y + 20); cout << "                                     @              @                                     ";
    gotoXY(x, y + 21); cout << "                                    @    @      @    @                                    ";
    gotoXY(x, y + 22); cout << "                                   @    @        @    @                                   ";
    gotoXY(x, y + 23); cout << "                                  @    @  @    @  @    @                                  ";
    gotoXY(x, y + 24); cout << "                                  @   @   @    @   @   @                                  ";
    gotoXY(x, y + 25); cout << "                                  @@@@@   @    @    @@@@                                  ";
    gotoXY(x, y + 26); cout << "                                     @    @    @    @                                     ";
    gotoXY(x, y + 27); cout << "                                      @@@@@    @@@@@                                      ";
    gotoXY(x, y + 28); cout << "                                          @    @                                          ";
    gotoXY(x, y + 29); cout << "                                           @@@@                                           ";
    Console::ForegroundColor = ConsoleColor::White
        ;
}

void Grafico::decoracion1() {
    sol(200, 2);

    arbol(172, 40);

    arbusto(60, 52);

    arbusto(140, 52);

    corazon(114, 45);

    aguilaxd1(107, 10);

    piso3(23, 59, 22);
}

void Grafico::lobo_ganador(int x, int y) {
    gotoXY(x, y + 0); cout << "                                                                               @@        ";
    gotoXY(x, y + 1); cout << "                                                                            @@@@@@       ";
    gotoXY(x, y + 2); cout << "                                                                         @@@@@@@@@@      ";
    gotoXY(x, y + 3); cout << "                                                                      @@@@@@@   @@@@     ";
    gotoXY(x, y + 4); cout << "                                                                   @@@@@@         @@     ";
    gotoXY(x, y + 5); cout << "                                                                @@@@@@            @@     ";
    gotoXY(x, y + 6); cout << "                                                  @@@@@@@@@@@@@@@@@@              @@     ";
    gotoXY(x, y + 7); cout << "                                            @@@@@@@@    @@@@   @@@@               @@     ";
    gotoXY(x, y + 8); cout << "                                         @@@@   @@@        @@@@@@@               @@@     ";
    gotoXY(x, y + 9); cout << "                                     @@@@@@    @@@@    @@@@@@@@@@@               @       ";
    gotoXY(x, y + 10); cout << "                                   @@@@@@@@          @@@@   @@@@@@@@            @        ";
    gotoXY(x, y + 11); cout << "                                  @@@@@@@@@@@@@    @@       @ @@@@             @         ";
    gotoXY(x, y + 12); cout << "                                @@@@      @@@   @@     @ @@@  @@              @@         ";
    gotoXY(x, y + 13); cout << "                              @@@@   @@   @   @%    @  @@@   @@               @@    @@@@ ";
    gotoXY(x, y + 14); cout << "                             @@@   @@@      @@@   @@@  @@  #@%                @@  @@@@@@@";
    gotoXY(x, y + 15); cout << "                            @@@@  @@@@     @@@   @@@@  @@  @@%                @@@@@@@@@@@";
    gotoXY(x, y + 16); cout << "                           @@@@@  @@@@    @@@   @@ @@  @@  @@%                  @@@ @@@@ ";
    gotoXY(x, y + 17); cout << "                             @@@@@@@@@   @@@    @@ @@      *@@%                     @@@  ";
    gotoXY(x, y + 18); cout << "                        @@@@@@@@@@@@@    @@@   @@  @@       @@%                   @@@    ";
    gotoXY(x, y + 19); cout << "                      @@@@@@@@       @@  @@@   @@  @@@       @@@                @@@      ";
    gotoXY(x, y + 20); cout << "                     @@@             @@   @@@   @@  @@        @@             @@@@        ";
    gotoXY(x, y + 21); cout << "                 @@@@              @@@@@@  @@@   @  @@@       @@           @@@           ";
    gotoXY(x, y + 22); cout << "              @@@         @@@    @@     @@ @@@@      @@        @          @@             ";
    gotoXY(x, y + 23); cout << "            @@@@       @@@@@@  @@@       @@  @@@     @@@       @        @@@              ";
    gotoXY(x, y + 24); cout << "             @@     @@@    @@@@@         @@@   @@@  @@@@    @  @@      @@@               ";
    gotoXY(x, y + 25); cout << "               @@@         @@@       @@@@@@@@@  @@@@@@@     @@        @@@                ";
    gotoXY(x, y + 26); cout << "                  @@@@@      @@@@@@@@@@@  @@@@@   @@@@@   @ @@     @@@@@@                ";
    gotoXY(x, y + 27); cout << "                        @@@@@@@@@              @   @@@@   @  @@    @@@@@                 ";
    gotoXY(x, y + 28); cout << "                @@@                            @@    @   @@  @@    @@@@@                 ";
    gotoXY(x, y + 29); cout << "              @@@         @@@                            @@  @@@   @@@@@@                ";
    gotoXY(x, y + 30); cout << "           @@@@     @@@@@@         @   @     @          @@@   @@@   @@ @@@               ";
    gotoXY(x, y + 31); cout << "          @@@@@@@@@@@@@@          @    @      @@        @@     @@@   @  @@               ";
    gotoXY(x, y + 32); cout << "              @@@@  @@@    @     %@   @@@     @@@      @@@       @@@@@@   @              ";
    gotoXY(x, y + 33); cout << "             @@@#   @@@@@@#    @@@    @@@       @@     @@@   @@     @@@@                 ";
    gotoXY(x, y + 34); cout << "           @@@     @@@@      @@@@     @@@@       @@@   @@@     @@       @                ";
    gotoXY(x, y + 35); cout << "          @@@    @@@@      @@@@      @@@ @@@      @@@@@@@@@    @@@@                      ";
    gotoXY(x, y + 36); cout << "        @@@@  @@@  @@    @@@@      @@@@   @@@@      @@@@@@@     @@@@                     ";
    gotoXY(x, y + 37); cout << "      @@@@@@@@@    @    @@@@     @@@        @@@@        @@@@    @@@@@                    ";
    gotoXY(x, y + 38); cout << "    @@@@@@@@@         @@@@   @@@@@           @@@@          @@    @@@@@@                  ";
    gotoXY(x, y + 39); cout << "        @@@         @@@@   @@@@@     @@@@@     @@@@    @     @   @@@ @@@                 ";
    gotoXY(x, y + 40); cout << "      @@@@        @@@@    @@@@@    @@@@ @@@     @@@@    @@       @@@  @@@                ";
    gotoXY(x, y + 41); cout << "    @@@@    @@   @@@@    @@@@@   @@@@    @@@     @@@@    @@       @@   @@@               ";
    gotoXY(x, y + 42); cout << "   @@@   @@@    @@@@    @@@@@     @@@@    @@@     @@@@   @@       @@    @@               ";
    gotoXY(x, y + 43); cout << "  @@@@@@@@     @@@@   @@@@@@@@@@@         @@@@     @@@@  @@@  @@  @@@    @               ";
    gotoXY(x, y + 44); cout << " @@  @@@@     @@@@        @@@@@@@@@@@@@@@@@@@      @@@@@ @@@   @@ @@@                    ";
    gotoXY(x, y + 45); cout << "    @@@@    @@@@%                 @@@@@@@@@        @@@@@@@@@   @@ @@@                    ";
    gotoXY(x, y + 46); cout << "   @@@     @@@@@@@@@@@%                          @@@@@@@@@@   @@@@@@@                    ";
    gotoXY(x, y + 47); cout << "  @@       @@@@@@@@@@@@@@@@@@@                @@@@@@  %@@@@   @@@@@@@                    ";
    gotoXY(x, y + 48); cout << "         @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     %@@@   @@  @@@@                   ";
    gotoXY(x, y + 49); cout << "        @@@@@@            @@@@@@@@@@@@@@@@@@@@@@@      @@@   @@@  @@@@                   ";
    gotoXY(x, y + 50); cout << "       @@@                @@@@@@@@@@@     @@@@@        @@    @@    @@                    ";
    gotoXY(x, y + 51); cout << "      @                  @@@@@          @@@@@          @@   @@     @@                    ";
    gotoXY(x, y + 52); cout << "                       @@@@           @@@             @@   @@      @                     ";
}


void Grafico::lobo_perdedor(int x, int y) {
    gotoXY(x, y + 1);  cout << "                             @@@@@                                             ";
    gotoXY(x, y + 2);  cout << "                     @@@@@@                                                    ";
    gotoXY(x, y + 3);  cout << "                 @@@@@      @@@           @@@@                                 ";
    gotoXY(x, y + 4);  cout << "              @@@@@                             @@@                            ";
    gotoXY(x, y + 5);  cout << "           @@@@@                                    @@                         ";
    gotoXY(x, y + 6);  cout << "         @@@@@                                         @@@                     ";
    gotoXY(x, y + 7);  cout << "       @@@@@                                             @@                    ";
    gotoXY(x, y + 8);  cout << "      @@@@                                              @  @@                  ";
    gotoXY(x, y + 9);  cout << "     @@@                                                  @  @                 ";
    gotoXY(x, y + 10); cout << "    @@@                                                     @ @                ";
    gotoXY(x, y + 11); cout << "   @@@                                                       @                 ";
    gotoXY(x, y + 12); cout << "  @@@@                                                        @                ";
    gotoXY(x, y + 13); cout << " @@@@@                     @@                                                  ";
    gotoXY(x, y + 14); cout << " @@@@                     @@@@@@@                                 @            ";
    gotoXY(x, y + 15); cout << "@@@@@                      @@@@  @@@                                           ";
    gotoXY(x, y + 16); cout << "@@@@                         @@@   @@@                             @           ";
    gotoXY(x, y + 17); cout << "@@@@ @                    @      +    @@@   @                                  ";
    gotoXY(x, y + 18); cout << "@@@@ @                    @                    @@                              ";
    gotoXY(x, y + 19); cout << "@@@@ @                    @@              @@@      @@                          ";
    gotoXY(x, y + 20); cout << "@#@@ @                      @@@            @@ @@      @@                       ";
    gotoXY(x, y + 21); cout << "@@@@ @                       @@@       @       @@  #@    @       @@            ";
    gotoXY(x, y + 22); cout << "@@@@ @@   @                     @@@      @@@@@@@    @@@   @@@@@@@@             ";
    gotoXY(x, y + 23); cout << "@@@@# @   @                        @@        @@@@@@@@@@@   @@@@@@@             ";
    gotoXY(x, y + 24); cout << " @@@@ @@@@@@                      @  @              @@@@@   @@@                ";
    gotoXY(x, y + 25); cout << " @@@@@  @@@@@@                      @                 #@@@  @  @@@             ";
    gotoXY(x, y + 26); cout << "  @@@@  @@@@@@@                     @@      @     @@   @@@@  @   @@@           ";
    gotoXY(x, y + 27); cout << "   @@@@  @@@@@@@@                    @@    @@       @@@@@@@@@       @@@@@@     ";
    gotoXY(x, y + 28); cout << "    @@@@  @@@@@@@@@                   @    @@   @      @@@@@@@@@@@    @@@      ";
    gotoXY(x, y + 29); cout << "     @@@@  @@@@@@@@@@@                %@   @@@  @@                  @@@        ";
    gotoXY(x, y + 30); cout << "       @@@@  @@@    @@@@@              @   @@@@  @@@  @@    @@@@@@@@@          ";
    gotoXY(x, y + 31); cout << "        @@@@  @@@     @@@@@@@       @  @@  @@@@   @@@   @@     @@              ";
    gotoXY(x, y + 32); cout << "          @@@@  @@      @@@@        @  @@  @@@@@@@  @@@@   @%@@@@@             ";
    gotoXY(x, y + 33); cout << "             @@@  @@     @@@@@      @  @@  @@@    @@@@@@@@@        @@          ";
    gotoXY(x, y + 34); cout << "               @@@@@     @   @@@   @@  @@@ @@@@        @@@@@@@@                ";
    gotoXY(x, y + 35); cout << "                   @@@         @@  @@ @@@@# @@@@       @@@@  @@@@@@@@@@*       ";
    gotoXY(x, y + 36); cout << "                        @@@@       @  @@@@@@  @@@@@     @@@     @@@@           ";
    gotoXY(x, y + 37); cout << "                                   @@  @ @@     @@@@@   @@@@      @@@  @       ";
    gotoXY(x, y + 38); cout << "                                   @@  @@   @@@@@@@@@@   @@@ @     @@@ @@      ";
    gotoXY(x, y + 39); cout << "                                   @@   @@ @@      %@@   @@@  @    @@@ @@@@    ";
    gotoXY(x, y + 40); cout << "                                   @@@   @@@@  @@   @@@  @@@@ @@@@@@@@ @@ @@@  ";
    gotoXY(x, y + 41); cout << "                                   @@@@     @ @@@@@  @@  @@@@   @@@%@  @@@   @@";
    gotoXY(x, y + 42); cout << "                                    @@@@         @@  @   @@@@  @@@@@@  @@  @@  ";
    gotoXY(x, y + 43); cout << "                                    @@ @@@@@   @@@  @   @@@@    @@@@  @@@      ";
    gotoXY(x, y + 44); cout << "                                    @@    @@@@@@@      @@@@     @@@   @@       ";
    gotoXY(x, y + 45); cout << "                                    @@      @@@@      @@@@      @@   @@        ";
    gotoXY(x, y + 46); cout << "                                    @@     @@@@     @@@@@@@@   @   @@@         ";
    gotoXY(x, y + 47); cout << "                                     @          @@@@@@@@@@@@@    @@@@       @  ";
    gotoXY(x, y + 48); cout << "                                     @  @@@@@@@@@@@@@@@@@@@@@@@@@@@@       @   ";
    gotoXY(x, y + 49); cout << "                                     @@  @@@@@               @@@@@@       @@   ";
    gotoXY(x, y + 50); cout << "                                      @    @@@   @@@@@@@@@@@  @@@@@     @@@@   ";
    gotoXY(x, y + 51); cout << "                                           @@@@  @@@       @@  @@@@@@@@@@@@    ";
    gotoXY(x, y + 52); cout << "                                            @@@  @@@        @@ @@@@@@@@@@@   @ ";
    gotoXY(x, y + 53); cout << "                                             @@@  @@@       @  @@@@@@@@@    @  ";
    gotoXY(x, y + 54); cout << "                                              @@@   @@@       @@@  @@@     @   ";
    gotoXY(x, y + 55); cout << "                                               @@@@   @@@@@@@@@@@@@      @@    ";
    gotoXY(x, y + 56); cout << "                                                 @@@@                 @@@      ";
    gotoXY(x, y + 57); cout << "                                                   @@@@@@@       @@@@@@        ";
    gotoXY(x, y + 58); cout << "                                                    @@@@@@@@@@@@@@@            ";
}

void Grafico::trofeo_perdedor(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkBlue;
    Console::SetCursorPosition(x, y + 1);  cout << "                 #####					  ";
    Console::SetCursorPosition(x, y + 2);  cout << "               #########				  ";
    Console::SetCursorPosition(x, y + 3);  cout << "               ###  #  ###				  ";
    Console::SetCursorPosition(x, y + 4);  cout << "        ####  ###########   ####		  ";
    Console::SetCursorPosition(x, y + 5);  cout << "     #### ############ # ##############   ";
    Console::SetCursorPosition(x, y + 6);  cout << "    #############  ### # ###  #########   ";
    Console::SetCursorPosition(x, y + 7);  cout << "    ### ######## # ### # # ####  #######  ";
    Console::SetCursorPosition(x, y + 8);  cout << "   ## # ######## #  #### ######  #######  ";
    Console::SetCursorPosition(x, y + 9);  cout << "  ###   ###                  #   ######## ";
    Console::SetCursorPosition(x, y + 10); cout << "###  ###### Perdedorrrrrr!!! #  ## #####  ";
    Console::SetCursorPosition(x, y + 11); cout << "## #### ###                  #####   #### ";
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

void Grafico::trofeo_ganador(int x, int y) {
    Console::ForegroundColor = ConsoleColor::DarkBlue;
    Console::SetCursorPosition(x, y + 1);  cout << "                 #####					  ";
    Console::SetCursorPosition(x, y + 2);  cout << "               #########				  ";
    Console::SetCursorPosition(x, y + 3);  cout << "               ###  #  ###				  ";
    Console::SetCursorPosition(x, y + 4);  cout << "        ####  ###########   ####		  ";
    Console::SetCursorPosition(x, y + 5);  cout << "     #### ############ # ##############   ";
    Console::SetCursorPosition(x, y + 6);  cout << "    #############  ### # ###  #########   ";
    Console::SetCursorPosition(x, y + 7);  cout << "    ### ######## # ### # # ####  #######  ";
    Console::SetCursorPosition(x, y + 8);  cout << "   ## # ######## #  #### ######  #######  ";
    Console::SetCursorPosition(x, y + 9);  cout << "  ###   ###                  #   ######## ";
    Console::SetCursorPosition(x, y + 10); cout << "###  ######  Ganadorrrrrr!!! #  ## #####  ";
    Console::SetCursorPosition(x, y + 11); cout << "## #### ###                  #####   #### ";
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

void Grafico::estadisticas(int x, int y) {
    gotoXY(x, y + 3);  cout << "Golpes en recibidos : " << endl;
    gotoXY(x, y + 5);  cout << "Golpes en hechos    : " << endl;
    gotoXY(x, y + 7);  cout << "Vida final          : " << endl;
    gotoXY(x, y + 7);  cout << "Mana final          : " << endl;
    gotoXY(x, y + 7);  cout << "Estamina final      : " << endl;
    gotoXY(x, y + 9);  cout << "Niveles pasado      : " << endl;
    gotoXY(x, y + 11); cout << "Preguntas resueltas : " << endl;
}



void Grafico::pantalla_perdedor_xd1() {

    lobo_perdedor(0, 5);

    dibujarRectanguloHueco(100, 3, 35, 30);

    estadisticas(110, 15);

    trofeo_perdedor(184, 4);

    piso1(180, 32, 6);

    piso1(100, 57, 16);

}

void Grafico::pantalla_ganador_xd1() {

    lobo_ganador(1, 5);

    dibujarRectanguloHueco(100, 3, 35, 30);

    estadisticas(110, 15);

    trofeo_ganador(184, 4);

    piso1(180, 32, 6);

    piso1(100, 57, 16);
}


void Grafico::pantallaPrimerNivel() {
    textoGrandeSinSleep("PRIMER NIVEL", 20, 20);
    mostrarPantallaDeCarga();
}

void Grafico::pantallaSegundoNivel() {
    textoGrandeSinSleep("SEGUNDO NIVEL", 20, 20);
    mostrarPantallaDeCarga();
}

void Grafico::pantallaTercerNivel() {
    textoGrandeSinSleep("TERCER NIVEL", 20, 20);
    mostrarPantallaDeCarga();
}
