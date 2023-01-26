#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 101
#define endl '\n'
#define coor pair<double,double>
#define edge pair<double, pair<double, double>>

using namespace std;

int star, cnt;
int parent[MAX];
double weightSum;
vector<coor> location;
vector<edge> edges;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> star;
    for(int i = 0; i < star; i++) {
        double x, y;
        cin >> x >> y;
        coor tmp = {x, y};
        location.push_back(tmp);
    }
    for(int i = 0; i < location.size()-1; i++) {
        for(int j = i+1; j < location.size(); j++) {
            coor x = location[i];
            coor y = location[j];
            double dist = sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
            edge tmp = {dist,{i,j}};
            edges.push_back(tmp);
        }
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < star; i++) {
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
    a = Find(a);
    b = Find(b);
    if(a != b) {
        parent[b] = a;
    }
}

void solve() {
    for(int i = 0; i < edges.size(); i++) {
        if(Find(edges[i].second.first) != Find(edges[i].second.second)) {
            cnt++;
            weightSum += edges[i].first;
            Union(edges[i].second.first, edges[i].second.second);
        }
        if(cnt == star - 1) {
            cout << weightSum << endl;
            return;
        }
    }
}

int main() {
    init();
    solve();
}