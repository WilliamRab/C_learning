#include<graphics.h>
#include<conio.h>
int main()
{
	int x = 300, y = 200;
	char c;
	initgraph(800, 400);
	setbkcolor(YELLOW);
	setfillcolor(BLUE);
	while (1)
	{
		cleardevice();
		fillcircle(x, y, 50);
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
	closegraph();
}