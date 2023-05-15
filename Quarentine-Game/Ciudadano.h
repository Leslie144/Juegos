#pragma once
#include"Personaje.h"

class Ciudadano : public Personaje {
public:
	Ciudadano();
	~Ciudadano();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};
