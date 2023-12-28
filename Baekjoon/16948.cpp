#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 201

using namespace std;

typedef struct {
    int x;
    int y;
    int count;
} step;

int siz, startX, startY, arriveX, arriveY;
queue<step> q;
bool isVisited[MAX][MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> siz;
    cin >> startX >> startY >> arriveX >> arriveY;
}

void solve() {
    step start = {startX, startY, 0};
    isVisited[startY][startX] == true;
    q.push(start);
    while(!q.empty()) {
        step cur = q.front();
        q.pop();
        int curX = cur.x;
        int curY = cur.y;
        int curCount = cur.count;
        if(curX == arriveX && curY == arriveY) {
            cout << cur.count << endl;
            return;
        }
        if(curX - 2 >= 0 && curY - 1 >= 0) {
            if(isVisited[curY-1][curX-2] == false) {
                step next = {curX-2, curY-1, curCount+1};
                isVisited[curY-1][curX-2] = true;
                q.push(next);
            }
        }
        if(curX - 2 >= 0 && curY + 1 < siz) {
            if(isVisited[curY+1][curX-2] == false) {
                step next = {curX-2, curY+1, curCount+1};
                isVisited[curY+1][curX-2] = true;
                q.push(next);
            }
        }
        if(curX >= 0 && curY - 2 >= 0) {
            if(isVisited[curY-2][curX] == false) {
                step next = {curX, curY-2, curCount+1};
                isVisited[curY-2][curX] = true;
                q.push(next);
            }
        }
        if(curX >= 0 && curY + 2 < siz) {
            if(isVisited[curY+2][curX] == false) {
                step next = {curX, curY+2, curCount+1};
                isVisited[curY+2][curX] = true;
                q.push(next);
            }
        }
        if(curX + 2 < siz && curY - 1 >= 0) {
            if(isVisited[curY-1][curX+2] == false) {
                step next = {curX+2, curY-1, curCount+1};
                isVisited[curY-1][curX+2] = true;
                q.push(next);
            }
        }
        if(curX + 2 < siz && curY + 1 < siz) {
            if(isVisited[curY+1][curX+2] == false) {
                step next = {curX+2, curY+1, curCount+1};
                isVisited[curY+1][curX+2] = true;
                q.push(next);
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    init();
    solve();
}