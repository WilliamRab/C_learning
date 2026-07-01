#include<conio.h>
#include<graphics.h>
#include<stdio.h>
const int len = 60, grid=10;
int bullet = 0;
int state[11][11] = { 0 };
//0=empty,1=wall, 2=bullet_supply, 3=player, 4=enemy, 5=pl_death, 6=loading, 7=bullet, 8=enemy_death
int Ax, Ay, Bx, By,Cx, Cy, Ai,Aj,Bi,Bj,Ci,Cj;
int checkpoint = 0;
bool lose = false,  A = true, B = true, C=true;//A and B are alive or dead

void drawbk() {//Draw the board
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	for (int i = 1; i <= grid + 1; i++)
	{
		line(i * len, len, i * len, (grid + 1) * len);
		line(len, i * len, (grid + 1) * len, i * len);
	}
	return;
}

void drawtoken() {
	int i, j;
	for (i = 1; i <= grid; i++) {
		for (j = 1;j <= grid;j++)
		{
			if (state[i][j] == 0) {
				setfillcolor(WHITE);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			}
			if(state[i][j] == 1) {
				setfillcolor(BLACK);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			} 
			if (state[i][j] == 2) {
				setfillcolor(YELLOW);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			}
			if (state[i][j] == 3) {
				setfillcolor(RED);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			}
			if (state[i][j] == 4) {
				setfillcolor(BLUE);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			}
			if (state[i][j] == 5) {
				setlinecolor(RED);
				line(i * len, j * len, (i + 1) * len, (j + 1) * len);
				line(i * len, (j + 1) * len, (i + 1) * len, j * len);
			}
			if (state[i][j] == 6) {
				setfillcolor(GREEN);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			}
			if (state[i][j] == 7) {
				setfillcolor(LIGHTMAGENTA);
				fillcircle((i+0.5)* len,(j+0.5) * len, 0.3 * len);
			}
			if (state[i][j] == 8) {
				setfillcolor(MAGENTA);
				fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
			}
		}

	}
	return;
}


void setup1() {
	A = true, B = true;
	state[1][1] = 3;

	state[5][9] = 2;
	state[8][4] = 2;
	state[9][7] = 2;

	state[4][7] = 4;
	state[6][2] = 4;
	Ax = 4;Ay = 7;Bx = 6;By = 2;
	Ai = 1;Aj = 0;Bi = 0;Bj = 1;

	state[1][4] = 1;
	state[1][5] = 1;
	state[1][6] = 1;
	state[2][6] = 1;
	state[3][2] = 1;
	state[3][3] = 1;
	state[3][4] = 1;
	state[4][2] = 1;
	state[5][4] = 1;
	state[5][5] = 1;
	state[5][6] = 1;
	state[4][6] = 1;
	state[4][8] = 1;
	state[4][9] = 1;
	state[5][8] = 1;
	state[7][3] = 1;
	state[8][3] = 1;
	state[9][3] = 1;
	state[9][4] = 1;
	state[7][6] = 1;
	state[8][6] = 1;
	state[9][6] = 1;
	state[9][8] = 1;
	state[10][8] = 1;
	state[7][8] = 1;
	state[7][9] = 1;

	drawtoken();
	return;
}

int plx() {//Get the x array of the player
	for (int i = 1;i <= 10;i++) {
		for (int j = 1; j <= 10; j++) {
			if (state[i][j] == 3)	return i;
		}
	}
}

int ply() {//Get the y array of the player
	for (int i = 1;i <= 10;i++) {
		for (int j = 1; j <= 10; j++) {
			if (state[i][j] == 3)	return j;
		}
	}
}

void move(char key) {//Move the player and load the bullet if it hits the bullet supply
		int x = plx();
		int y = ply();
		if (key == 'w') {
			if (state[x][y - 1] == 0 && y > 1) {//If the next position is empty, move the player
				state[x][y] = 0;
				state[x][y - 1] = 3;
			}
			if (state[x][y - 1] == 2) {//If the next position is bullet supply, load the bullet and move the player
				state[x][y] = 0;
				state[x][y - 1] = 6;
				bullet++;
				drawtoken();
				Sleep(50);
				state[x][y - 1] = 3;
			}

		}
		if (key == 's') {
			if (state[x][y + 1] == 0 && y < 10) {
				state[x][y] = 0;
				state[x][y + 1] = 3;
			}
			if (state[x][y + 1] == 2) {
				state[x][y] = 0;
				state[x][y + 1] = 6;
				bullet++;
				drawtoken();
				Sleep(50);
				state[x][y + 1] = 3;
			}
		}
		if (key == 'a') {
			if (state[x - 1][y] == 0 && x > 1) {
				state[x][y] = 0;
				state[x - 1][y] = 3;
			}
			if (state[x - 1][y] == 2) {
				state[x][y] = 0;
				state[x - 1][y] = 6;
				bullet++;
				drawtoken();
				Sleep(50);
				state[x - 1][y] = 3;
			}
		}
		if (key == 'd') {
			if (state[x + 1][y] == 0 && x < 10) {
				state[x][y] = 0;
				state[x + 1][y] = 3;
			}
			if (state[x + 1][y] == 2) {
				state[x][y] = 0;
				state[x + 1][y] = 6;
				bullet++;
				drawtoken();
				Sleep(50);
				state[x + 1][y] = 3;
			}
		}
		drawtoken();
		return;
	}
	

void moveA() {//Move the enemy A and check if it hits the player
	if (checkpoint == 1 && A == true) {
		if (state[Ax+Ai][Ay] == 0 && Ax + Ai > 0 && Ax+Ai <11) {
			state[Ax][Ay] = 0;
			state[Ax+Ai][Ay] = 4;
			Ax = Ax + Ai;
			drawtoken();
		}
		else if (state[Ax + Ai][Ay] == 3) {
			state[Ax][Ay] = 0;
			state[Ax + Ai][Ay] = 5;
			Ax = Ax + Ai;
			drawtoken();
			lose = true;
		}
		else	Ai = -Ai;
	}
	if (checkpoint == 2) {
		int px = plx();
		int py = ply();
		// ---------- BFS 寻路 ----------
		int qx[105], qy[105];    // 队列数组
		int head = 0, tail = 0;  // 队列头尾指针
		int prevX[11][11], prevY[11][11];  // 前驱坐标
		bool visited[11][11] = { false };
		qx[tail] = Ax;// 起点入队
		qy[tail] = Ay;
		tail++;
		visited[Ax][Ay] = true;
		prevX[Ax][Ay] = -1;   // 起点没有前驱
		prevY[Ax][Ay] = -1;
		int dx[4] = { 0, 0, -1, 1 };// 方向数组：上、下、左、右
		int dy[4] = { -1, 1, 0, 0 };
		bool found = false;
		int targetX = -1, targetY = -1;  // 找到玩家时的格子坐标
		while (head < tail) {   // 队列不为空
			int cx = qx[head];
			int cy = qy[head];
			head++;             // 出队
			if (cx == px && cy == py) {// 如果当前格子就是玩家位置
				found = true;
				targetX = cx;
				targetY = cy;
				break;
			}
			for (int d = 0; d < 4; d++) {// 尝试四个方向
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (nx < 1 || nx > 10 || ny < 1 || ny > 10) continue;// 边界检查
				if (visited[nx][ny]) continue;// 已访问过
				if (state[nx][ny] == 1 || state[nx][ny] == 2 || state[nx][ny] == 4) continue;// 墙壁或弹药箱不可通行
				visited[nx][ny] = true;// 标记访问，记录前驱，入队
				prevX[nx][ny] = cx;
				prevY[nx][ny] = cy;
				qx[tail] = nx;
				qy[tail] = ny;
				tail++;
			}
		}
		if (!found) return;// 没有路径可到达玩家，原地不动
		int bx = targetX, by = targetY;// 回溯得到第一步
		while (!(prevX[bx][by] == Ax && prevY[bx][by] == Ay)) {// 从目标往回走，直到前驱是起点
			int pbx = prevX[bx][by];
			int pby = prevY[bx][by];
			bx = pbx;
			by = pby;
		}// 此时 (bx, by) 就是敌人下一步要走的格子
		if (bx == px && by == py) {// 检查是否踩到玩家
			state[Ax][Ay] = 0;
			state[bx][by] = 5;      // 玩家死亡标记
			Ax = bx; Ay = by;
			lose = true;
			drawtoken();
			return;
		}
		state[Ax][Ay] = 0;// 正常移动
		state[bx][by] = 4;
		Ax = bx; Ay = by;
		drawtoken();
	}
	return;
}

void moveB() {//Move the enemy B and check if it hits the player
	if (checkpoint == 1 && B==true) {
		if (state[Bx][By + Bj] == 0 && By + Bj > 0 && By + Bj < 11) {
			state[Bx][By] = 0;
			state[Bx][By + Bj] = 4;
			By = By + Bj;
			drawtoken();
		}
		else if (state[Bx][By + Bj] == 3) {
			state[Bx][By] = 0;
			state[Bx][By + Bj] = 5;
			By = By + Bj;
			drawtoken();
			lose = true;
		}
		else	Bj = -Bj;
	}
	if (checkpoint == 2){
	
		int px = plx();
		int py = ply();
		// ---------- BFS 寻路 ----------
		int qx[105], qy[105];    // 队列数组
		int head = 0, tail = 0;  // 队列头尾指针
		int prevX[11][11], prevY[11][11];  // 前驱坐标
		bool visited[11][11] = { false };
		qx[tail] = Bx;// 起点入队
		qy[tail] = By;
		tail++;
		visited[Bx][By] = true;
		prevX[Bx][By] = -1;   // 起点没有前驱
		prevY[Bx][By] = -1;
		int dx[4] = { 0, 0, -1, 1 };// 方向数组：上、下、左、右
		int dy[4] = { -1, 1, 0, 0 };
		bool found = false;
		int targetX = -1, targetY = -1;  // 找到玩家时的格子坐标
		while (head < tail) {   // 队列不为空
			int cx = qx[head];
			int cy = qy[head];
			head++;             // 出队
			if (cx == px && cy == py) {// 如果当前格子就是玩家位置
				found = true;
				targetX = cx;
				targetY = cy;
				break;
			}
			for (int d = 0; d < 4; d++) {// 尝试四个方向
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (nx < 1 || nx > 10 || ny < 1 || ny > 10) continue;// 边界检查
				if (visited[nx][ny]) continue;// 已访问过
				if (state[nx][ny] == 1 || state[nx][ny] == 2 || state[nx][ny] == 4) continue;// 墙壁或弹药箱不可通行
				visited[nx][ny] = true;// 标记访问，记录前驱，入队
				prevX[nx][ny] = cx;
				prevY[nx][ny] = cy;
				qx[tail] = nx;
				qy[tail] = ny;
				tail++;
			}
		}
		if (!found) return;// 没有路径可到达玩家，原地不动
		int bx = targetX, by = targetY;// 回溯得到第一步
		while (!(prevX[bx][by] == Bx && prevY[bx][by] == By)) {// 从目标往回走，直到前驱是起点
			int pbx = prevX[bx][by];
			int pby = prevY[bx][by];
			bx = pbx;
			by = pby;
		}// 此时 (bx, by) 就是敌人下一步要走的格子
		if (bx == px && by == py) {// 检查是否踩到玩家
			state[Bx][By] = 0;
			state[bx][by] = 5;      // 玩家死亡标记
			Bx = bx; By = by;
			lose = true;
			drawtoken();
			return;
		}
		state[Bx][By] = 0;// 正常移动
		state[bx][by] = 4;
		Bx = bx; By = by;
		drawtoken();
	}
	return;
}

void moveC() {//Move the enemy C and check if it hits the player
	if (checkpoint == 2 && C == true) {
		int px = plx();          
		int py = ply();          
		// ---------- BFS 寻路 ----------
		int qx[105], qy[105];    // 队列数组
		int head = 0, tail = 0;  // 队列头尾指针
		int prevX[11][11], prevY[11][11];  // 前驱坐标
		bool visited[11][11] = { false };
		qx[tail] = Cx;// 起点入队
		qy[tail] = Cy;
		tail++;
		visited[Cx][Cy] = true;
		prevX[Cx][Cy] = -1;   // 起点没有前驱
		prevY[Cx][Cy] = -1;
		int dx[4] = { 0, 0, -1, 1 };// 方向数组：上、下、左、右
		int dy[4] = { -1, 1, 0, 0 };
		bool found = false;
		int targetX = -1, targetY = -1;  // 找到玩家时的格子坐标
		while (head < tail) {   // 队列不为空
			int cx = qx[head];
			int cy = qy[head];
			head++;             // 出队
			if (cx == px && cy == py) {// 如果当前格子就是玩家位置
				found = true;
				targetX = cx;
				targetY = cy;
				break;
			}
			for (int d = 0; d < 4; d++) {// 尝试四个方向
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if (nx < 1 || nx > 10 || ny < 1 || ny > 10) continue;// 边界检查
				if (visited[nx][ny]) continue;// 已访问过
				if (state[nx][ny] == 1 || state[nx][ny] == 2 || state[nx][ny] == 4) continue;// 墙壁或弹药箱不可通行
				visited[nx][ny] = true;// 标记访问，记录前驱，入队
				prevX[nx][ny] = cx;
				prevY[nx][ny] = cy;
				qx[tail] = nx;
				qy[tail] = ny;
				tail++;
			}
		}
		if (!found) return;// 没有路径可到达玩家，原地不动
		int bx = targetX, by = targetY;// 回溯得到第一步
		while (!(prevX[bx][by] == Cx && prevY[bx][by] == Cy)) {// 从目标往回走，直到前驱是起点
			int pbx = prevX[bx][by];
			int pby = prevY[bx][by];
			bx = pbx;
			by = pby;
		}// 此时 (bx, by) 就是敌人下一步要走的格子
		if (bx == px && by == py) {// 检查是否踩到玩家
			state[Cx][Cy] = 0;
			state[bx][by] = 5;      // 玩家死亡标记
			Cx = bx; Cy = by;
			lose = true;
			drawtoken();
			return;
		}
		state[Cx][Cy] = 0;// 正常移动
		state[bx][by] = 4;
		Cx = bx; Cy = by;
		drawtoken();
	}
	return;
}

void shoot(char key) {//Shoot the bullet and check if it hits the enemy
	bullet--;
	int x = plx();
	int y = ply();
	if (key == 'i') {//子弹打到边缘消失
		for (int j = y - 1; j >= 0; ) {
			if (state[x][j] == 1) {//If it hits the wall, stop shooting
				if (state[x][j + 1] == 7)		state[x][j + 1] = 0;
				return;
			}
			if (j == 0) {
				if (state[x][j + 1] == 7)		state[x][j + 1] = 0;
				return;
			}
			else if (state[x][j] == 0 || state[x][j] == 2) {//If it hits the empty space or bullet supply, continue shooting
				state[x][j] = 7;
				if (state[x][j + 1] == 7)		state[x][j + 1] = 0;
				drawtoken();
				j--;
			}
			else if (state[x][j] == 4) {
				state[x][j] = 8;//If it hits the enemy, change the state to enemy death
				if (state[x][j + 1] == 7)		state[x][j + 1] = 0;
				if (x == Ax && j == Ay)		A = false;//If the enemy is killed, change the state to dead
				else if (x == Bx && j == By)		B = false;
				else if (x == Cx && j == Cy)		C = false;
				drawtoken();
				Sleep(50);
				state[x][j] = 0;//After the enemy is killed, change the state to empty
				drawtoken();
				return;
			}
			Sleep(50);
		}
	}
	else if (key == 'k') {
		for (int j = y + 1; j <= 11; ) {
			if (state[x][j] == 1) { 
				if (state[x][j - 1] == 7)		state[x][j - 1] = 0;
				return; 
			}
			if (j == 11) {
				if (state[x][j - 1] == 7)		state[x][j - 1] = 0;
				return;
			}

			else if (state[x][j] == 0 || state[x][j] == 2) {
				state[x][j] = 7;
				if (state[x][j - 1] == 7)		state[x][j - 1] = 0;
				drawtoken();
				j++;
			}
			else if (state[x][j] == 4) {
				state[x][j] = 8;
				if (state[x][j - 1] == 7)		state[x][j - 1] = 0;
				if (x == Ax && j == Ay)		A = false;
				else if (x == Bx && j == By)		B = false;
				else if (x == Cx && j == Cy)		C = false;
				drawtoken();
				Sleep(50);
				state[x][j] = 0;
				drawtoken();
				return;
			}
			Sleep(50);
		}
	}
	else if (key == 'j') {
		for (int i = x - 1; i >= 0; ) {
			if (state[i][y] == 1) {
				if (state[i + 1][y] == 7)		state[i + 1][y] = 0;
				return;
			}
			if (i == 0) {
				if (state[i + 1][y] == 7)		state[i + 1][y] = 0;
				return;
			}
			else if (state[i][y] == 0 || state[i][y] == 2) {
				state[i][y] = 7;
				if (state[i+1][y] == 7)		state[i+1][y] = 0;
				drawtoken();
				i--;
			}
			else if (state[i][y] == 4) {
				state[i][y] = 8;
				if (state[i+1][y] == 7)		state[i+1][y] = 0;
				if (i == Ax && y == Ay)		A = false;
				else if (i == Bx && y == By)		B = false;
				else if (i == Cx && y == Cy)		C = false;
				drawtoken();
				Sleep(50);
				state[i][y] = 0;
				drawtoken();
				return;
			}
			Sleep(50);
		}
	}
	else if (key == 'l') {
		for (int i = x + 1; i <= 11; ) {
			if (state[i][y] == 1) {
				if (state[i - 1][y] == 7)		state[i - 1][y] = 0;
				return;
			}
			if (i == 11) {
				if (state[i - 1][y] == 7)		state[i - 1][y] = 0;
				return;
			}
			else if (state[i][y] == 0 || state[i][y] == 2) {
				state[i][y] = 7;
				if (state[i - 1][y] == 7)		state[i - 1][y] = 0;
				drawtoken();
				i++;
			}
			else if (state[i][y] == 4) {
				state[i][y] = 8;
				if (state[i - 1][y] == 7)		state[i - 1][y] = 0;
				if (i == Ax && y == Ay)		A = false;
				else if (i == Bx && y == By)		B = false;
				else if (i == Cx && y == Cy)		C = false;
				drawtoken();
				Sleep(50);
				state[i][y] = 0;
				drawtoken();
				return;
			}
			Sleep(50);
		}
	}
}

void setup2() {
	bullet = 0;
	lose = false;//Reset the game state for checkpoint 2

	A = true, B = true, C=true;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			state[i][j] = 0;

	state[5][1] = 3;
	state[7][1] = 2;
	state[3][2] = 2;
	state[1][10] = 2;
	state[7][9] = 2;
	state[2][5] = 4;
	state[5][10] = 4;
	state[8][7] = 4;
	Ax = 2; Ay = 5; Bx = 5; By = 10;Cx = 8; Cy = 7;
	Ai = 0; Aj = 0; Bi = 0; Bj = 0;Ci = 0; Cj = 0;
	state[4][1] = 1;
	state[4][2] = 1;
	state[4][3] = 1;
	state[3][3] = 1;
	state[2][3] = 1;
	state[3][5] = 1;
	state[3][6] = 1;
	state[4][5] = 1;
	state[4][6] = 1;
	state[2][9] = 1;
	state[3][9] = 1;
	state[4][9] = 1;
	state[4][8] = 1;
	state[6][1] = 1;
	state[6][2] = 1;
	state[7][2] = 1;
	state[7][3] = 1;
	state[8][3] = 1;
	state[8][4] = 1;
	state[6][6] = 1;
	state[6][7] = 1;
	state[6][8] = 1;
	state[6][9] = 1;
	state[7][6] = 1;
	state[7][7] = 1;
	state[7][8] = 1;
	state[8][8] = 1;
	state[9][8] = 1;
	state[9][9] = 1;

	drawtoken();
	return;
}

int main()
{
	initgraph(12*len,12*len);
	drawbk();
	setup1();
	checkpoint++;
	while (checkpoint == 1)
	{
		Sleep(200);
		if (A == false && B == false) {
			printf("You win!\n");
			checkpoint++;
		}
		if(A==true)	moveA();
		if (B == true)	moveB();
		drawtoken();
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w'|| ch == 's'|| ch == 'a'|| ch == 'd') {
				move(ch);
			}
			if ((ch == 'i' || ch == 'j' || ch == 'k' || ch == 'l') && bullet > 0) {
				shoot(ch);
			}
		}
		if (lose == true) {
			printf("You lose!\n");
			break;
		}
	}
	if (checkpoint == 2) { 
		Sleep(800);
		setup2(); 
	}
	int k = 0;//New enemy moving rule for checkpoint 2
	while (checkpoint == 2)
	{
		Sleep(200);
		k++;
		if (A == false && B == false && C == false) {
			printf("You win!\n");
			checkpoint++;
		}
		if (k % 5 == 0) {
			if (A == true)	moveA();
			if (B == true)	moveB();
			if (C == true)	moveC();
		}
		drawtoken();
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd') {
				move(ch);
			}
			if ((ch == 'i' || ch == 'j' || ch == 'k' || ch == 'l') && bullet > 0) {
				shoot(ch);
			}
		}
		if (lose == true) {
			printf("You lose!\n");
			break;
		}
	 }
	_getch();
	closegraph();
	return 0;
}