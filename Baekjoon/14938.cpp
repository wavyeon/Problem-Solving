#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int region, scope, road, from, to, weight, output;
const int MAX = 101;
const int INF = 1501;
int item[MAX];
int map[MAX][MAX];
int dist[MAX];
int maxItem[MAX];
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> region >> scope >> road;
    for(int i = 1; i <= region; i++) {
        cin >> item[i]; 
    }
    for(int i = 1; i <= region; i++) {
        for(int j = 1; j <= region; j++) {
            if(i == j) {
                map[i][j] = 0;
            }
            else {
                map[i][j] = INF;
            }
        }
    }
    for(int i = 0; i < road; i++) {
        cin >> from >> to >> weight;
        map[from][to] = map[to][from] = weight;
    }
}

void dijkstra(int start) {
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int distSum = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 1; i <= region; i++) {
            if(distSum + map[cur][i] < dist[i] && distSum + map[cur][i] <= scope) {
                dist[i] = distSum + map[cur][i];
                pq.push(make_pair(dist[i],i));
            }
        }
    }
}

void findItem(int start) {
    for(int i = 1; i <= region; i++) {
        dist[i] = INF;
    }
    dijkstra(start);
    for(int i = 1; i <= region; i++) {
        if(dist[i] <= scope) {
            maxItem[start] += item[i];
        }
    }
    pq = priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >(); //  queue를 클리어하는 방법
}

void solve() {
    for(int i = 1; i <= region; i++) {
        findItem(i);
        if(output < maxItem[i]) {
            output = maxItem[i];
        }
    }
    cout << output << "\n";
}

int main() {
    init();
    solve();
}