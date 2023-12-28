//BFS 말고 Dijkstra
//Dijkstra는 Priority Queue 이용!
#include <iostream>
#include <queue>
#include <algorithm>
#define visited 1
#define notVisited 0
#define MAX_VALUE 100001

using namespace std;

int MAX = 100001;
int from, to;

// pair 안에는 구조체 사용이 불가능하다!! -> 아닌 듯?
typedef struct {
    int time;
    int location;
} route;

priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
// priority_queue< pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>> > pq;
int isVisited[MAX_VALUE];

void init() {
    scanf("%d %d", &from, &to);
}

void bfs() {
    while(!pq.empty()) {
        route cur;
        cur.time = pq.top().first;
        cur.location = pq.top().second;
        pq.pop();
        if(cur.location == to) {
            printf("%d\n", cur.time);
            return;
        }
        else {
            route next;
            if(cur.location*2 < MAX && isVisited[cur.location*2] == notVisited) { // visited 처리때문에 가장 우수한 경우인 순간이동을 가장 먼저 푸시!
                isVisited[cur.location*2] = visited;
                next.location = cur.location*2;
                next.time = cur.time;
                pq.push(make_pair(next.time, next.location));
            }
            if(cur.location-1 >= 0 && isVisited[cur.location-1] == notVisited) {
                isVisited[cur.location-1] = visited;
                next.location = cur.location-1;
                next.time = cur.time+1;
                pq.push(make_pair(next.time, next.location));
            }
            if(cur.location+1 < MAX && isVisited[cur.location+1] == notVisited) {
                isVisited[cur.location+1] = visited;
                next.location = cur.location+1;
                next.time = cur.time+1;
                pq.push(make_pair(next.time, next.location));
            }
        }
    }
}

void solve() {
    route start;
    start.time = 0;
    start.location = from;
    isVisited[start.location] = visited;
    pq.push(make_pair(start.time, start.location));
    bfs();
}

int main() {
    init();
    solve();
}