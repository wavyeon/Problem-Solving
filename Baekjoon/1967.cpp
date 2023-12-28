#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int index;
    int dist;
} node;

const int MAX = 10001;
int vertex, maxDist, maxIdx;
vector<node> graph[MAX];
bool isVisited[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> vertex;
    for(int i = 0; i < vertex-1; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].push_back({to,dist});
        graph[to].push_back({from,dist});
    }
}

void dfs(int cur, int dis) {
    isVisited[cur] = true;
    if(dis > maxDist) {
        maxIdx = cur;
        maxDist = dis;
    }
    for(int i = 0; i < graph[cur].size(); i++) {
        int nextIdx = graph[cur][i].index;
        int nextDis = graph[cur][i].dist + dis;
        if(isVisited[nextIdx] == false) {
            dfs(nextIdx, nextDis);
        }
    }
}

void solve() {
    maxDist = 0;
    maxIdx = 1;
    dfs(1,0);
    maxDist = 0;
    for(int i = 1; i <= vertex; i++) {
        isVisited[i] = false;
    }
    dfs(maxIdx, maxDist);
    cout << maxDist << "\n";
}

int main() {
    init();
    solve();
}