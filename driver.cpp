#include <iostream>
#include "board.h"
#include "minesweeper.h"

int main()
{
	minesweeper game = minesweeper();
	game.play();
	return 0;
}
