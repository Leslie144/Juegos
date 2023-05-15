#pragma once
#include"Personaje.h"

class Ambulancia : public Personaje {
public:
	Ambulancia();
	~Ambulancia();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};

