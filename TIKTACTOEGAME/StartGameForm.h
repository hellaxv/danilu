#pragma once

#include "GameMap.h"
#include "Gamer.h"

#include <Windows.h>

namespace TIKTACTOEGAME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для StartGameForm
	/// </summary>
	public ref class StartGameForm : public System::Windows::Forms::Form
	{
	public:
		StartGameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~StartGameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eXITToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ listBoxGameMod;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSizaMap;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownLineWin;
	private: System::Windows::Forms::Button^ buttonStartGame;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eXITToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listBoxGameMod = (gcnew System::Windows::Forms::ListBox());
			this->numericUpDownSizaMap = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownLineWin = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonStartGame = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSizaMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLineWin))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Game MOD: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 34);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Size MAP: ";
			this->label2->Click += gcnew System::EventHandler(this, &StartGameForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 34);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Line WIN: ";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->справкаToolStripMenuItem,
					this->eXITToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(289, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->справкаToolStripMenuItem->Text = L"Reference";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartGameForm::справкаToolStripMenuItem_Click);
			// 
			// eXITToolStripMenuItem
			// 
			this->eXITToolStripMenuItem->Name = L"eXITToolStripMenuItem";
			this->eXITToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->eXITToolStripMenuItem->Text = L"EXIT";
			this->eXITToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartGameForm::eXITToolStripMenuItem_Click);
			// 
			// listBoxGameMod
			// 
			this->listBoxGameMod->Font = (gcnew System::Drawing::Font(L"Microsoft Himalaya", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBoxGameMod->FormattingEnabled = true;
			this->listBoxGameMod->ItemHeight = 24;
			this->listBoxGameMod->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"PvP", L"PvE" });
			this->listBoxGameMod->Location = System::Drawing::Point(127, 32);
			this->listBoxGameMod->Name = L"listBoxGameMod";
			this->listBoxGameMod->Size = System::Drawing::Size(150, 28);
			this->listBoxGameMod->TabIndex = 4;
			this->listBoxGameMod->SelectedIndexChanged += gcnew System::EventHandler(this, &StartGameForm::listBoxGameMod_SelectedIndexChanged);
			// 
			// numericUpDownSizaMap
			// 
			this->numericUpDownSizaMap->Location = System::Drawing::Point(127, 110);
			this->numericUpDownSizaMap->Name = L"numericUpDownSizaMap";
			this->numericUpDownSizaMap->Size = System::Drawing::Size(120, 20);
			this->numericUpDownSizaMap->TabIndex = 9;
			// 
			// numericUpDownLineWin
			// 
			this->numericUpDownLineWin->Location = System::Drawing::Point(127, 71);
			this->numericUpDownLineWin->Name = L"numericUpDownLineWin";
			this->numericUpDownLineWin->Size = System::Drawing::Size(120, 20);
			this->numericUpDownLineWin->TabIndex = 8;
			// 
			// buttonStartGame
			// 
			this->buttonStartGame->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonStartGame->Location = System::Drawing::Point(70, 164);
			this->buttonStartGame->Name = L"buttonStartGame";
			this->buttonStartGame->Size = System::Drawing::Size(143, 45);
			this->buttonStartGame->TabIndex = 7;
			this->buttonStartGame->Text = L"Start Game";
			this->buttonStartGame->UseVisualStyleBackColor = true;
			this->buttonStartGame->Click += gcnew System::EventHandler(this, &StartGameForm::buttonStartGame_Click);
			// 
			// StartGameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 221);
			this->Controls->Add(this->buttonStartGame);
			this->Controls->Add(this->numericUpDownLineWin);
			this->Controls->Add(this->numericUpDownSizaMap);
			this->Controls->Add(this->listBoxGameMod);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(305, 260);
			this->Name = L"StartGameForm";
			this->Text = L"StartGameForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSizaMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLineWin))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//поля игры
	public: int rows;//размерность строк и столбцов в нашей игре
	public: int columns;
	public: int length;//длина для победы
	public: int selectedGameMode;//выбранный режим игры
	private: Random^ rand;
	private: System::Media::SoundPlayer^ soundClick;
	private: System::Media::SoundPlayer^ soundEndGame;
///////////////////////////////////////////////////////////////
    
    //методы игры
	private: void GameLogic();//игровая логика, где все проверяется и тп.
	private: void Update();//события для обновления разных моментов
	private: void NewGame();//событие для запуска новой игры
	private: void StepAI();//ии делает ход
	private: void UpdateGameGrid();//обновление игровой сетки
	private: void CreateGameGrid(Vector2);//создание игровой сетки
	private: void SetPositionPlayer(Vector2);//задать позицию игрока на сетке

	//события игры
private: System::Media::SoundPlayer^ sound; //созданите звука.

private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void eXITToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void listBoxGameMod_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
