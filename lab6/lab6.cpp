#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
	setcolor(2, 4);
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y);
	printf("| |");
}
void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("   ");
	setcolor(3, 5);
}
void draw_star(int x, int y) 
{
	gotoxy(x, y);
	setcolor(2, 0);
	printf("*");
}
void show_score(int x, int y, int s)
{
	gotoxy(x, y);
	setcolor(4, 7);
	printf("%d", s);
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
int main()
{
	char ch = 'k', move = 'k';
	int x = 38, y = 20, count = 0, score = 0;
	int xb[20]{}, yb[20]{} , slot = 0;
	bool bullet[20]{};

	srand(time(NULL));
	for (int i = 0; i < 20; i++) { draw_star(rand() % 60 + 10, rand() % 4 + 2); }
	draw_star(42, 6);
	draw_star(41, 6);
	draw_star(40, 6);

	setcursor(0);
	setcolor(2, 4);
	draw_ship(x, y);
	
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				move = 'a';
			}
			if (ch == 'd') {
				move = 'd';
			}
			if (ch == 'w') {
				move = 'w';
			}
			if (ch == 's') {
				move = 's';
			}
			if (ch == 'c') {
				move = 'c';
			}
			if (ch == ' ' && count < 5) {
				Beep(700, 50);
				count++;
				slot = (slot + 1) % 5;
				bullet[slot] = true;
				xb[slot] = x + 2;
				yb[slot] = y ;
			}
		}
		if (move == 'a') {
			if (x - 1 > 0) {
				erase_ship(x, y);
				draw_ship(--x, y);
			}
		}
		if (move == 'd') {
			if (x + 1 < 70) {
				erase_ship(x, y);
				draw_ship(++x, y);
			}
		}
		if (move == 'w') {
			if (y - 1 > 0) {
				erase_ship(x, y);
				draw_ship(x, --y);
			}
		}
		if (move == 's') {
			if (y + 1 < 30) {
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
		}
		for (int i = 0; i < 5; i++){
			if (bullet[i] == true) {
				erase_bullet(xb[i], yb[i]);
				if (yb[i] > 0 && yb[i] < 40) {
					draw_bullet(xb[i], --yb[i]);
					draw_ship(x, y);
					if (cursor(xb[i], yb[i] - 1) == '*' || cursor(xb[i] + 1, yb[i] - 1) == '*' || cursor(xb[i] + 2, yb[i] - 1) == '*') {
						if (cursor(xb[i], yb[i] - 1) == '*') {
							draw_star(rand() % 60 + 10, rand() % 4 + 2);
							score++;
						}
						if (cursor(xb[i] + 1, yb[i] - 1) == '*') {
							draw_star(rand() % 60 + 10, rand() % 4 + 2);
							score++;
						}
						if (cursor(xb[i] + 2, yb[i] - 1) == '*') {
							draw_star(rand() % 60 + 10, rand() % 4 + 2);
							score++;
						}
						erase_bullet(xb[i], yb[i]);
						erase_bullet(xb[i], yb[i] - 1);
						Beep(200, 50);
						count--;
						bullet[i] = false;
					}
				}
				if (yb[i] < 1) {
					erase_bullet(xb[i], yb[i]);
					count--;
					bullet[i] = false;
				}
			} 
		}
		
		show_score(69, 1, score);
		fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
	setcolor(7, 0);
	return 0;
}