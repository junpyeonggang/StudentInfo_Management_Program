#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INSERT 5
#define PRINT 7
#define SEARCH 9
#define UPDATE 11
#define SAVE 13
#define EXIT 15

int x, y;		

typedef struct student { 

 	char name[15];	
	char major[25];	
	char age[10];	
	char phone_number[25];	
	struct student* next;

}student;

student* head, * tail;		

void cursor(bool flag, int size)
{	

	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = flag;
	cursor.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void cursor_move(int q)	
{
	cursor_toxy(3, y);
	printf("  ");	
	cursor_toxy(3, y = y + q);	
	if (y > 15) y = 5;	
	if (y < 5) y = 15;
	cursor_toxy(3, y);

	printf("▶");		
}

void cursor_toxy(int x, int y)	
{
	COORD position = { x , y };	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}