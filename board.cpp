//Christopher Clarizio 2-4-17
//board.cpp

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "board.h"

board::board()
{
	setSize( 10 );
	setNumMines( getSize()*getSize()/10 );

	for( int i = 0; i < getSize(); i++ )
	{
		for( int j = 0; j < getSize(); j++ )
		{
			setMineLayer( i, j, false );
			setAdjsLayer( i, j, 0 );
			setFlagLayer( i, j, false );
			setRvldLayer( i, j, false );
		}
	}

	placeMines();
	updateAdjLayer();
}
board::~board(){}

bool board::getMineLayer( int x, int y ){ return mineLayer[x][y]; }
void board::setMineLayer( int x, int y, bool b ){ mineLayer[x][y] = b; }

int board::getAdjsLayer( int x, int y ){ return adjsLayer[x][y]; }
void board::setAdjsLayer( int x, int y, int n ){ adjsLayer[x][y] = n; }

bool board::getFlagLayer( int x, int y ){ return flagLayer[x][y]; }
void board::setFlagLayer( int x, int y, bool b ){ flagLayer[x][y] = b; }

bool board::getRvldLayer( int x, int y ){ return rvldLayer[x][y]; }
void board::setRvldLayer( int x, int y, bool b ){ rvldLayer[x][y] = b; }

int board::getSize(){ return size; }
void board::setSize( int s ){ size = s; }

int board::getNumMines(){ return numMines; }
void board::setNumMines( int n ){ numMines = n; }

bool board::isGameWon()
{

	int numFlaggedMines = 0;

	for( int x = 0; x < getSize(); x++ )
	{
		for( int y = 0; y < getSize(); y++ )
		{
			if( getMineLayer( x, y ) && getFlagLayer( x, y ) && !getRvldLayer( x, y ) )
			{
				numFlaggedMines++;
			}
		}
	}

	if( numFlaggedMines == getNumMines() )
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool board::isGameLost()
{

	for( int x = 0; x < getSize(); x++ )
	{
		for( int y = 0; y < getSize(); y++ )
		{
			if( getMineLayer( x, y ) && getRvldLayer( x, y ) )
			{
				return true;
			}
		}
	}

	return false;

}

void board::placeMines()
{

	int numPlacedMines = 0;

	while( numPlacedMines < getNumMines() )
	{
		int x = rand()%getSize();
		int y = rand()%getSize();

		if( !getMineLayer( x, y ) )
		{
			setMineLayer( x, y, true );
			std::cout<<"MINE PLACED AT:"<<x<<","<<y<<std::endl;
			numPlacedMines++;
		}

	}

}

void board::display()
{

	for( int y = getSize()-1; y >= 0; y-- )
	{

		std::cout<<std::setw(3)<<y+1;
		std::cout<<" |";

		for( int x = 0; x < getSize(); x++ )
		{
			if( getRvldLayer( x, y ) )
			{
				if( getMineLayer( x, y ) )
				{
					std::cout<<"*";
				}
				else
				{
					std::cout<<getAdjsLayer( x, y );
				}
			}
			else if( getFlagLayer( x, y ) )
			{
				std::cout<<"X";
			}
			else
			{
				std::cout<<" ";
			}
			std::cout<<"|";
		}
		std::cout<<std::endl;
	}
	std::cout<<"     ";
	for( int x = 1; x <= getSize(); x++ )
	{
		std::cout<<x<<" ";
	}
	std::cout<<std::endl;

}

void board::setNumAdjs( int x, int y )
{

	int adjMines = 0;

	for( int dx = -1; dx < 2; dx++ )
	{
		if( x + dx < 0 || x + dx > getSize()-1 ){ dx++; }
		for( int dy = -1; dy < 2; dy++ )
		{
			if( y + dy < 0 || y + dy > getSize()-1 ){ dy++; }
			if( dx == 0 && dy == 0 ){ dy++; }
			if( getMineLayer( x + dx, y + dy ) )
			{
				adjMines++;
			}
		}
	}

	setAdjsLayer( x, y , adjMines );
	std::cout<<adjMines<<std::endl;
}

void board::updateAdjLayer()
{
	for( int x = 0; x < getSize(); x++ )
	{
		for( int y = 0; y < getSize(); y++ )
		{
			std::cout<<"finding number of adjacent mines for:"<<x<<","<<y<<std::endl;
			setNumAdjs( x, y );
		}
	}
}
