#include "Bala.h"
Bala::Bala(int x, int y, int dx, int dy){
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;

	fila = columna = 0;
}
Bala::~Bala(){}


void Bala::Mostrar(Graphics^ g, Bitmap^ img) {
	alto = img->Height / 2;
	ancho = img->Width / 1;

	Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);

	//img->MakeTransparent(img->GetPixel(0, 0));

	g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);

}
void Bala::Mover(){
	x += dx;
	y += dy;

}