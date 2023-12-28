#include <iostream>
#include <queue>
#define isVisited 1
#define notVisited 0

using namespace std;

typedef struct {
    int index;
    int step;
} space;

int game[10][10];
int visited[101];
queue<space> q;

void init(int ladder, int snake) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            game[i][j] = 10*i + j + 1;
        }
    }
    int index, ladderTo, snakeTo;
    for(int i = 0; i < ladder; i++) {
        cin >> index >> ladderTo;
        game[(index-1)/10][(index-1)%10] = ladderTo;
    }
    for(int j = 0; j < snake; j++) {
        cin >> index >> snakeTo;
        game[(index-1)/10][(index-1)%10] = snakeTo;
    }
}

void bfs() {
    space front;
    while(!q.empty()) {
        front = q.front();
        q.pop();
        if(front.index == 100) {
            cout << front.step << endl;
            break;
        }
        for(int i = 1; i <= 6; i++) {
            if(visited[front.index-1 + i] == notVisited) {
                space next;
                int nextIndex = front.index - 1 + i;
                next.index = game[nextIndex / 10][nextIndex % 10];
                next.step = front.step + 1;
                q.push(next);
                visited[front.index - 1 + i] = isVisited;
            }
            
        }
    }
}

void solve() {
    space start;
    start.index = 1;
    start.step = 0;
    visited[start.index - 1] = isVisited;
    q.push(start);
    bfs();
}


int main() {
    int ladder, snake;
    cin >> ladder >> snake;
    init(ladder, snake);
    solve();
}