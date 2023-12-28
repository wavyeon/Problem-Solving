#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_VERTEX 100001
#define isVisited 1
#define notVisited 0

using namespace std;

vector<int>* graph = new vector<int>[MAX_VERTEX];
int visited[MAX_VERTEX] = {notVisited, };
int connectedEdge[MAX_VERTEX] = {0, };
int order[MAX_VERTEX] = {0, };
int orderCount = 1;
queue<int> q;

void bfs(int start) {
    int front;
    q.push(start);
    visited[start] = isVisited;
    order[start] = orderCount;
    orderCount++;
    while(!q.empty()) {
        front = q.front();
        q.pop();
        for(int i = 0; i < connectedEdge[front]; i++) {
            if(visited[graph[front][i]] == notVisited) {
                q.push(graph[front][i]);
                visited[graph[front][i]] = isVisited;
                order[graph[front][i]] = orderCount;
                orderCount++;
            }
        }
    }
}

int main() {
    int vertex, edge, start;
    cin >> vertex >> edge >> start;
    for(int i = 0; i < edge; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        connectedEdge[x]++;
        connectedEdge[y]++;
    }
    for(int k = 1; k <= vertex; k++) {
        sort(graph[k].begin(), graph[k].end());
    }
    bfs(start);
    for(int i = 1; i <= vertex; i++) {
        printf("%d\n", order[i]);
    }
}