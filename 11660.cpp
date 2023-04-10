#include <iostream>
#define endl '\n'

using namespace std;

int n, test;
int graph[1025][1025];
int dp[1025][1025];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> test;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    dp[1][1] = graph[1][1];
    // idx가 0인 부분 이용해서 하나의 점화식으로 나타낼 수 있었음
    for(int i = 2; i <= n; i++) {
        dp[1][i] = dp[1][i-1] + graph[1][i];
    }
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i-1][1] + graph[i][1];
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i][j];
        }
    }
}

void solve() {
    int x1, y1, x2, y2, ans;
    for(int i = 0; i < test; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << endl;
    }
}

int main() {
    init();
    solve();
}