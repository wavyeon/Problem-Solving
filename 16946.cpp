#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define MAX 1001
#define ALL_DIR 4
#define endl '\n'

using namespace std;

int n, m;
vector<int> areaSize(1);
int map[MAX][MAX];
int areaNum[MAX][MAX];
int answer[MAX][MAX];
bool visited[MAX][MAX];
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
    areaNum[i][j] = idx;
    visited[i][j] = true;
    while(!q.empty()) {
        coo cur = q.front();
        q.pop();
        for(int k = 0; k < ALL_DIR; k++) {
            int nextX = cur.x + dx[k];
            int nextY = cur.y + dy[k];
            if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if(map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
                    coo next = {nextX, nextY};
                    q.push(next);
                    count++;
                    areaNum[nextY][nextX] = idx;
                    visited[nextY][nextX] = true;
                }
            }
        }
    }
    areaSize.push_back(count);
}

void classifyZero() {
    int idx = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0 && visited[i][j] == false) {
                zeroBfs(i, j, idx);
                idx++;
            }
        }
    }
}

int countMovable(int i, int j) {
    set<int> visitedArea;
    int count = 1;
    for(int k = 0; k < ALL_DIR; k++) {
        int adjacentX = j + dx[k];
        int adjacentY = i + dy[k];
        if(adjacentX >= 0 && adjacentX < m && adjacentY >= 0 && adjacentY < n) {
            if(map[adjacentY][adjacentX] == 0) {
                if(visitedArea.find(areaNum[adjacentY][adjacentX]) == visitedArea.end())  {// visited에서 못찾았음 == 방문한 적 없음
                    count += areaSize[areaNum[adjacentY][adjacentX]];
                    count %= 10;
                    visitedArea.insert(areaNum[adjacentY][adjacentX]);
                }
            }
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