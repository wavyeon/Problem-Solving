#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int n, a, b, relation;
int pedigree[MAX];
vector<vector<int>> tree(MAX);
bool visited[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> a >> b;
    cin >> relation;
    int parent, child;
    for(int i = 0; i < relation; i++) {
        cin >> parent >> child;
        pedigree[child] = parent;
        tree[parent].push_back(child);
    }
}

void bfs() {
    queue<pair<int, int>> q;
    pair<int, int> start = {a, 0};
    visited[a] == true;
    q.push(start);
    while(!q.empty()) {
        int curIdx = q.front().first;
        int curStep = q.front().second;
        q.pop();
        if(curIdx == b) {
            cout << curStep << endl;
            return;
        }
        if(visited[pedigree[curIdx]] == false) { // parent push
            q.push(make_pair(pedigree[curIdx], curStep+1));
            visited[pedigree[curIdx]] = true;
        }
        for(int i = 0; i < tree[curIdx].size(); i++) { // child push
            if(visited[tree[curIdx][i]] == false) {
                q.push(make_pair(tree[curIdx][i], curStep+1));
                visited[tree[curIdx][i]] = true;
            }
        }
    }
    cout << -1 << endl;
}

void solve() {
    bfs();
}

int main() {
    init();
    solve();
}