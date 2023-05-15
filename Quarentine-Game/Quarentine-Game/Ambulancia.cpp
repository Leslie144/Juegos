#include"Ambulancia.h"
#include<iostream>
using namespace System;

Ambulancia::Ambulancia(){
	Random j;
	x = y = j.Next(100, 150);
	dx = dy = 2;
	fila = columna = 0;
}
Ambulancia::~Ambulancia(){}


void Ambulancia::Mostrar(Graphics^ g, Bitmap^ img){
	alto = img->Height / 4;
	ancho = img->Width / 3;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	img->MakeTransparent(img->GetPixel(0, 0));

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

	columna++;
	if (columna == 3)
		columna = 0;
}

void Ambulancia::Mover(Direccion direccion, Graphics^ g){
	switch (direccion) {
	case Direccion::Arriba:
		if (y - dy > 60)
			y -= dy;
		fila = 3;
		break;
	case Direccion::Abajo:
		if (y + alto + dy < g->VisibleClipBounds.Bottom)
			y += dy;
		fila = 0;
		break;
	case Direccion::Izquierda:
		if (x - dx > 0)
			x -= dx;
		fila = 1;
		break;
	case Direccion::Derecha:
		if (x + ancho + dx < g->VisibleClipBounds.Right)
			x += dx;
		fila = 2;
		break;

	}
}