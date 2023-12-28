#include <iostream>
#include <queue>
#define MAX_SCOPE 1001
#define isVisited 1
#define notVisited 0
#define notBroken 0
#define ALL_BROKEN 11
#define wall 1
#define road 0
#define ALL_DIR 4
#define day 0
#define night 1

using namespace std;

typedef struct {
    int x;
    int y;
    int step;
    int brokenCount;
    int time;
} coordinate;

int moveX[ALL_DIR] = {0, 1, 0, -1};
int moveY[ALL_DIR] = {-1, 0, 1, 0};

int n, m, maxBreak;
int map[MAX_SCOPE][MAX_SCOPE];
int visited[ALL_BROKEN][MAX_SCOPE][MAX_SCOPE] = {notVisited, };
queue<coordinate> q;

void init() {
    cin >> n >> m >> maxBreak;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
}

void bfs() {
    coordinate start = {0, 0, 1, notBroken, 0};
    q.push(start);
    visited[notBroken][0][0] = isVisited;
    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();
        if(cur.x == m-1 && cur.y == n-1) {
            cout << cur.step << endl;
            return;
        }
        int nextX, nextY;
        coordinate next;
        if(cur.time % 2 == night) { // 제자리에 있는 걸 고려해보는 경우
            for(int i = 0; i < ALL_DIR; i++) {
                nextX = cur.x + moveX[i];
                nextY = cur.y + moveY[i];
                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                    if(cur.brokenCount != maxBreak && map[nextY][nextX] == wall && visited[cur.brokenCount+1][nextY][nextX] == notVisited) { //제자리에 있어봐야 함
                        next.x = cur.x;
                        next.y = cur.y;
                        next.step = cur.step + 1;
                        next.brokenCount = cur.brokenCount;
                        next.time = cur.time + 1;
                        q.push(next);
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = cur.x + moveX[i];
            nextY = cur.y + moveY[i];
            next.x = nextX;
            next.y = nextY;
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if(cur.brokenCount == maxBreak && map[nextY][nextX] == road && visited[maxBreak][nextY][nextX] == notVisited) {
                    next.brokenCount = cur.brokenCount;
                    visited[maxBreak][nextY][nextX] = isVisited;
                    next.step = cur.step + 1;
                    next.time = cur.time + 1;
                    q.push(next);
                }
                else if(cur.brokenCount != maxBreak) {
                    if(map[nextY][nextX] == road && visited[cur.brokenCount][nextY][nextX] == notVisited) {
                        next.brokenCount = cur.brokenCount;
                        visited[next.brokenCount][nextY][nextX] = isVisited;
                        next.step = cur.step + 1;
                        next.time = cur.time + 1;
                        q.push(next);
                    }
                    else if(map[nextY][nextX] == wall && visited[cur.brokenCount+1][nextY][nextX] == notVisited && cur.time % 2 == day) {
                        next.brokenCount = cur.brokenCount + 1;
                        visited[next.brokenCount][nextY][nextX] = isVisited;
                        next.step = cur.step + 1;
                        next.time = cur.time + 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}
void solve() {
    bfs();
}

int main() {
    init();
    solve();
}