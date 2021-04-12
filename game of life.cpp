#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
using namespace std;
 
#define High 50
#define Width 80
 
int cells[50][80];
 
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
 
void startup()
{
	int i, j;
	for ( i = 0; i < High; i++)
	{
		for ( j = 0; j < Width; j++)
		{
			cells[i][j] = 1;
		}
	}
}

void show()
{
	gotoxy(0, 0);
	int i, j;
	for ( i = 1; i <= High-1; i++)
	{
		for ( j = 1; j <= Width-1; j++)
		{
			if (cells[i][j]==1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	Sleep(80);
}
 
void UpdateWithoutInput()
{
	int newcells[50][80];
	int neibournumber;
	int i, j;
	for ( i = 1; i <= High-1; i++)
	{
		for ( j = 1; j <= Width-1; j++)
		{
			neibournumber = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1] + cells[i][j - 1] + cells[i][j + 1] + cells[i + 1][j - 1] + cells[i + 1][j] + cells[i + 1][j + 1];
			if (neibournumber == 3)
			{
				newcells[i][j] = 1;
			}
			else if (neibournumber == 2)
			{
				newcells[i][j] = cells[i][j];
			}
			else
				newcells[i][j] = 0;
		}
	}
	for (i = 1; i <= High - 1; i++)
	{
		for ( j = 1; j <= Width-1 ; j++)
		{
			cells[i][j] = newcells[i][j];
		}
	}
}
 
void UpdateWithInput()
{
	int high[27];
	int width[56];
}
 
int main()
{
	startup();
	while (1)
	{
		show();
		UpdateWithoutInput();
		UpdateWithInput();
	}
	return 0;
}
