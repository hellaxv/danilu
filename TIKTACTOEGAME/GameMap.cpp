#include "GameMap.h"

GameMap::GameMap()
{
	size.x = 0;
	size.y = 0;

	length = 0;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}
}

GameMap::GameMap(Vector2 _size, int l)
{
	//инициализируем игровую карту
	size = _size;

	length = l;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++)
	{
		map[i] = new int[size.y];
	}

	//обнуляем
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			map[i][j] = 0;
		}
	}
}

GameMap::GameMap(int i, int j, int l)
{
	//инициализируем игровую карту
	size.x = i;
	size.y = j;

	length = l;

	map = new int* [size.x];
	for (i = 0; i < size.x; i++) 
	{
		map[i] = new int[size.y];
	}

	//обнуляем
	for (i = 0; i < size.x; i++) 
	{
		for (j = 0; j < size.y; j++) 
		{
			map[i][j] = 0;
		}
	}
}

GameMap::~GameMap()
{
	//очищаем матрицу
	for (int i = 0; i < size.x; i++) {
		delete[] map[i];
	}
	delete[] map;
}

bool GameMap::SetPosition(Vector2 cell, int c)//Vector2 cell-данные ячейки, int c-то каким образом мы сейчас ходим
{
	if (IsEmpty(cell))//запоминаем, если ячейка свободно, то 
	{
		map[cell.x][cell.y] = c;//то мы сюда уже сделали ход
		return true;//да, мы сделали ход
	}
	else
	{
		return false;//иначе выводится фалс, типо данная ячейка была занята
	}
}

bool GameMap::IsEmpty(Vector2 cell)
{
	if (map[cell.x][cell.y] == 0)
		return true;
	else
		return false;
}

bool GameMap::IsEmpty(int i, int j)
{
	if (map[i][j] == 0)
		return true;
	else
		return false;
}

void GameMap::SetMap(Vector2 _size, int l) //все также как конструктор с параметрами чуть выше по коду
{
	//инициализируем игровую карту
	size = _size;

	length = l;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}

	//обнуляем
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

void GameMap::SetMap(int i, int j, int l)//будет работать также как конструктор с параметрами
{
	//инициализируем игровую карту
	size.x = i;
	size.y = j;

	length = l;

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}

	//обнуляем
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

int GameMap::GetValue(Vector2 cell)//возвращает значение, которое хранится в соответствующей ячейки
{
	return map[cell.x][cell.y];
}

int GameMap::GetValue(int i, int j)//параметры которые приходят в соответствующую ячейку
{
	return map[i][j];
}

int GameMap::CheckList(std::vector<int> a)
{
	if (a.size() < length)
		return 0;

	//флажки победы игроков
	bool winPl1 = false;
	bool winPl2 = false;

	int count1 = 0, count2 = 0;

	//проверяем набранные очки 
	for (int i = 0; i < a.size(); i++) 
	{
		for (int j = i; j < i + length; j++) // i отвечает за текущий элемент, а j для последующий
		{
			if (j < a.size()) 
			{
				if (a[j] == 1)
				{
					count1++;
				}
			}
			else
				break;
		}

		if (count1 >= length) 
		{
			winPl1 = true;
			break;
		}

		count1 = 0;
	}

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i; j < i + length; j++) 
		{
			if (j < a.size()) 
			{
				if (a[j] == 2) 
				{
					count2++;
				}
			}
			else
				break;
		}

		if (count2 >= length) 
		{
			winPl2 = true;
			break;
		}

		count2 = 0;
	}

	//выводим результат
	if (winPl1 && winPl2) {
		return 3;//ничья
	}
	else if (!winPl1 && winPl2) {
		return 2;//победил 2
	}
	else if (winPl1 && !winPl2) {
		return 1;//победил 1
	}
	else
		return 0;
}

int GameMap::CheckingWin()//этот метод вызывает на проверку команду,которая написана выше, то есть CheckList
                          //тут идет полная проверка по всем направлениям
{
	//проходим по карте в поиске последовательности заданной длины
	int stateWin = 0;//вспомогательная переменная, которая ответит-не победил ли кто из игроков
	std::vector<int> check;//контейнейрный класс, который представлять из себя одномерный массив относительно которого мы будем все проверять

	/*
		[][][]
		[][][]
		[][][]
	*/

	//1. проверка всех горизонталей
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			check.push_back(map[i][j]);//сюда запоминать все элементы, которые находятся на гаризонтале
		}

		//проверяем, все элементы со строки выше и запоминаем результат этой проверки
		stateWin = CheckList(check);
		check.clear();//очищаем этот массив, а далее результаты игры

		if (stateWin == 3) {
			return 3;//ничья 
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}

	//2. проверяем все вертикали
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			check.push_back(map[j][i]);//элементы меняются местами, так как проверяем по вертикали и далее все идет также
		}

		//проверка
		stateWin = CheckList(check);
		check.clear();

		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}

	//3. проверяем все левые диагонали
	//главная диагональ и над ней
	for (int i = 0; i < size.x; ++i)
	{
		for (int j = 0; i + j < size.y; ++j) {
			check.push_back(map[i + j][j]);
		}

		//проверка
		stateWin = CheckList(check);
		check.clear();

		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}

	//под главной диагональю
	for (int i = 1; i < size.x; ++i)
	{
		for (int j = 0; i + j < size.y; ++j) {
			check.push_back(map[i + j][j]);
		}

		//проверка
		stateWin = CheckList(check);
		check.clear();

		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}

	//4. проверяем все правые диагонали 
	//побочная диагональ и над ней
	for (int j = size.y; j > 0; --j) {
		for (int i = 0; i < size.x; ++i)
		{
			if (size.x - j - i >= 0) {
				check.push_back(map[i][size.x - j - i]);
			}
		}

		//проверка
		stateWin = CheckList(check);
		check.clear();

		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}

	//подпобочной диагональю
	for (int j = 0; j < size.y; ++j) {
		for (int i = 0; i < size.x; ++i)
		{
			if (size.x + j - i < size.x) {
				check.push_back(map[i][size.x + j - i]);
			}
		}

		//проверка
		stateWin = CheckList(check);
		check.clear();

		if (stateWin == 3) {
			return 3;//ничья
		}
		else if (stateWin == 2) {
			return 2;//победил 2
		}
		else if (stateWin == 1) {
			return 1;//победил 1
		}
	}

	if (CanMove())//после всей проверки, если нет свободных ходов для выигрыша, то
		return 0;//то нет победителя
	else
		return 3; //иначе говоря ничья
}

bool GameMap::CanMove()//есть свободные ходы, куда можно сходить, если
{
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++) 
		{
			if (map[i][j] == 0) //если значение равно 0, значит оно пустое и мы можем сходить
			{
				return true;
			}
		}
	}

	return false;
}

Vector2 GameMap::GetCenter()
{
	Vector2 center;
	int x;

	if (size.x % 2 != 0) {
		x = (size.x - 1) / 2;
	}
	else {
		x = (size.x / 2) - 1;
	}

	center.x = x;
	center.y = x;

	return center;
}
