#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int student, compare;
int in_degree[32001];
vector<int> graph[32001];
vector<int> line;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> student >> compare;
    for(int i = 0; i < compare; i++) {
        int front, back;
        cin >> front >> back;
        graph[front].push_back(back);
        in_degree[back]++;
    }
}

void solve() {
    queue<int> q;
    for(int i = 1; i <= student; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        line.push_back(cur);
        q.pop();
        for(int j = 0; j < graph[cur].size(); j++) {
            in_degree[graph[cur][j]]--;
            if(in_degree[graph[cur][j]] == 0) {
                q.push(graph[cur][j]);
            }
        }
    }
    for(int i = 0; i < line.size(); i++) {
        cout << line[i] << " ";
    }
    cout << endl;
}

int main() {
    init();
    solve();
}