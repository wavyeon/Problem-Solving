#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX = 1001;
const int INF = 100001;
int student, road, party;
int dist[MAX];
int graph[MAX][MAX];
int toParty[MAX];
int fromParty[MAX];
int roundDistance[MAX];
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

void input() {
    fill(&graph[0][0], &graph[MAX][MAX], INF);
    for(int i = 1; i < MAX; i++) {
        graph[i][i] = 0;
    }
    scanf("%d %d %d", &student, &road, &party);
    int from, to, dist;
    for(int i = 0; i < road; i++) {
        scanf("%d %d %d", &from, &to, &dist);
        graph[from][to] = dist;
    }
}

void init() {
    for(int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    // memset(dist, INF, sizeof(int)*MAX);
    // fill(&distance[0], &distance[MAX], INF);
}

void dijkstra(int idx) {
    pq.push(make_pair(0, idx));
    int curIdx, curTime;
    while(!pq.empty()) {
        curIdx = pq.top().second;
        curTime = pq.top().first;
        // cout << "팝: " << curIdx << " " << curTime << endl;
        pq.pop();
        // if(curTime > dist[curIdx]) {
        //     cout << curTime << " " << dist[curIdx] << endl;
        //     continue;
        // }
        // 이미 방문한 적이 있고 방문할 이유가 더이상 없는 경우 continue?
        for(int i = 1; i <= student; i++) {
            if(dist[i] > curTime + graph[curIdx][i]) {
                // cout << i << "방문" << endl;
                dist[i] = curTime + graph[curIdx][i];
                pq.push(make_pair(dist[i], i));
            }
        } 
    }
}

void solve() {
    for(int i = 1; i <= student; i++) {
        init();
        dijkstra(i);
        // cout << i << "탐색" << endl;
        // for(int i = 1; i <= student; i++) {
        //     cout << dist[i] << " ";
        // }
        // cout << endl;
        toParty[i] = dist[party];
        if(i == party) {
            for(int j = 1; j <= student; j++) {
                fromParty[j] = dist[j];
            }
        }
    }
    // for(int i = 1; i <= student; i++) {
    //     roundDistance[i] = toParty[i] + fromParty[i];
    // }
    // cout << max_element(begin(roundDistance, end(roundDistance))) << endl;
    int output = 0;
    for(int i = 1; i <= student; i++) {
        roundDistance[i] = toParty[i] + fromParty[i];
        // cout << toParty[i] << " " << fromParty[i] << endl;
        if(roundDistance[i] > output) {
            output = roundDistance[i];
        }
    }
    cout << output << endl;
}

int main() {
    input();
    solve();
}