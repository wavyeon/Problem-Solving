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

// pair 안에는 구조체 사용이 불가능하다!!
typedef struct {
    int time;
    int location;
} route;

priority_queue<pair<int,pair<int, int>>> pq;
int isVisited[MAX_VALUE];

void init() {
    scanf("%d %d", &from, &to);
}

void bfs() {
    while(!pq.empty()) {
        cout <<"시발" <<endl;
        route cur;
        cur.time = pq.top().second.first;
        cur.location = pq.top().second.second;
        pq.pop();
        cout << cur.time << " " << cout.location << endl;
        if(cur.location == to) {
            
            printf("%d\n", cur.time);
        }
        else {
            route next;
            if(cur.location-1 >= 0 && isVisited[cur.location-1] == notVisited) {
                isVisited[cur.location-1] = visited;
                next.location = cur.location-1;
                next.time = cur.time+1;
                pq.push(make_pair(1,make_pair(next.time, next.location)));
            }
            if(cur.location < from) {
                if(cur.location+1 < MAX && isVisited[cur.location+1] == notVisited) {
                    isVisited[cur.location+1] = visited;
                    next.location = cur.location+1;
                    next.time = cur.time+1;
                    pq.push(make_pair(1,make_pair(next.time, next.location)));
                }
                if(cur.location*2 < MAX && isVisited[cur.location*2] == notVisited) {
                    isVisited[cur.location*2] = visited;
                    next.location = cur.location*2;
                    next.time = cur.time;
                    pq.push(make_pair(0,make_pair(next.time, next.location)));
                }
            }
        }
    }
}

void solve() {
    route start;
    start.time = 0;
    start.location = from;
    isVisited[start.location] = visited;
    pq.push(make_pair(0, make_pair(start.time, start.location)));
    bfs();
}

int main() {
    init();
    solve();
}