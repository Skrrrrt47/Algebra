#include "game_of_life.h"
#include <random>

game_of_life::game_of_life() {
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0;j < COLS;j++) {
			if (random_value())
			{
				_generation[i][j] = 1;
			}
			else
			{
				_generation[i][j] = 0;
			}
		}
	}
}

void game_of_life::next_generation() {
	for (size_t i = 1; i < ROWS-1; i++)
	{
		for (size_t j = 1; j < COLS-1; j++)
		{
			if (cell_taken(i,j) == 1) {
				_next_generation[i][j] = 0;
			}
			else if (cell_taken(i,j) == 2)
			{
				_next_generation[i][j] = _generation[i][j];
			}
			else if (cell_taken(i,j) == 3)
			{
				_next_generation[i][j] = 1;
			}
		}
	}
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			_generation[i][j] = _next_generation[i][j];
		}
	}
}

void game_of_life::draw() {
	for (size_t i = 1; i < ROWS-1; i++)
	{
		for (size_t j = 1; j < COLS-1; j++)
		{
			if (_generation[i][j] == 1)
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}

bool game_of_life::random_value() {
	int i = rand() % (4 - 1 + 1) + 1;
	return  4 % i;
}

int game_of_life::cell_taken(int i,int j) {
	int count = 0;
	count = _generation[i - 1][j] +
		_generation[i - 1][j - 1] +
		_generation[i][j - 1] +
		_generation[i + 1][j - 1] +
		_generation[i + 1][j] +
		_generation[i + 1][j + 1] +
		_generation[i][j + 1] +
		_generation[i - 1][j + 1];
	if (count < 2 ||count > 3) {
		return 1;
	}
	else if (count == 2)
	{
		return 2;
	}
	else if (count == 3)
	{
		return 3;
	}
}