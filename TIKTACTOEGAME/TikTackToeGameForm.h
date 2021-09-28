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
	/// —водка дл€ TikTackToeGameForm
	/// </summary>
	public ref class TikTackToeGameForm : public System::Windows::Forms::Form
	{
	public:
		TikTackToeGameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~TikTackToeGameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ backOnMenuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsSoundToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ referenceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eXITToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ StripStatus;
	private: System::Windows::Forms::DataGridView^ dataGridView;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backOnMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsSoundToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->referenceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eXITToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->StripStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuToolStripMenuItem,
					this->referenceToolStripMenuItem, this->eXITToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(560, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newGameToolStripMenuItem,
					this->backOnMenuToolStripMenuItem, this->settingsSoundToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			this->menuToolStripMenuItem->Click += gcnew System::EventHandler(this, &TikTackToeGameForm::menuToolStripMenuItem_Click);
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->newGameToolStripMenuItem->Text = L"New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &TikTackToeGameForm::newGameToolStripMenuItem_Click);
			// 
			// backOnMenuToolStripMenuItem
			// 
			this->backOnMenuToolStripMenuItem->Name = L"backOnMenuToolStripMenuItem";
			this->backOnMenuToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->backOnMenuToolStripMenuItem->Text = L"Go Back <--";
			this->backOnMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &TikTackToeGameForm::backOnMenuToolStripMenuItem_Click);
			// 
			// settingsSoundToolStripMenuItem
			// 
			this->settingsSoundToolStripMenuItem->Name = L"settingsSoundToolStripMenuItem";
			this->settingsSoundToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->settingsSoundToolStripMenuItem->Text = L"Settings Sound";
			this->settingsSoundToolStripMenuItem->Click += gcnew System::EventHandler(this, &TikTackToeGameForm::settingsSoundToolStripMenuItem_Click);
			// 
			// referenceToolStripMenuItem
			// 
			this->referenceToolStripMenuItem->Name = L"referenceToolStripMenuItem";
			this->referenceToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->referenceToolStripMenuItem->Text = L"Reference";
			this->referenceToolStripMenuItem->Click += gcnew System::EventHandler(this, &TikTackToeGameForm::referenceToolStripMenuItem_Click);
			// 
			// eXITToolStripMenuItem
			// 
			this->eXITToolStripMenuItem->Name = L"eXITToolStripMenuItem";
			this->eXITToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->eXITToolStripMenuItem->Text = L"EXIT";
			this->eXITToolStripMenuItem->Click += gcnew System::EventHandler(this, &TikTackToeGameForm::eXITToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->StripStatus });
			this->statusStrip1->Location = System::Drawing::Point(0, 278);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(560, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// StripStatus
			// 

			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 24);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(560, 254);
			this->dataGridView->TabIndex = 2;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TikTackToeGameForm::dataGridView_CellContentClick);
			// 
			// TikTackToeGameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(560, 300);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"TikTackToeGameForm";
			this->Text = L"TikTackToeGame";
			this->Load += gcnew System::EventHandler(this, &TikTackToeGameForm::TikTackToeGameForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: int rows;
	public: int columns;
	public: int length;
	public: int selectedGameMode;
	private: Random^ rand;
	private: System::Media::SoundPlayer^ soundClick;
	private: System::Media::SoundPlayer^ soundEndGame;

		   //метод игры
	private: void GameLogic();
	private: void Update();
	private: void NewGame();
	private: void StepAI();
	private: void UpdateGameGrid();
	private: void CreateGameGrid(Vector2);
	private: void SetPositionPlayer(Vector2);
		   //событи€ игры
private: System::Void TikTackToeGameForm_Load(System::Object^ sender, System::EventArgs^ e);	
private: System::Void menuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void backOnMenuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void settingsSoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void referenceToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void eXITToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

};
}
