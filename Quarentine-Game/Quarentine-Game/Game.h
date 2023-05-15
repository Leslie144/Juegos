#pragma once
#include<iostream>
#include<fstream>
#include"MyForm.h"
#include"Avanzado.h"
using namespace std;
namespace QuarentineGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBox_Usuario;
	protected:
	private: System::Windows::Forms::NumericUpDown^ UpDown_vidas;
	private: System::Windows::Forms::NumericUpDown^ UpDown_Tiempo;




	private: System::Windows::Forms::Button^ button_Comenzar_Juego;
	private: System::Windows::Forms::ComboBox^ comboBox_dificultad;
	private: System::Windows::Forms::Button^ button_registrar;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button_cerrar_registro;





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->txtBox_Usuario = (gcnew System::Windows::Forms::TextBox());
			this->UpDown_vidas = (gcnew System::Windows::Forms::NumericUpDown());
			this->UpDown_Tiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox_dificultad = (gcnew System::Windows::Forms::ComboBox());
			this->button_Comenzar_Juego = (gcnew System::Windows::Forms::Button());
			this->button_registrar = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button_cerrar_registro = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpDown_vidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpDown_Tiempo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBox_Usuario
			// 
			this->txtBox_Usuario->Location = System::Drawing::Point(120, 63);
			this->txtBox_Usuario->Name = L"txtBox_Usuario";
			this->txtBox_Usuario->Size = System::Drawing::Size(100, 20);
			this->txtBox_Usuario->TabIndex = 0;
			// 
			// UpDown_vidas
			// 
			this->UpDown_vidas->Location = System::Drawing::Point(160, 89);
			this->UpDown_vidas->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->UpDown_vidas->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->UpDown_vidas->Name = L"UpDown_vidas";
			this->UpDown_vidas->Size = System::Drawing::Size(60, 20);
			this->UpDown_vidas->TabIndex = 1;
			this->UpDown_vidas->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->UpDown_vidas->Validated += gcnew System::EventHandler(this, &Game::Validar_vidas);
			// 
			// UpDown_Tiempo
			// 
			this->UpDown_Tiempo->Location = System::Drawing::Point(160, 115);
			this->UpDown_Tiempo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->UpDown_Tiempo->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->UpDown_Tiempo->Name = L"UpDown_Tiempo";
			this->UpDown_Tiempo->Size = System::Drawing::Size(60, 20);
			this->UpDown_Tiempo->TabIndex = 2;
			this->UpDown_Tiempo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->UpDown_Tiempo->Validated += gcnew System::EventHandler(this, &Game::Validar_Tiempo);
			// 
			// comboBox_dificultad
			// 
			this->comboBox_dificultad->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_dificultad->FormattingEnabled = true;
			this->comboBox_dificultad->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Principiante", L"Avanzado" });
			this->comboBox_dificultad->Location = System::Drawing::Point(120, 141);
			this->comboBox_dificultad->Name = L"comboBox_dificultad";
			this->comboBox_dificultad->Size = System::Drawing::Size(100, 21);
			this->comboBox_dificultad->TabIndex = 6;
			// 
			// button_Comenzar_Juego
			// 
			this->button_Comenzar_Juego->Location = System::Drawing::Point(72, 186);
			this->button_Comenzar_Juego->Name = L"button_Comenzar_Juego";
			this->button_Comenzar_Juego->Size = System::Drawing::Size(105, 27);
			this->button_Comenzar_Juego->TabIndex = 5;
			this->button_Comenzar_Juego->Text = L"Comenzar Juego";
			this->button_Comenzar_Juego->UseVisualStyleBackColor = true;
			this->button_Comenzar_Juego->Click += gcnew System::EventHandler(this, &Game::button_Comenzar_Juego_Click);
			this->button_Comenzar_Juego->Enter += gcnew System::EventHandler(this, &Game::Pulsar_enter);
			// 
			// button_registrar
			// 
			this->button_registrar->Location = System::Drawing::Point(264, 210);
			this->button_registrar->Name = L"button_registrar";
			this->button_registrar->Size = System::Drawing::Size(18, 21);
			this->button_registrar->TabIndex = 7;
			this->button_registrar->Text = L"R";
			this->button_registrar->UseVisualStyleBackColor = true;
			this->button_registrar->Click += gcnew System::EventHandler(this, &Game::button_registrar_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(292, 248);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(298, 12);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(161, 227);
			this->textBox3->TabIndex = 10;
			// 
			// button_cerrar_registro
			// 
			this->button_cerrar_registro->Location = System::Drawing::Point(264, 212);
			this->button_cerrar_registro->Name = L"button_cerrar_registro";
			this->button_cerrar_registro->Size = System::Drawing::Size(18, 21);
			this->button_cerrar_registro->TabIndex = 11;
			this->button_cerrar_registro->Text = L"C";
			this->button_cerrar_registro->UseVisualStyleBackColor = true;
			this->button_cerrar_registro->Visible = false;
			this->button_cerrar_registro->Click += gcnew System::EventHandler(this, &Game::button_cerrar_registro_Click);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(289, 243);
			this->Controls->Add(this->button_cerrar_registro);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button_registrar);
			this->Controls->Add(this->comboBox_dificultad);
			this->Controls->Add(this->button_Comenzar_Juego);
			this->Controls->Add(this->UpDown_Tiempo);
			this->Controls->Add(this->UpDown_vidas);
			this->Controls->Add(this->txtBox_Usuario);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(500, 283);
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpDown_vidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->UpDown_Tiempo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Comenzar_Juego_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int valor_mundo = 1;
		String^ valor_usuario = System::Convert::ToString(this->txtBox_Usuario->Text);
		String^ valor_dificultad = System::Convert::ToString(this->comboBox_dificultad->Text);
		int valor_vidas = System::Convert::ToInt16(this->UpDown_vidas->Text);
		int valor_tiempo = System::Convert::ToInt16(this->UpDown_Tiempo->Text);
		

		if (String::IsNullOrEmpty(valor_usuario)) {
			MessageBox::Show("Debes completar nombre de usuario.", "Completar", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		if (String::IsNullOrEmpty(valor_dificultad)) {
			MessageBox::Show("Debes selecionar la dificultad.", "Completar", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}


		if (valor_dificultad == "Principiante") {
			MyForm^ Formulario_contiene_Principiante = gcnew MyForm(valor_vidas, valor_tiempo, valor_dificultad = "Principiante", valor_usuario, valor_mundo);
			Formulario_contiene_Principiante->ShowDialog();
		}
		else {
			//MessageBox::Show("Avanzado");
			Avanzado^ Formulario_contiene_Avanzado = gcnew Avanzado(valor_vidas, valor_tiempo, valor_dificultad = "Avanzado", valor_usuario, valor_mundo);
			Formulario_contiene_Avanzado->ShowDialog();
		}

		char arrusuarios[30] = { 0 };

		sprintf(arrusuarios, "%s", valor_usuario);

		string nuevo_usuario(arrusuarios);

		ofstream fs;
		//apertura
		fs.open("Historial.txt", ios::ate);
		//datos a escribir
		fs << "Nombre del jugador: ";
		fs << nuevo_usuario;
		//cierre del archivo
		fs.flush();
		fs.close();

	}

	private: System::Void Validar_vidas(System::Object^ sender, System::EventArgs^ e) {
		if (UpDown_vidas->Text == "") {
			UpDown_vidas->Text = "3";
		}
		
	}
	private: System::Void Validar_Tiempo(System::Object^ sender, System::EventArgs^ e) {
		if (UpDown_Tiempo->Text == "") {
			UpDown_Tiempo->Text = "1";
		}
	}
	private: System::Void Pulsar_enter(System::Object^ sender, System::EventArgs^ e) {
		button_Comenzar_Juego_Click(sender, e);
	}
	private: System::Void button_registrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Width = 500;
		this->button_registrar->Visible = false;
		this->button_cerrar_registro->Visible = true;

		string linea;
		String^ nuevo;

		ifstream fe;
		fe.open("Historial.txt", ios::in);

		while (!fe.eof()) {
			fe >> linea;
			nuevo = gcnew String(linea.c_str());

			textBox3->Text = textBox3->Text + "" + nuevo + "\n";

		}
	}
	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Width = 310;
	}
	private: System::Void button_cerrar_registro_Click(System::Object^ sender, System::EventArgs^ e) {
		this->button_cerrar_registro->Visible = false;
		this->button_registrar->Visible = true;
		this->Width = 310;

	}
};
}