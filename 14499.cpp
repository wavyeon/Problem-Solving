#include <iostream>
#include <vector>

using namespace std;

const int MAX = 21;
int n, m, x, y, inst;
int map[MAX][MAX];

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
// int dice[6]; // 0: 위 1: 북 2: 동 3: 남 4: 서 5: 아래
vector<int> dice(6, 0);

void init() {
    scanf("%d %d %d %d %d", &n, &m, &y, &x, &inst);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }  
}

bool isPossible(int nextX, int nextY) {
    if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
        return false;
    }
    return true;
}

// 0:위 1:북 2:동 3:남 4:서 5:아래
void rollNorth() {
    dice = {dice[3], dice[0], dice[2], dice[5], dice[4], dice[1]};
}

void rollEast() {
    dice = {dice[4], dice[1], dice[0], dice[3], dice[5], dice[2]};
}

void rollSouth() {
    dice = {dice[1], dice[5], dice[2], dice[0], dice[4], dice[3]};
}

void rollWest() {
    dice = {dice[2], dice[1], dice[5], dice[3], dice[0], dice[4]};
}

void copypaste() {
    if(map[y][x] == 0) {
        map[y][x] = dice[5];
    }
    else {
        dice[5] = map[y][x];
        map[y][x] = 0;
    }
}

void moveDice(int dir) {
    int nextX = x + dx[dir];
    int nextY = y + dy[dir];
    if(isPossible(nextX, nextY)) {
        switch(dir) {
            case 1:
                rollEast();
                break;
            case 2:
                rollWest();
                break;
            case 3:
                rollNorth();
                break;
            case 4:
                rollSouth();
        }
        x = nextX;
        y = nextY;
        copypaste();
        printf("%d\n", dice[0]);
    }
    
}

void solve() {
    int dir;
    for(int i = 0; i < inst; i++) {
        scanf("%d", &dir);
        moveDice(dir);
    }
}

int main() {
    init();
    solve();
}