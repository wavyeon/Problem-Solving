#include <iostream> 
using namespace std;

int n, m, startX, startY, nextX, nextY, dir, dirValue, tmp;
int cnt = 1;
int map[51][51];
bool stop = false;
bool movable[51][51];
int dirSelect[4] = {0, 3, 2, 1}; // modular 연산으로 나타낼 수 있을 것 같음
int oppdX[4] = {0,1,0,-1};
int oppdY[4] = {1,0,-1,0};

int dX[4][4] = {
    {0,-1,0,1},
    {1,0,-1,0},
    {0,1,0,-1},
    {-1,0,1,0}
};

int dY[4][4] = {
    {-1,0,1,0},
    {0,-1,0,1},
    {1,0,-1,0},
    {0,1,0,-1}
};

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> startY >> startX >> dir;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            movable[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                movable[i][j] = 0;
            } 
        }
    }
    cout << "movable" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << movable[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    do {
        cout << "시작: " << startY << " " << startX << " " << dir << endl;
        movable[startY][startX] = 0;
        bool goBack = true;
        for(int i = 0; i < 4; i++) {
            nextX = startX + dX[dir][i];
            nextY = startY + dY[dir][i];
            dir = dirSelect[(dir + i) % 4];
            cout << "탐색: " << nextY << " " << nextX << " " << dir << " " << movable[nextY][nextX] << endl;
            if(movable[nextY][nextX] == 1) {
                cout << "발견!" << endl;
                movable[nextY][nextX] = 0;
                startX = nextX;
                startY = nextY;
                goBack = false;
                cnt++;
                break;
            }
        }
        if(goBack) { // 사방에 갈 곳 없음
            startX = startX + oppdX[dir];
            startY = startY + oppdY[dir];
            if(map[startY][startX] == 1) { // 후진도 못함
                stop = true;
            }
        }
        if(tmp == 4) {
            break;
        }
        tmp++;
        cout << "movable" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << movable[i][j] << " ";
            }
            cout << endl;
        }
    } while(!stop);
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}