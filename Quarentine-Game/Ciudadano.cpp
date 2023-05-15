#include "Ciudadano.h"
using namespace System;

Ciudadano::Ciudadano() {
	Random j;
	x = j.Next(100, 400);
	System::Threading::Thread::Sleep(10);
	y = j.Next(200, 400);
	System::Threading::Thread::Sleep(10);
	dx = dy = 2;
	fila = 0; columna = 0;
}
Ciudadano::~Ciudadano() {}



void Ciudadano::Mostrar(Graphics^ g, Bitmap^ img) {
	alto = img->Height / 4;
	ancho = img->Width / 3;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	img->MakeTransparent(img->GetPixel(0, 0));

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);


	columna++;
	if (columna == 3)
		columna = 1;
	if (columna == 6)
		columna = 4;
}
/*void Ciudadano::Mover(Direccion direccion, Graphics^ g) {
	if (y + dy<60 || y + dy + alto>g->VisibleClipBounds.Bottom)
		dy = dy * -1;
	if (x + dx<0 || x + dx + ancho>g->VisibleClipBounds.Right)
		dx = dx * -1;
	x += dx;
	y += dy;
}*/

void Ciudadano::Mover(Direccion direccion, Graphics^ g) {
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