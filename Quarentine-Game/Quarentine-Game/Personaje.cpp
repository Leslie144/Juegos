#include "Personaje.h"

Personaje::Personaje(){}
Personaje::~Personaje(){}

int Personaje::GetX(){return x;}
int Personaje::GetY(){return y;}
int Personaje::GetDX(){return dx;}
int Personaje::GetDY(){return dy;}
int Personaje::GetAncho(){return ancho;}
int Personaje::GetAlto(){return alto;}
int Personaje::GetFila(){return fila;}
int Personaje::GetColumna(){return columna;}

void Personaje::SetX(int n){x = n;}
void Personaje::SetY(int n){y = n;}
void Personaje::SetDX(int n){dx = n;}
void Personaje::SetDY(int n){dy = n;}
void Personaje::SetAncho(int n){ancho = n;}
void Personaje::SetAlto(int n){alto = n;}
void Personaje::SetFila(int n){fila = n;}
void Personaje::SetColumna(int n){columna = n;}

void Personaje::Mostrar(Graphics^ g, Bitmap^ img){}
void Personaje::Mover(Direccion direccion, Graphics^ g) {}