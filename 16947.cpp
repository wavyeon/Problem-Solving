#include <iostream>
#include <vector>
#include <stack>
#define endl '\n'

using namespace std;

int station, from, to, testCase;
const int MAX = 3001;
vector<vector<int>> graph(MAX);
bool visited[station] = {false};

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> station;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void findCycle() {
    for(int i = 0; i < station; i++) {
        
    }
}

void solve() {
    findCycle();
    findDist();
}

int main() {
    init();
    solve();

}