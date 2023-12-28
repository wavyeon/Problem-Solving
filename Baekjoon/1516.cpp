#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

int building;
vector<int> build[501];
int in_degree[501];
int constTIme[501];
int minTIme[501];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> building;
    for(int i = 1; i <= building; i++) {
        cin >> constTIme[i];
        int precede;
        while(true) {
            cin >> precede;
            if(precede == -1) {
                break;
            }
            else {
                in_degree[i]++;
                build[precede].push_back(i);
            }
        }
    }
}

void solve() {
    queue<int> q;
    for(int i = 1; i <= building; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
            minTIme[i] = constTIme[i];
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int j = 0; j < build[cur].size(); j++) {
            int next = build[cur][j];
            in_degree[next]--;
            minTIme[next] = max(minTIme[next], minTIme[cur] + constTIme[next]);
            if(in_degree[next] == 0) {
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= building; i++) {
        cout << minTIme[i] << endl;
    }
}

int main() {
    init();
    solve();
}