// 그래프 탐색에서 경로를 구해야하는 경우에는 parent 배열 사용을 고려할 것!!
#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
#define MAX 1001
#define INF 2e9

using namespace std;

int city, bus, start, dest;
int distlist[MAX];
int parent[MAX];
vector<int> order;
vector<pair<int,int>> graph[MAX]; // to, dist
priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; // dist, to 

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> city;
    cin >> bus;
    fill(&distlist[1], &distlist[1]+city, INF);
    int from, to, dist;
    for(int i = 0; i < bus; i++) {
        cin >> from >> to >> dist;
        graph[from].push_back({to, dist});
    }
    cin >> start >> dest;
}

void backtrack() {
    int cnt = 1;
    int cur = dest;
    while(true) {
        order.push_back(cur);
        if(cur == start) {
            break;
        }
        else {
            cnt++;
            cur = parent[cur];
        }
    }
    cout << cnt << endl;
    for(int i = order.size() - 1 ; i >= 0; i--) {
        cout << order[i] << " ";
    }
    cout << endl;
}

void solve() {  
    pq.push({0, start});
    int curIdx, curDist;
    while(!pq.empty()) {
        curDist = pq.top().first;
        curIdx = pq.top().second;
        pq.pop();
        // distlist에 이미 더 짧은 거리가 들어가있으므로 현재 노드를 거치는 탐색 무의미
        // 이런 식의 가지치기는 다익스트라 알고리즘 시간 단축에 필수!!
        if(distlist[curIdx] < curDist) {
            continue;
        }
        for(int i = 0; i < graph[curIdx].size(); i++) {
            int nextDist = curDist + graph[curIdx][i].second;
            int nextIdx = graph[curIdx][i].first;
            if(distlist[nextIdx] > nextDist) {
                distlist[nextIdx] = nextDist;
                pq.push({nextDist, nextIdx});
                parent[nextIdx] = curIdx;
            }
        }
    }
    cout << distlist[dest] << endl;
    backtrack();
}

int main() {
    init();
    solve();
}