#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 100001
#define isVisited 1
#define notVisited 0

using namespace std;

vector<int>* graph = new vector<int>[MAX_VERTEX];
int visited[MAX_VERTEX] = {notVisited, };
int connectedEdge[MAX_VERTEX] = {0, };
int order[MAX_VERTEX] = {0, };
int orderCount = 1;

void dfs(int current) {
    visited[current] = isVisited;
    order[current] = orderCount;
    orderCount++;
    for(int i = 0; i < connectedEdge[current]; i++) {
        if(visited[graph[current][i]] == notVisited) {
            dfs(graph[current][i]);
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
    dfs(start);
    for(int i = 1; i <= vertex; i++) {
        printf("%d\n", order[i]);
    }
}