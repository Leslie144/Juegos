#pragma once
#include"Personaje.h"

class A_Saludable : public Personaje {
public:
	A_Saludable();
	~A_Saludable();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};