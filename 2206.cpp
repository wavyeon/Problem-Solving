#include <iostream>
#include <queue>
#define MAX_SCOPE 1001
#define isVisited 1
#define notVisited 0
#define isBroken 1
#define notBroken 0
#define ALL_BROKEN 2
#define wall 1
#define road 0
#define ALL_DIR 4

using namespace std;

typedef struct {
    int x;
    int y;
    int step;
    int broken;
} coordinate;

int moveX[ALL_DIR] = {0, 1, 0, -1};
int moveY[ALL_DIR] = {-1, 0, 1, 0};

int n, m;
int map[MAX_SCOPE][MAX_SCOPE];
int visited[ALL_BROKEN][MAX_SCOPE][MAX_SCOPE] = {notVisited, };
int isArrived = 0;
queue<coordinate> q;

void init() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
}

void bfs() {
    while(!q.empty()) {
        coordinate cur = q.front();
        // cout << "위치: " << cur.x << cur.y << endl;
        q.pop();
        if(cur.x == m-1 && cur.y == n-1) {
            cout << cur.step << endl;
            isArrived = 1;
            break;
        }
        int nextX, nextY;
        coordinate next;
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = cur.x + moveX[i];
            nextY = cur.y + moveY[i];
            next.x = nextX;
            next.y = nextY;
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if(cur.broken == isBroken && map[nextY][nextX] == road && visited[isBroken][nextY][nextX] == notVisited) {
                    next.broken = isBroken;
                    visited[isBroken][nextY][nextX] = isVisited;
                    next.step = cur.step + 1;
                    q.push(next);
                }
                else if(cur.broken == notBroken) {
                    if(map[nextY][nextX] == road && visited[notBroken][nextY][nextX] == notVisited) {
                        next.broken = notBroken;
                        visited[notBroken][nextY][nextX] = isVisited;
                        next.step = cur.step + 1;
                        q.push(next);
                    }
                    else if(map[nextY][nextX] == wall && visited[isBroken][nextY][nextX] == notVisited) {
                        next.broken = isBroken;
                        visited[isBroken][nextY][nextX] = isVisited;
                        next.step = cur.step + 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    if(isArrived == 0) {
        cout << -1 << endl;
    }
}
void solve() {
    coordinate start;
    start.x = 0;
    start.y = 0;
    start.step = 1;
    start.broken = notBroken;
    q.push(start);
    visited[notBroken][0][0] = isVisited;
    bfs();
}

int main() {
    init();
    solve();

}