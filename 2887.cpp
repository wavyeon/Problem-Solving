// 시간제한 1초 => n = 100000000 (1억) 
// https://lemonlemon.tistory.com/54

// kruskal 알고리즘 쓸 때 인접한 정점만 생각해도 된다!
// 증명은 https://www.acmicpc.net/board/view/10945
// 지능의 벽...

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define MAX 100001
#define axis pair<int,int>
// 인접한 정점만 고려하기 위해 <행성의 절편값 (x,y,z 중 한 차원), 행성의 인덱스> 순으로 입력받은 후에 정렬하여 그 차원에서 인접한 정점간의 차(간선)만을 고려!!
#define edge pair<int, pair<int,int>>
 
using namespace std;

int parent[MAX];
int planet, costSum;
vector<axis> adj[3]; 
vector<edge> edges; 

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
        parent[b] = a;
    }
}

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> planet;
    int x, y, z;
	for (int i = 0; i < planet; i++) {
		cin >> x >> y >> z;
		adj[0].push_back({x, i});
		adj[1].push_back({y, i});
		adj[2].push_back({z, i});
		parent[i] = i;
	}
    sort(adj[0].begin(), adj[0].end());
	sort(adj[1].begin(), adj[1].end());
	sort(adj[2].begin(), adj[2].end());
}

void solve() {
    for (int i = 0; i < planet - 1; i++) {
		edges.push_back( {abs(adj[0][i].first - adj[0][i + 1].first), {adj[0][i].second, adj[0][i+1].second}} );
		edges.push_back( {abs(adj[1][i].first - adj[1][i + 1].first), {adj[1][i].second, adj[1][i + 1].second}} );
		edges.push_back( {abs(adj[2][i].first - adj[2][i + 1].first), {adj[2][i].second, adj[2][i + 1].second}} );
    }
	sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
		if (Find(edges[i].second.first) != Find(edges[i].second.second)) {
			costSum += edges[i].first;
			Union(edges[i].second.first, edges[i].second.second);
		}

	}
	cout << costSum << endl;
}

int main() {
    init();
    solve();
}