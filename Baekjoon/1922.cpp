#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define edge pair<int, pair<int, int>>
#define MAX 1001

using namespace std;

int com, line, cnt;
long long costSum;
vector<edge> edges;
int parent[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> com;
    cin >> line;
    int from, to, cost;
    for(int i = 0; i < line; i++) {
        cin >> from >> to >> cost;
        edge tmp = {cost, {from, to}};
        edges.push_back(tmp);
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < com; i++) {
        parent[i] = i;
    }
}

int Find(int num) {
    if(parent[num] == num) {
        return num;
    }
    else {
        return parent[num] = Find(parent[num]);
    }
}

void Union(int a, int b) {
    a = parent[a];
    b = parent[b];
    if(a != b) {
        parent[b] = a;
    }
}

void solve() {
    for(int i = 0; i < edges.size(); i++) {
        if(Find(edges[i].second.first) != Find(edges[i].second.second)) {
            Union(edges[i].second.first, edges[i].second.second);
            cnt++;
            costSum += edges[i].first;    
        }
        if(cnt == com-1) {
            cout << costSum << endl;
            return;
        }
    }
}

int main() {
    init();
    solve();
}