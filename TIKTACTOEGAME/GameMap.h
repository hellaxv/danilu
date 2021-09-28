#pragma once

#include <vector>
#include <algorithm>

struct Vector2 {
	int x,
		y;
};


class GameMap
{
	//поля класса.
private:
	int** map;
	Vector2 size;
	int length;//необходимая длина выйгрышной линии.

	  //метод класса.
public:
	GameMap();//конструктор
	GameMap(Vector2, int);//конструктор
	GameMap(int, int, int);//конструктор
	~GameMap();//деструктор

	bool SetPosition(Vector2, int);//задать позицию
	bool IsEmpty(Vector2);//проверка на свободную ячейку
	bool IsEmpty(int, int);//проверка на свободную ячейку
	void SetMap(Vector2, int);//получить значения текущей карты
	void SetMap(int, int, int);//получить значения текущей карты
	int GetValue(Vector2);//получить значение
	int GetValue(int, int);//получить значение
	int GetLength() { return length; };//получить длину для выигрышной линии
	Vector2 GetSize() { return size; };//получить размер текущей карты
	int CheckList(std::vector<int> a);
	int CheckingWin();//поверить кто выиграл
	bool CanMove();//есть ли сводобные ходы
	Vector2 GetCenter();//проверка для центра
};

