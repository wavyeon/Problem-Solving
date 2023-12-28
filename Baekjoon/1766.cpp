#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int problem, info;
vector<int> graph[32001];
int in_degree[32001];
vector<int> answer;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> problem >> info;
    for(int i = 0; i < info; i++) {
        int precede, follow;
        cin >> precede >> follow;
        graph[precede].push_back(follow);
        in_degree[follow]++;
    }
}

void solve() {
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i = 1; i <= problem; i++) {
        if(in_degree[i] == 0) {
            pq.push(i);
        }
    }
    while(!pq.empty()) {
        int cur = pq.top();
        answer.push_back(cur);
        pq.pop();
        for(int j = 0; j < graph[cur].size(); j++) {
            in_degree[graph[cur][j]]--;
            if(in_degree[graph[cur][j]] == 0) {
                pq.push(graph[cur][j]);
            }
        }
    }
    for(int k = 0; k < answer.size(); k++) {
        cout << answer[k] << " ";
    }
    cout << endl;
}

int main() {
    init();
    solve();
}