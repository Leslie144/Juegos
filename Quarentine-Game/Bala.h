#pragma once
#include"Personaje.h"

class Bala : public Personaje {
public:
	Bala(int x, int y, int dx, int dy);
	~Bala();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover();
};

