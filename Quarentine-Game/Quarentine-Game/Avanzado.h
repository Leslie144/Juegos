#pragma once
#include"Controladora.h"

namespace QuarentineGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Avanzado
	/// </summary>
	public ref class Avanzado : public System::Windows::Forms::Form
	{
	private:
		int valor_vidas, valor_tiempo;
		int valor_mundo;
	private: System::Windows::Forms::Label^ label_Dificultad;
		   String^ valor_dificultad;
	private: System::Windows::Forms::Label^ label_enviado;

		   String^ valor_usuario;
	public:
		SoundPlayer^ fondo = gcnew SoundPlayer("Sonidos\\Fondo.wav");

		Avanzado(int vv, int vt, String^ vd, String^ vu, int vm)
		{
			valor_vidas = vv;
			valor_tiempo = vt * 1000;
			valor_dificultad = vd;
			valor_usuario = vu;
			valor_mundo = vm;
			InitializeComponent();
			g = this->CreateGraphics();

			juego = gcnew Controladora(valor_vidas, valor_tiempo, valor_mundo);

		}

	protected:
		~Avanzado()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:

		Graphics^ g;
	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label_mundo;

	private: System::Windows::Forms::Label^ label_Usuario;

	private: System::Windows::Forms::Label^ label_puntos;
	private: System::Windows::Forms::Label^ label_Vidas;
	private: System::Windows::Forms::Label^ label_Tiempo;
	private: System::Windows::Forms::Label^ label_Vulnerabilidad;



		   Controladora^ juego;



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_enviado = (gcnew System::Windows::Forms::Label());
			this->label_Dificultad = (gcnew System::Windows::Forms::Label());
			this->label_Vulnerabilidad = (gcnew System::Windows::Forms::Label());
			this->label_Tiempo = (gcnew System::Windows::Forms::Label());
			this->label_Vidas = (gcnew System::Windows::Forms::Label());
			this->label_puntos = (gcnew System::Windows::Forms::Label());
			this->label_Usuario = (gcnew System::Windows::Forms::Label());
			this->label_mundo = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Info;
			this->groupBox1->Controls->Add(this->label_enviado);
			this->groupBox1->Controls->Add(this->label_Dificultad);
			this->groupBox1->Controls->Add(this->label_Vulnerabilidad);
			this->groupBox1->Controls->Add(this->label_Tiempo);
			this->groupBox1->Controls->Add(this->label_Vidas);
			this->groupBox1->Controls->Add(this->label_puntos);
			this->groupBox1->Controls->Add(this->label_Usuario);
			this->groupBox1->Controls->Add(this->label_mundo);
			this->groupBox1->Location = System::Drawing::Point(1, 1);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(602, 63);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			// 
			// label_enviado
			// 
			this->label_enviado->AutoSize = true;
			this->label_enviado->Location = System::Drawing::Point(242, 35);
			this->label_enviado->Name = L"label_enviado";
			this->label_enviado->Size = System::Drawing::Size(54, 13);
			this->label_enviado->TabIndex = 7;
			this->label_enviado->Text = L"Enviados:";
			// 
			// label_Dificultad
			// 
			this->label_Dificultad->AutoSize = true;
			this->label_Dificultad->Location = System::Drawing::Point(419, 16);
			this->label_Dificultad->Name = L"label_Dificultad";
			this->label_Dificultad->Size = System::Drawing::Size(54, 13);
			this->label_Dificultad->TabIndex = 6;
			this->label_Dificultad->Text = L"Dificultad:";
			// 
			// label_Vulnerabilidad
			// 
			this->label_Vulnerabilidad->AutoSize = true;
			this->label_Vulnerabilidad->Location = System::Drawing::Point(465, 35);
			this->label_Vulnerabilidad->Name = L"label_Vulnerabilidad";
			this->label_Vulnerabilidad->Size = System::Drawing::Size(79, 13);
			this->label_Vulnerabilidad->TabIndex = 5;
			this->label_Vulnerabilidad->Text = L"Vulnerabilidad: ";
			// 
			// label_Tiempo
			// 
			this->label_Tiempo->AutoSize = true;
			this->label_Tiempo->Location = System::Drawing::Point(124, 35);
			this->label_Tiempo->Name = L"label_Tiempo";
			this->label_Tiempo->Size = System::Drawing::Size(48, 13);
			this->label_Tiempo->TabIndex = 4;
			this->label_Tiempo->Text = L"Tiempo: ";
			// 
			// label_Vidas
			// 
			this->label_Vidas->AutoSize = true;
			this->label_Vidas->Location = System::Drawing::Point(355, 35);
			this->label_Vidas->Name = L"label_Vidas";
			this->label_Vidas->Size = System::Drawing::Size(39, 13);
			this->label_Vidas->TabIndex = 3;
			this->label_Vidas->Text = L"Vidas: ";
			// 
			// label_puntos
			// 
			this->label_puntos->AutoSize = true;
			this->label_puntos->Location = System::Drawing::Point(21, 35);
			this->label_puntos->Name = L"label_puntos";
			this->label_puntos->Size = System::Drawing::Size(46, 13);
			this->label_puntos->TabIndex = 2;
			this->label_puntos->Text = L"Puntos: ";
			// 
			// label_Usuario
			// 
			this->label_Usuario->AutoSize = true;
			this->label_Usuario->Location = System::Drawing::Point(50, 16);
			this->label_Usuario->Name = L"label_Usuario";
			this->label_Usuario->Size = System::Drawing::Size(46, 13);
			this->label_Usuario->TabIndex = 1;
			this->label_Usuario->Text = L"Usuario:";
			// 
			// label_mundo
			// 
			this->label_mundo->AutoSize = true;
			this->label_mundo->Location = System::Drawing::Point(211, 16);
			this->label_mundo->Name = L"label_mundo";
			this->label_mundo->Size = System::Drawing::Size(43, 13);
			this->label_mundo->TabIndex = 0;
			this->label_mundo->Text = L"Mundo ";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Avanzado::timer1_Tick);
			// 
			// Avanzado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 675);
			this->Controls->Add(this->groupBox1);
			this->MaximumSize = System::Drawing::Size(619, 713);
			this->Name = L"Avanzado";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Avanzado";
			this->Load += gcnew System::EventHandler(this, &Avanzado::Avanzado_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Avanzado::Avanzado_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &Avanzado::Avanzado_Resize);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->Clear(Color::White);
		//bf->Graphics->Clear(Color::Transparent);

		juego->Tiempo(bf->Graphics, timer1);

		bf->Render(g);
		delete bf, bfc;



		////////---- TABLA DE  ----////////
		if (juego->Retornar_Mundo() == 1) {
			this->label_mundo->Text = L"Mundo " + juego->Retornar_Mundo() + " Responsable";
		}
		else {
			this->label_mundo->Text = L"Mundo " + juego->Retornar_Mundo() + " Irresponsable";
		}
		this->label_puntos->Text = L"Puntos: " + juego->Puntaje();
		this->label_Tiempo->Text = L"Tiempo: " + juego->Retornar_Tiempo();
		this->label_Vidas->Text = L"Vidas: " + juego->Retornar_Vidas();
		this->label_Vulnerabilidad->Text = L"Vulnerabilidad: " + juego->Retornar_Vulnerabilidad();

		if (juego->Retornar_Mundo() == 1)
			this->label_enviado->Text = L"Enviados: " + juego->Retornar_enviado() + "/" + juego->Retornar_adversarios();
		else
			this->label_enviado->Text = L"Enviados: " + juego->Retornar_enviado() + "/" + juego->Retornar_adversarios() * 2;

	}
	private: System::Void Avanzado_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->MoverJugador(e->KeyCode, g);
		if (e->KeyCode == Keys::Space)
			juego->Disparar();
	}
	private: System::Void Avanzado_Load(System::Object^ sender, System::EventArgs^ e) {
		fondo->PlayLooping();

		
		this->label_Usuario->Text = L"Usuario: " + valor_usuario;
		this->label_Dificultad->Text = L"Dificultad: " + valor_dificultad;

		juego->Pasar_Mundo();
		juego->Cambiar_velocidades();

	}
	private: System::Void Avanzado_Resize(System::Object^ sender, System::EventArgs^ e) {
		g = this->CreateGraphics();
	}
};
}
