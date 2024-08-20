#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];

int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
void clear_buffer() 
{
	for (int y = 0; y < screen_y; ++y) {
		for (int x = 0; x < screen_x; ++x) {
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}
void init_star()
{
	for (int i = 0; i < scount; i++) {
		star[i].X = rand() % 80;
		star[i].Y = rand() % 25;
	}
}
void star_fall()
{
	int i;
	for (i = 0; i < scount; i++) {
		if (star[i].Y >= screen_y - 1) {
			star[i] = { (rand() % screen_x),1 };
		}
		else {
			star[i] = { star[i].X, star[i].Y + 1 };
		}
	}
}
void fill_star_to_buffer()
{
	for (int i = 0; i < scount; i++) {
			consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
			consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
	}
}
void draw_ship(int x, int y,int color)
{
	if (x >= 0 && x <= 80 && y >= 0 && y <= 25) {
		consoleBuffer[x - 1 + screen_x * y].Char.AsciiChar = '<';
		consoleBuffer[x - 1 + screen_x * y].Attributes = color;
		consoleBuffer[x + screen_x * y].Char.AsciiChar = '-';
		consoleBuffer[x + screen_x * y].Attributes = color;
		consoleBuffer[x + 1 + screen_x * y].Char.AsciiChar = '>';
		consoleBuffer[x + 1 + screen_x * y].Attributes = color;
		fill_buffer_to_console();
	}
}
void life_left(int crash) {
	consoleBuffer[72].Char.AsciiChar = 'l';
	consoleBuffer[73].Char.AsciiChar = 'i';
	consoleBuffer[74].Char.AsciiChar = 'f';
	consoleBuffer[75].Char.AsciiChar = 'e';
	consoleBuffer[77].Char.AsciiChar = ':';
	consoleBuffer[79].Char.AsciiChar = crash + 47;
}
int main()
{
	bool play = true;
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	int posx = 0, posy = 0;
	int* xmouse = &posx, *ymouse = &posy;
	int ship_color = 5, crash = 10;
	
	srand(time(NULL));
	setConsole(screen_x, screen_y);
	setMode();
	clear_buffer();
	init_star();
	setConsole(screen_x, screen_y);
	setcursor(0);
	setMode();
	while (play && crash > 0)
	{
		clear_buffer();
		star_fall();
		fill_star_to_buffer();
		fill_buffer_to_console();
		life_left(crash);

		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) {
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) {
				if (eventBuffer[i].EventType == KEY_EVENT &&
					eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
						play = false;
					}
					if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c') {
						ship_color = rand() % 15 + 1;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) {
					posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
						ship_color = rand() % 15 + 1;
					}
					else if (eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED);
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
						draw_ship(posx, posy, ship_color);
					}
				}
			}
			delete[] eventBuffer;
		}
		else {
			draw_ship(*xmouse, *ymouse, ship_color);
		}
		for (int i = 0; i < scount; i++) {
			if (*xmouse == star[i].X && *ymouse == star[i].Y ||
				*xmouse == star[i].X - 1 && *ymouse == star[i].Y || 
				*xmouse == star[i].X + 1 && *ymouse == star[i].Y) {
				star[i].X = rand() % 80;
				star[i].Y = 0;
				crash--;
			}
		}
		Sleep(100);
	}
	return 0;
}