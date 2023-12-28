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

int from, to;
queue<location> q;
int visited[MAX_VALUE];
int root[MAX_VALUE];
vector<int> history;

void traceBack(int to) {
    while(to != from) {
        history.push_back(to);
        to = root[to];
    }
    history.push_back(from);
    for(int i = history.size()-1; i >= 0; i--) {
        printf("%d ", history[i]);
    }                   
    printf("\n");
}

void bfs(int to) {
    while(!q.empty()) {
        location cur = q.front();
        q.pop();
        if(cur.distance == to) {
            cout << cur.time << endl;
            traceBack(to);
            break;
        }
        location next;
        if(cur.distance - 1 >= 0 && visited[cur.distance - 1] == notVisited) {
            visited[cur.distance - 1] = isVisited;
            next.distance = cur.distance - 1; 
            next.time = cur.time + 1;
            q.push(next);
            root[next.distance] = cur.distance;
        }
        if(cur.distance + 1 < MAX_VALUE && visited[cur.distance + 1] == notVisited) {
            visited[cur.distance + 1] = isVisited;
            next.distance = cur.distance + 1;
            next.time = cur.time + 1;
            q.push(next);
            root[next.distance] = cur.distance;
        }
        if(cur.distance * 2 < MAX_VALUE&& visited[cur.distance * 2] == notVisited) {
            visited[cur.distance * 2] = isVisited;
            next.distance = cur.distance * 2;
            next.time = cur.time + 1;
            q.push(next);
            root[next.distance] = cur.distance;
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
    cin >> from >> to;
    solve(from, to);
}