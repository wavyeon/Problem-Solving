// 사이클의 개수를 묻는 문제로 환원
#include <iostream>
#define endl '\n'
#define MAX 1001
#define coo pair<int,int>
#define notVisited 0
#define isVisited 1
#define isCounted 2

using namespace std;

int n, m, cnt;
coo nextNode[MAX][MAX];
int visited[MAX][MAX];
// 세 가지 상태로 분류 
// notVisited : 아직 방문 안함
// isVisited : 방문 했지만 카운팅 안함 (현재 탐색 중)
// isCounted : 방문 했고 카운팅도 했음 (이미 탐색 끝)
// 탐색 중에 이미 형성된 사이클에 도달하는 경우도 고려해야 하기 때문!!
// 사이클이 형성되는 순간에 카운팅을 해주고,
// 이후에 다른 노드 탐색 중 이 사이클에 도달하여 중복으로 카운팅을 하는 것을 방지하기 위해
// 사이클이 형성되면 사이클을 구성하는 노드를 isVisited 상태에서 isCounted 상태로 바꿔줌
// 즉, 탐색 중 isVisited를 만났다는 건 이번 탐색에서 방문했던 노드를 다시 만난 것이므로 새로운 사이클이 형성
// 탐색 중 isCounted를 만났다는 건 이전 탐색에서 형성된 사이클의 일부를 만난 것이므로 새로운 사이클 형성이 아님

coo findNextCoordinate(int i, int j, char dir) {
    coo ret;
    switch (dir) {
        case 'U':
            ret = {i-1, j};
            break;
        case 'D':
            ret =  {i+1, j};
            break;
        case 'R':
            ret =  {i, j+1};
            break;
        case 'L':
            ret =  {i, j-1};
    }
    return ret;
}

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    char dir;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> dir;
            nextNode[i][j] = findNextCoordinate(i, j, dir);
        }
    }
}

void dfs(int i, int j) {
    visited[i][j] = isVisited;
    int nextX = nextNode[i][j].second;
    int nextY = nextNode[i][j].first;
    if(visited[nextY][nextX] == notVisited) {
        dfs(nextY, nextX);
    }
    else if(visited[nextY][nextX] == isVisited) {
        cnt++;
    }
    else if(visited[nextY][nextX] == isCounted) {
        // 카운팅할 필요 없음!!
    }
    visited[i][j] = isCounted;
    // dfs 탐색을 종료한다는 건 사이클을 발견했다는 의미
    // 발견한 것이 새 사이클이건, 기존의 사이클이건 카운팅이 이미 된 사이클이므로 isCounted 상태로 바꿔줌
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == notVisited) {
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}