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

