#include "Board.h"
#include<vector>
using namespace std;
void Board6Player()
{
	int s = 50;
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			int x1 = x * s,
				y1 = y * s,
				x2 = (x + 1) * s,
				y2 = (y + 1) * s;
			//if ((x + y) % 2 == 0)
			if ((y >= 0 && y < 3) && (x >= 0 && x < 3))
			{
				setfillstyle(SOLID_FILL, GREEN);
				bar(y1, x1, y2, x2);
			}
			else if (y == 1 && x == 3)
			{
				setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);
			}
			else if (y == 3 && x == 7)
			{
				setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);
			}

			else if (y == 9 && x == 7)
			{
				setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);
			}
			else if (y == 5 && x == 1)
			{
				setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);
			}
			else if (y == 11 && x == 1)
			{
				setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);
			}
			else if (y == 13 && x == 5)
			{
				setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);
			}
			else if ((y >= 0 && y < 3) && (x >= 6 && x <= 8))
			{
				setfillstyle(SOLID_FILL, RED);
				bar(y1, x1, y2, x2);
			}
			else if ((y >= 6 && y <= 8) && (x >= 6 && x <= 8))
			{
				setfillstyle(SOLID_FILL, BLUE);
				bar(y1, x1, y2, x2);
			}
			else if ((y >= 6 && y <= 8) && (x >= 0 && x <= 2))
			{
				setfillstyle(SOLID_FILL, YELLOW);
				bar(y1, x1, y2, x2);
			}
			else if ((y >= 12 && y <= 14) && (x >= 6 && x <= 8))
			{
				setfillstyle(SOLID_FILL, MAGENTA);
				bar(y1, x1, y2, x2);
			}
			else if ((y >= 12 && y <= 14) && (x >= 0 && x <= 2))
			{
				setfillstyle(SOLID_FILL, CYAN);
				bar(y1, x1, y2, x2);
			}
			else if ((y > 0 && y < 14) && (x == 4))
			{
				setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (y == 1 || y == 2 || y==3)
				{
					setfillstyle(SOLID_FILL, GREEN);
					bar(y1, x1, y2, x2);
				}
				if (y == 12 || y == 13 || y==11)
				{
					setfillstyle(SOLID_FILL, MAGENTA);
					bar(y1, x1, y2, x2);
				}
			}
			else if (y == 4 && (x > 0 && x < 8))
			{
				setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (x == 1 || x == 2 || x==3)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(y1, x1, y2, x2);
				}
				if (x == 6 || x == 7 || x==5)
				{
					setfillstyle(SOLID_FILL, RED);
					bar(y1, x1, y2, x2);
				}
			}
			else if (y == 10 && (x > 0 && x < 8))
			{
				setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);

				if (x == 1 || x == 2 || x==3)
				{
					setfillstyle(SOLID_FILL, CYAN);
					bar(y1, x1, y2, x2);
				}
				if (x == 7 || x == 6 || x==5)
				{
					setfillstyle(SOLID_FILL, BLUE);
					bar(y1, x1, y2, x2);
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, WHITE);
				bar(y1, x1, y2, x2);
			}
			setcolor(BLACK);
			rectangle(y1, x1, y2, x2);
		}
	}
	setfillstyle(INTERLEAVE_FILL, LIGHTRED);
	bar(4 * 50, 4 * 50, 4 * 50 + 50, 4 * 50 + 50);

	setfillstyle(INTERLEAVE_FILL, LIGHTGREEN);
	bar(10 * 50, 4* 50, 10 * 50 + 50, 4 * 50 + 50);
	setcolor(BLACK);
	rectangle(4 * 50, 4 * 50, 4 * 50 + 50, 4 * 50 + 50);
	rectangle(10 * 50, 4 * 50, 10 * 50 + 50, 4 * 50 + 50);

	for (int i = 5; i < 10; i++)
	{
		setfillstyle(SOLID_FILL, BLACK);
		bar(i* 50, 4 * 50, i * 50 + 50, 4 * 50 + 50);
		setcolor(BLACK);
		rectangle(i * 50, 4 * 50, i* 50 + 50, 4 * 50 + 50);
	}
}
void Board::DisplayPieces()
{
	for (int i = 0; i < 9; i++)
	{
		for (int c = 0; c < 15; c++)
		{
			if (B[i][c] != nullptr)
			{
				B[i][c]->Draw();
			}
		}
	}
}
void Board::init()
{
	cout << "Enter S for save game and N for NewGame: (S/N)";
	char inp;
	cin >> inp;
	if (inp == 'S' || inp == 's')
	{
		LoadGame();
	}
	else
	{
		cout << "Enter nop";
		cin >> Nop;
		switch (Nop)
		{
		case 2:
			Init2();
			break;
		case 4:
			Init4();
			break;
		case 6:
			Init6();
			break;
		default:
			break;
		}
	}
	B[4][4] = new Piece(White, Position(4, 4), this);
	B[4][10] = new Piece(White, Position(4, 10), this);
}
void Board::Init2()
{
	for (int i = 0; i < 9; i++)
	{
		for (int c = 0; c < 15; c++)
		{
			B[i][c] = nullptr;
		}
	}
	Nop = 2;
	player = new Player[Nop];

	Turn = green;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			//	int x1 = x * s, y1 = y * s, x2 = (x + 1) * s - 0, y2 = (y + 1) * s - 0;
				//if ((x + y) % 2 == 0)
			if ((y >= 0 && y < 3) && (x >= 0 && x < 3))
			{
				/*setfillstyle(SOLID_FILL, GREEN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 1 && x == 3)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 3 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}

			else if (y == 9 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 5 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 11 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 13 && x == 5)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}



			else if ((y >= 0 && y < 3) && (x >= 6 && x <= 8))
			{
				/*setfillstyle(SOLID_FILL, RED);
				bar(y1, x1, y2, x2);*/
			}
			else if ((y >= 6 && y <= 8) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 6 && y <= 8) && (x >= 0 && x <= 2))
			{
			}
			else if ((y >= 12 && y <= 14) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 12 && y <= 14) && (x >= 0 && x <= 2))
			{

			}
			else if ((y > 0 && y < 14) && (x == 4))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (y == 1 || y == 2)
				{
					setfillstyle(SOLID_FILL, GREEN);
					bar(y1, x1, y2, x2);
				}
				if (y == 12 || y == 13)
				{
					setfillstyle(SOLID_FILL, MAGENTA);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 4 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(y1, x1, y2, x2);
				}
				if (x == 6 || x == 7)
				{
					setfillstyle(SOLID_FILL, RED);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 10 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);

				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, CYAN);
					bar(y1, x1, y2, x2);
				}
				if (x == 7 || x == 6)
				{
					setfillstyle(SOLID_FILL, BLUE);
					bar(y1, x1, y2, x2);
				}*/
			}
			else
			{

				B[y][x] = new Piece(White, Position(y, x), this);
			}
		}
	}

	B[0][1] = new Piece(green, Position(0, 1), this);
	B[1][0] = new Piece(green, Position(1, 0), this);
	B[1][2] = new Piece(green, Position(1, 2), this);
	B[2][1] = new Piece(green, Position(2, 1), this);

	Player P1(B[0][1], B[1][0], B[1][2], B[2][1]);


	B[6][13] = new Piece(purple, Position(6, 13), this);
	B[7][12] = new Piece(purple, Position(7, 12), this);
	B[8][13] = new Piece(purple, Position(8, 13), this);
	B[7][14] = new Piece(purple, Position(7, 14), this);
	Player P4(B[6][13], B[7][12], B[8][13], B[7][14]);

	player[0] = P1;
	player[1] = P4;
	
}
void Board::Init4()
{
	for (int i = 0; i < 9; i++)
	{
		for (int c = 0; c < 15; c++)
		{
			B[i][c] = nullptr;
		}
	}
	Nop = 4;
	player = new Player[Nop];

	Turn = green;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			//	int x1 = x * s, y1 = y * s, x2 = (x + 1) * s - 0, y2 = (y + 1) * s - 0;
				//if ((x + y) % 2 == 0)
			if ((y >= 0 && y < 3) && (x >= 0 && x < 3))
			{
				/*setfillstyle(SOLID_FILL, GREEN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 1 && x == 3)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 3 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}

			else if (y == 9 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 5 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 11 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 13 && x == 5)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}



			else if ((y >= 0 && y < 3) && (x >= 6 && x <= 8))
			{
				/*setfillstyle(SOLID_FILL, RED);
				bar(y1, x1, y2, x2);*/
			}
			else if ((y >= 6 && y <= 8) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 6 && y <= 8) && (x >= 0 && x <= 2))
			{
			}
			else if ((y >= 12 && y <= 14) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 12 && y <= 14) && (x >= 0 && x <= 2))
			{

			}
			else if ((y > 0 && y < 14) && (x == 4))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (y == 1 || y == 2)
				{
					setfillstyle(SOLID_FILL, GREEN);
					bar(y1, x1, y2, x2);
				}
				if (y == 12 || y == 13)
				{
					setfillstyle(SOLID_FILL, MAGENTA);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 4 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(y1, x1, y2, x2);
				}
				if (x == 6 || x == 7)
				{
					setfillstyle(SOLID_FILL, RED);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 10 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);

				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, CYAN);
					bar(y1, x1, y2, x2);
				}
				if (x == 7 || x == 6)
				{
					setfillstyle(SOLID_FILL, BLUE);
					bar(y1, x1, y2, x2);
				}*/
			}
			else
			{

				B[y][x] = new Piece(White, Position(y, x), this);
			}
		}
	}

	B[0][1] = new Piece(green, Position(0, 1), this);
	B[1][0] = new Piece(green, Position(1, 0), this);
	B[1][2] = new Piece(green, Position(1, 2), this);
	B[2][1] = new Piece(green, Position(2, 1), this);

	Player P1(B[0][1], B[1][0], B[1][2], B[2][1]);

	B[6][1] = new Piece(red, Position(6, 1), this);
	B[7][0] = new Piece(red, Position(7, 0), this);
	B[8][1] = new Piece(red, Position(8, 1), this);
	B[7][2] = new Piece(red, Position(7, 2), this);
	Player P6(B[6][1], B[7][0], B[8][1], B[7][2]);


	B[6][13] = new Piece(purple, Position(6, 13), this);
	B[7][12] = new Piece(purple, Position(7, 12), this);
	B[8][13] = new Piece(purple, Position(8, 13), this);
	B[7][14] = new Piece(purple, Position(7, 14), this);
	Player P4(B[6][13], B[7][12], B[8][13], B[7][14]);


	B[0][13] = new Piece(Cyan, Position(0, 13), this);
	B[1][12] = new Piece(Cyan, Position(1, 12), this);
	B[2][13] = new Piece(Cyan, Position(2, 13), this);
	B[1][14] = new Piece(Cyan, Position(1, 14), this);

	Player P3(B[0][13], B[1][12], B[2][13], B[1][14]);


	player[0] = P1;
	player[1] = P3;
	player[2] = P4;
	player[3] = P6;	

}
void Board::Init6()
{

	for (int i = 0; i < 9; i++)
	{
		for (int c = 0; c < 15; c++)
		{
			B[i][c] = nullptr;
		}
	}
	Nop = 6;
	player = new Player[Nop];
	
	Turn = green;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			//	int x1 = x * s, y1 = y * s, x2 = (x + 1) * s - 0, y2 = (y + 1) * s - 0;
				//if ((x + y) % 2 == 0)
			if ((y >= 0 && y < 3) && (x >= 0 && x < 3))
			{
				/*setfillstyle(SOLID_FILL, GREEN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 1 && x == 3)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 3 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}

			else if (y == 9 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 5 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 11 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 13 && x == 5)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}



			else if ((y >= 0 && y < 3) && (x >= 6 && x <= 8))
			{
				/*setfillstyle(SOLID_FILL, RED);
				bar(y1, x1, y2, x2);*/
			}
			else if ((y >= 6 && y <= 8) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 6 && y <= 8) && (x >= 0 && x <= 2))
			{
			}
			else if ((y >= 12 && y <= 14) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 12 && y <= 14) && (x >= 0 && x <= 2))
			{

			}
			else if ((y > 0 && y < 14) && (x == 4))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (y == 1 || y == 2)
				{
					setfillstyle(SOLID_FILL, GREEN);
					bar(y1, x1, y2, x2);
				}
				if (y == 12 || y == 13)
				{
					setfillstyle(SOLID_FILL, MAGENTA);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 4 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(y1, x1, y2, x2);
				}
				if (x == 6 || x == 7)
				{
					setfillstyle(SOLID_FILL, RED);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 10 && (x > 0 && x < 8)) 
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);

				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, CYAN);
					bar(y1, x1, y2, x2);
				}
				if (x == 7 || x == 6)
				{
					setfillstyle(SOLID_FILL, BLUE);
					bar(y1, x1, y2, x2);
				}*/
			}
			else
			{

				B[y][x] = new Piece(White, Position(y, x), this);
			}
		}
	}

	B[0][1] = new Piece(green, Position(0, 1), this);
	B[1][0] = new Piece(green, Position(1, 0), this);
	B[1][2] = new Piece(green, Position(1, 2), this);
	B[2][1] = new Piece(green, Position(2, 1), this);

	Player P1(B[0][1], B[1][0], B[1][2], B[2][1]);


	B[6][1] = new Piece(red, Position(6, 1), this);
	B[7][0] = new Piece(red, Position(7, 0), this);
	B[8][1] = new Piece(red, Position(8, 1), this);
	B[7][2] = new Piece(red, Position(7, 2), this);
	Player P6(B[6][1], B[7][0], B[8][1], B[7][2]);


	B[6][7] = new Piece(blue, Position(6, 7), this);
	B[7][6] = new Piece(blue, Position(7, 6), this);
	B[7][8] = new Piece(blue, Position(7, 8), this);
	B[8][7] = new Piece(blue, Position(8, 7), this);
	Player P5(B[6][7], B[7][6], B[7][8], B[8][7]);


	B[0][7] = new Piece(yellow, Position(0, 7), this);
	B[1][6] = new Piece(yellow, Position(1, 6), this);
	B[2][7] = new Piece(yellow, Position(2, 7), this);
	B[1][8] = new Piece(yellow, Position(1, 8), this);

	Player P2(B[0][7], B[1][6], B[2][7], B[1][8]);

	B[6][13] = new Piece(purple, Position(6, 13), this);
	B[7][12] = new Piece(purple, Position(7, 12), this);
	B[8][13] = new Piece(purple, Position(8, 13), this);
	B[7][14] = new Piece(purple, Position(7, 14), this);
	Player P4(B[6][13], B[7][12], B[8][13], B[7][14]);


	B[0][13] = new Piece(Cyan, Position(0, 13), this);
	B[1][12] = new Piece(Cyan, Position(1, 12), this);
	B[2][13] = new Piece(Cyan, Position(2, 13), this);
	B[1][14] = new Piece(Cyan, Position(1, 14), this);

	Player P3(B[0][13], B[1][12], B[2][13], B[1][14]);



	//B[3][1] = new Piece[6];



	//B[3][1] =
	/*vector<Piece*>B1;
	B1 = new Piece(brown, Position(3, 1), this);*/
		/*B[1][5] =150

		B[1][11] =
		B[5][13] =
		B[7][3] =
		B[7][9] =*/


	player[0] = P1;
	player[1] = P2;
	player[2] = P3;
	player[3] = P4;
	player[4] = P5;
	player[5] = P6;

	/*B[3][1] = new Piece(brown, Position(3, 1), this);
	B[3][1] = new Piece(brown, Position(3, 1), this);
	B[3][1] = new Piece(brown, Position(3, 1), this);
	B[3][1] = new Piece(brown, Position(3, 1), this);
	B[3][1] = new Piece(brown, Position(3, 1), this);
	B[3][1] = new Piece(brown, Position(3, 1), this);*/

}
int Board::RollDice()
{
	return 0;
}
bool Board::IsValidSelection()
{
	return (B[S.r][S.c]->GetColor() == Turn);
}
bool Board::anymovesleft(int Dr)
{
	if (IsAtHome() && Dr!=6)
		return false;
	switch (Nop)
	{
		case 2:
		{
			//cout << "A gya A gya A gya!!!!!!";
			int c=0;
			if (Turn == green)
				c = 0;
			else if (Turn == purple)
				c = 1;
			Position lol;
			Color i = Turn;
			for (int pi = 0; pi < 4; pi++)
			{
				if (((player[c].Goti[pi]->p.r == player[c].Goti[pi]->Org.r)
					&& (player[c].Goti[pi]->p.c == player[c].Goti[pi]->Org.c)) && Dr != 6)
				{
					continue;
				}
				lol.r = player[c].Goti[pi]->p.r;
				lol.c = player[c].Goti[pi]->p.c;
				switch (Dr)
				{
				case 1:
					if (player[c].Goti[pi]->IsOut == true)
						return true;
				case 2:
				case 3:
				case 4:
				case 5:
					if (i == purple)
					{
						//cout << "Purple mein";
						if (lol.r == 4 && (lol.c - Dr) < 10 && (lol.c - Dr) > 1)
							continue;//lmove = false;
						else return true;

						//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == green)
					{
						//cout << "Green mein";
						if (lol.r == 4 && (lol.c + Dr) > 4 && (lol.c + Dr) < 13)
							continue;
						else
							return true;
						//player[turn].Goti[pi]->Lmove = true;
					}
					break;
				case 6:
					if ((i == green )|| (i == purple))
					{
						//cout << "case 6";
						if (lol.r == 4)
							continue;//lmove = false;
						else if ((lol.r == 5) && (lol.c == 0) && (i == green))
							continue; //lmove = false;
						else if (lol.r == 3 && (lol.c == 0 )&& (i == purple))
							continue; //lmove = false;
						else return true;
					}
					break;
				}
			}
			break;
		}
		case 4:
		{
			//cout << "A gya A gya A gya!!!!!!";
			int c = 0;
			if (Turn == green)
				c = 0;
			else if (Turn == Cyan)
				c = 1;
			else if (Turn == purple)
				c = 2;
			else if (Turn ==red)
				c = 3;

			Position lol;
			Color i = Turn;
			for (int pi = 0; pi < 4; pi++)
			{
				if (((player[c].Goti[pi]->p.r == player[c].Goti[pi]->Org.r)
					&& (player[c].Goti[pi]->p.c == player[c].Goti[pi]->Org.c)) && Dr != 6)
				{
					continue;
				}
				lol.r = player[c].Goti[pi]->p.r;
				lol.c = player[c].Goti[pi]->p.c;
				switch (Dr)
				{
				case 1:
					if (player[c].Goti[pi]->IsOut == true)
						return true;
					break;
				case 2:
				case 3:
				case 4:
				case 5:
					if (i == purple)
					{
						//cout << "Purple mein";
						if (lol.r == 4 && (lol.c - Dr) < 10 && (lol.c - Dr) > 1)
							continue;//lmove = false;
						else return true;

						//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == Cyan)
					{
						if (lol.c == 10 && (lol.r + Dr) > 4 && (lol.r + Dr) < 8)
							continue;	//lmove = false;
							//player[turn].Goti[pi]->Lmove = false;
						else
							return true;//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == green)
					{
						//cout << "Green mein";
						if (lol.r == 4 && (lol.c + Dr) > 4 && (lol.c + Dr) < 14)
							continue;
						else
							return true;
						//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == red)
					{
						if (lol.c == 4 && (lol.r - Dr) < 4 && (lol.r - Dr) > 0)
							continue;//lmove = false;
						else return true; //player[turn].Goti[pi]->Lmove = true;
					}
					break;
				case 6:
					if ((i == green) || (i == purple))
					{
						//cout << "case 6";
						if (lol.r == 4)
							continue;//lmove = false;
						else if ((lol.r == 5) && (lol.c == 0) && (i == green))
							continue; //lmove = false;
						else if (lol.r == 3 && (lol.c == 0) && (i == purple))
							continue; //lmove = false;
						else return true;
					}
					if (i == red)
					{
						if (lol.c == 4)
							continue; // lmove = false;
						else if (lol.r == 8 && (lol.c == 5) && i == red)
							continue; // lmove = false;
						else return true;
					}
					if (i == Cyan)
					{
						if (lol.c == 10)
							continue;// lmove = false;
						else if (lol.r == 0 && (lol.c == 9) && i == Cyan)
							continue;//  lmove = false;
						else return true;
					}
					break;
				}
			}
			break;
		}
		case 6:
		{
			bool lmove;
			Position lol;
			Color i = Turn;
			for (int pi = 0; pi < 4; pi++)
			{
				if (((player[Turn].Goti[pi]->p.r == player[Turn].Goti[pi]->Org.r)
					&& (player[Turn].Goti[pi]->p.c == player[Turn].Goti[pi]->Org.c)) && Dr != 6)
				{
					continue;
				}
				lol.r = player[Turn].Goti[pi]->p.r;
				lol.c = player[Turn].Goti[pi]->p.c;

				switch (Dr)
				{
				case 1:
					if (player[Turn].Goti[pi]->IsOut == true)
						return true;
					//return true;
					//  player[turn].Goti[pi]->Lmove = true;
					//break;
				case 2:
				case 3:
				case 4:
				case 5:
					if (i == green)
					{
						if (lol.r == 4 && (lol.c + Dr) > 4 && (lol.c + Dr) < 14)
							continue;
						else
							return true;
						//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == yellow)
					{
						if (lol.c == 4 && (lol.r + Dr) > 4 && (lol.r + Dr) < 8)
							continue;
						//lmove = false;
							//player[turn].Goti[pi]->Lmove = false;
						else
							return true;//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == Cyan)
					{
						if (lol.c == 10 && (lol.r + Dr) > 4 && (lol.r + Dr) < 8)
							continue;	//lmove = false;
							//player[turn].Goti[pi]->Lmove = false;
						else
							return true;//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == purple)
					{
						if (lol.r == 4 && (lol.c - Dr) < 10 && (lol.c - Dr) > 0)
							continue;//lmove = false;
						else return true;
						//player[turn].Goti[pi]->Lmove = true;
					}
					if (i == blue)
					{
						if (lol.c == 10 && (lol.r - Dr) < 4 && (lol.r - Dr) > 0)
							continue;//lmove = false;
						else return true; //player[turn].Goti[pi]->Lmove = true;
					}
					if (i == red)
					{
						if (lol.c == 4 && (lol.r - Dr) < 4 && (lol.r - Dr) > 0)
							continue;//lmove = false;
						else return true; //player[turn].Goti[pi]->Lmove = true;
					}
					break;
				case 6:
					if (i == green || i == purple)
					{
						if (lol.r == 4)
							continue;//lmove = false;
						else if (lol.r == 5 && (lol.c == 0) && i == green)
							continue; //lmove = false;
						else if (lol.r == 3 && (lol.c == 0 )&& i == purple)
							continue; //lmove = false;
						else return true;
					}
					if (i == yellow || i == red)
					{
						if (lol.c == 4)
							continue; // lmove = false;
						else if (lol.r == 0 && (lol.c == 3) && i == yellow)
							continue; // lmove = false;
						else if (lol.r == 8 && (lol.c == 5) && i == red)
							continue; // lmove = false;
						else return true;
					}
					if (i == Cyan || i == blue)
					{
						if (lol.c == 10)
							continue;// lmove = false;
						else if (lol.r == 0 && (lol.c == 9) && i == Cyan)
							continue;//  lmove = false;
						else if (lol.r == 8 && (lol.c == 11) && i == blue)
							continue;//  lmove = false;
						else return true;
					}
					break;
				}
			}


			return false;
		}
	}
	return false;
}
bool Board::IsValidDestination(int Dr)
{
	Position temp = S;
	Position T = S;
	bool home = false;
	for (int i = 0; i < Dr; i++)
		{
			if (B[S.r][S.c]->GetColor() == green)
			{
				if (T.r == 4 && T.c <= 3)
				{
					if ((Dr - i) + T.c <= 4)
					{
						T.c++;
						home = true;
					}
					else home = false;
				}
			}
			else if (B[S.r][S.c]->GetColor() == yellow)
			{
				if (T.r <= 3 && T.c == 4)
				{
					if ((Dr - i) + T.r <= 4)
					{
						T.r++;
						home = true;
					}
					else home = false;
				}
			}
			else if (B[S.r][S.c]->GetColor() == Cyan)
			{
				if (T.r <= 3 && T.c == 10)
				{
					if ((Dr - i) + T.r <= 4)
					{
						T.r++;
						home = true;
					}
					else home = false;
				}
			}
			else if (B[S.r][S.c]->GetColor() == purple)
			{
				if (T.r == 4 && T.c >= 10)
				{
					if ((Dr - i) - T.c <= -10)
					{
						T.c--;
						home = true;
					}
					else home = false;
				}
			}
			else if (B[S.r][S.c]->GetColor() == blue)
			{
				if (T.r >= 5 && T.c == 10)
				{
					if ((Dr - i) + T.r >= -4)
					{
						T.r--;
						home = true;
					}
					else home = false;
				}
			}
			else if (B[S.r][S.c]->GetColor() == red)
			{
				if (T.r >= 5 && T.c == 4)
				{
					if ((Dr - i) + T.r >= -4)
					{
						T.r--;
						home = true;
					}
					else home = false;
				}
			}
			if (temp.r == 3)
			{
				if (temp.c == 3 || temp.c == 9)
				{
					temp.r--;
					if (home == false)
						T.r--;
				}
				else if (temp.c == 14)
				{
					temp.r++;
					if (home == false)
					{
						T.r++;
					}
				}
				else
				{
					temp.c++;
					if (home == false)
						T.c++;
				}
			}
			else if (temp.r == 0)
			{
				if (temp.c == 5 || temp.c == 11)
				{
					temp.r++;
					if (home == false)
						T.r++;
				}
				else
				{
					temp.c++;
					if (home == false)
						T.c++;
				}
			}
			else if (temp.r == 5)
			{
				if (temp.c == 5 || temp.c == 11)
				{
					temp.r++;
					if (home == false)
						T.r--;
				}
				else if (temp.c == 0)
				{
					temp.r--;
					if(home == false)
						T.r--;
				}
				else
				{
					temp.c--; 
					if(home == false)
					{
						T.c--;
					}
				}
					
			}
			else if (temp.r == 8)
			{
				if (temp.c == 3 || temp.c == 9)
				{
					temp.r--;
					if (home == false)
						T.r--;
				}
				else 
				{
					temp.c--;
					if (home == false)
						T.c--;
				}
			}
			else
			{
				if (temp.c == 9 || temp.c == 0)
					temp.r--;
				else if (temp.c == 3 && temp.r != 4)
					temp.r--;
				else if ((temp.c == 5 || temp.c == 14))
					temp.r++;
				else if (temp.c == 11 && temp.r != 4)
					temp.r++;
			}	
	}
	/*if ((E.r == temp.r && E.c == temp.c) && ((B[temp.r][temp.c] == nullptr) || (B[temp.r][temp.c]->GetColor() == White)) && IsLocoSafe(temp))
		return true;
	else
		return false;*/
	if (IsLocoSafe(temp) && (E.r == temp.r && E.c == temp.c))
	{
		if ((B[temp.r][temp.c] == nullptr) || (B[temp.r][temp.c]->GetColor() == White))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	if ((E.r == temp.r && E.c == temp.c) || ((E.r == T.r && E.c == T.c) && home == true))
		return true;
	else
		cout << "Invalid Destination!!!";
		return false;
}
void Board::PrintBoard()
{
	Board6Player();
}
void Board::MoveToSafe()
{
	if (Turn == green)
	{

	}
}
void Board::DiceRoll(int &Di)
{
	outtextxy(200, 500, "Dice Roll");
	Position t;
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, t.c, t.r);
	cout << t.r << " " << t.c << endl;
	t.r = t.r / 50;
	t.c = t.c / 50;
	cout << t.r << " " << t.c;
	if (t.r == 12 && t.c == 1)
	{
		Di = 1;
	}
	else if (t.r == 12 && t.c == 3)
	{
		Di = 2;
	}
	else if (t.r == 12 && t.c == 5)
	{
		Di = 3;
	}
	else if (t.r == 12 && t.c == 7)
	{
		Di = 4;
	}
	else if (t.r == 12 && t.c == 8)
	{
		Di = 5;
	}
	else if (t.r == 12 && t.c == 10)
	{
		Di = 6;
	}
	else
		Di = D.GenerateNum();
	outtextxy(200, 500, "                      ");
}
void Board::DrawDices()
{
	D.DrawDice(1, 40, 600);
	D.DrawDice(2, 130, 600);
	D.DrawDice(3, 220, 600);
	D.DrawDice(4, 310, 600);
	D.DrawDice(5, 400, 600);
	D.DrawDice(6, 490, 600);
}
void Board::SaveGame()
{
	ofstream Wrt("SaveGame.txt");
	Wrt << Nop << endl;
	Wrt << Turn << endl;
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 15; c++)
		{
			if (B[r][c] != nullptr)
			{
				if (B[r][c]->GetColor() == red)
				{
					Wrt << "r";
					Wrt << B[r][c]->IsOut;

				}
				if (B[r][c]->GetColor() == green)
				{
					Wrt << "g";
					Wrt << B[r][c]->IsOut;

				}
				if (B[r][c]->GetColor() == blue)
				{
					Wrt << "b";
					Wrt << B[r][c]->IsOut;

				}
				if (B[r][c]->GetColor() == yellow)
				{
					Wrt << "y";
					Wrt << B[r][c]->IsOut;

				}
				if (B[r][c]->GetColor() == Cyan)
				{
					Wrt << "c";
					Wrt << B[r][c]->IsOut;

				}
				if (B[r][c]->GetColor() == purple)
				{
					Wrt << "p";
					Wrt << B[r][c]->IsOut;

				}
				if (B[r][c]->GetColor() == White)
				{
					Wrt << "w";
					Wrt << B[r][c]->IsOut;
				}
				/*else
				{
					Wrt << "-";
				}*/
			}
			else
			{
				Wrt << "w";
				Wrt << 0;
				//Wrt << B[r][c]->IsOut;
			}
		}
		Wrt << endl;
	}
}
void Board::LoadGame()
{
	ifstream rdr("SaveGame.txt");
	char G;
	rdr >> Nop;
	int T;
	rdr >> T;
	switch (Nop)
	{
	case 2:
		if (T == 0)
			Turn == green;
		else if(T==1)
			Turn == purple;
		break;
	case 4:
		if (T == 0)
			Turn == green;
		else if (T == 1)
			Turn == Cyan;
		else if (T == 2)
			Turn == purple;
		else if (T == 3)
			Turn == red;
		break;
	case 6:
		if (T == 0)
			Turn == green;
		else if (T == 1)
			Turn == yellow;
		else if (T == 2)
			Turn == Cyan;
		else if (T == 3)
			Turn == purple;
		else if (T == 4)
			Turn == blue;
		else if (T == 5)
			Turn == red;
		break;

	default:
		break;
	}

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			//	int x1 = x * s, y1 = y * s, x2 = (x + 1) * s - 0, y2 = (y + 1) * s - 0;
				//if ((x + y) % 2 == 0)
			if ((y >= 0 && y < 3) && (x >= 0 && x < 3))
			{
				/*setfillstyle(SOLID_FILL, GREEN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 1 && x == 3)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 3 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}

			else if (y == 9 && x == 7)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 5 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 11 && x == 1)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}
			else if (y == 13 && x == 5)
			{
				/*setfillstyle(SOLID_FILL, BROWN);
				bar(y1, x1, y2, x2);*/
			}



			else if ((y >= 0 && y < 3) && (x >= 6 && x <= 8))
			{
				/*setfillstyle(SOLID_FILL, RED);
				bar(y1, x1, y2, x2);*/
			}
			else if ((y >= 6 && y <= 8) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 6 && y <= 8) && (x >= 0 && x <= 2))
			{
			}
			else if ((y >= 12 && y <= 14) && (x >= 6 && x <= 8))
			{

			}
			else if ((y >= 12 && y <= 14) && (x >= 0 && x <= 2))
			{

			}
			else if ((y > 0 && y < 14) && (x == 4))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (y == 1 || y == 2)
				{
					setfillstyle(SOLID_FILL, GREEN);
					bar(y1, x1, y2, x2);
				}
				if (y == 12 || y == 13)
				{
					setfillstyle(SOLID_FILL, MAGENTA);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 4 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);
				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, YELLOW);
					bar(y1, x1, y2, x2);
				}
				if (x == 6 || x == 7)
				{
					setfillstyle(SOLID_FILL, RED);
					bar(y1, x1, y2, x2);
				}*/
			}
			else if (y == 10 && (x > 0 && x < 8))
			{
				/*setfillstyle(SOLID_FILL, DARKGRAY);
				bar(y1, x1, y2, x2);

				if (x == 1 || x == 2)
				{
					setfillstyle(SOLID_FILL, CYAN);
					bar(y1, x1, y2, x2);
				}
				if (x == 7 || x == 6)
				{
					setfillstyle(SOLID_FILL, BLUE);
					bar(y1, x1, y2, x2);
				}*/
			}
			else
			{

				B[y][x] = new Piece(White, Position(y, x), this);
			}
		}
	}
	//rdr >>Turn;
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 15; c++)
		{
			rdr >> G;
			if (G=='r')
			{
				B[r][c]=new Piece(red, Position(r, c), this);
				rdr >> B[r][c]->IsOut;

			}
			else if (G == 'c')
			{
				B[r][c] = new Piece(Cyan, Position(r, c), this);
				rdr >> B[r][c]->IsOut;

			}
			else if (G == 'y')
			{
				B[r][c] = new Piece(yellow, Position(r, c), this);
				rdr >> B[r][c]->IsOut;

			}
			else if (G == 'b')
			{
				B[r][c] = new Piece(blue, Position(r, c), this);
				rdr >> B[r][c]->IsOut;
			}
			else if (G == 'p')
			{
				B[r][c] = new Piece(purple, Position(r, c), this);
				rdr >> B[r][c]->IsOut;
			}
			else if (G == 'g')
			{
				B[r][c] = new Piece(green, Position(r, c), this);
				rdr >> B[r][c]->IsOut;
			}
			else if (G == 'w')
			{
				B[r][c] = new Piece(White, Position(r, c), this);
				rdr >> B[r][c]->IsOut;
			}
			/*else
				B[r][c] = new Piece(White, Position(r, c), this);*/
		}
	}

}
void Board::Play()
{
	init();
	PrintBoard();
	do
	{
	x:
		int Di;
		DisplayPieces();
		DisplayMessage();
		DrawDices();
		DiceRoll(Di);
		D.DrawDice(1);delay(100); D.DrawDice(4); delay(100); D.DrawDice(3); delay(100); D.DrawDice(1); delay(100); D.DrawDice(5);
		D.DrawDice(Di);
		if (IsAtHome() == true && Di!=6)
		{
			TurnChange();
			goto x;
		}
		do
		{
			do
			{
				if (anymovesleft(Di)==false)
				{
					cout << "Ham ko hamin se chura lo";
					TurnChange();
					goto x;
				}
				SelectPiece();
				if (IsValidSelection() != true)            
					cout << "Invalid selection";
				if (IsValidSelection() != true)             //iskill false && kai
				{
					if (B[S.r][S.c]->GetColor() == Turn && B[S.r][S.c] != nullptr && B[S.r][S.c]->IsOut == true)
					{
						B[S.r][S.c]->Move(B[S.r][S.c]->SP);
						PrintBoard();
						DisplayPieces();
					}
				}
			} while (!IsValidSelection());
			if (Di == 6 && B[S.r][S.c]->IsOut == false)
			{
				B[S.r][S.c]->IsOut = true;
				B[S.r][S.c]->Move(B[S.r][S.c]->SP);
				PrintBoard();
				DisplayPieces();
				goto x;
			}
			SelectDestination();
			if (IsValidDestination(Di) != true)
			{
				cout << "Invalid Destination";
			}
		} while (!IsValidDestination(Di));
		KillHappen();
		B[S.r][S.c]->Move(E);
		PrintBoard();
		if (Di==6)
		{
			goto x;
		}
		if (IsWin())
		{
			PrintBoard();
			outtextxy(700, 500, "WINNER");
			break;
		}
	y:
		TurnChange();
		SaveGame();
	} while (!GameOver());
	DisplayWinnerMessage();
}
bool Board::IsAtHome()
{
	switch (Nop)
	{
		case 2:
		{
			if (Turn == purple)
			{
				for (int i = 0; i < 4; i++)
				{
					if (player[1].Goti[i]->IsOut == true)
						return false;
				}
			}
			if (Turn == green)
			{
				for (int i = 0; i < 4; i++)
				{
					if (player[0].Goti[i]->IsOut == true)
						return false;
				}
			}
			return true;
			break;
		}
		case 4:
		{
				if (Turn == purple)
				{
					for (int i = 0; i < 4; i++)
					{
						if (player[2].Goti[i]->IsOut == true)
							return false;
					}
				}
				if (Turn == green)
				{
					for (int i = 0; i < 4; i++)
					{
						if (player[0].Goti[i]->IsOut == true)
							return false;
					}
				}
				if (Turn == red)
				{
					for (int i = 0; i < 4; i++)
					{
						if (player[3].Goti[i]->IsOut == true)
							return false;
					}
				}
				if (Turn == Cyan)
				{
					for (int i = 0; i < 4; i++)
					{
						if (player[1].Goti[i]->IsOut == true)
							return false;
					}
				}
				return true;
				break;
		}
		case 6:
		{
			for (int i = 0; i < 4; i++)
			{
				if (player[Turn].Goti[i]->IsOut == true)
					return false;
			}
			return true;
			break;
		}
	}
	//player[0]
}
void Board::Move()
{

}
void Board::UpdateBoard()
{

}
bool Board::IsWin()
{
	switch (Nop)
	{
	case 2:
	{
		Position E1(4, 4), E2(4, 10);
		if (E.r == E1.r && E.c == E1.c)
		{
			if (B[E.r][E.c]->GetColor() == green)
			{
				for (int  g = 0; g < 4; g++)
				{
					if (player[0].Goti[g]->p.r == E.r && player[0].Goti[g]->p.c == E.c)
						player[0].Goti[g]->IsOut = false;					
				}
				player[0].count--;
				cout << "Green ka count" << player[0].count;
			}
		}
		if (E.r == E2.r && E.c == E2.c)
		{
			if (B[E.r][E.c]->GetColor() == purple)
			{
				for (int g = 0; g < 4; g++)
				{
					if (player[1].Goti[g]->p.r == E.r && player[1].Goti[g]->p.c == E.c)
						player[1].Goti[g]->IsOut = false;
				}
			player[1].count--;
			cout << "Purple ka count" << player[1].count;
			}
		}
		break;
	}
	case 4:
	{
		Position E1(4, 4), E2(4, 10);
		if (E.r == E1.r && E.c == E1.c)
		{
			if (B[E.r][E.c]->GetColor() == green)
			{
				for (int g = 0; g < 4; g++)
				{
					if (player[0].Goti[g]->p.r == E.r && player[0].Goti[g]->p.c == E.c)
						player[0].Goti[g]->IsOut = false;
				}
				player[0].count--;
			}
			if (B[E.r][E.c]->GetColor() == red)
			{
				for (int g = 0; g < 4; g++)
				{
					if (player[3].Goti[g]->p.r == E.r && player[3].Goti[g]->p.c == E.c)
						player[3].Goti[g]->IsOut = false;
				}
				player[3].count--;
			}
		}
		if (E.r == E2.r && E.c == E2.c)
		{
			if (B[E.r][E.c]->GetColor() == purple)
			{
				for (int g = 0; g < 4; g++)
				{
					if (player[2].Goti[g]->p.r == E.r && player[2].Goti[g]->p.c == E.c)
						player[2].Goti[g]->IsOut = false;
				}
				player[2].count--;
			}
			if (B[E.r][E.c]->GetColor() == Cyan)
			{
				for (int g = 0; g < 4; g++)
				{
					if (player[1].Goti[g]->p.r == E.r && player[1].Goti[g]->p.c == E.c)
						player[1].Goti[g]->IsOut = false;
				}
				player[1].count--;
			}
		}
		break;
	}
	case 6:
	{
		Position E1(4, 4), E2(4, 10);
		if (E.r == E1.r && E.c == E1.c)
		{
			if (B[E.r][E.c]->GetColor() == green)
			{
				//player[0].Goti[green]->IsOut = false;
				player[0].count--;
			}
			else if (B[E.r][E.c]->GetColor() == yellow)
			{
				player[1].count--;
				//player[1].Goti[yellow]->IsOut = false;
			}
			else if (B[E.r][E.c]->GetColor() == red)
			{
				//player[5].Goti[red]->IsOut = false;
				player[5].count--;

			}
		}
		if (E.r == E2.r && E.c == E2.c )
		{
			if (B[E.r][E.c]->GetColor() == Cyan)
			{
				player[2].count--;
				//player[2].Goti[Cyan]->IsOut = false;
			}
			else if (B[E.r][E.c]->GetColor() == purple)
			{
				//player[3].Goti[purple]->IsOut = false;
				player[3].count--;
			}
			else if (B[E.r][E.c]->GetColor() == blue)
			{
				//player[4].Goti[blue]->IsOut = false;
				player[4].count--;
			}

			for (int g = 0; g < 4; g++)
			{
				if (player[Turn].Goti[g]->p.r == E.r && player[Turn].Goti[g]->p.c == E.c)
					player[Turn].Goti[g]->IsOut = false;
			}
		}
		break;
	}
	default:
		break;
	}
	
	int wc = 0;
	for (int i = 0; i < Nop; i++)
	{
		if (player[i].count == 0)
		{
			player[i].isWin = true;
			return true;
			//player[i].Goti[Turn]->IsOut = false;
			wc++;
			//return true;
		}
	}
	return false;
	//if (wc==4)
	//{
	//	return true;
	//}
	//return false;
}
void Board::TurnChange()
{
	switch (Nop)
	{
	case 6:
		if (Turn == green)
		{
			Turn = yellow;
		}
		else if (Turn == yellow)
		{
			Turn = Cyan;
		}
		else if (Turn == Cyan)
		{
			Turn = purple;
		}
		else if (Turn == purple)
		{
			Turn = blue;
		}
		else if (Turn == blue)
		{
			Turn = red;
		}
		else if (Turn == red)
		{
			Turn = green;
		}
		break;
	case 4:

		if (Turn == green)
		{
			Turn = Cyan;
		}
		else if (Turn == Cyan)
		{
			Turn = purple;
		}
		else if (Turn == purple)
		{
			Turn = red;
		}
		else if (Turn == red)
		{
			Turn = green;
		}
		break;
	case 2:
		if (Turn == green)
		{
			Turn = purple;
		}
		else if (Turn == purple)
		{
			Turn = green;
		}
		break;
	}
}
void Board::DisplayMessage()
{
	outtextxy(200, 540, "                                                                                     ");
	if (Turn == green)
	{
		setcolor(GREEN);
		outtextxy(200, 540, "Green");
	}
	if (Turn == yellow)
	{
		setcolor(YELLOW);
		outtextxy(200, 540, "Yellow");
	}
	if (Turn == Cyan)
	{
		setcolor(CYAN);
		outtextxy(200, 540, "Cyan");
	}
	if (Turn == purple)
	{
		setcolor(MAGENTA);
		outtextxy(200, 540, "Purple");
	}
	if (Turn == blue)
	{
		setcolor(BLUE);
		outtextxy(200, 540, "Blue");
	}
	if (Turn == red)
	{
		setcolor(RED);
		outtextxy(200, 540, "Red");
	}
}
void Board::DisplayWinnerMessage()
{

}
bool Board::IsLocoSafe(Position Lame)
{
	Position A[6];
	A[0].r = 3, A[0].c = 1;
	A[1].r = 1, A[1].c = 5;
	A[2].r = 1, A[2].c = 11;
	A[3].r = 5, A[3].c = 13;
	A[4].r = 7, A[4].c = 9;
	A[5].r = 7, A[5].c = 3;
	for (int i = 0; i < 6; i++)
	{
		if (Lame.r == A[i].r && Lame.c == A[i].c)
			return true;
	}
	return false;
}
void Board::DisplayKillMessage()
{
	outtextxy(50, 50, "Life without Life is AfterLife......");
}
void Board::SelectPiece()
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, S.c, S.r);

	cout << S.r << " " << S.c << endl;
	S.r = S.r / 50;
	S.c = S.c / 50;
	cout << S.r << " " << S.c;



}
void Board::SelectDestination()
{
	while (!ismouseclick(WM_LBUTTONDOWN))              //mapping abhi karni hai
	{
		delay(500);
	}
	getmouseclick(WM_LBUTTONDOWN, E.c, E.r);

	cout << E.r << " " << E.c << endl;
	E.r = E.r / 50;
	E.c = E.c / 50;
	cout << E.r << " " << E.c;

}
void Board::KillHappen()
{
	if (B[E.r][E.c] != nullptr && B[E.r][E.c]->GetColor() != Turn && B[E.r][E.c]->GetColor() != White  &&  !IsLocoSafe(E))
	{
	//	B[E.r][E.c] = nullptr;
		//B[B[E.r][E.c]->Org.r][B[E.r][E.c]->Org.c]=B[E.r][E.c];
		//B[E.r][E.c]->p = B[E.r][E.c]->Org;
		B[E.r][E.c]->IsOut = false;
		 B[E.r][E.c]->Move(B[E.r][E.c]->Org) ;

		//B[E.r][E.c]->Draw();


	}
		

}
bool  Board::GameOver()
{
	return false;
}
void Board::Move(Position s, Position e)
{
	B[e.r][e.c] = B[s.r][s.c];
	/*B[e.r][e.c]->Draw();
	B[s.r][s.c]->UnDraw();*/
	B[s.r][s.c] = nullptr;
	B[s.r][s.c] = new Piece(White,Position(s.r,s.c), this);

}
