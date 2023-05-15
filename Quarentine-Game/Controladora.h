#pragma once
#include"Jugador.h"
#include"A_Saludable.h"
#include"A_Asintomatico.h"
#include"Ambulancia.h"
#include"Policia.h"
#include"Ciudadano.h"

#include<string>

using namespace System::Windows::Forms;
using namespace System::Media;
using namespace std;

ref class Controladora {
private:
	int ancho_escenario;
	int alto_escenario;

	int mundo_juego;
	int puntos;
	int tiempo_juego;
	int tiempo;
	int vida_jugador;
	int vulnerabilidad;
	int vidas;
	int cantidad_a_saludables;
	int cantidad_a_asintomatico;
	int cantidad_ciudadano;

	Jugador* objJugador;
	A_Saludable** objA_Saludables;
	A_Asintomatico** objA_Asintomatico;
	Ambulancia* objAmbulancia;
	Policia* objPolicia;
	Ciudadano** objCiudadano;


	int cant_saludable;
	int cant_asintomatico;
	int cant_ciudadano;

	int tiempo_ambulancia;
	int tiempo_policia;

	int tiempo_adversarios;
	int cantidad_enviada;


	Bitmap^ img_Mundo;
	Bitmap^ img_Jugador;
	Bitmap^ img_A_Saludable;
	Bitmap^ img_A_Asintomatico;
	Bitmap^ img_Ambulancia;
	Bitmap^ img_Policia;
	Bitmap^ img_Ciudadano;
	Bitmap^ img_mensaje;

	SoundPlayer^ fondo;
	SoundPlayer^ gameover;
	SoundPlayer^ up;
	SoundPlayer^ coin;


public:
	Controladora(int vidas, int tiempo, int mundo);
	~Controladora();


	void Dinamica_Juego(Graphics^ g);

	void Pasar_Mundo();

	void Tiempo(Graphics^ g, Timer^ timer1);

	//JUGADOR
	Jugador* Get_Jugador();
	void MoverJugador(Keys key, Graphics^ g);
	void Disparar();
	//ADVERSARIO SALUDABLE
	void MoverA_Saludables(Graphics^ g);
	void AgregarA_Saludables(int n);
	void EliminarA_Saludables(int n);

	void Mandar_Mensaje_Saludable(Graphics^ g);
	void Colision_JyA_Salud(Graphics^ g);

	int GetA_Saludable();

	//ADVERSARIO ASINTOMATICO
	void MoverA_Asintomatico(Graphics^ g);
	void AgregarA_Asintomatico(int n);
	void EliminarA_Asintomatico(int n);
	void Mandar_Mensaje_Asintomatico(Graphics^ g);
	void Colision_JyA_Asin(Graphics^ g);

	int GetA_Asintomatico();
	//AMBULANCIA
	void MoverAmbulancia(Graphics^ g);
	void Ambulancia_Captura();
	//POLICIA
	void MoverPolicia(Graphics^ g);
	void Policia_Captura();


	//Ciudadano
	void Mover_Ciudadano(Graphics^ g);
	void Agregar_Ciudadano(int n);
	void Ciudadano_Contagia(Graphics^ g);


	int Puntaje();
	int Retornar_Tiempo();
	int Retornar_Vidas();
	int Retornar_Vulnerabilidad();

	int Retornar_Mundo();
	int Retornar_enviado();
	int Retornar_adversarios();


	void Cambiar_velocidades();
};
