#include <iostream>
#include <queue>
#define MAX 11

using namespace std;

typedef struct {
    int x;
    int y;
} coo;

typedef struct {
    coo r; // 현재 빨간 구슬 좌표
    coo b; // 현재 파란 구슬 좌표
} situ;

int n, m;
char maze[MAX][MAX];
coo red, blue;
queue<pair<int, situ>> q; // 구슬 움직인 횟수, 현재 구슬 위치

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &maze[i][j]);
            if(maze[i][j] == 'R') {
                red.x = j;
                red.y = i;
                maze[i][j] = '.';
            }
            else if(maze[i][j] == 'B') {
                blue.x = j;
                blue.y = i;
                maze[i][j] = '.';
            }
        }
    }
}

void leanLeft(int cnt, coo curRed, coo curBlue) {
    int* moreRight = curRed.x > curBlue.x ? &curRed.x : &curBlue.x;
    bool redInHole = false;
    bool blueInHole = false;
    while(maze[curRed.y][curRed.x-1] != '#') {
        curRed.x--;
        if(maze[curRed.y][curRed.x] == 'O') { // 빨간 구슬 구멍에 빠짐
            redInHole = true;
            break;
        }
    }
    while(maze[curBlue.y][curBlue.x-1] != '#') {
        curBlue.x--;
        if(maze[curBlue.y][curBlue.x] == 'O') { // 파란 구슬 구멍에 빠짐
            blueInHole = true;
            break;
        }
    }
    if(blueInHole) { // 파란 구슬 구멍에 빠졌으면 빨간 구슬만 빼내는 것에 실패한 경우 -> 더 이상 따질 이유 없음
        return;
    }
    else {
        if(redInHole) { // 빨간 구슬만 구멍에 빠짐 -> 몇 번만인지 출력하고 프로그램 종료
            cout << cnt + 1 << endl;
            exit(0);
        }
        else { // 두 구슬 모두 구멍에 빠지지 않음 -> 현재 상태 queue에 넣고 계속 따져봐야함
            if(curRed.x == curBlue.x && curRed.y == curBlue.y) { // 두 구슬이 한 줄에 있다가 부딪히게 되는 경우
                // 더 오른쪽에 있던 구슬이 한 칸 오른쪽으로 가야함 (구슬 위치는 겹칠 수 없으므로)
                *moreRight += 1;
            }
            q.push({cnt+1, {curRed, curBlue}});
        }
    }
}

void leanRight(int cnt, coo curRed, coo curBlue) {
    int* moreLeft = curRed.x < curBlue.x ? &curRed.x : &curBlue.x;
    bool redInHole = false;
    bool blueInHole = false;
    while(maze[curRed.y][curRed.x+1] != '#') {
        curRed.x++;
        if(maze[curRed.y][curRed.x] == 'O') { // 빨간 구슬 구멍에 빠짐
            redInHole = true;
            break;
        }
    }
    while(maze[curBlue.y][curBlue.x+1] != '#') {
        curBlue.x++;
        if(maze[curBlue.y][curBlue.x] == 'O') { // 파란 구슬 구멍에 빠짐
            blueInHole = true;
            break;
        }
    }
    if(blueInHole) { // 파란 구슬 구멍에 빠졌으면 빨간 구슬만 빼내는 것에 실패한 경우 -> 더 이상 따질 이유 없음
        return;
    }
    else {
        if(redInHole) { // 빨간 구슬만 구멍에 빠짐 -> 몇 번만인지 출력하고 프로그램 종료
            cout << cnt + 1 << endl;
            exit(0);
        }
        else { // 두 구슬 모두 구멍에 빠지지 않음 -> 현재 상태 queue에 넣고 계속 따져봐야함
            if(curRed.x == curBlue.x && curRed.y == curBlue.y) { // 두 구슬이 한 줄에 있다가 부딪히게 되는 경우
                // 더 왼쪽에 있던 구슬이 한 칸 왼쪽으로 가야함 (구슬 위치는 겹칠 수 없으므로)
                *moreLeft -= 1;
            }
            q.push({cnt+1, {curRed, curBlue}});
        }
    }
}

void leanUp(int cnt, coo curRed, coo curBlue) {
    int* moreDown = curRed.y > curBlue.y ? &curRed.y : &curBlue.y;
    bool redInHole = false;
    bool blueInHole = false;
    while(maze[curRed.y-1][curRed.x] != '#') {
        curRed.y--;
        if(maze[curRed.y][curRed.x] == 'O') { // 빨간 구슬 구멍에 빠짐
            redInHole = true;
            break;
        }
    }
    while(maze[curBlue.y-1][curBlue.x] != '#') {
        curBlue.y--;
        if(maze[curBlue.y][curBlue.x] == 'O') { // 파란 구슬 구멍에 빠짐
            blueInHole = true;
            break;
        }
    }
    if(blueInHole) { // 파란 구슬 구멍에 빠졌으면 빨간 구슬만 빼내는 것에 실패한 경우 -> 더 이상 따질 이유 없음
        return;
    }
    else {
        if(redInHole) { // 빨간 구슬만 구멍에 빠짐 -> 몇 번만인지 출력하고 프로그램 종료
            cout << cnt + 1 << endl;
            exit(0);
        }
        else { // 두 구슬 모두 구멍에 빠지지 않음 -> 현재 상태 queue에 넣고 계속 따져봐야함
            if(curRed.x == curBlue.x && curRed.y == curBlue.y) { // 두 구슬이 한 줄에 있다가 부딪히게 되는 경우
                // 더 아래쪽에 있던 구슬이 한 칸 아래쪽으로 가야함 (구슬 위치는 겹칠 수 없으므로)
                *moreDown += 1;
            }
            q.push({cnt+1, {curRed, curBlue}});
        }
    }
}

void leanDown(int cnt, coo curRed, coo curBlue) {
    int* moreUp = curRed.y < curBlue.y ? &curRed.y : &curBlue.y;
    bool redInHole = false;
    bool blueInHole = false;
    while(maze[curRed.y+1][curRed.x] != '#') {
        curRed.y++;
        if(maze[curRed.y][curRed.x] == 'O') { // 빨간 구슬 구멍에 빠짐
            redInHole = true;
            break;
        }
    }
    while(maze[curBlue.y+1][curBlue.x] != '#') {
        curBlue.y++;
        if(maze[curBlue.y][curBlue.x] == 'O') { // 파란 구슬 구멍에 빠짐
            blueInHole = true;
            break;
        }
    }
    if(blueInHole) { // 파란 구슬 구멍에 빠졌으면 빨간 구슬만 빼내는 것에 실패한 경우 -> 더 이상 따질 이유 없음
        return;
    }
    else {
        if(redInHole) { // 빨간 구슬만 구멍에 빠짐 -> 몇 번만인지 출력하고 프로그램 종료
            cout << cnt + 1 << endl;
            exit(0);
        }
        else { // 두 구슬 모두 구멍에 빠지지 않음 -> 현재 상태 queue에 넣고 계속 따져봐야함
            if(curRed.x == curBlue.x && curRed.y == curBlue.y) { // 두 구슬이 한 줄에 있다가 부딪히게 되는 경우
                // 더 아래쪽에 있던 구슬이 한 칸 아래쪽으로 가야함 (구슬 위치는 겹칠 수 없으므로)
                *moreUp -= 1;
            }
            q.push({cnt+1, {curRed, curBlue}});
        }
    }
}

void bfs() {
    q.push({0,{red, blue}});
    while(!q.empty()) {
        int cnt = q.front().first;
        coo curRed = q.front().second.r;
        coo curBlue = q.front().second.b;
        q.pop();
        if(cnt == 10) { // 종료조건
            cout << -1 << endl;
            exit(0);
        }
        leanLeft(cnt, curRed, curBlue);
        leanRight(cnt, curRed, curBlue);
        leanUp(cnt, curRed, curBlue);
        leanDown(cnt, curRed, curBlue);
    }
}

void solve() {
    bfs();
}

int main() {
    input();
    solve();
}