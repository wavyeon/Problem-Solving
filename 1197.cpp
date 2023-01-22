//https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html
//https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define edge pair<int,pair<int,int>>
#define MAX 10001

using namespace std;

int v, e;
vector<edge> vec;
int parent[MAX];

int Find(int num) {
    if(parent[num] == num) {
        return num;
    }
    else {
        return Find(parent[num]); // 재귀함수 돌리기만하면 안되고 return을 해줘야함!!
    }
}

void Union(int from, int to) {
    from = Find(from);
    to = Find(to);
    parent[to] = from;
}

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < MAX; i++) { // Kruskal MST (Union-Find) 하려면 parent 초기화 해줘야함!!
        parent[i] = i;
    }
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edge tmp = {weight, {from, to}};
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end()); // Kruskal MST 하려면 sorting 해줘야함!!
}

void solve() {
    int cnt = 0;
    long long weightSum = 0;
    for(int i = 0; i < vec.size(); i++) {
        if(Find(vec[i].second.first) != Find(vec[i].second.second)) { // 두 vertex가 같은 집합 아님 -> 선택해도 cycle 형성하지 않음
            Union(vec[i].second.first, vec[i].second.second);
            cnt++;
            weightSum += vec[i].first;
        }
        if(cnt == v-1) {
            cout << weightSum << endl;
            return;
        }
    }
}

int main() {
    init();
    solve();
}