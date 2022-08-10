#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#define MAX_VERTEX 20001
#define notVisited 0
#define visitedAndBlack 1
#define visitedAndWhite 2

using namespace std;

vector<int> graph[MAX_VERTEX];
vector<string> output;
queue<int> q;
int visited[MAX_VERTEX] = {notVisited, }; //bfs 돌때 재방문 막으려는 용도가 아니라 단절된 그래프일 경우 모든 정점을 방문하지 않으므로 이를 막기 위해 사용
// int color[MAX_VERTEX] = {noColor, };
int connectedVertex[MAX_VERTEX] = {0, };

// bool isColored(int idx) {
//     if(color[idx] == 0) {
//         return false;
//     }
//     else {
//         return true;
//     }     
// }

void coloring(int cur, int next) {
    if(visited[cur] == visitedAndBlack) {
        visited[next] = visitedAndWhite;
    }
    else if(visited[cur] == visitedAndWhite) {
        visited[next] = visitedAndBlack;
    }
}

void isBipartite(int vertexNum) {
    bool bipartiteFlag = true;
    for(int i = 1; i <= vertexNum; i++) {
        int current = i;
        for(int j = 0; j < connectedVertex[i]; j++) {
            int adjacent = graph[i][j];
            if(visited[adjacent] == visited[current]) {
                bipartiteFlag = false;
            } 
        }
    }
    if(bipartiteFlag == true) {
        output.push_back("YES");
    }
    else {
        output.push_back("NO");
    }
}

// bool areDifferent(int cur, int next) {
//     if(color[cur] != noColor && color[next] != noColor && color[cur] != color[next]) {
//         return true;
//     }
//     return false;
// }

void bfs(vector<int>* graph) {
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        // if(isBipartite == false) {
        //     break;
        // }
        for(int i = 0; i < connectedVertex[cur]; i++) {
            int next = graph[cur][i];
            if(visited[next] == notVisited) {
                coloring(cur, next);
                q.push(next);
            }
        }
    }
}

void solve(int vertexNum, int edgeNum) {
    int u, v;
    for(int i = 0; i < edgeNum; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        connectedVertex[u]++;
        connectedVertex[v]++;
    }
    for(int j = 1; j <= vertexNum; j++) {
        if(visited[j] == notVisited) {
            int start = j;
            q.push(start);
            visited[start] = visitedAndBlack;
            bfs(graph);
            // if(isBipartite == false) {
            //     output.push_back("NO");
            //     break;
            // }
        } 
    }
    isBipartite(vertexNum);
    // if(isBipartite == true) {
    //     output.push_back("YES");
    // }
}

void init(int vertexNum) {
    while(!q.empty()) {
        q.pop();
    }
    for(int i = 1; i <= vertexNum; i++) {
        graph[i].clear();
    }
    memset(connectedVertex, 0, sizeof(connectedVertex));
    memset(visited, notVisited, sizeof(visited));
}

int main() {
    int testCase, vertexNum, edgeNum;
    cin >> testCase;
    while(testCase--) {
        scanf("%d %d", &vertexNum, &edgeNum);
        solve(vertexNum, edgeNum);
        init(vertexNum);
    }
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}