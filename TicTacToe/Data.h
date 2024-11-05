#pragma once

#include <iostream>

struct Vector {
	int x;
	int y;
};

void GamePrint();

int** GetMapping();

int GameUpdate(Vector vector, char player, int round);

bool CheckState(Vector vector);