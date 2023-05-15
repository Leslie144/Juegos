#pragma once
#include"Personaje.h"

class A_Asintomatico : public Personaje {
public:
	A_Asintomatico();
	~A_Asintomatico();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};