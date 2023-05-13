#include <iostream>
#include <queue>
#define MAX 11

using namespace std;

typedef struct {
    int x;
    int y;
} coo;

typedef struct {
    coo r; // 현재 빨간 구슬 좌표
    coo b; // 현재 파란 구슬 좌표
} situ;

int n, m;
char maze[MAX][MAX];
coo red, blue;
queue<int, situ> q; // 구슬 움직인 횟수, 현재 구슬 위치

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &maze[i][j]);
            if(maze[i][j] == 'R') {
                red.x = j;
                red.y = i;
            }
            else if(maze[i][j] == 'B') {
                blue.x = j;
                blue.y = i;
            }
        }
    }
}

void bfs() {
    q.push({0,{red, blue}});
    while(!q.empty()) {
        int cnt = q.front().first;
        coo curRed = q.front().second.r;
        coo curBlue = q.front().second.b;
        q.pop();
        
    }
}

void solve() {
    bfs();
}

int main() {
    input();
    solve();
}