#pragma once
#include"Player.h"
#include"Dice.h"
#include"graphics.h"
#include<fstream>
class Piece;
class Board
{
	friend class Piece;
protected:
	Piece* B[9][15];
	int Nop;
	Dice D;
	Position S, E;
	Player* player;
	Color Turn;
	//int turn = 0;
public:
	Board() 
	{
		//init();
	}
	bool IsLocoSafe(Position Lame);
	bool IsAtHome();
	void MoveToSafe();
	void DisplayPieces();
	void init(); //init the arrays , Turn, NOP ,Pieces etc
	void Init6();
	void Init4();
	void Init2();
	void SaveGame();
	void LoadGame();
	int RollDice(); //returns random num from 1-6; In case of Three 6 return 0
	bool IsValidSelection(); //checks for valid piece selection
	bool IsValidDestination(int Di); //checks for valid destination
	void PrintBoard();   //Prints the Board
	void Play();     //Main Flow in this function
	void Move(); //Updates The Board (Pieces Array)
	bool anymovesleft(int Dr);
	void UpdateBoard(); // Move function
	bool IsWin(); // Checks for is win (all 4 pugi?)
	void TurnChange(); // changes turn
	void DisplayMessage(); //Displays player Name and color;
	void DisplayWinnerMessage(); //Displays the list of Winners Accordingly;
	void DisplayKillMessage(); //Displays which piece is killed;
	void SelectPiece();          //mapping abhi karni hai
	void SelectDestination();//Select Destination
	bool GameOver();//Check for Game over condition;
	void KillHappen();
	void Move(Position s, Position e);
	void DiceRoll(int &Di);
	void DrawDices();
};

