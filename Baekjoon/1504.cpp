#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 801;
const int INF = 800001;
int vertex, edge;
int via1, via2;
int from, to, dist;
int graph[MAX][MAX];
int distlist[MAX];
int toVia1, toVia2, fromVia1, fromVia2, viatovia;
bool via1tovia2 = true;
bool via2tovia1 = true;
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

void init() {
    fill(&distlist[1], &distlist[1]+vertex, INF);
}

void input() {
    scanf("%d %d", &vertex, &edge);
    fill(&graph[0][0], &graph[0][0]+641601, INF);
    for(int i = 1; i <= vertex; i++) {
        graph[i][i] = 0;
    }
    for(int i = 0; i <   edge; i++) {
        scanf("%d %d %d", &from, &to, &dist);
        graph[from][to] = dist;
        graph[to][from] = dist;
    }
    scanf("%d %d", &via1, &via2);
}

void dijkstra(int start) {
    pq.push(make_pair(0, start));
    int curIdx, curDist;
    while(!pq.empty()) {
        curIdx = pq.top().second;
        curDist = pq.top().first;
        pq.pop();
        for(int i = 1; i <= vertex; i++) {
            if(curDist + graph[curIdx][i] < distlist[i]) {
                distlist[i] = curDist + graph[curIdx][i];
                pq.push(make_pair(distlist[i], i));
            }
        }
    }
}

void solve() {

    init();
    dijkstra(1);
    if(distlist[via1] == INF) {
        via1tovia2 = false;
    }
    if(distlist[via2] == INF) {
        via2tovia1 = false;
    }
    toVia1 = distlist[via1];
    toVia2 = distlist[via2];

    init();
    dijkstra(via1);
    if(distlist[via2] == INF) {
        via1tovia2 = false;
        via2tovia1 = false;
    }
    if(distlist[vertex] == INF) {
        via2tovia1 = false;
    }
    viatovia = distlist[via2];
    fromVia1 = distlist[vertex];

    init();
    dijkstra(via2);
    if(distlist[vertex] == INF) {
        via1tovia2 = false;
    }
    fromVia2 = distlist[vertex];

    if(via1tovia2 == false && via2tovia1 == false) {
        printf("-1\n");
    }
    else{
        printf("%d\n", viatovia + min( (toVia1+fromVia2), (toVia2+fromVia1) ));
    }
}

int main() {
    input();
    solve();
}
