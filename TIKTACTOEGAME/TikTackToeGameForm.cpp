#include "TikTackToeGameForm.h"
#include "StartGameForm.h"

enum GameMode {
    PvP = 0,//èãðîê ïðîòèâ èãðîêà
    PvE //èãðîê ïðîòèâ AI
} gameMode;
//игровая карта
GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;
Vector2 selectedCellPlayer;
//Флажки
bool canPlay;
bool endGame;
bool sound;
//данный для AI
std::vector<Vector2> allMoves;//все возможные ходы
int currentMoves;//текущий код, с которого начинать


System::Void TIKTACTOEGAME::TikTackToeGameForm::TikTackToeGameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	//инициализируем параметры
	if (selectedGameMode == 0) {
		gameMode = PvP;
	}
	else {
		gameMode = PvE;
	}

	//инициализируем звуки
	soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\1.wav");
	soundEndGame = gcnew System::Media::SoundPlayer("..\\Resources\\2.wav");
	sound = true;

	NewGame();
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::menuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	if (MessageBox::Show("Continune", "FIGHT!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		NewGame();
	}
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::backOnMenuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	if (MessageBox::Show("Continune?", "FIGTH!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		StartGameForm^ form = gcnew StartGameForm();
		form->Show();
		this->Hide();
	}
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::settingsSoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	sound = !sound;
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::referenceToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	MessageBox::Show("Programm release game tiktactoe standart type for two players and versus pc");
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::eXITToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	if (MessageBox::Show("Continue?", "FIGHT!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

System::Void TIKTACTOEGAME::TikTackToeGameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	auto senderGrid = (DataGridView^)sender;//преобразуем полученный объект в таблицу

	//запоминаем индексы выбранной ячейки
	selectedCellPlayer.x = e->RowIndex;
	selectedCellPlayer.y = e->ColumnIndex;

	//делаем ход
	SetPositionPlayer(selectedCellPlayer);
}

void TIKTACTOEGAME::TikTackToeGameForm::GameLogic()
{
	//проверяем режим
	if (gameMode == PvE) {
		//очередь ии
		if (currentPlayer == Computer) {
			//делаем ход
			StepAI();
		}

		Update();
	}
}

void TIKTACTOEGAME::TikTackToeGameForm::Update()
{
	if (endGame)
		return;

	//проверка состояния игрового поля
	int state_game = map.CheckingWin();

	if (state_game == 1) {
		if (gameMode == PvP) {
			MessageBox::Show("PLAYER1 WIN", "FATALITY!");
		}
		else {
			MessageBox::Show("PLAYER WIN", "FATALITY!");
		}
		UpdateGameGrid();//обновление игровой сетки

		endGame = true;
	}
	else if (state_game == 2) {
		if (gameMode == PvP) {
			MessageBox::Show("PLAYER2 WIN", "FATALITY!");
		}
		else {
			MessageBox::Show("PLAYER WIN", "FATALITY!");
		}
		UpdateGameGrid();

		endGame = true;
	}
	else if (state_game == 3) {
		MessageBox::Show("No one win..", "FRIENDSHIP!");
		UpdateGameGrid();

		endGame = true;
	}

	if (endGame) {
		if (sound) {
			soundEndGame->Play();
		}

		if (MessageBox::Show("New FIGTH?", "FIGTH!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
			NewGame();
		}
		return;
	}

	if (gameMode == PvE) {
		if (currentPlayer == Computer) {
			StripStatus->Text = "Motion: Player!";
			currentPlayer = Player;
			return;
		}
		else {
			StripStatus->Text = "Motion: PC!";
			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();
			return;
		}
	}
	else {
		if (currentPlayer == Player1) {
			StripStatus->Text = "MOTION: 0!";
			currentPlayer = Player2;
		}
		else {
			StripStatus->Text = "MOTION: X!";
			currentPlayer = Player1;
		}
	}

	GameLogic();
	UpdateGameGrid();
}

void TIKTACTOEGAME::TikTackToeGameForm::NewGame()
{
	//инициализация данных
	map.SetMap(rows, columns, length);
	rand = gcnew Random();
	endGame = false;

	CreateGameGrid(map.GetSize()); //создание игрового поле

	//инициализировать все возможные ходы для ии
	currentMoves = 0;
	allMoves.clear();
	Vector2 buf;
	for (int i = 0; i < map.GetSize().x; i++) {
		for (int j = 0; j < map.GetSize().x; j++) {
			buf.x = i;
			buf.y = j;

			allMoves.push_back(buf);
		}
	}

	//перемешиваем все возможные ходы
	//несколько раз
	int num_mixing = rand->Next(1, 10);
	for (int i = 0; i < num_mixing; i++)
		std::random_shuffle(allMoves.begin(), allMoves.end());

	//проверяем очередь и режим игры
	int state_gamer = rand->Next(1, 3);
	if (state_gamer == 1) {
		if (gameMode == PvE) {
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			StripStatus->Text = "Motion: Player!";

			currentPlayer = Player;
		}
		else {
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			StripStatus->Text = "Motion: X!";

			currentPlayer = Player1;
		}
	}
	else if (state_gamer == 2) {
		if (gameMode == PvE) {
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			StripStatus->Text = "Motion: PC!";

			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();

		}
		else {
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			StripStatus->Text = "Motion: 0!";

			currentPlayer = Player2;
		}
	}
	else {
		MessageBox::Show("Error first pick pleayer", "ERROR!");
		return;
	}
}

void TIKTACTOEGAME::TikTackToeGameForm::StepAI()
{
	//проверка есть ли ходы
	if (currentMoves < allMoves.size()) {
		//проверяем текущий ход
		if (map.IsEmpty(allMoves[currentMoves])) {
			//если свободно, делаем ход
			map.SetPosition(allMoves[currentMoves], player2.GetMark());
			currentMoves++;
		}
		else {
			//если занята, перемещаемся на следующий ход
			//и вызываем рекурсивно данную функцию
			currentMoves++;
			StepAI();
		}
	}
}

void TIKTACTOEGAME::TikTackToeGameForm::UpdateGameGrid()
{
	for (int i = 0; i < map.GetSize().x; i++) {
		for (int j = 0; j < map.GetSize().y; j++) {
			if (!map.IsEmpty(i, j)) {
				if (map.GetValue(i, j) == 1) {
					dataGridView->Rows[i]->Cells[j]->Value = "X";
				}
				else {
					dataGridView->Rows[i]->Cells[j]->Value = "0";
				}
			}
		}
	}
}

void TIKTACTOEGAME::TikTackToeGameForm::CreateGameGrid(Vector2 size)
{
	//очищаем таблицу
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	//задаем стиль
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	//создаем столбцы
	for (int i = 0; i < size.x; i++) {
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1);
		column->Name = "column" + i;
		column->Width = 50;

		dataGridView->Columns->Add(column);
	}

	//создаем строки 
	for (int i = 0; i < size.y; i++) {
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView->Rows[i]->Height = 50;
	}
}

void TIKTACTOEGAME::TikTackToeGameForm::SetPositionPlayer(Vector2 cell)
{
	//проверяем режим игры
	if (gameMode == PvE) {
		//проверяем очередность игрока
		if (currentPlayer == Player) {
			//делаем ход
			if (!map.SetPosition(cell, player1.GetMark())) {
				MessageBox::Show("position occupied", "NOW!");
				return;
			}
		}
		else {
			MessageBox::Show("not u turn!", "NOW!");
			return;
		}
	}
	else {
		//проверка очереди игрока
		if (currentPlayer == Player1) {
			//делаем ход
			if (!map.SetPosition(cell, player1.GetMark())) {
				MessageBox::Show("position occupied!", "NOW!");
				return;
			}
		}
		else {
			//делаем ход
			if (!map.SetPosition(cell, player2.GetMark())) {
				MessageBox::Show("position occupied!", "NOW!");
				return;
			}
		}
	}

	Update();
}
