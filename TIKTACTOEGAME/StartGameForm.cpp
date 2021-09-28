#include "StartGameForm.h"
#include "TikTackToeGameForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TIKTACTOEGAME::TikTackToeGameForm form;
	Application::Run(% form);
}
TIKTACTOEGAME::TikTackToeGameForm::TikTackToeGameForm(void)
{
	InitializeComponent();


}


System::Void TIKTACTOEGAME::StartGameForm::label2_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void TIKTACTOEGAME::StartGameForm::справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();//âîñïðîèçâåäåíèå çâóêà
    MessageBox::Show("GET \"OUT\".", "PONEL NE!");
}

System::Void TIKTACTOEGAME::StartGameForm::eXITToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();//âîñïðîèçâåäåíèå çâóêà
    Application::Exit();
}

System::Void TIKTACTOEGAME::StartGameForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	sound->Play();//âîñïðîèçâåäåíèå çâóêà

	//Ñ÷èòûâàåì äàííûå
	int indexGameMode = listBoxGameMod->SelectedIndex;
	if (indexGameMode == -1) {
		MessageBox::Show("Âûáåðèòå ðåæèì èãðû!", "Âíèìàíèå!");
		return;
	}

	int size;
	size = Convert::ToInt32(numericUpDownSizaMap->Value);

	numericUpDownSizaMap->Maximum = size;
	int length = Convert::ToInt32(numericUpDownSizaMap->Value);

	//Ñîçäàåì ôîðìó 
	TikTackToeGameForm^ form = gcnew TikTackToeGameForm();
	form->rows = size;
	form->columns = size;
	form->length = length;
	form->selectedGameMode = indexGameMode;
	form->Show();
	this->Hide();
}

System::Void TIKTACTOEGAME::StartGameForm::listBoxGameMod_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

void TIKTACTOEGAME::StartGameForm::GameLogic()
{
    throw gcnew System::NotImplementedException();
}

void TIKTACTOEGAME::StartGameForm::Update()
{
    throw gcnew System::NotImplementedException();
}

void TIKTACTOEGAME::StartGameForm::NewGame()
{
    throw gcnew System::NotImplementedException();
}

void TIKTACTOEGAME::StartGameForm::StepAI()
{
    throw gcnew System::NotImplementedException();
}

void TIKTACTOEGAME::StartGameForm::UpdateGameGrid()
{
    throw gcnew System::NotImplementedException();
}

void TIKTACTOEGAME::StartGameForm::CreateGameGrid(Vector2)
{
    throw gcnew System::NotImplementedException();
}

void TIKTACTOEGAME::StartGameForm::SetPositionPlayer(Vector2)
{
    throw gcnew System::NotImplementedException();
}
