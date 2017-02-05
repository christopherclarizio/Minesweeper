//Christopher Clarizio 2-4-17
//minesweeper.h

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "board.h"

class minesweeper
{
	public:
		minesweeper();   //constructor
		~minesweeper();   //destructor
		void play();   //plays the game of minesweeper
		void getInput();   //gets player's input
		void guess( int, int, int );   //handles guessing holes
	private:
		board gameboard;
};

#endif
