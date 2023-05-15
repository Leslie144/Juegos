#pragma once
using namespace System::Drawing;
enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno};

class Personaje{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int fila, columna;
public:
	Personaje();
	~Personaje();

	int GetX();
	int GetY();
	int GetDX();
	int GetDY();
	int GetAncho();
	int GetAlto();
	int GetFila();
	int GetColumna();

	void SetX(int n);
	void SetY(int n);
	void SetDX(int n);
	void SetDY(int n);
	void SetAncho(int n);
	void SetAlto(int n);
	void SetFila(int n);
	void SetColumna(int n);

	virtual void Mostrar(Graphics^ g, Bitmap^ img);
	virtual void Mover(Direccion direccion, Graphics^ g);
};