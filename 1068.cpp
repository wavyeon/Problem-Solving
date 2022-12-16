#include <iostream>
#include <vector>
#include <queue>

#define MAX 51
#define endl '\n'

using namespace std;

int n, del;
vector<vector<int>> child(MAX);
int parent[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int par;
    for(int i = 0; i < n; i++) {
        cin >> par;
        parent[i] = par;
        if(par == -1) {
            continue;
        }
        child[par].push_back(i);
    }
    cin >> del;
}

int countOriginalLeaf() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(child[i].size() == 0) {
            cnt++;
        }
    }
    return cnt;
}

int countPruningLeaf(int del) {
    int cnt = 0;
    queue<int> q;

    if(child[del].size() == 0) { // 지우려하는 노드가 리프 노드일 때
        cnt = 1;
    }
    else {
        q.push(del);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(child[cur].size() == 0) {
                cnt++;
            }
            else {
                for(int i = 0; i < child[cur].size(); i++) {
                    q.push(child[cur][i]);
                }
            }
        }
    }
    if(parent[del] != -1) {
        if(child[parent[del]].size() == 1) { // 삭제하려는 노드의 부모 노드가 자식이 하나 뿐이라면 삭제와 동시에 리프 노드가 하나 생김
            cnt -= 1;
        }
    }
    return cnt;
}

void solve() {
    int originalLeaf = countOriginalLeaf();
    int pruningLeaf = countPruningLeaf(del);
    int remainingLeaf = originalLeaf - pruningLeaf;
    cout << remainingLeaf << endl;
}

int main() {
    init();
    solve();
}