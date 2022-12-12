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

int main() {
	char key;
	x = 3, y = INSERT;	

	void (*fp)(void) = run;

	cursor(false, 1);	
	main_menu();	
	make_node();
	upload();			

	while (1) {
		key = _getch();	
		switch (key) {
		case 13:	 		
			fp(y);		
			break;
		case 27:		
			cursor_toxy(5, 20);
			exit(0);	
			break;
		case 72:		
			cursor_move(-2);
			break;
		case 80:		
			cursor_move(2);
			break;
		default:
			break;
		}
	}
	return 0;
}

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


student* insert(void)	
{
	student* a;
	a = (student*)malloc(sizeof(student));
	cursor_toxy(22, 5); printf("   이름 : ");
	cursor_toxy(32, 5); fgets(a->name, 15, stdin);
	cursor_toxy(22, 7); printf("   전공 : ");
	cursor_toxy(32, 7); fgets(a->major, 25, stdin);
	cursor_toxy(22, 9); printf("   나이 : ");
	cursor_toxy(32, 9); fgets(a->age, 10, stdin);
	cursor_toxy(22, 11);	printf("   전화번호 : ");
	cursor_toxy(36, 11); fgets(a->phone_number, 25, stdin);

	a -> next = head -> next;
	head -> next = a;

	return a;
}

void print()	
{
	student* a;
	int number = 1;
	
	a = head -> next;	

	if (head -> next == tail) {
		cursor_toxy(20, PRINT);
		printf("저장된 정보가 없습니다.");
		Sleep(1000);
	}

	system("cls");
	while (a != tail) {
		printf("-----------------------\n");
		printf("%d ", number++);
		printf(" 이    름 : %s", a->name);
		printf("   전    공 : %s", a->major);
		printf("   나    이 : %s", a->age);
		printf("   전화번호 : %s", a->phone_number);
	
		a = a->next;
		printf("-----------------------\n");
	}

	printf("\n");

	printf("아무 숫자 입력 : 메뉴로 돌아가기");
	_getch();	
}

void update() {	
	char name[15];
	student* a;

	system("cls");
	printf("\n수정할 학생의 이름 : ");

	fgets(name, 15, stdin);

	a = head->next;

	while (1) {
		if (!(strcmp(name, a->name))) {	
			cursor_toxy(2, 5); printf("수정할 정보 입력");

			cursor_toxy(2, 7); printf("이름 :");
			cursor_toxy(9, 7); fgets(a->name, 15, stdin);
			cursor_toxy(2, 9); printf("전공 :");
			cursor_toxy(9, 9); fgets(a->major, 25, stdin);
			cursor_toxy(2, 11); printf("나이 :");
			cursor_toxy(9, 11); fgets(a->age, 10, stdin);
			cursor_toxy(2, 13);	printf("전화번호 :");
			cursor_toxy(13, 13); fgets(a->phone_number, 25, stdin);	

			printf("\n\n 수정 완료");

			Sleep(1000);	
			break;
		}
		if (a == tail) {	
			printf("\n해당 학생의 정보는 없습니다.\n");
			Sleep(1000);	
			break;
		}
		a = a -> next;	
	}
}

void cursor_toxy(int x, int y)	
{
	COORD position = { x , y };	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}