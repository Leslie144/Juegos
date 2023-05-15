#include "Controladora.h"
#include<iostream>
using namespace System;

Controladora::Controladora(int valor_vidas, int valor_tiempo, int valor_mundo) {
	Random j;
	mundo_juego = valor_mundo;
	puntos = 0;
	tiempo = 0;
	tiempo_juego = valor_tiempo;
	vida_jugador = valor_vidas;
	vulnerabilidad = 20;

	objJugador = new Jugador();
	objA_Saludables = new A_Saludable * [cant_saludable];
	objA_Asintomatico = new A_Asintomatico * [cant_asintomatico];
	objAmbulancia = new Ambulancia();
	objPolicia = new Policia();
	objCiudadano = new Ciudadano * [cant_ciudadano];

	fondo = gcnew SoundPlayer("Sonidos\\Fondo.wav");
	gameover = gcnew SoundPlayer("Sonidos\\GameOver.wav");
	up = gcnew SoundPlayer("Sonidos\\Up.wav");
	coin = gcnew SoundPlayer("Sonidos\\Coin.wav");
}

Controladora::~Controladora() {}

void Controladora::Dinamica_Juego(Graphics^ g) {
	

	objJugador->MostrarBalas(g, img_mensaje);
	objJugador->Mostrar(g, img_Jugador);


	for (int i = 0; i < cant_saludable; i++) 
		objA_Saludables[i]->Mostrar(g, img_A_Saludable);
	
	for (int i = 0; i < cant_asintomatico; i++)
		objA_Asintomatico[i]->Mostrar(g, img_A_Asintomatico);


	if (tiempo >= tiempo_ambulancia)
		objAmbulancia->Mostrar(g, img_Ambulancia);

	if (tiempo >= tiempo_policia)
		objPolicia->Mostrar(g, img_Policia);

	for (int i = 0; i < cant_ciudadano; i++)
		objCiudadano[i]->Mostrar(g, img_Ciudadano);
}



void Controladora::Pasar_Mundo() {
	Random j;
	switch (mundo_juego) {
	case 1:
		img_Mundo = gcnew Bitmap("Imagenes\\Base_Mapa01.jpg");
		img_Jugador = gcnew Bitmap("Imagenes\\Jugador.png");
		img_A_Saludable = gcnew Bitmap("Imagenes\\A_Saludable.png");
		img_A_Asintomatico = gcnew Bitmap("Imagenes\\A_Asintomatico.png");
		img_Ambulancia = gcnew Bitmap("Imagenes\\Ambulancia.png");
		img_Policia = gcnew Bitmap("Imagenes\\Policia.png");
		img_Ciudadano = gcnew Bitmap("Imagenes\\Ciudadano.png");
		img_mensaje = gcnew Bitmap("Imagenes\\Mensaje01.png");

		tiempo = 0;
		cantidad_enviada = 0;

		tiempo_ambulancia = j.Next(10, 40);
		tiempo_policia = j.Next(40, 55);
		tiempo_adversarios = j.Next(5, 9);

		cantidad_a_saludables = j.Next(3, 5);
		cantidad_a_asintomatico = j.Next(3, 5);
		cantidad_ciudadano = j.Next(3, 6);


		cant_saludable = 0;
		AgregarA_Saludables(cantidad_a_saludables);
		cant_asintomatico = 0;
		AgregarA_Asintomatico(cantidad_a_asintomatico);

		cant_ciudadano = 0;
		Agregar_Ciudadano(cantidad_ciudadano);
		break;
	case 2:
		img_Mundo = gcnew Bitmap("Imagenes\\Base_Mapa02.jpg");
		img_Jugador = gcnew Bitmap("Imagenes\\Jugador.png");
		img_A_Saludable = gcnew Bitmap("Imagenes\\A_Saludable.png");
		img_A_Asintomatico = gcnew Bitmap("Imagenes\\A_Asintomatico.png");
		img_Ambulancia = gcnew Bitmap("Imagenes\\Ambulancia.png");
		img_Policia = gcnew Bitmap("Imagenes\\Policia.png");
		img_Ciudadano = gcnew Bitmap("Imagenes\\Ciudadana.png");
		img_mensaje = gcnew Bitmap("Imagenes\\Mensaje02.png");

		objJugador->SetX(10);
		objJugador->SetY(60);

		tiempo = 0;
		cantidad_enviada = 0;

		tiempo_ambulancia = j.Next(10, 40);
		tiempo_policia = j.Next(40, 50);


		cantidad_a_saludables = j.Next(3, 5);
		cantidad_a_asintomatico = j.Next(3, 5);
		cantidad_ciudadano = j.Next(3, 6);

		cant_saludable = 0;
		AgregarA_Saludables(cantidad_a_saludables * 2);
		cant_asintomatico = 0;
		AgregarA_Asintomatico(cantidad_a_asintomatico * 2);
		cant_ciudadano = 0;
		Agregar_Ciudadano(cantidad_ciudadano);
		break;
	default:
		break;
	}
}


void Controladora::Tiempo(Graphics^ g, Timer^ timer01) {
	if (mundo_juego == 1) {
		if (cantidad_enviada == ((cantidad_a_saludables + cantidad_a_asintomatico) / 2) && tiempo <= tiempo_juego) {
			mundo_juego = 2;
			tiempo = 0;
			Pasar_Mundo();
			
			timer01->Enabled = true;
		}
	}
	else if (mundo_juego == 2) {
		if (cantidad_enviada == (((cantidad_a_saludables + cantidad_a_asintomatico) * 2) / 2) && tiempo <= tiempo_juego) {
			timer01->Enabled = false;
			up->Play();

			MessageBox::Show( "haz ganado\n" +
				"Mundo: " + Retornar_Mundo() +
				"\nVidas: " + Retornar_Vidas() +
				"\nPuntos: " + Puntaje() +
				"\nMensajes enviados: " + Retornar_enviado() +
				"\nTiempo: " + Retornar_Tiempo(), "Estadísticas", MessageBoxButtons::OK, MessageBoxIcon::Information);
		
		}
	}
	ancho_escenario = g->VisibleClipBounds.Width;
	alto_escenario = g->VisibleClipBounds.Height;

	g->DrawImage(img_Mundo, 0, 60, ancho_escenario, alto_escenario);

	Dinamica_Juego(g);
	tiempo++;
	MoverA_Saludables(g);
	MoverA_Asintomatico(g);

	MoverAmbulancia(g);
	MoverPolicia(g);

	Mover_Ciudadano(g);

	////////---- MENSAJE ----////////
	Mandar_Mensaje_Saludable(g);
	Mandar_Mensaje_Asintomatico(g);


	////////---- COLISION ----////////
	Colision_JyA_Salud(g);
	Colision_JyA_Asin(g);
	Ambulancia_Captura();
	Policia_Captura();
	Ciudadano_Contagia(g);


	if (mundo_juego == 1 && cantidad_enviada == ((cantidad_a_saludables + cantidad_a_asintomatico) / 2) && tiempo <= tiempo_juego) {
		timer01->Enabled = false;
		up->Play();

		MessageBox::Show("haz ganado\n" +
			"Mundo: " + Retornar_Mundo() +
			"\nVidas: " + Retornar_Vidas() +
			"\nPuntos: " + Puntaje() +
			"\nMensajes enviados: " + Retornar_enviado() +
			"\nTiempo: " + Retornar_Tiempo(), "Estadísticas", MessageBoxButtons::OK, MessageBoxIcon::Information);
		timer01->Enabled = true;
	}
	if (mundo_juego > 2 && vida_jugador > 0) {
		timer01->Enabled = false;
		up->Play();

		MessageBox::Show("haz ganado\n" +
			"Mundo: " + Retornar_Mundo() +
			"\nVidas: " + Retornar_Vidas() +
			"\nPuntos: " + Puntaje() +
			"\nMensajes enviados: " + Retornar_enviado() +
			"\nTiempo: " + Retornar_Tiempo(), "Estadísticas", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	if ((mundo_juego > 2 && vida_jugador <= 0) || vida_jugador <= 0) {
		if (vida_jugador <= 0) {
			vida_jugador = 0;
			vulnerabilidad = 0;
			
		}
		gameover->Play();

		timer01->Enabled = false;
		MessageBox::Show("haz perdido\n" +
			"Mundo: " + Retornar_Mundo() + 
			"\nVidas: " + Retornar_Vidas() +
			"\nPuntos: " + Puntaje() +
			"\nMensajes enviados: " + Retornar_enviado() +
			"\nTiempo: " + Retornar_Tiempo(), "Estadísticas", MessageBoxButtons::OK, MessageBoxIcon::Information);
		

	}
	if (tiempo >= tiempo_juego && vida_jugador >= 1) {
		vulnerabilidad = vulnerabilidad - 1;
		if (vulnerabilidad <= 0) {
			vulnerabilidad = 20;
			vida_jugador = vida_jugador - 1;
		}
	}

}

//////////////-------------JUGADOR-----------/////////////////////
Jugador* Controladora::Get_Jugador() { return objJugador; }
void Controladora::MoverJugador(Keys key, Graphics^ g) {
	if (key == Keys::Up)
		objJugador->Mover(Direccion::Arriba, g);

	else if (key == Keys::Down)
		objJugador->Mover(Direccion::Abajo, g);

	else if (key == Keys::Left)
		objJugador->Mover(Direccion::Izquierda, g);

	else if (key == Keys::Right)
		objJugador->Mover(Direccion::Derecha, g);

	else if (key == Keys::None)
		objJugador->Mover(Direccion::Ninguno, g);
}
void Controladora::Disparar() { objJugador->CrearBala(); }


//////////////-------------ADVERSARIO SALUDABLE-----------/////////////////////
void Controladora::MoverA_Saludables(Graphics^ g) {
	Direccion direccion;
	for (int i = 0; i < cant_saludable; i++)
		objA_Saludables[i]->Mover(direccion, g);

	objJugador->MoverBalas();
}


void Controladora::AgregarA_Saludables(int n) {
	for (int m = 0; m < n; m++) {
		A_Saludable** aux = new A_Saludable * [cant_saludable + 1];

		for (int i = 0; i < cant_saludable; i++)
			aux[i] = objA_Saludables[i];

		aux[cant_saludable] = new A_Saludable();

		objA_Saludables = aux;
		cant_saludable++;
	}
}
void Controladora::EliminarA_Saludables(int n) {
	A_Saludable** aux = new A_Saludable * [cant_saludable - 1];

	delete objA_Saludables[n];

	for (int i = 0; i < n; i++)
		aux[i] = objA_Saludables[i];

	for (int i = n; i < cant_saludable - 1; i++)
		aux[i] = objA_Saludables[i + 1];

	cant_saludable--;
	objA_Saludables = aux;
}
void Controladora::Mandar_Mensaje_Saludable(Graphics^ g) {
	Rectangle bala;
	Rectangle a_saludable;

	Bala* BALA;

inicio:
	for (int b = 0; b < objJugador->GetCantBalas(); b++) {
		BALA = objJugador->GetBala(b);

		bala = Rectangle(BALA->GetX(), BALA->GetY(), BALA->GetAncho(), BALA->GetAlto());
		for (int e = 0; e < cant_saludable; e++) {
			a_saludable = Rectangle(objA_Saludables[e]->GetX(), objA_Saludables[e]->GetY(), objA_Saludables[e]->GetAncho(), objA_Saludables[e]->GetAlto());
			if (bala.IntersectsWith(a_saludable)) {
				if (objA_Saludables[e]->GetColumna() <= 3) {
					puntos = puntos + 10;
					coin->Play();
					cantidad_enviada++;
				}
				objJugador->EliminarBala(b);
				objA_Saludables[e]->SetFila(0);
				objA_Saludables[e]->SetColumna(4);

				goto inicio;
			}
		}
	}
}

void Controladora::Colision_JyA_Salud(Graphics^ g) {
	Rectangle a_saludables;
	Rectangle jugador;
inicio:

	jugador = Rectangle(objJugador->GetX(), objJugador->GetY(), objJugador->GetAncho(), objJugador->GetAlto());
	for (int e = 0; e < cant_saludable; e++) {
		a_saludables = Rectangle(objA_Saludables[e]->GetX(), objA_Saludables[e]->GetY(), objA_Saludables[e]->GetAncho(), objA_Saludables[e]->GetAlto());
		if (a_saludables.IntersectsWith(jugador)) {
			vulnerabilidad = vulnerabilidad - 1;
			if (vulnerabilidad <= 0) {
				vulnerabilidad = 20;
				vida_jugador = vida_jugador - 1;
				objJugador->SetX(10);
				objJugador->SetY(60);
				MoverA_Saludables(g);
				goto inicio;
			}
		}
	}
}
int Controladora::GetA_Saludable() { return cant_saludable; }

//////////////-------------ADVERSARIO ASINTOMATICO-----------/////////////////////
void Controladora::MoverA_Asintomatico(Graphics^ g) {
	Direccion direccion;
	for (int i = 0; i < cant_asintomatico; i++)
		objA_Asintomatico[i]->Mover(direccion, g);

	objJugador->MoverBalas();
}
void Controladora::AgregarA_Asintomatico(int n) {
	for (int m = 0; m < n; m++) {
		A_Asintomatico** aux = new A_Asintomatico * [cant_asintomatico + 1];

		for (int i = 0; i < cant_asintomatico; i++)
			aux[i] = objA_Asintomatico[i];

		aux[cant_asintomatico] = new A_Asintomatico();

		objA_Asintomatico = aux;
		cant_asintomatico++;
	}
}

void Controladora::EliminarA_Asintomatico(int n) {
	A_Asintomatico** aux = new A_Asintomatico * [cant_asintomatico - 1];

	delete objA_Asintomatico[n];

	for (int i = 0; i < n; i++)
		aux[i] = objA_Asintomatico[i];

	for (int i = n; i < cant_asintomatico - 1; i++)
		aux[i] = objA_Asintomatico[i + 1];

	cant_asintomatico--;
	objA_Asintomatico = aux;
}
void Controladora::Mandar_Mensaje_Asintomatico(Graphics^ g) {
	Rectangle bala;
	Rectangle a_asintomatico;

	Bala* BALA;

inicio:
	for (int b = 0; b < objJugador->GetCantBalas(); b++) {
		BALA = objJugador->GetBala(b);

		bala = Rectangle(BALA->GetX(), BALA->GetY(), BALA->GetAncho(), BALA->GetAlto());
		for (int e = 0; e < cant_asintomatico; e++) {
			a_asintomatico = Rectangle(objA_Asintomatico[e]->GetX(), objA_Asintomatico[e]->GetY(), objA_Asintomatico[e]->GetAncho(), objA_Asintomatico[e]->GetAlto());
			if (bala.IntersectsWith(a_asintomatico)) {
				if (objA_Asintomatico[e]->GetColumna() <= 3) {
					puntos = puntos + 10;		
					coin->Play();
					cantidad_enviada++;

				}
				objJugador->EliminarBala(b);
				objA_Asintomatico[e]->SetFila(0);
				objA_Asintomatico[e]->SetColumna(4);

				goto inicio;
			}
		}
	}
}

void Controladora::Colision_JyA_Asin(Graphics^ g) {
	Rectangle a_asintomatico;
	Rectangle jugador;
inicio:

	jugador = Rectangle(objJugador->GetX(), objJugador->GetY(), objJugador->GetAncho(), objJugador->GetAlto());
	for (int e = 0; e < cant_asintomatico; e++) {
		a_asintomatico = Rectangle(objA_Asintomatico[e]->GetX(), objA_Asintomatico[e]->GetY(), objA_Asintomatico[e]->GetAncho(), objA_Asintomatico[e]->GetAlto());
		if (a_asintomatico.IntersectsWith(jugador)) {
			vulnerabilidad = vulnerabilidad - 1;
			if (vulnerabilidad <= 0) {
				vulnerabilidad = 20;
				vida_jugador = vida_jugador - 1;
				
				objJugador->SetX(10);
				objJugador->SetY(60);
				
				MoverA_Saludables(g);
				goto inicio;
			}
		}
	}
}
int Controladora::GetA_Asintomatico() { return cant_asintomatico; }


//////////////-------------AMBULANCIA-----------/////////////////////
void Controladora::MoverAmbulancia(Graphics^ g) {
	for (int i = 0; i < cant_saludable; i++) {
		if (objA_Saludables[i]->GetColumna() == 4) {
			if (objAmbulancia->GetX() > objA_Saludables[i]->GetX())
				objAmbulancia->Mover(Direccion::Izquierda, g);
			else if (objAmbulancia->GetX() < objA_Saludables[i]->GetX())
				objAmbulancia->Mover(Direccion::Derecha, g);

			if (objAmbulancia->GetY() > objA_Saludables[i]->GetY())
				objAmbulancia->Mover(Direccion::Arriba, g);
			else if (objAmbulancia->GetY() < objA_Saludables[i]->GetY())
				objAmbulancia->Mover(Direccion::Abajo, g);
		}
	}
}
void Controladora::Ambulancia_Captura() {
	Rectangle a_saludables;
	Rectangle ambulancia;
inicio:

	ambulancia = Rectangle(objAmbulancia->GetX(), objAmbulancia->GetY(), objAmbulancia->GetAncho(), objAmbulancia->GetAlto());
	for (int e = 0; e < cant_saludable; e++) {
		a_saludables = Rectangle(objA_Saludables[e]->GetX(), objA_Saludables[e]->GetY(), objA_Saludables[e]->GetAncho(), objA_Saludables[e]->GetAlto());
		if (objA_Saludables[e]->GetColumna() == 4) {
			if (a_saludables.IntersectsWith(ambulancia)) {
				EliminarA_Saludables(e);
				goto inicio;
			}
		}
	}
}

//////////////-------------POLICIA-----------/////////////////////
void Controladora::MoverPolicia(Graphics^ g) {
	
	for (int i = 0; i < cant_asintomatico; i++) {
		if (objA_Asintomatico[i]->GetColumna() == 4) {
			if (objPolicia->GetX() > objA_Asintomatico[i]->GetX())
				objPolicia->Mover(Direccion::Izquierda, g);
			else if (objPolicia->GetX() < objA_Asintomatico[i]->GetX())
				objPolicia->Mover(Direccion::Derecha, g);

			if (objPolicia->GetY() > objA_Asintomatico[i]->GetY())
				objPolicia->Mover(Direccion::Arriba, g);
			else if (objPolicia->GetY() < objA_Asintomatico[i]->GetY())
				objPolicia->Mover(Direccion::Abajo, g);
		}
	}
}

void Controladora::Policia_Captura() {
	Rectangle a_asintomatico;
	Rectangle policia;
inicio:

	policia = Rectangle(objPolicia->GetX(), objPolicia->GetY(), objPolicia->GetAncho(), objPolicia->GetAlto());
	for (int e = 0; e < cant_asintomatico; e++) {
		a_asintomatico = Rectangle(objA_Asintomatico[e]->GetX(), objA_Asintomatico[e]->GetY(), objA_Asintomatico[e]->GetAncho(), objA_Asintomatico[e]->GetAlto());
		if (objA_Asintomatico[e]->GetColumna() == 4) {
			if (a_asintomatico.IntersectsWith(policia)) {
				EliminarA_Asintomatico(e);
				goto inicio;
			}
		}
	}
}


void Controladora::Mover_Ciudadano(Graphics^ g) {
	for (int i = 0; i < cant_ciudadano; i++) {

		if (objCiudadano[i]->GetX() > objJugador->GetX())
			objCiudadano[i]->Mover(Direccion::Izquierda, g);
		else if (objCiudadano[i]->GetX() < objJugador->GetX())
			objCiudadano[i]->Mover(Direccion::Derecha, g);

		if (objCiudadano[i]->GetY() > objJugador->GetY())
			objCiudadano[i]->Mover(Direccion::Arriba, g);
		else if (objCiudadano[i]->GetY() < objJugador->GetY())
			objCiudadano[i]->Mover(Direccion::Abajo, g);
	}
}
void Controladora::Agregar_Ciudadano(int n) {
	for (int m = 0; m < n; m++) {
		Ciudadano** aux = new Ciudadano * [cant_ciudadano + 1];

		for (int i = 0; i < cant_ciudadano; i++)
			aux[i] = objCiudadano[i];

		aux[cant_ciudadano] = new Ciudadano();

		objCiudadano = aux;
		cant_ciudadano++;
	}
}
void Controladora::Ciudadano_Contagia(Graphics^ g) {
	Rectangle jugador;
	Rectangle ciudadano;
inicio:

	jugador = Rectangle(objJugador->GetX(), objJugador->GetY(), objJugador->GetAncho(), objJugador->GetAlto());
	for (int e = 0; e < cantidad_ciudadano; e++) {
		ciudadano = Rectangle(objCiudadano[e]->GetX(), objCiudadano[e]->GetY(), objCiudadano[e]->GetAncho(), objCiudadano[e]->GetAlto());
		if (ciudadano.IntersectsWith(jugador)) {
			vulnerabilidad = vulnerabilidad - 1;
			if (vulnerabilidad <= 0) {
				vulnerabilidad = 20;
				vida_jugador = vida_jugador - 1;
				objJugador->SetX(10);
				objJugador->SetY(60);
				MoverA_Saludables(g);
				goto inicio;
			}
		}
	}
}



int Controladora::Puntaje() { return puntos; }

int Controladora::Retornar_Tiempo() { return tiempo; }
int Controladora::Retornar_Vidas() { return vida_jugador; }
int Controladora::Retornar_Vulnerabilidad() { return vulnerabilidad; }
int Controladora::Retornar_Mundo() { return mundo_juego; }
int Controladora::Retornar_enviado() { return cantidad_enviada; }
int Controladora::Retornar_adversarios() { return cantidad_a_asintomatico + cantidad_a_saludables; }


void Controladora::Cambiar_velocidades() {
	Random j;
	for (int i = 0; i < cantidad_a_asintomatico; i++) {
		objA_Asintomatico[i]->SetDX(j.Next(2, 4));
		objA_Asintomatico[i]->SetDY(j.Next(2, 4));
	}
	for (int i = 0; i < cantidad_a_saludables; i++) {
		objA_Saludables[i]->SetDX(j.Next(2, 4));
		objA_Saludables[i]->SetDY(j.Next(2, 4));
	}

	for (int i = 0; i < cantidad_ciudadano; i++) {
		objCiudadano[i]->SetDX(3);
		objCiudadano[i]->SetDY(3);
	}
	objAmbulancia->SetDX(3);
	objAmbulancia->SetDY(3);

	objPolicia->SetDX(3);
	objPolicia->SetDY(3);
}

