#include<stdio.h>
#include<graphics.h>
#include<conio.h>
const int grid = 60 , board = 10 ;//10*10 , a = 60
int state[board + 1][board + 1] = { 0 };//0: empty, 1: player, 2: wall, 3: box, 4: target, 5:done
int checkpoint = 0;

void drawbk() {//Draw the board
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	for (int i = 1; i <= board + 1; i++)
	{
		line(i * grid, grid, i * grid, (board + 1) * grid);
		line(grid, i * grid, (board + 1) * grid, i * grid);
	}
	return;
}

void drawtoken() {//Everything on the board is drawn according to the state array
	for (int i = 1; i <= board; i++)
	{
		for (int j = 1; j <= board; j++)
		{
			if (state[i][j] == 2)
			{
				setfillcolor(BLACK);
				fillrectangle(i * grid, j * grid, (i + 1) * grid, (j + 1) * grid);
			}
			else if (state[i][j] == 3)
			{
				setfillcolor(YELLOW);
				fillrectangle(i * grid, j * grid, (i + 1) * grid, (j + 1) * grid);
			}
			else if (state[i][j] == 1)
			{
				setfillcolor(RED);
				fillrectangle(i * grid, j * grid, (i + 1) * grid, (j + 1) * grid);
			}
			else if (state[i][j] == 4)
			{
				setfillcolor(BLUE);
				fillrectangle(i * grid, j * grid, (i + 1) * grid, (j + 1) * grid);
			}
			else if (state[i][j] == 5)
			{
				setfillcolor(GREEN);
				fillrectangle(i * grid, j * grid, (i + 1) * grid, (j + 1) * grid);
			}
		
		}
	}
	return;
}

int plx() {//Get the x array of the player
	for (int i = 1;i <= 10;i++) {
		for (int j = 1; j <= 10; j++) {
			if (state[i][j] == 1)	return i;
		}
	}
}

int ply() {//Get the y array of the player
	for (int i = 1;i <= 10;i++) {
		for (int j = 1; j <= 10; j++) {
			if (state[i][j] == 1)	return j;
		}
	}
}

void move(char key) {
	int x = plx();
	int y = ply();
	if (key == 's') {
		if (state[x][y + 1] == 0 && y<10) {
			state[x][y] = 0;
			state[x][y + 1] = 1;
		}
		else if (state[x][y + 1] == 3 && state[x][y + 2] == 0 && y < 9) {
			state[x][y] = 0;
			state[x][y + 1] = 1;
			state[x][y + 2] = 3;
		}
		else if (state[x][y + 1] == 3 && state[x][y + 2] == 4 && y < 9) {
			state[x][y] = 0;
			state[x][y + 1] = 1;
			state[x][y + 2] = 5;
		}
	}
	else if (key == 'w') {
		if (state[x][y - 1] == 0 && y>1) {
			state[x][y] = 0;
			state[x][y - 1] = 1;
		}
		else if (state[x][y - 1] == 3 && state[x][y - 2] == 0 && y>2) {
			state[x][y] = 0;
			state[x][y - 1] = 1;
			state[x][y - 2] = 3;
		}
		else if (state[x][y - 1] == 3 && state[x][y - 2] == 4 && y > 2) {
			state[x][y] = 0;
			state[x][y - 1] = 1;
			state[x][y - 2] = 5;
		}
	}
	else if (key == 'a' ) {
		if (state[x - 1][y] == 0 && x>1) {
			state[x][y] = 0;
			state[x - 1][y] = 1;
		}
		else if (state[x - 1][y] == 3 && state[x - 2][y] == 0 && x>2) {
			state[x][y] = 0;
			state[x - 1][y] = 1;
			state[x - 2][y] = 3;
		}
		else if (state[x - 1][y] == 3 && state[x - 2][y] == 4 && x > 2) {
			state[x][y] = 0;
			state[x - 1][y] = 1;
			state[x - 2][y] = 5;
		}
	}
	else if (key == 'd') {
		if (state[x + 1][y] == 0 && x<10) {
			state[x][y] = 0;
			state[x + 1][y] = 1;
		}
		else if (state[x + 1][y] == 3 && state[x + 2][y] == 0 && x<9) {
			state[x][y] = 0;
			state[x + 1][y] = 1;
			state[x + 2][y] = 3;	
		}
		else if (state[x + 1][y] == 3 && state[x + 2][y] == 4 && x < 9) {
			state[x][y] = 0;
			state[x + 1][y] = 1;
			state[x + 2][y] = 5;
		}
	}
	drawbk();
	drawtoken();
	return;
}

void checkwin() {		//win? checkpoint++
	int k = 0;
	for (int i = 1; i <= board; i++)
		{
			for (int j = 1; j <= board; j++)
			{
				if (state[i][j] == 4) k++;
			}
		}
	if (k == 0)	checkpoint++;

	return;
}

void setup1() {
	for (int i = 1; i <= board; i++)
	{
		for (int j = 1; j <= board; j++)
		{
			state[i][j] = 0;
		}
	}
	state[1][1] = 1;
	state[10][10] = 4;

	state[1][3] = 2;
	state[1][4] = 2;
	state[1][5] = 2;
	state[1][6] = 2;
	state[3][1] = 2;
	state[3][2] = 2;
	state[3][3] = 2;
	state[3][4] = 2;
	state[3][7] = 2;
	state[4][7] = 2;
	state[5][5] = 2;
	state[5][4] = 2;
	state[5][3] = 2;
	state[5][2] = 2;
	state[7][2] = 2;
	state[8][2] = 2;
	state[9][2] = 2;
	state[7][5] = 2;
	state[8][5] = 2;
	state[9][5] = 2;
	state[7][7] = 2;
	state[7][8] = 2;
	state[7][9] = 2;
	state[9][8] = 2;
	state[10][8] = 2;

	state[3][6] = 3;

	drawtoken();

}

void setup2() {
	for (int i = 1; i <= board; i++)
	{
		for (int j = 1; j <= board; j++)
		{
			state[i][j] = 0;
		}
	}
	state[1][1] = 1;

	state[2][2] = 2;
	state[3][2] = 2;
	state[4][3] = 2;
	state[4][4] = 2;
	state[2][4] = 2;
	state[2][5] = 2;
	state[1][5] = 2;
	state[1][6] = 2;
	state[3][8] = 2;
	state[3][9] = 2;
	state[3][10] = 2;
	state[9][1] = 2;
	state[9][2] = 2;
	state[9][3] = 2;
	state[7][3] = 2;
	state[8][3] = 2;
	state[6][5] = 2;
	state[7][5] = 2;
	state[8][5] = 2;
	state[9][5] = 2;
	state[6][6] = 2;
	state[6][7] = 2;
	state[6][8] = 2;
	state[7][8] = 2;
	state[7][7] = 2;
	
	state[3][4] = 3;
	state[4][5] = 3;
	state[4][9] = 3;

	state[8][6] = 4;
	state[8][2] = 4;
	state[2][10] = 4;

	drawtoken();
}

int main()
{
	initgraph(grid*(board+2), grid * (board + 2));
	drawbk();
	char key;
	checkpoint++;
	setup1();
	while (checkpoint == 1) {
		move(_getch());
		checkwin();
	}
	Sleep(1000);
	printf("You win!");

	drawbk();
	setup2();
	while (checkpoint == 2) {
		move(_getch());
		checkwin();
	}
	printf("You win!");


	_getch();
	closegraph();
	return 0;
}