#include "A_Asintomatico.h"
using namespace System;

A_Asintomatico::A_Asintomatico() {
	Random j;
	x = j.Next(100, 500);
	System::Threading::Thread::Sleep(10);
	y = j.Next(100, 300);
	System::Threading::Thread::Sleep(10);
	dx = dy = j.Next(2,3);
	fila = 0; columna = 0;
}
A_Asintomatico::~A_Asintomatico() {}



void A_Asintomatico::Mostrar(Graphics^ g, Bitmap^ img) {
	alto = img->Height / 4;
	ancho = img->Width / 6;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	img->MakeTransparent(img->GetPixel(0, 0));

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);


	columna++;
	if (columna == 3)
		columna = 1;
	if (columna == 6)
		columna = 4;
}
void A_Asintomatico::Mover(Direccion direccion, Graphics^ g) {
	if (y + dy<60 || y + dy + alto>g->VisibleClipBounds.Bottom)
		dy = dy * -1;
	if (x + dx<1 || x + dx + ancho>g->VisibleClipBounds.Right)
		dx = dx * -1;
	x += dx;
	y += dy;
}