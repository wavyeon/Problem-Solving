#include <iostream>
#include <vector>
#define MAX_VALUE 1001
#define visited true
#define notVisited false

using namespace std;

int numOfVertex, numOfEdge;
vector<int> graph[MAX_VALUE];
int connectedVertex[MAX_VALUE];
bool isVisited[MAX_VALUE];
int count;

void init() {
    cin >> numOfVertex >> numOfEdge;
    int u, v;
    for(int i = 0; i < numOfEdge; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
}

void dfs(int ver) {
    for(int i = 0; i < graph[ver].size(); i++) {
        if(isVisited[graph[ver][i]] == notVisited) {
            isVisited[graph[ver][i]] = visited;
            dfs(graph[ver][i]);
        }
    }
}

void solve() {
    for(int i = 1; i <= numOfVertex; i++) {
        if(isVisited[i] == notVisited) {
            count++;
            dfs(i);
        }
    }
    cout << count;
}

int main() {
    init();
    solve();
}