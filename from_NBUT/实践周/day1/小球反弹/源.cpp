#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
const double pi = 3.1415926;
int main()
{
	initgraph(800, 800);	// 创建绘图窗口，大小为 800x800 像素
	setbkcolor(YELLOW);
	cleardevice();
	setfillcolor(RED);
	int x = 20;
	int y = 80;
	int i = 10;
	int j = 10;
	while (1) {
		fillcircle(x, y, 10);	// 绘制一个实心圆，圆心坐标为 (20, 30)，半径为 10
		Sleep(10);
		cleardevice();			// 清空绘图窗口
		if (x <= 10) {i = 10;}
		if (x >= 790) {i = -10;}
		if (y <= 10) {j = 10;}
		if (y >= 790) {j = -10;}
		x += i;				// 更新 x 坐标
		y += j;				// 更新 y 坐标
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}