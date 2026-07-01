#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
const double pi = 3.1415926;
int main()
{
	initgraph(800, 800);	// 创建绘图窗口，大小为 800x800 像素
	setbkcolor(BLUE);
	cleardevice();
	int n = 8;//将圆分为8份
	int i;
	for (i = 0; i < n; i++) {
		setfillcolor((i%2)?RED:GREEN);
		fillpie(40, 40, 760, 760, i*2*pi/n, (i+1)* 2 * pi / n);
	}
	for (i = 0; i < n; i++) {
		setfillcolor((i % 2) ? BLACK : WHITE);
		fillpie(60, 60, 740, 740, i * 2 * pi / n, (i + 1) * 2 * pi / n);
	}
	setfillcolor(GREEN);
	fillcircle(400, 400, 40);
	setfillcolor(RED);
	fillcircle(400, 400, 20);

	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}