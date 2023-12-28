#include <iostream>
#include <queue>
#define visited 1
#define notVisited 0

using namespace std;

const int MAX = 101;
int maze[MAX][MAX];
int isVisited[MAX][MAX];
int M, N, x, y, breakCount;
priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void init() {
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }
}

void pushIfVisitable(int count, int x, int y) {
    if(isVisited[y][x] == notVisited && x >= 0 && x < M && y >= 0 && y < N) {
        isVisited[y][x] = visited;
        if(maze[y][x] == 1) {
            pq.push(make_pair(count+1, make_pair(x, y)));
        }
        else if(maze[y][x] == 0) {
            pq.push(make_pair(count, make_pair(x, y)));
        }
    }
}

void solve() {
    pq.push(make_pair(0, make_pair(0,0)));
    isVisited[0][0] = visited;
    while(!pq.empty()) {
        breakCount = pq.top().first;
        x = pq.top().second.first;
        y = pq.top().second.second;
        pq.pop();
        if(x == M-1 && y == N-1) {
            printf("%d\n", breakCount);
            break;
        }
        for(int i = 0; i < 4; i++) {
            pushIfVisitable(breakCount, x+dx[i], y+dy[i]);
        }
    }
}

int main() {
    init();
    solve();
}