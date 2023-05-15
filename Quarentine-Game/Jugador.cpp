#include "Jugador.h"
using namespace System;

Jugador::Jugador(){
	Random j;
	x = 10;
	y = 60;
	dx = dy = 2;
	fila = 0; columna = 1;
	cant = 0;
	direccion = Direccion::Arriba;
	ultima_tecla = Arriba;
}
Jugador::~Jugador(){}

void Jugador::CrearBala(){

	Bala** aux = new Bala * [cant + 1];

	for (int i = 0; i < cant; i++)
		aux[i] = balas[i];

	int dx = 0, dy = 0;
	switch (direccion)	{
	case Direccion::Arriba: dy = -16; break;
	case Direccion::Abajo: 	dy = 16; break;
	case Direccion::Izquierda:  dx = -16; break;
	case Direccion::Derecha:    dx = 16; break;
	}

	aux[cant] = new Bala(x + ancho / 2, y + alto / 2, dx, dy);

	cant++;
	balas = aux;
}
void Jugador::EliminarBala(int p){
	Bala** aux = new Bala * [cant - 1];

	delete balas[p];

	for (int i = 0; i < p; i++)
		aux[i] = balas[i];

	for (int i = p; i < cant - 1; i++)
		aux[i] = balas[i + 1];

	cant--;
	balas = aux;
}
void Jugador::MostrarBalas(Graphics^ g, Bitmap^ img){
	for (int i = 0; i < cant; i++)
		balas[i]->Mostrar(g, img);
}
void Jugador::MoverBalas(){
	for (int i = 0; i < cant; i++)
		balas[i]->Mover();
}

int Jugador::GetCantBalas(){
	return cant;
}
Bala* Jugador::GetBala(int i){
	return balas[i];
}

void Jugador::Mostrar(Graphics^ g, Bitmap^ img){
	alto = img->Height / 4;
	ancho = img->Width / 3;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	img->MakeTransparent(img->GetPixel(0, 0));

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
}


void Jugador::Mover(Direccion direccion, Graphics^ g) {
	switch (direccion)	{
	case Direccion::Arriba:
		
		if (y - dy > 60)
			y -= dy;
		this->direccion = Direccion::Arriba;
		fila = 3;
		if (columna >= 0 && columna < 2)
			columna++;
		else
			columna = 1;
		ultima_tecla = Arriba;
		break;
	case Direccion::Abajo:
		
		if (y + alto + dy < g->VisibleClipBounds.Bottom)
			y += dy;
		this->direccion = Direccion::Abajo;
		fila = 0;
		if (columna >= 0 && columna < 2)
			columna++;
		else
			columna = 1;
		ultima_tecla = Abajo;
		break;
	case Direccion::Izquierda:
		
		if (x - dx > 0)
			x -= dx;
		this->direccion = Direccion::Izquierda;
		fila = 1;
		if (columna >= 0 && columna < 2)
			columna++;
		else
			columna = 1;
		ultima_tecla = Izquierda;
		break;
	case Direccion::Derecha:
		
		if (x + ancho + dx < g->VisibleClipBounds.Right)
			x += dx;
		this->direccion = Direccion::Derecha;
		fila = 2;
		if (columna >= 0 && columna < 2)
			columna++;
		else
			columna = 1;
		ultima_tecla = Derecha;
		break;
	case Direccion::Ninguno:
		dx = dy = 0;
		switch (ultima_tecla){
		case Direccion::Arriba:
			columna = 1;
			fila = 3;
			break;
		case Direccion::Abajo:
			columna = 1;
			fila = 0;
			break;
		case Direccion::Izquierda:
			columna = 1;
			fila = 1;
			break;
		case Direccion::Derecha:
		
			columna = 1;
			fila = 2;
			break;
		}
		break;
	}
}