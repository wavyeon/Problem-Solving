//배열 사용해서 graph 저장하면 20000 X 20000 X 4(int) 이므로 메모리 초과 발생
//2차원 벡터 행의 개수만 알때 선언 방법 2가지 모두 숙지!
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 20001;
const int INF = 200001;
int vertex, edge, start;
int distlist[MAX];
// int graph[MAX][MAX];  메모리 초과로 사용 불가
// vector<vector<pair<int,int>>> graph(MAX);  이 방법도 된다!! 성능은 비슷
vector<pair<int,int>> graph[MAX];
priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

void input() {
    scanf("%d %d", &vertex, &edge);
    scanf("%d", &start);
    fill(&distlist[1], &distlist[1]+vertex, INF);
    distlist[start] = 0;
    int from, to, dist;
    for(int i = 0; i < edge; i++) {
        scanf("%d %d %d", &from, &to, &dist);
        graph[from].push_back(make_pair(to, dist));
    }
    // for(int i = 1; i <= vertex; i++) {
    //     for(int j = 0; j < graph[i].size(); j++) {
    //         cout << graph[i][j].first << " " << graph[i][j].second << " ";
    //     }
    //     cout << endl;
    // }
}

void solve() {
    pq.push(make_pair(0, start));
    int curIdx, curDist;
    while(!pq.empty()) {
        curDist = pq.top().first;
        curIdx = pq.top().second;
        pq.pop();
        for(int i = 0; i < graph[curIdx].size(); i++) {
            int nextDist = graph[curIdx][i].second + curDist;
            int nextIdx = graph[curIdx][i].first;
            if(distlist[nextIdx] > nextDist) {
                distlist[nextIdx] = nextDist;
                pq.push(make_pair(nextDist, nextIdx)); 
            }
        }
    }
}

void output() {
    for(int i = 1; i <= vertex; i++) {
        if(distlist[i] == INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n", distlist[i]);
        }
    }
}

int main() {
    input();
    solve();
    output();
}