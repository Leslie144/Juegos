#pragma once
#include "Personaje.h"
#include "Bala.h"

using namespace System::Drawing;

class Jugador:public Personaje {
private:
	Direccion direccion;
	Direccion ultima_tecla;
	Bala** balas;
	int cant;
public:
	Jugador();
	~Jugador();

	void CrearBala();
	void EliminarBala(int p);
	void MostrarBalas(Graphics^ g, Bitmap^ img);
	void MoverBalas();

	Bala* GetBala(int i);
	int GetCantBalas();

	void Mostrar(Graphics^ g, Bitmap^ img);
	void Mover(Direccion direccion, Graphics^ g);
};
