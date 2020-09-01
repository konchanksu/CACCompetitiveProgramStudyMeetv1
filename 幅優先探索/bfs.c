/**
 * 競技プログラミング勉強会用のコード
 * ABC007 C 幅優先探索
 * C言語 解答例
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_X 50
#define MAX_Y 50
#define QUEUE_MAX 50

int R, C;  // 迷路のサイズ
int sy, sx, gy, gx;  // スタートの座標, ゴールの座標
char mazeMap[MAX_Y][MAX_X];  // 迷路

/* キュー */
int queue[QUEUE_MAX][3];
int bottom = 0, top = 0;

void enqueue(int y, int x, int times)
{
	queue[bottom][0] = y; queue[bottom][1] = x; queue[bottom][2] = times;
    bottom--;
	if(bottom == -1) bottom = QUEUE_MAX - 1;
}

int isAlwaysArrived[MAX_Y][MAX_X];  // すでにたどり着いたか

void makeIsAlwaysArrived(void);  // isAlwaysArrivedの初期化
void solve(void);  // 幅優先探索

int main(void)
{
    /* 入力 */
    scanf("%d %d", &R, &C);
    scanf("%d %d", &sy, &sx);
    sy--, sx--;

    scanf("%d %d", &gy, &gx);
    gy--, gx--;

    for(int i = 0; i < R; i++)
    {
        scanf("%s", mazeMap[i]);
    }

    makeIsAlwaysArrived();

    // キューにスタート地点を追加する
    enqueue(sy, sx, 0);

    solve();  // 幅優先探索

    return 0;
}

/* isAlwaysArrivedの初期化 */
void makeIsAlwaysArrived()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(i == sy && j == sx) isAlwaysArrived[i][j] = true;
            else isAlwaysArrived[i][j] = false;
        }
    }
}

/* 幅優先探索 */
void solve()
{
    int popY, popX, times;  // 取り出してきた座標と移動距離
    int nextY, nextX;  // 次に移動する座標

    while(true)
    {
        popY = queue[top][0];
        popX = queue[top][1];
        times = queue[top][2];
        top--;
        if(top < 0) top = QUEUE_MAX - 1;

        // もしゴールならば
        if(popY == gy && popX == gx)
        {
            printf("%d\n", times);
            break;
        }

        // 移動できる4方向の確認
        for(int x = -1; x <= 1; x++)
        {
            for(int y = -1; y <= 1; y++)
            {
                if(abs(x) + abs(y) != 1) continue;  // 2重ループで発生する余計な移動をしない

                nextY = popY + y, nextX = popX + x;

                // 範囲外に出ない
                if(nextY < 0 || nextY >= R || nextX < 0 || nextX >= C) continue;

                // まだ行ったことのない道であれば
                if(!isAlwaysArrived[nextY][nextX] && mazeMap[nextY][nextX] == '.')
                {
                    // キューに追加
                    enqueue(nextY, nextX, times + 1);
                    // 到達した
                    isAlwaysArrived[nextY][nextX] = true;
                }
            }
        }
    }
}
