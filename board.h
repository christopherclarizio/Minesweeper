//Christopher Clarizio 2-4-17
//board.h

#ifndef BOARD_H
#define BOARD_H

class board
{

	public:
		board();   //constructor
		~board();   //destructor
		
		bool getMineLayer( int, int );   //whether a specific hole has a mien
		void setMineLayer( int, int, bool );
		
		int getAdjsLayer( int, int );   //how many mines are in adjacent holes
		void setAdjsLayer( int, int, int );
		
		bool getFlagLayer( int, int );   //whether a hole is flagged
		void setFlagLayer( int, int, bool );
		
		bool getRvldLayer( int, int );   //whether a hole is revealed
		void setRvldLayer( int, int, bool );
		
		int getSize();
		void setSize( int );
		
		int getNumMines();
		void setNumMines( int );
		
		bool isGameWon();   //whether the game has been won
		bool isGameLost();   //whether the game has been lost
		void placeMines();   //places the mines in the holes
		void display();   //displays the board;
		void setNumAdjs( int, int );   //finds the num adj mines
		void updateAdjLayer();   //sets the adjs layer
	private:
		bool mineLayer[10][10];   //contains whether a hole has a mine 
		int adjsLayer[10][10];   //contains how many bombs are adjacent
		bool flagLayer[10][10];   //contains whether a hole is flagged
		bool rvldLayer[10][10];   //contains wheter a hole is revealed
		int size;   //size of the board
		int numMines;   //number of mines in the game

};

#endif
