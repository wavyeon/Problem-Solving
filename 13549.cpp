#include <iostream>
#include <queue>
#define MAX_VALUE 100001
#define isVisited 1
#define notVisited 0

using namespace std;

typedef struct {
    int time;
    int distance;
} location;

queue<location> q;
int visited[MAX_VALUE];

void bfs(int to) {
    while(!q.empty()) {
        location cur = q.front();
        q.pop();
        if(cur.distance == to) {
            cout << cur.time << endl;
            break;
        }
        location next;
        if(cur.distance - 1 >= 0 && visited[cur.distance - 1] == notVisited) {
            visited[cur.distance - 1] = isVisited;
            next.distance = cur.distance - 1; 
            next.time = cur.time + 1;
            q.push(next);
        }
        if(cur.distance + 1 < MAX_VALUE && visited[cur.distance + 1] == notVisited) {
            visited[cur.distance + 1] = isVisited;
            next.distance = cur.distance + 1;
            next.time = cur.time + 1;
            q.push(next);
        }
        if(cur.distance * 2 < MAX_VALUE&& visited[cur.distance * 2] == notVisited) {
            visited[cur.distance * 2] = isVisited;
            next.distance = cur.distance * 2;
            next.time = cur.time;
            q.push(next);
        }    
    }
}
void solve(int from, int to) {
    location start;
    start.time = 0;
    start.distance = from;
    visited[start.distance] = isVisited;
    q.push(start);
    bfs(to);
}

int main() {
    int from, to;
    cin >> from >> to;
    solve(from, to);
}