#include <iostream>

struct Vector
{
	int x;
	int y;
};

char GameBoard[6][14]{
	"   A   B   C ",
	"1    |   |   ",
	"  ---+---+---",
	"2    |   |   ",
	"  ---+---+---",
	"3    |   |   ",
};

int** GameMapping = new int* [2] {
	new int [3] { 3, 7, 11 },
		new int [3] { 1, 3, 5 }
	};

void GamePrint() {
	for (char* str : GameBoard) {
		std::cout << str << "\n";
	}
}

int** GetMapping() {
	return GameMapping;
}

int GameUpdate(Vector vector, char player, int round) {
	try {
		if (GameBoard[vector.y][vector.x] == ' ') {
			GameBoard[vector.y][vector.x] = player;
		}
		else throw std::invalid_argument("Square occupied.");
	}
	catch(std::exception){
		return round - 1;
	}	
	return round;
}

bool CheckState(Vector vector) {
	return false;
}