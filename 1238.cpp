#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;
int student, road, party;
int timeRecord[MAX];
int originalGraph[MAX][MAX];
int tmpGraph[MAX][MAX];
int goTime[MAX];
int backTime[MAX];
int roundTime[MAX];
bool isVisited[MAX];
priority_queue<  pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;

void input() {
    fill(&originalGraph[0][0], &originalGraph[MAX][MAX], 100001);
    for(int i = 0; i < MAX; i++) {
        originalGraph[i][i] = 0;
    }
    scanf("%d %d %d", &student, &road, &party);
    int from, to, tmpTime;
    for(int i = 0; i < road; i++) {
        scanf("%d %d %d", &from, &to, &tmpTime);
        originalGraph[from][to] = tmpTime;
    }
}

void init(int idx) {
    fill(&isVisited[0], &isVisited[MAX], false);
    for(int i = 1; i <= student; i++) {
        timeRecord[i] = originalGraph[idx][i];
    }
}

void bfs(int idx) {
    // cout << idx << "시작 ------------------------------------------" << endl;
    q.push(make_pair(idx, 0));
    isVisited[idx] = true;
    while(!q.empty()) {
        int curIdx = q.top().first;
        int curTime = q.top().second;
        q.pop();
        // cout << "현재 방문: " << curIdx << endl;
        int nextIdx = 0;
        int tmpMax = 100001;
        for(int i = 1; i <= student; i++) {
            if(originalGraph[curIdx][i] + curTime < timeRecord[i] ) {
                timeRecord[i] = originalGraph[curIdx][i] + curTime;
            }
            if(!isVisited[i] && originalGraph[curIdx][i] > 0 && originalGraph[curIdx][i] < 100001) {
                if(timeRecord[i] < tmpMax) {
                    tmpMax = timeRecord[i];
                    nextIdx = i;
                }
            }
        }
        if(nextIdx != 0) {
            // cout << nextIdx << "를 push" << endl;
            q.push(make_pair(nextIdx, curTime + originalGraph[curIdx][nextIdx]));
            isVisited[nextIdx] = true;
        }
        // for(int i = 1; i <= student; i++) {
        //     cout << timeRecord[i] << " ";
        // }
        // cout << endl;
    }
}

void solve() {
    for(int i = 1; i <= student; i++) {
        init(i);
        bfs(i);
        goTime[i] = timeRecord[party];
        if(i == party) {
            for(int j = 1; j <= student; j++) {
                backTime[j] = timeRecord[j];
            }
        }
    }
    int output = 0;
    for(int i = 1; i <= student; i++) {
        roundTime[i] = goTime[i] + backTime[i];
        if(roundTime[i] > output) {
            output = roundTime[i];
        }
        // cout << i << "왕복: " << roundTime[i] << " ";
    }
    // cout << endl;
    cout << output << endl;
}

int main() {
    input();
    solve();
}