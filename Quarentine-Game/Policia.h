#pragma once
#include"Personaje.h"

class Policia : public Personaje {
public:
	Policia();
	~Policia();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};