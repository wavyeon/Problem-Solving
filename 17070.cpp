#include <iostream>

using namespace std;

int n, cnt;
int house[17][17];
int dx[3] = {1,1,0};
int dy[3] = {0,1,1};

typedef struct {
    int x;
    int y;
} coo;


void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }
}

bool isMovable(coo target) { // 집의 범위 벗어나지 않는지, 벽이 아닌지 체크
    int x = target.x;
    int y = target.y;
    if(x > 0 && x <= n && y > 0 && y <= n) {
        if(!house[y][x]) {
            return true;
        }
    }
    return false;
}

void dfs(coo tail, coo head, int dir) {
    if(head.x == n && head.y == n) {
        cnt++;
        return;
    }

    coo headRight = {head.x+1, head.y};
    coo headRightDown = {head.x+1, head.y+1};
    coo headDown = {head.x, head.y+1};

    switch(dir) {
        case 0: // 가로로 놓여진 경우
            if(isMovable(headRight)) { // 오른쪽으로 밀 수 있는지
                dfs(head, headRight, 0);
                if(isMovable(headDown) && isMovable(headRightDown)) { // 오른쪽으로 밀고 시계방향으로 돌릴 수 있는지
                    dfs(head, headRightDown, 1);
                }
            }
            break;
        case 1: // 대각선으로 놓여진 경우
            if(isMovable(headRight)) { // 대각선으로 밀고 반시계방향으로 돌릴 수 있는지
                dfs(head, headRight, 0);
            }            
            if(isMovable(headDown)) { // 대각선으로 밀고 시계방향으로 돌릴 수 있는지
                dfs(head, headDown, 2);
            }
            if(isMovable(headRightDown) && isMovable(headRight) && isMovable(headDown)) { // 대각선으로 밀 수 있는지
                dfs(head, headRightDown, 1);
            }
            break;
        case 2: // 세로로 놓여진 경우
            if(isMovable(headDown)) { // 아래로 밀 수 있는 지
                dfs(head, headDown, 2);
                if(isMovable(headRight) && isMovable(headRightDown)) { // 아래로 밀고 반시계방향으로 돌릴 수 있는지
                    dfs(head, headRightDown, 1);                    
                }
            }
    }
}

void solve() {
    coo startTail = {1,1};
    coo startHead = {2,1};
    dfs(startTail, startHead, 0);
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}