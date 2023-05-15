#pragma once
#include"Game.h"
#include"Instrucciones.h"

namespace QuarentineGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Menu_Principal
	/// </summary>
	public ref class Menu_Principal : public System::Windows::Forms::Form
	{
	public:
		SoundPlayer^ sonidointro = gcnew SoundPlayer("Sonidos\\Intro.wav");

		Menu_Principal(void)
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
		~Menu_Principal()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Timer^ timer_Carga;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label_Estudiante;
	private: System::Windows::Forms::Button^ button_Instruciones;
	private: System::Windows::Forms::Button^ button_Jugar;
	private: System::Windows::Forms::Button^ button_apagar;

	private: System::Windows::Forms::Button^ button_encender;





	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Menu_Principal::typeid));
			this->timer_Carga = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label_Estudiante = (gcnew System::Windows::Forms::Label());
			this->button_Instruciones = (gcnew System::Windows::Forms::Button());
			this->button_Jugar = (gcnew System::Windows::Forms::Button());
			this->button_apagar = (gcnew System::Windows::Forms::Button());
			this->button_encender = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// timer_Carga
			// 
			this->timer_Carga->Enabled = true;
			this->timer_Carga->Tick += gcnew System::EventHandler(this, &Menu_Principal::timer_Carga_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(157, 337);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(138, 23);
			this->progressBar1->TabIndex = 7;
			// 
			// label_Estudiante
			// 
			this->label_Estudiante->AutoSize = true;
			this->label_Estudiante->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_Estudiante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label_Estudiante.Image")));
			this->label_Estudiante->Location = System::Drawing::Point(100, 25);
			this->label_Estudiante->Name = L"label_Estudiante";
			this->label_Estudiante->Size = System::Drawing::Size(257, 22);
			this->label_Estudiante->TabIndex = 8;
			this->label_Estudiante->Text = L"Leslie Torres - U201914358";
			// 
			// button_Instruciones
			// 
			this->button_Instruciones->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button_Instruciones->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Instruciones->Location = System::Drawing::Point(296, 264);
			this->button_Instruciones->Name = L"button_Instruciones";
			this->button_Instruciones->Size = System::Drawing::Size(86, 31);
			this->button_Instruciones->TabIndex = 10;
			this->button_Instruciones->Text = L"Instrucciones";
			this->button_Instruciones->UseVisualStyleBackColor = false;
			this->button_Instruciones->Visible = false;
			this->button_Instruciones->Click += gcnew System::EventHandler(this, &Menu_Principal::button_Instruciones_Click);
			// 
			// button_Jugar
			// 
			this->button_Jugar->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button_Jugar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Jugar->Location = System::Drawing::Point(57, 264);
			this->button_Jugar->Name = L"button_Jugar";
			this->button_Jugar->Size = System::Drawing::Size(86, 31);
			this->button_Jugar->TabIndex = 9;
			this->button_Jugar->Text = L"Jugar";
			this->button_Jugar->UseVisualStyleBackColor = false;
			this->button_Jugar->Visible = false;
			this->button_Jugar->Click += gcnew System::EventHandler(this, &Menu_Principal::button_Jugar_Click);
			// 
			// button_apagar
			// 
			this->button_apagar->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button_apagar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_apagar.BackgroundImage")));
			this->button_apagar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_apagar.Image")));
			this->button_apagar->Location = System::Drawing::Point(12, 328);
			this->button_apagar->Name = L"button_apagar";
			this->button_apagar->Size = System::Drawing::Size(27, 32);
			this->button_apagar->TabIndex = 11;
			this->button_apagar->UseVisualStyleBackColor = false;
			this->button_apagar->Click += gcnew System::EventHandler(this, &Menu_Principal::button_apagar_Click);
			// 
			// button_encender
			// 
			this->button_encender->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button_encender->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_encender.BackgroundImage")));
			this->button_encender->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_encender.Image")));
			this->button_encender->Location = System::Drawing::Point(12, 328);
			this->button_encender->Name = L"button_encender";
			this->button_encender->Size = System::Drawing::Size(38, 32);
			this->button_encender->TabIndex = 12;
			this->button_encender->UseVisualStyleBackColor = false;
			this->button_encender->Visible = false;
			this->button_encender->Click += gcnew System::EventHandler(this, &Menu_Principal::button_encender_Click);
			// 
			// Menu_Principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(437, 381);
			this->Controls->Add(this->button_encender);
			this->Controls->Add(this->button_apagar);
			this->Controls->Add(this->button_Instruciones);
			this->Controls->Add(this->button_Jugar);
			this->Controls->Add(this->label_Estudiante);
			this->Controls->Add(this->progressBar1);
			this->DoubleBuffered = true;
			this->MaximumSize = System::Drawing::Size(453, 419);
			this->Name = L"Menu_Principal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Menu_Principal";
			this->Activated += gcnew System::EventHandler(this, &Menu_Principal::Menu_Principal_Activated);
			this->Load += gcnew System::EventHandler(this, &Menu_Principal::Menu_Principal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Menu_Principal_Load(System::Object^ sender, System::EventArgs^ e) {
		this->timer_Carga->Start();
		sonidointro->PlayLooping();
	}
	private: System::Void timer_Carga_Tick(System::Object^ sender, System::EventArgs^ e) {
		this->progressBar1->Increment(1);
		if (this->progressBar1->Value == 100) {
			this->progressBar1->Visible = false;
			this->button_Jugar->Visible = true;
			this->button_Instruciones->Visible = true;
			this->timer_Carga->Enabled = false;
		}
	}
	private: System::Void button_Jugar_Click(System::Object^ sender, System::EventArgs^ e) {
		sonidointro->Stop();

		Game^ Formulario_contiene_Game = gcnew Game();
		Formulario_contiene_Game->ShowDialog();
	}
	private: System::Void button_Instruciones_Click(System::Object^ sender, System::EventArgs^ e) {
		Instrucciones^ Formulario_contiene_Instrucciones = gcnew Instrucciones();
		Formulario_contiene_Instrucciones->ShowDialog();
	}

	private: System::Void button_sonido_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button_encender_Click(System::Object^ sender, System::EventArgs^ e) {
		this->button_encender->Visible = false;
		this->button_apagar->Visible = true;
		sonidointro->PlayLooping();

	
	}
	private: System::Void button_apagar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->button_apagar->Visible = false;
		this->button_encender->Visible = true;
		sonidointro->Stop();
	}
	private: System::Void Menu_Principal_Activated(System::Object^ sender, System::EventArgs^ e) {
		sonidointro->PlayLooping();
	}
};
}
