#define _CRT_SECURE_NO_WARNINGS
#include <graphics.h>
#include <conio.h>
#include <stdio.h>

const int len = 60, grid = 10;
int state[11][11] = { 0 }; // 0=空, 1=墙, 2=补给, 3=玩家, 4=敌人
int bullets = 0;            // 当前子弹数（初始为0，靠补给获得）
int enemyCount = 0;         // 当前敌人数量
int dir = 0;                // 0上 1下 2左 3右（默认朝上）
bool gameOver = false;
bool gameWin = false;

// 敌人移动数据
struct Enemy {
    int x, y;       // 当前位置
    int moveDir;    // 移动方向：1正向，-1反向
    int axis;       // 0水平移动，1垂直移动
};
Enemy enemies[2];

// ---------- 绘图函数 ----------
void drawbk() {
    setbkcolor(WHITE);
    cleardevice();
    setlinecolor(BLACK);
    for (int i = 1; i <= grid + 1; i++) {
        line(i * len, len, i * len, (grid + 1) * len);
        line(len, i * len, (grid + 1) * len, i * len);
    }
}

void drawtoken() {
    for (int i = 1; i <= grid; i++) {
        for (int j = 1; j <= grid; j++) {
            if (state[i][j] == 1) {
                setfillcolor(BLACK);
                fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
            }
            else if (state[i][j] == 2) {
                setfillcolor(YELLOW);
                fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
            }
            else if (state[i][j] == 3) {
                setfillcolor(RED);
                fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
            }
            else if (state[i][j] == 4) {
                setfillcolor(BLUE);
                fillrectangle(i * len, j * len, (i + 1) * len, (j + 1) * len);
            }
        }
    }
}

// 宽字符版本的 HUD 显示
void showHUD() {
    wchar_t buf[64];
    swprintf(buf, 64, L"Bullets: %d   Enemies: %d", bullets, enemyCount);
    settextstyle(20, 0, _T("Consolas"));
    setbkmode(TRANSPARENT);
    outtextxy(10, 16, buf);
}

// ---------- 辅助函数 ----------
int plx() {
    for (int i = 1; i <= grid; i++)
        for (int j = 1; j <= grid; j++)
            if (state[i][j] == 3) return i;
    return -1;
}

int ply() {
    for (int i = 1; i <= grid; i++)
        for (int j = 1; j <= grid; j++)
            if (state[i][j] == 3) return j;
    return -1;
}

// ---------- 玩家移动 ----------
void move(char key) {
    int x = plx(), y = ply();
    int nx = x, ny = y;

    if (key == 'w') { ny--; dir = 0; }
    else if (key == 's') { ny++; dir = 1; }
    else if (key == 'a') { nx--; dir = 2; }
    else if (key == 'd') { nx++; dir = 3; }

    if (nx < 1 || nx > grid || ny < 1 || ny > grid) return;
    if (state[nx][ny] == 1) return;
    if (state[nx][ny] == 4) { gameOver = true; return; }

    // 先判断新位置是否为补给，再移动
    if (state[nx][ny] == 2) {
        bullets++;           // 捡起一颗子弹
        state[x][y] = 0;
        state[nx][ny] = 3;
    }
    else {
        state[x][y] = 0;
        state[nx][ny] = 3;
    }
}

// ---------- 射击（带子弹动画）----------
void shoot() {
    if (bullets <= 0) return;

    bullets--;
    int x = plx(), y = ply();
    int dx = 0, dy = 0;
    switch (dir) {
    case 0: dy = -1; break;
    case 1: dy = 1; break;
    case 2: dx = -1; break;
    case 3: dx = 1; break;
    }

    int cx = x + dx, cy = y + dy;
    while (cx >= 1 && cx <= grid && cy >= 1 && cy <= grid) {
        if (state[cx][cy] == 1) break;       // 撞墙

        // 绘制子弹（灰色小方块）
        setfillcolor(LIGHTGRAY);
        fillrectangle(cx * len + len / 4, cy * len + len / 4,
            cx * len + 3 * len / 4, cy * len + 3 * len / 4);
        Sleep(80);  // 动画延迟

        if (state[cx][cy] == 4) {            // 击中敌人
            state[cx][cy] = 0;
            enemyCount--;
            if (enemyCount <= 0) gameWin = true;
            break;
        }
        cx += dx;
        cy += dy;
    }
    // 重绘棋盘
    drawbk();
    drawtoken();
    showHUD();
}

// ---------- 敌人机械移动 ----------
void moveEnemies() {
    for (int i = 0; i < 2; i++) {
        int ex = enemies[i].x;
        int ey = enemies[i].y;
        int edir = enemies[i].moveDir;
        int eaxis = enemies[i].axis;

        int nex = ex, ney = ey;
        if (eaxis == 0) nex += edir;
        else            ney += edir;

        bool canMove = (nex >= 1 && nex <= grid && ney >= 1 && ney <= grid &&
            state[nex][ney] != 1);
        if (!canMove) {
            enemies[i].moveDir = -edir;
            continue;
        }
        if (state[nex][ney] == 3) {
            gameOver = true;
            return;
        }
        state[ex][ey] = 0;
        state[nex][ney] = 4;
        enemies[i].x = nex;
        enemies[i].y = ney;
    }
}

// ---------- 关卡初始化 ----------
void setup1() {
    for (int i = 1; i <= grid; i++)
        for (int j = 1; j <= grid; j++)
            state[i][j] = 0;

    state[1][1] = 3;          // 玩家
    state[5][9] = 2;          // 补给
    state[8][4] = 2;
    state[9][7] = 2;

    state[4][7] = 4;          // 敌人
    state[6][2] = 4;
    enemyCount = 2;

    enemies[0] = { 4, 7, 1, 0 }; // 敌人1：水平移动，先向右
    enemies[1] = { 6, 2, 1, 1 }; // 敌人2：垂直移动，先向下

    // 墙壁
    state[1][4] = 1; state[1][5] = 1; state[1][6] = 1;
    state[2][6] = 1;
    state[3][2] = 1; state[3][3] = 1; state[3][4] = 1;
    state[4][2] = 1; state[4][6] = 1; state[4][8] = 1; state[4][9] = 1;
    state[5][4] = 1; state[5][5] = 1; state[5][6] = 1; state[5][8] = 1;
    state[7][3] = 1; state[7][6] = 1; state[7][8] = 1; state[7][9] = 1;
    state[8][3] = 1; state[8][6] = 1;
    state[9][3] = 1; state[9][4] = 1; state[9][6] = 1; state[9][8] = 1;
    state[10][8] = 1;

    bullets = 0;  // 初始子弹为0
}

// ---------- 主函数 ----------
int main() {
    initgraph(12 * len, 12 * len);
    setup1();
    drawbk();
    drawtoken();
    showHUD();

    while (!gameOver && !gameWin) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd') {
                move(ch);
                if (gameOver) break;
                moveEnemies();
                drawbk();
                drawtoken();
                showHUD();
            }
            else if (ch == ' ') {
                shoot();
                if (gameWin) break;
                moveEnemies();
                drawbk();
                drawtoken();
                showHUD();
            }
        }
    }

    // 显示结局（宽字符串）
    cleardevice();
    settextstyle(48, 0, _T("SimHei"));
    setbkmode(TRANSPARENT);
    if (gameWin)
        outtextxy(240, 290, L"You Win!");
    else
        outtextxy(210, 290, L"Game Over!");

    _getch();
    closegraph();
    return 0;
}