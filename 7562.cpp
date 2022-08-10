#include <iostream>
#include <queue>
#include <vector>
#define MAX_SCOPE 301
#define isVisited 1
#define notVisited 0
#define ALL_DIR 8

using namespace std;

typedef struct {
    int x;
    int y;
    int step;
} coordinate;

int moveX[ALL_DIR] = {-2, -1, 1, 2, 2, 1, -1, -2};
int moveY[ALL_DIR] = {1, 2, 2, 1, -1, -2, -2, -1};
int visited[MAX_SCOPE][MAX_SCOPE];
queue<coordinate> q;
vector<int> output;

void init() {
    for(int i = 0; i < MAX_SCOPE; i++) {
        for(int j = 0; j < MAX_SCOPE; j++) {
            visited[j][i] = notVisited;
        }
    }
    while(!q.empty()) {
        q.pop();
    }

}

void bfs(coordinate finish, int side) {
    while(!q.empty()) {
        coordinate cur;
        cur = q.front();
        q.pop();
        if(cur.x == finish.x && cur.y == finish.y) {
            output.push_back(cur.step);
            break;
        }
        coordinate next;
        int nextX, nextY;
        for(int i = 0; i < ALL_DIR; i++) {
            nextX = cur.x + moveX[i];
            nextY = cur.y + moveY[i];
            if(nextX >= 0 && nextX < side && nextY >= 0 && nextY < side && visited[nextY][nextX] == notVisited) {
                next.x = nextX;
                next.y = nextY;
                next.step = cur.step + 1;
                q.push(next);
                visited[next.y][next.x] = isVisited;
            }
        }
    }
}

void solve(int side) {
    init();
    int startX, startY, finishX, finishY;
    cin >> startX >> startY >> finishX >> finishY;
    coordinate start, finish;
    start.x = startX;
    start.y = startY;
    start.step = 0;
    q.push(start);
    visited[start.y][start.x] = isVisited;
    finish.x = finishX;
    finish.y = finishY; 
    bfs(finish, side);
}

int main() {
    int testCase;
    cin >> testCase;
    int side;
    while(testCase--) {
        cin >> side;
        solve(side);
    }
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}