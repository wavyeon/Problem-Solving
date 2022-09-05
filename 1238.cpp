#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
int student, road, party;
int timeRecord[MAX];
int graph[MAX][MAX];
bool visited[MAX];

void init() {
    fill(&graph[0][0], &graph[MAX][MAX], 2147483647);
    scanf("%d %d %d", &student, &road, &party);
    int from, to, tmpTime;
    for(int i = 0; i < road; i++) {
        scanf("%d %d %d", &from, &to, &tmpTime);
        graph[from][to] = tmpTime;
    }
}

void solve() {
    for(int i = 0; i < student; i++) {
        
    }
}

int main() {
    init();
    solve();
}