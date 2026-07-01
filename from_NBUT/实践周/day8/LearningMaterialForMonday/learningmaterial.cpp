#include<graphics.h>
#include<conio.h>
int main()
{
	char c;
	int x = 300, y = 200, x1 = 100, y1 = 100;
	initgraph(800, 400);
	setbkcolor(YELLOW);
	while (1)
	{
		cleardevice();
		setfillcolor(BLUE);
		fillcircle(x, y, 50);
		setfillcolor(RED);
		fillcircle(x1, y1, 50);
		Sleep(200);
		x1 += 10;
		if (_kbhit())
		{
			c = _getch();
			if (c == 'w')
				y -= 50;
			else if (c == 's')
				y += 50;
			else if (c == 'a')
				x -= 50;
			else if (c == 'd')
				x += 50;
		}
	}
	closegraph();
	return 0;
}