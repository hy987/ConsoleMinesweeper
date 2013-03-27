#include "IntMatrix.h"
#include "CharMatrix.h"
#include "Minesweeper.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	Minesweeper game;
	game.play_game();
	

	return 0;
}