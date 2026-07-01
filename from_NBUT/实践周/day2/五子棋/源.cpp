#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#pragma execution_character_set("utf-8")

const int GRID = 40;
const int BOARD = 15; // 15x15 五子棋
int board[BOARD][BOARD]; // 0 空, 1 黑, 2 白
int lastR = -1, lastC = -1;

/*原来的棋盘
void drawBoard()
{
	setbkcolor(YELLOW);
	cleardevice();
	setlinecolor(BLACK);
	for (int i = 0; i <= BOARD; i++) {
		// 横线
		line(GRID, GRID + i * GRID, BOARD * GRID, GRID + i * GRID);
		// 竖线
		line(GRID + i * GRID, GRID, GRID + i * GRID, BOARD * GRID);
	}
}
*/

// 用更好看的绘制棋盘（替换原 drawBoard 实现）
void drawBoard()
{
	setbkcolor(RGB(245, 222, 179)); // 木色背景
	cleardevice();

	int left = GRID;
	int top = GRID;
	int right =  BOARD * GRID;
	int bottom =  BOARD * GRID;

	// 边框
	setlinecolor(RGB(100, 50, 0));
	rectangle(left - 8, top - 8, right + 8, bottom + 8);

	// 网格线（浅棕色）
	setlinecolor(RGB(120, 70, 20));
	for (int i = 0; i <= BOARD; i++) {
		line(left, top + i * GRID, right, top + i * GRID);           // 横线
		line(left + i * GRID, top, left + i * GRID, bottom);         // 竖线
	}
}

void drawPiece(int r, int c, int player)
{
	int x = GRID * (c + 1);
	int y = GRID * (r + 1);
	int rads = GRID / 2 - 4;
	if (player == 1) {
		setfillcolor(BLACK);
		solidcircle(x, y, rads);
	}
	else if (player == 2) {
		setfillcolor(WHITE);
		solidcircle(x, y, rads);
		setlinecolor(BLACK);
		circle(x, y, rads);
	}
}

bool inBoard(int r, int c) { return r >= 0 && r < BOARD && c >= 0 && c < BOARD; }

bool checkWin(int r, int c, int player)
{
	const int dr[4] = {0, 1, 1, 1};
	const int dc[4] = {1, 0, 1, -1};
	for (int d = 0; d < 4; d++) {
		int cnt = 1;
		for (int k = 1; k <= 4; k++) {
			int nr = r + dr[d] * k;
			int nc = c + dc[d] * k;
			if (inBoard(nr, nc) && board[nr][nc] == player) cnt++; else break;
		}
		for (int k = 1; k <= 4; k++) {
			int nr = r - dr[d] * k;
			int nc = c - dc[d] * k;
			if (inBoard(nr, nc) && board[nr][nc] == player) cnt++; else break;
		}
		if (cnt >= 5) return true;
	}
	return false;
}

int main()
{
	initgraph(GRID * (BOARD + 1), GRID * (BOARD + 1));
	drawBoard();// 初始化棋盘
	for (int i = 0; i < BOARD; i++) for (int j = 0; j < BOARD; j++) board[i][j] = 0;

	int turn = 1; // 1 黑方先手
	bool finished = false;

	MOUSEMSG msg;
	settextstyle(20, 0, L"\u5FAE\u8F6F\u96C5\u9ED1");
	settextcolor(RED);
	outtextxy(10, 10, L"\u6309 R \u91CD\u7F6E\uFF0CEsc \u9000\u51FA\u3002\u672C\u5730\u53CC\u4EBA\uFF0C\u5DE6\u952E\u843D\u5B50\u3002");

	while (true) {
		if (MouseHit()) {
			msg = GetMouseMsg();
			if (msg.uMsg == WM_LBUTTONDOWN && !finished) {
				int cx = msg.x;
				int cy = msg.y;
				// 计算最近的棋点
				double fx = (double)(cx - GRID) / GRID;
				double fy = (double)(cy - GRID) / GRID;
				int c = (int)(fx + 0.5);
				int r = (int)(fy + 0.5);
				if (inBoard(r, c) && board[r][c] == 0) {
					board[r][c] = turn;
					drawPiece(r, c, turn);
					if (checkWin(r, c, turn)) {
						finished = true;
						settextcolor(RED);
						if (turn == 1) outtextxy(GRID, GRID * (BOARD + 0.2), L"\u9ED1\u65B9\u83B7\u80DC\uFF01\u6309 R \u91CD\u7F6E\u3002");
						else outtextxy(GRID, GRID * (BOARD + 0.2), L"\u767D\u65B9\u83B7\u80DC\uFF01\u6309 R \u91CD\u7F6E\u3002");
					}
					turn = 3 - turn; // 切换
								}
							}
						}

		// 使用 GetAsyncKeyState 检测 Esc 和 R
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			break; // Esc 退出
		}
		if (GetAsyncKeyState('R') & 0x0001) { // 按下 R 的瞬间触发（避免连续触发）
			for (int i = 0; i < BOARD; i++)
				for (int j = 0; j < BOARD; j++)
					board[i][j] = 0;
			drawBoard();
			turn = 1;
			finished = false;
			settextcolor(BLACK);
			outtextxy(10, 10, L"\u6309 R \u91CD\u7F6E\uFF0CEsc \u9000\u51FA\u3002\u672C\u5730\u53CC\u4EBA\uFF0C\u5DE6\u952E\u843D\u5B50\u3002");
		}
		Sleep(10);
	}

	closegraph();
	return 0;
}
