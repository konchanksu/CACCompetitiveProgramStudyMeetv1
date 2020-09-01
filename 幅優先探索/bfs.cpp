#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define MAX_X 50
#define MAX_Y 50

int R, C;  // 迷路のサイズ
int sy, sx, gy, gx;  // スタートの座標, ゴールの座標
char mazeMap[MAX_Y][MAX_X];  // 迷路

bool maze[MAX_Y][MAX_X];
queue<vector<int>> que;
vector<int> tmp;

int nextY, nextX;

int main()
{
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;

    for(int i = 0; i < R; i++)
    {
        scanf("%s", mazeMap[i]);
    }

    for(int i = 0; i < R; i++) { for(int j = 0; j < C; j++) { maze[i][j] = true; } }

    tmp.push_back(sy - 1);
    tmp.push_back(sx - 1);
    tmp.push_back(0);
    que.push(tmp);
    maze[sy - 1][sx - 1] = false;
    gy--, gx--;

    while(true)
    {
        tmp = que.front();
        que.pop();

        if(tmp[0] == gy && tmp[1] == gx)
        {
            cout << tmp[2] << endl;
            break;
        }

        for(int y = -1; y <= 1; y++)
        {
            for(int x = -1; x <= 1; x++)
            {
                if(abs(x) + abs(y) != 1) continue;

                nextY = y + tmp[0], nextX = x + tmp[1];

                if(maze[nextY][nextX] && mazeMap[nextY][nextX] == '.')
                {
                    vector<int> t = {nextY, nextX, tmp[2] + 1};
                    maze[nextY][nextX] = false;
                    que.push(t);
                }
            }
        }
    }

    return 0;
}
