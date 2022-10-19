#include <iostream>
#include <vector>

#define endl "\n"
const int MAX = 501;
const int INF = 10001;
using namespace std;

typedef struct {
    //그래프라고 무조건 2차원 map을 그린다는 생각을 버리자.
    int from;
    int to;
    int time;
} edge;

vector<edge> edges; // 벨만-포드 알고리즘에서는 edge로 이루어진 1차원 배열을 이용하자.
int test, node, road, worm;
int dist[MAX];

void init() {
    edges.clear();
    for(int i = 1; i < MAX; i++) {
        dist[i] = INF;
    }
}

void input() {
    cin >> node >> road >> worm;
    int from, to, time;
    for(int i = 0; i < road; i++) {
        cin >> from >> to >> time;
        edges.push_back({from,to,time});
        edges.push_back({to,from,time});
        // 구조체 이용하면 make_pair 복잡하게 안해도 됨!
        // 단방향과 양방향 간선이 모두 존재하면 
        // 양방향 간선을 단방향 간선 두 번 입력해주는 식으로!
    }
    for(int i = 0; i < worm; i++) {
        cin >> from >> to >> time;
        edges.push_back({from,to,-time});
    }
}

void Bellman_Ford() {
    dist[1] = 0;
    for(int i = 1; i <= node-1; i++) {
        // node-1 번 도는 이유 매우 중요
        // n개의 노드를 모두 잇기 위해서는 최소한 n-1번의 탐색(n-1개의 엣지가 필요)
        // ex) 1 -> 2 -> 3 -> 4 식의 그래프
        for(int j = 0; j < edges.size(); j++) {
            edge cur = edges[j];
            if(dist[cur.from] == INF) {
                // 출발 정점이 한 번이라도 계산(갱신)되었는 지 판단해야합!
                // dist[1] = 0을 해주는 이유이기도 함 (계산 되지 않았다면 INF)
                continue;
            }
            if(dist[cur.from] + cur.time < dist[cur.to]) {
                dist[cur.to] = dist[cur.from] + cur.time;
            }
        }
    }
    string answer = "NO";
    for(int i = 0; i < edges.size(); i++) {
        // 이미 n-1번 돌아서 n개의 노드를 연결한 상태임
        // 그런데도 갱신되는 경우가 있다면? 음의 사이클이 존재하는 것
        edge cur = edges[i];
        if(dist[cur.from] == INF) {
            continue;
        }
        if(dist[cur.from] + cur.time < dist[cur.to]) {
            answer = "YES";
        }
    }
    cout << answer << endl;
}

void solve() {
    cin >> test;
    while (test--) {
        init();
        input();
        Bellman_Ford();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
}