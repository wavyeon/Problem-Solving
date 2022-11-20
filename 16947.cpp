#include <iostream>
#include <vector>
#include <stack>
#define endl '\n'

using namespace std;

int station, from, to, testCase, cycleStart;
const int MAX = 3001;
vector<vector<int>> graph(MAX);
bool dfsVisited[MAX];
bool bfsVisited[MAX];
stack<int> st;
vector<int> cycle;
bool cycleIndex[MAX];
bool cycleFound;

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
    // cout << "현재: " << cur << endl;
    // for(int i = 0; i < history.size(); i++) {
    //     cout << history[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < graph[cur].size(); i++) {
        if(cycleFound == true) {
            return;
        }   
        int next = graph[cur][i];
        if(next != prev) { // 직전 방문이 아님
            if(dfsVisited[next] == true) { // 이전에 방문한 적 있음 -> 사이클 발견
                cycleStart = next;
                cycle = history;
                // cout << "!" << endl;
                // for(int i = 0; i < history.size(); i++) {
                //     cout << history[i] << " ";
                // }
                cycleFound = true;
                // return;
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
    // cout << cycleStart << endl;
    for(int i = 0; i < cycle.size(); i++) {
        // cout << cycle[i] << " ";
        cycleIndex[cycle[i]] = true;
    }
}

void bfs(int start) {
    queue<subway> q;
    subway depart = {start, 0};
    q.push(depart);
    while(!q.empty()) {
        
    }
}

void findDist() {
    for(int i = 1; i <= station; i++) {
        bfs(i);
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