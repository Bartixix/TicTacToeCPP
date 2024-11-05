#include <iostream>

#include "Data.h"

using std::cout;
using std::cin;
using std::system;

Vector GetInputVector(char* input, int** Mappings) {
	if (strlen(input) != 2) throw std::invalid_argument("Input is not valid.");

	int x = toupper(input[0]) - 'A';
	int y = input[1] - '1';

	if (x > 2 || x < 0) throw std::invalid_argument("Input is not valid.");
	if (y > 2 || y < 0) throw std::invalid_argument("Input is not valid.");

	int xMapped = Mappings[0][x];
	int yMapped = Mappings[1][y];

	Vector res = { xMapped, yMapped };

	return res;
}

static char FindPlayer(int round) {
	if (round % 2 == 1) return 'X';
	else return 'O';
}

int GameLoop() {
	char player;
	char input[3];
	bool finish = false;

	for (int i = 0; i < 9; i++) {
		try {
			player = FindPlayer(i);
			cout << "Select square. " << player << " is playing.\n";

			GamePrint();

			cin.getline(input, 3);
			Vector square = GetInputVector(input, GetMapping());
			i = GameUpdate(square, player, i);

			if (i > 4) finish = CheckState(square);

			if (finish) {
				cout << player << " won!";
				return 1;
			}

			
		}
		catch(std::exception){
			i--;
		}
		system("cls");
	}

	return 0;
}