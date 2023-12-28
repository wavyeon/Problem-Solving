#include <iostream> 
using namespace std;

int n, m, startX, startY, nextX, nextY, lookingDir;
int cnt = 1;
int map[51][51];
bool stop = false;
bool movable[51][51];
int dirSelect[4] = {0, 3, 2, 1}; // modular 연산 이용
int oppdX[4] = {0,-1,0,1};
int oppdY[4] = {1,0,-1,0};

// int dX[4][4] = {
//     {0,-1,0,1},
//     {1,0,-1,0},
//     {0,1,0,-1},
//     {-1,0,1,0}
// };

int dx[4] = {0,1,0,-1};

// int dY[4][4] = {
//     {-1,0,1,0},
//     {0,-1,0,1},
//     {1,0,-1,0},
//     {0,1,0,-1}
// };

int dy[4] = {-1,0,1,0};

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> startY >> startX >> lookingDir;
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
}

void solve() {
    do {
        movable[startY][startX] = 0;
        bool noWay = true;
        for(int i = 0; i < 4; i++) {
            int searchDir = (3 - i + lookingDir) % 4; // 바라보는 방향 기준 왼쪽부터 반시계 방향으로 
            // nextX = startX + dX[(lookingDir + 3) % 4][i]; // dx와 dy는 탐색을 시작하는 방향(0,1,2,3)부터 반시계방향으로 이루어짐
            // nextY = startY + dY[(lookingDir + 3) % 4][i]; // 이 방법 버림
            nextX = startX + dx[searchDir]; // dx와 dy를 각 방향마다 설정해주고 searchDir으로 dx와 dy값 결정
            nextY = startY + dy[searchDir]; // 이 방법 사용
            if(movable[nextY][nextX] == 1) {
                movable[nextY][nextX] = 0;
                startX = nextX;
                startY = nextY;
                noWay = false;
                cnt++;
                lookingDir = searchDir;
                break;
            }
        }
        if(noWay) { // 사방에 갈 곳 없음
            startX = startX + oppdX[lookingDir];
            startY = startY + oppdY[lookingDir];
            if(map[startY][startX] == 1) { // 후진도 못함
                stop = true;
            }
        }
    } while(!stop);
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}