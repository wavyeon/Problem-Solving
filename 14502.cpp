#include <iostream>
#include <stack>
#define space 0
#define wall 1
#define virus 2

using namespace std;

int n, m, maxIdx, maxSafeZone;
const int MAX = 10;
int originalMap[MAX][MAX];
int testMap[MAX][MAX];
int wallLocation[4];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
stack<pair<int,int>> st;
bool isVisited[MAX][MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> originalMap[i][j];
        }
    }
    maxIdx = n * m;
}

void countSafeZone() {
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(testMap[i][j] == space) {
                count++;
            }
        }
    }
    if(maxSafeZone < count) {
        maxSafeZone = count;
    }
}

void spreadVirus() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(testMap[i][j] == virus && isVisited[i][j] == false) {
                st.push(make_pair(i, j));
                isVisited[i][j] = true;
                while(!st.empty()) {
                    int curX = st.top().second;
                    int curY = st.top().first;
                    st.pop();
                    for(int i = 0; i < 4; i++) {
                        int nextX = curX + dirX[i];
                        int nextY = curY + dirY[i];
                        if(nextX < m && nextX >= 0 && nextY < n && nextY >= 0) { // 범위 체크
                            if(testMap[nextY][nextX] != wall && isVisited[nextY][nextX] == false) { // 벽이 아닌지, 방문한적 있는지 체크
                                testMap[nextY][nextX] = virus;
                                isVisited[nextY][nextX] = true;
                                st.push(make_pair(nextY, nextX));
                            }
                        }
                    }
                }
            }
        }
    }
    countSafeZone();
}

void locateWall(int idx, int count) {
    if(count == 4) { // 벽 세개를 모두 고른 경우
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                testMap[i][j] = originalMap[i][j];
                isVisited[i][j] = false;
            }
        }
        for(int i = 1; i <= 3; i++) {
            int wallY = wallLocation[i] / m;
            int wallX = wallLocation[i] % m;
            testMap[wallY][wallX] = wall;
            // cout << wallY << ". " << wallX << endl;
        }
        spreadVirus();
    }
    else {
        for(int k = idx; k < maxIdx; k++) {
            int i = k / m;
            int j = k % m;
            // cout << i << " , " << j << endl;
            if(originalMap[i][j] == space) {
                wallLocation[count] = k;
                locateWall(k+1, count+1);
            }
        }
    }
    
}

void solve() {
    locateWall(0,1);
    cout << maxSafeZone << "\n";
}


int main() {
    init();
    solve();      
}