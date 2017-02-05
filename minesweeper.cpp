//Christopher Clarizio 2-4-17
//minesweeper.cpp

#include <iostream>
#include <stdlib.h>
#include "board.h"
#include "minesweeper.h"

minesweeper::minesweeper()
{
	gameboard = board();
}
minesweeper::~minesweeper(){}

void minesweeper::play()
{

	while( !gameboard.isGameWon() && !gameboard.isGameLost() )
	{
		gameboard.display();
		getInput();
	}

	gameboard.display();

	if( gameboard.isGameWon() )
	{
		std::cout<<"CONGRATULATIONS YOU WON!"<<std::endl;
	}
	else
	{
		std::cout<<"GAME OVER!"<<std::endl;
	}

}

void minesweeper::getInput()
{

	int fg, x, y;

	std::cout<<"Please enter whether you want to 1. flag a hole or 2. reveal a hole"<<std::endl;
	std::cin>>fg;

	std::cout<<"Please enter the x coordinate followed by the y coordinate"<<std::endl;
	std::cin>>x;
	std::cin>>y;

	guess( x-1, y-1, fg );

}

void minesweeper::guess( int x, int y, int fg )
{

	if( fg == 1 )
	{
		if( gameboard.getFlagLayer( x, y ) )
		{
			gameboard.setFlagLayer( x, y, false );
		}
		else
		{
			gameboard.setFlagLayer( x, y, true );
		}
	}
	else if( fg == 2 )
	{
		if( !gameboard.getFlagLayer( x, y ) )
		{
			gameboard.setRvldLayer( x, y, true );
		}
		else
		{
			std::cout<<"You can't do that"<<std::endl;
		}
	}
	else
	{
		std::cout<<"You can't do that"<<std::endl;
	}

}
