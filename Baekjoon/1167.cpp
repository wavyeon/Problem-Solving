#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int index;
    int dist;
} node;

const int MAX = 100001;
int vertex, maxDist, maxIdx;
vector<node> graph[MAX];
bool isVisited[MAX];
// vector<node> graph(MAX);  와는 다름!! 

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> vertex;
    int from, to, dist;
    for(int i = 1; i <= vertex; i++) {
        cin >> from;
        while(true) {
            cin >> to;
            if(to == -1) {
                break;
            }
            cin >> dist;
            graph[from].push_back({to, dist});
        }
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
    //트리(원)의 지름에 있는 두 노드(점)
    //원 안의 임의의 점에서 가장 멀리 있는 점은 원의 지름을 이루는 두 점 중 한 점임
    //첫번째 dfs에서 그 점을 찾는다
    maxDist = 0;
    maxIdx = 1;
    dfs(1,0);
    //조건을 초기화 한 다음 두 번째 dfs에서 지름의 길이 찾는다
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