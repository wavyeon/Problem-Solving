#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl '\n'

using namespace std;

int construction, build, target;
int constTIme[1001];
vector<int> builds[100001];
int in_degree[1001]; // in_degree의 의미: vertex로 들어오는 edge 수
int minTIme[1001];

void init() {
    memset(constTIme, 0, sizeof(constTIme));
    memset(in_degree, 0, sizeof(in_degree));
    memset(minTIme, 0, sizeof(minTIme));
    for(int i = 0; i < 100001; i++) {
        builds[i].clear();
    }
}

void input() {
    cin >> construction >> build;
    for(int i = 1; i <= construction; i++) {
        cin >> constTIme[i];
    }
    for(int i = 0; i < build; i++) {
        int idx, next;
        cin >> idx >> next;
        builds[idx].push_back(next);
        in_degree[next]++;
    }
    cin >> target;
}

void solution() {
    queue<int> q;
    for(int i = 1; i <= construction; i++) { // in_degree가 0인 점 (출발점) 찾아서 queue에 push
        if(in_degree[i] == 0) {
            q.push(i);
            minTIme[i] = constTIme[i]; // 출발점은 건설 시간만 고려하면 됨
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < builds[cur].size(); i++) {
            int next = builds[cur][i];
            in_degree[next]--;
            minTIme[next] = max(minTIme[cur] + constTIme[next], minTIme[next]);
            // in_degree 값이 0이 아니더라도 minTIme은 갱신해줘야함!!
            // 그래야 필요 조건들 중 가장 최대값을 찾을 수 있음
            if(in_degree[next] == 0) { // 필요 조건을 모두 따져보아 minTIme을 구했다면 (in_degree 값이 0이라면) queue에 push
                q.push(next);   
            }
        }
    }
    cout << minTIme[target] << endl;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++) {
        init();
        input();
        solution();
    }
}

int main() {
    solve();
}