#include<stdio.h>
#include<windows.h>
#include<conio.h>



void draw(int x , int y) {

	COORD xy = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf(" <-0-> ");
}

void drawAmmo(int x , int y)
{
	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf("O");

}

void H1(int x,int y) {
	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf(" --0-- ");

}

void deleteXY(int x, int y) {
	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf("       ");

}

void deleteX(int x, int y) {
	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf(" ");

}


void draw2(int x,int y) {

	COORD xy = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
		printf("      ");

}


void setcolor(int bg,int fg) {
	//bg background , fg foreground สีตัวอักษร
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //color = output
	SetConsoleTextAttribute(color, bg *16 + fg ); //(output ,เป็นอะไร)


}

void deletecolor(int bg ,int fg){
	bg = 0, fg = 0;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,bg*16+fg );
}

void setcursor(bool visible) {
	//cusur หายไป
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Ipcursur;
	Ipcursur.bVisible = visible;
	Ipcursur.dwSize = 20;
	SetConsoleCursorInfo(console, &Ipcursur);

}

void color(int x,int y ,int bg ,int fg) {
	//bg background , fg foreground สีตัวอักษร
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //color = output
	SetConsoleTextAttribute(color, bg * 16 + fg); //(output ,เป็นอะไร)

	HANDLE color2 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 0);

}

void move() { //move1 + move2
	setcursor(0);
	setcolor(6, 4);


		int x = 20, y = 20;
		draw(x, y);
		char m = ' ';
		do {
			if (_kbhit() && (x > 0 && y > 0 && x < 80 && y < 80)) {
				m = _getch();
				setcolor(6, 4);
				if (m == 'a') {draw(--x, y); deletecolor(0, 0);  deleteXY(x + 7 , y);}
				if (m == 'd') { draw(++x, y); deletecolor(0, 0); deleteX(x - 1, y);  }
				if (m == 'w') { draw(x, --y); deleteXY(x, y + 1);  deletecolor(0, 0); deleteXY(x, y + 1);}
				if (m == 's') { deleteXY(x, y + 1); draw(x, ++y); deleteXY(x, y - 1);  deletecolor(0, 0); deleteXY(x, y - 1);}
			}
			else {
				if (x == 0)
				{
					setcolor(6, 4);

					if (_kbhit())
					{
						m = _getch();
						if (m == 'd') { draw(++x, y);  deletecolor(0, 0); deleteX(x - 1, y); }
						if (m == 'w') { deleteXY(x, y - 1); draw(x, --y); deleteXY(x, y + 1); deletecolor(0, 0); deleteXY(x, y + 1); }
						if (m == 's') { deleteXY(x, y + 1); draw(x, ++y); deleteXY(x, y - 1); deletecolor(0, 0); deleteXY(x, y - 1);}

					}
				}

				else if (x == 80)
				{ 
					setcolor(6, 4);
					if (_kbhit())
					{
						m = _getch();
						if (m == 'a') { draw(--x, y); deletecolor(0, 0);  deleteXY(x + 7, y);}
						if (m == 'w') { deleteXY(x, y - 1); draw(x, --y); deleteXY(x, y + 1); deletecolor(0, 0); deleteXY(x, y + 1);}
						if (m == 's') { deleteXY(x, y + 1); draw(x, ++y); deleteXY(x, y - 1); deletecolor(0, 0); deleteXY(x, y - 1); }

					}
				}
				else if (y == 0)
				{
					setcolor(6, 4);
					if (_kbhit())
					{
						m = _getch();
						if (m == 's') { deleteXY(x, y + 1); draw(x, ++y); deleteXY(x, y - 1); deletecolor(0, 0); deleteXY(x, y - 1); }
						if (m == 'a') { draw(--x, y); deletecolor(0, 0);  deleteXY(x + 7, y);}
						if (m == 'd') { draw(++x, y); deletecolor(0, 0);  deleteXY(x - 7, y);}

					}
				}
				else if (y == 80)
				{
					setcolor(6, 4);
					if (_kbhit())
					{
						m = _getch();
						if (m == 'w') { deleteXY(x, y - 1); draw(x, --y); deleteXY(x, y + 1); deletecolor(0, 0); deleteXY(x, y + 1); }
						if (m == 'a') { draw(--x, y); deletecolor(0, 0);  deleteXY(x + 7, y); }
						if (m == 'd') { draw(++x, y); deletecolor(0, 0);  deleteXY(x - 7, y);}

					}
				}


			}

			//Sleep(60);
		} while (m != 'x');
	}


void gotoxy(int x,int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void testX() {
	for (int i = 1; i <= 10; i++)
	{
		printf("x\n");
			Sleep(100);
	}
	//sleep is delay (10^-3 second)
}

void auto_left(int x,int y)
{
		setcolor(6, 4);
		draw(x, y);
		Sleep(100);
		deletecolor(0, 0);
		deleteXY(x, y);
}

void auto_right(int x, int y)
{

	setcolor(6, 4);
	draw(x, y);

	deletecolor(0, 0);
	deleteXY(x + 8, y);

	Sleep(100);

	deletecolor(0, 0);
	deleteXY(x, y);
}

void automove() 
{
	int x = 10 , y = 20 ,i = x;
	setcolor(6, 4);
	draw(x, y);
	char m = ' ';
	do
	{
		if(_kbhit)
		{
			m = _getch();  
			if (m == 'a') { 
				for (x; x >= 0; x--) {

					auto_left(x,y);

					if (x == 0)
					{
						setcolor(6, 4);
						draw(x, y);
					}

					if (_kbhit())
					{
						m = _getch();
						if (m == 's') { setcolor(6, 4); draw(x, y);  break; }

					}
				}
			}

			else if (m == 'd') 
			{
				for (x; x <= 80; x++) 
				{
					auto_right(x, y);
					if (x == 80)
					{
						setcolor(6, 4);
						draw(x+1, y);
					}

					if (_kbhit())
					{
						m = _getch();
						if (m == 's') { setcolor(6, 4); draw(x, y); break; }

					}

				}
			}
		}
		
	} while (m != 'x');
}

void Ammo(int x, int y)
{
	deleteX(x, y - 1);
	drawAmmo(x, y);
	deleteX(x, y + 1);
}

void AmmoMove()
{
	char m = ' ';
	int x = 20, y = 20, i = y;
	int c = 0;

	drawAmmo(x, y);
	deleteX(x, y);

	do
	{
		do {
			if (_kbhit())
			{
				m = _getch();

				if (m == ' ')
				{
					for (y; y >= 0; y--)
					{
						if (y == 19) {
							y = y - 1;
							for (y; y >= 0; y--)
							{
								Ammo(x, y);

								Sleep(100);
							}
						}

						if (y == 18)
						{
							for (i; i >= 0; i--)
							{
								Ammo(x, i-1);
								Ammo(x, i);
								Sleep(100);
							}
						}




					}



				}

			}
			/*else
			{

				if (_kbhit())
				{
					m = _getch();

					if (m == ' ')
					{
						for (y = 19; y >= 0; y--)
						{
							Ammo(x, y);
							Sleep(50);


							if (y == 0)
							{
								deleteX(x, y);
							}



						}


					}
				}
			}*/
		} while (_kbhit() == 5);

		} while (m != x);

	}


int main (){
	//setcolor(6,4);
	AmmoMove();
	//automove();
	//move1();

	//testX();
	//gotoxy(10,5);

	}

