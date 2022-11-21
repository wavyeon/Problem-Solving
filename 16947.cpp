#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

int station, from, to, testCase, cycleStart;
const int MAX = 3001;
vector<vector<int>> graph(MAX);
bool dfsVisited[MAX];

stack<int> st;
vector<int> cycle;
bool cycleIndex[MAX];
bool cycleFound;
int answer[MAX];

typedef struct {
    int num;
    int dist;
} subway;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> station;
    for(int i = 0; i < station; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

void dfs(int prev, int cur, vector<int> history) {
    for(int i = 0; i < graph[cur].size(); i++) {
        if(cycleFound == true) {
            return;
        }   
        int next = graph[cur][i];
        if(next != prev) { // 직전 방문이 아님
            if(dfsVisited[next] == true) { // 이전에 방문한 적 있음 -> 사이클 발견
                cycleStart = next;
                cycle = history;
                cycleFound = true;
            }
            else {
                st.push(next);
                dfsVisited[next] = true;
                history.push_back(next);
                dfs(cur, next, history);
                history.erase(history.begin() + history.size() - 1);
            }
        }
    }
}

void findCycle() {
    st.push(1);
    dfsVisited[1] = true;
    vector<int> v;
    v.push_back(1);
    dfs(0, 1, v);
    auto it = find(cycle.begin(), cycle.end(), cycleStart);
    for(int i = it - cycle.begin(); i < cycle.size(); i++) {
        cycleIndex[cycle[i]] = true;
    }
}

void bfs(int start) {
    bool bfsVisited[MAX] = {false, };
    queue<subway> q;
    subway depart = {start, 0};
    q.push(depart);
    bfsVisited[0] = true;
    while(!q.empty()) {
        subway cur = q.front();
        q.pop();
        if(cycleIndex[cur.num] == true) {
            answer[start] = cur.dist;
            return;
        }
        for(int i = 0; i < graph[cur.num].size(); i++) {
            if(bfsVisited[graph[cur.num][i]] == false) {
                subway next = {graph[cur.num][i], cur.dist+1};
                q.push(next);
                bfsVisited[graph[cur.num][i]] = true;
            }
        }
    }
}

void findDist() {
    for(int i = 1; i <= station; i++) {
        bfs(i);
    }
    for(int i = 1; i <= station; i++) {
        cout << answer[i] << " ";
    }
}

void solve() {
    findCycle();
    findDist();
}

int main() {
    init();
    solve();

}