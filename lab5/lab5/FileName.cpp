#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
	gotoxy(x, y);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {if (x - 1 > 0) draw_ship(--x, y); }
			if (ch == 'd') {if (x + 1 < 100) draw_ship(++x, y); }
			if (ch == 'w') {
				if (y - 1 > 0) {
					erase_ship(x, y);
					draw_ship(x, --y);
				}
			}
			if (ch == 's') { 
				if(y + 1 < 30) {
					erase_ship(x, y);
					draw_ship(x, ++y);
				}
			}
			fflush(stdin);
		}
		Sleep(10);
	} while (ch != 'x');
	return 0;
}