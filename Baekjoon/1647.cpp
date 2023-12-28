// Union-Find 최적화 필요한 문제 (시간초과 issue)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define info pair<int, pair<int, int>>
#define endl '\n'
#define MAX 100001

using namespace std;

int house, road, cnt, biggest;
long long weightSum;
vector<info> vec;
int parent[MAX];
int height[MAX]; // union 함수 최적화

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> house >> road;
    int cost, from, to;
    for(int i = 0; i < road; i++) {
        cin >> from >> to >> cost;
        info tmp = {cost, {from, to}};
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= house; i++) {
        parent[i] = i;
        height[i] = 0;
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

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) {
        return;
    }
    else {
        if(height[x] < height[y]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
        }
        if(height[x] == height[y]) {
            height[x]++;
        }
    }
}

void solve() {
    for(int i = 0; i < vec.size(); i++) {
        if(Find(vec[i].second.first) != Find(vec[i].second.second)) {
            Union(vec[i].second.first, vec[i].second.second);
            weightSum += vec[i].first;
            cnt++;
            biggest = max(biggest, vec[i].first);
        }
        if(cnt == house - 1) {
            cout << weightSum - biggest << endl;
            return;
        }
    }
}
    

int main() {
    init();
    solve();
}