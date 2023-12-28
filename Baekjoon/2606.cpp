#include <iostream>
#include <vector>
#define MAX_COMPUTER 101
#define isVisited 1
#define notVisited 0

using namespace std;

vector<int> graph[MAX_COMPUTER];
int visited[MAX_COMPUTER];
int infectedCom;

void init(int& com, int& connect, int& x, int& y) {
    cin >> com >> connect;
    while(connect--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void dfs(int cur) {
    visited[cur] = isVisited;
    // cout << cur << infectedCom << endl;
    for(int i = 0; i < graph[cur].size(); i++) {
        if(visited[graph[cur][i]] == notVisited) {
            dfs(graph[cur][i]);
            infectedCom++;
        }
    }
} 

int main() {
    int com, connect, x, y;
    init(com, connect, x, y);
    dfs(1);
    cout << infectedCom << endl;
}



