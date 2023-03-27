/* 
 * File:   funciones.h
 * Author: Franco
 *
 * Created on 13 de noviembre de 2022, 09:18 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Movement.h"
#include "Pokemon.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;

void gotoXY(int x,int y);
void bordes();
void box();
void atackBox(int x,int y,int i,struct Movement *moves);
void pintar0(int x,int y);
void pintar1(int x,int y);
void line(ofstream &,char );
void fillPokemons(struct Pokemon *,int &);
void fillMoves(struct Movement *,int &);
void compare(int *,int *,struct Pokemon *,ofstream &);
void pkmoves(struct Pokemon *,struct Movement *,int);

#endif /* FUNCIONES_H */

