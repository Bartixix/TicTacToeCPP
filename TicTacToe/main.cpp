#include <iostream>

#include "Data.h"
#include "Game.h"

using std::cout;
using std::cin;
using std::system;

int main(int argc, char** argv) {
	int res = GameLoop();

	system("pause");
	
	return 0;
}