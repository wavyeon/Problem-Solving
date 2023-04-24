// 단방향 그래프에서 모든 정점의 최단 거리 => 플로이드 워셜
#include <iostream>
#include <algorithm>
#define endl '\n'
#define INF 2e9

using namespace std;

int city, bus;
int graph[101][101];

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> city;
    cin >> bus;
    for(int i = 1; i <= city; i++) {
        for(int j = 1; j <= city; j++) {
            graph[i][j] = INF;
        }
    }
    int from, to, cost;
    for(int i = 0; i < bus; i++) {
        cin >> from >> to >> cost;
        if(graph[from][to] > cost) {
             graph[from][to] = cost;
        }
    }
}

void solve() {
    for(int i = 1; i <= city; i++) { // 경유하는 city
        for(int j = 1; j <= city; j++) { // 경유하기 전의 city
            for(int k = 1; k <= city; k++) { // 경유한 후의 city
                if(graph[j][i] != INF && graph[i][k] != INF) {
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }
    for(int i = 1; i <= city; i++) {
        for(int j = 1; j <= city; j++) {
            if(graph[i][j] == INF || i == j) { // 출발 도착 같은 곳도 INF 처리
                cout << 0 << " ";
            }
            else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    init();
    solve();
}