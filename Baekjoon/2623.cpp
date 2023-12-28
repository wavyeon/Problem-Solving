#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int singer, PD;
int in_degree[1001];
vector<int> follow[1001];
vector<int> order;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> singer >> PD;
    int managing;
    for(int i = 0; i < PD;i++) {
        cin >> managing;
        int prev, cur;
        cin >> prev;
        for(int j = 1; j < managing; j++) {
            cin >> cur;
            follow[prev].push_back(cur);
            in_degree[cur]++;
            prev = cur;
        }
    }
}

void solve() {
    queue<int> q;
    for(int i = 1; i <= singer; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for(int i = 0; i < follow[cur].size(); i++) {
            in_degree[follow[cur][i]]--;
            if(in_degree[follow[cur][i]] == 0) {
                q.push(follow[cur][i]);
            }
        }
    }
    for(int i = 1; i <= singer; i++) { // queue가 비어있는데 in_degree 값이 0보다 큰 경우 -> 순서를 정하는 것이 불가능
        if(in_degree[i] > 0) {
            cout << 0 << endl;
            return;
        }
    }
    for(int i = 0; i < order.size(); i++) {
        cout << order[i] << endl;
    }
}

int main() {
    init();
    solve();
}