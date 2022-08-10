#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cstdlib>

#define MAX_SCOPE 101
#define ALL_DIR 4
#define isVisited 1
#define notVisited 0

using namespace std;

typedef struct {
    int x;
    int y;
    int step;
} coordinate;

int XDir[ALL_DIR] = {0,1,0,-1};
int YDir[ALL_DIR] = {-1,0,1,0};
int maze[MAX_SCOPE][MAX_SCOPE];
int visited[MAX_SCOPE][MAX_SCOPE];
queue<coordinate> q;

void init(int N, int M) {
    string line;
    char cline[MAX_SCOPE];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
}

void bfs(int N, int M) {
    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();
        if(cur.x == M-1 && cur.y == N-1) {
            cout << cur.step << endl;
            break;
        }
        coordinate next;
        int nextX, nextY, nextStep;
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = cur.x + XDir[i];
            nextY = cur.y + YDir[i];
            nextStep = cur.step + 1;
            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && maze[nextY][nextX] == 1 && visited[nextY][nextX] == notVisited) {
                next.x = nextX;
                next.y = nextY;
                next.step = nextStep;
                visited[next.y][next.x] = isVisited;
                q.push(next);
            }
        } 
    }
}

void solve(int N, int M) {
    coordinate start;
    start.x = 0;
    start.y = 0;
    start.step = 1;
    visited[start.y][start.x] = isVisited;
    q.push(start);
    bfs(N, M);
}

int main() {
    int N, M;
    cin >> N >> M;
    init(N, M);
    solve(N, M);
}