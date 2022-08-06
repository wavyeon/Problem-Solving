#include <iostream>
#include <vector>
#define MAX_VALUE 2001
#define visited 1
#define notvisited 0
#define connected 1

using namespace std;

int people, relationship;
vector<vector<int>> graph;
int isVisited[MAX_VALUE];
int isConnected[MAX_VALUE];
int exist = 0;

void init() {
    scanf("%d %d", &people, &relationship);
    for(int i = 0; i < people; i++) {
        vector<int> row;
        graph.push_back(row);
    }
    int x, y;
    for(int i = 0; i < relationship; i++) {
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void dfs(int me, int count) {
    if(count == 5 || exist == 1) {
        exist = 1;
        return;
    }
    for(int j = 0; j < graph[me].size(); j++) {
        int you = graph[me][j];
        if(isVisited[you] == notvisited) {
            isVisited[you] = visited;
            count++;
            dfs(you, count);
            count--;
            isVisited[you] = notvisited;
        }
    }
}

void solve() {
    for(int i = 0; i < people; i++) {
        int count = 1;
        if(exist == true) {
            break;
        }
        isVisited[i] = visited;
        dfs(i, count);
        isVisited[i] = notvisited;
    }
    printf("%d", exist);
}

int main() {
    init();
    solve();
}