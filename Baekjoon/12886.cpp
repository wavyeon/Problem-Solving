#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int a,b,c;
int sum;
bool visited[1501][1501];
queue<pair<int,int>> q;

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    sum = a + b + c;
}

void solve() {
    if(sum % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    q.push({a,b});
    visited[a][b] = true;
    int curA, curB, curC;
    while(!q.empty()) {
        curA = q.front().first;
        curB = q.front().second;
        curC = sum - curA - curB;
        if(curA == curB && curB == curC) {
            cout << 1 << endl;
            return;
        }
        q.pop();
        int cur[3] = {curA, curB, curC};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                // if(cur[i] > cur[j]) {
                //     if(visited[cur[i]-cur[j]][cur[j]+cur[j]] = false) {
                //         q.push({cur[i]-cur[j], cur[j]+cur[j]});
                //         visited[cur[i]-cur[j]][cur[j]+cur[j]] = true;
                //     }
                // }
                // else if(cur[i] < cur[j]) {
                //     if(visited[cur[i]+cur[i]][cur[j]-cur[i]] = false) {
                //         q.push({cur[i]+cur[i], cur[j]-cur[i]});
                //         visited[cur[i]+cur[i]][cur[j]-cur[i]] = true;
                //     }
                // }
                // else {
                //     continue;
                // }





                if(cur[i] < cur[j]) {
                    if(visited[cur[i]*2][cur[j]-cur[i]] == true) {
                        continue;
                    }
                    q.push({cur[i]*2, cur[j]-cur[i]});
                    visited[cur[i]*2][cur[j]-cur[i]] = true;
                }
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    input();
    solve();
}