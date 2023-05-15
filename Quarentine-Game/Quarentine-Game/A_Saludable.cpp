#include "A_Saludable.h"
using namespace System;

A_Saludable::A_Saludable(){
	Random j;
	x = j.Next(100, 400);
	System::Threading::Thread::Sleep(10);
	y = j.Next(200, 400);
	System::Threading::Thread::Sleep(10);
	dx = dy = j.Next(2, 3);
	fila = 0; columna = 0;
}
A_Saludable::~A_Saludable(){}



void A_Saludable::Mostrar(Graphics^ g, Bitmap^ img){
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
void A_Saludable::Mover(Direccion direccion, Graphics^ g){
	if (y + dy<150 || y + dy + alto>g->VisibleClipBounds.Bottom - 100)
		dy = dy * -1;
	if (x + dx<100 || x + dx + ancho>g->VisibleClipBounds.Right - 100)
		dx = dx * -1;
	x += dx;
	y += dy;
}