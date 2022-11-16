#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define ALL_DIR 4
#define endl '\n'

using namespace std;

int n, m;
vector<int> zeroIndex(1);
int map[MAX][MAX];
int zeroMap[MAX][MAX];
int answer[MAX][MAX];

int dx[ALL_DIR] = {0, 1, 0, -1};
int dy[ALL_DIR] = {-1, 0, 1, 0};

typedef struct {
    int x;
    int y;
} coo;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
}

void zeroBfs(int i, int j, int idx) {
    int count = 1;
    queue<coo> q;
    coo start = {j, i};
    q.push(start);
    zeroMap[i][j] = idx;
    while(!q.empty()) {
        coo cur = q.front();
        q.pop();
        for(int i = 0; i < ALL_DIR; i++) {
            int nextX = cur.x + dx[i];
            int nextY = cur.y + dy[i];
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if(map[nextY][nextX] == 0 && zeroMap[nextY][nextX] == 0) {
                    coo next = {nextX, nextY};
                    q.push(next);
                    count++;
                    zeroMap[nextY][nextX] = idx;
                }
            }
        }
    }
    zeroIndex.push_back(count);
}

void classifyZero() {
    int idx = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0 && zeroMap[i][j] == 0) {
                zeroBfs(i, j, idx);
                idx++;
            }
        }
    }
}

int countMovable(int i, int j) {
    bool idxCheck[zeroIndex.size()] = {false, };
    int count = 1;
    for(int k = 0; k < ALL_DIR; k++) {
        int adjacentX = j + dx[k];
        int adjacentY = i + dy[k];
        if(map[adjacentY][adjacentX] == 0 && idxCheck[zeroMap[adjacentY][adjacentX]] == false) {
            count += zeroIndex[zeroMap[adjacentY][adjacentX]];
            count %= 10;
            idxCheck[zeroMap[adjacentY][adjacentX]] = true;
        }
    }
    return count;
}

void solve() {
    classifyZero();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 1) {
                answer[i][j] = countMovable(i, j);
            }
            else {
                answer[i][j] = 0;
            }
        }
    }
}

void output() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << answer[i][j];
        }
        cout << endl;
    }
}

int main() {
    input();
    solve();
    output();
}