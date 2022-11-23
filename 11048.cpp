#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int n, m, cnt;
int maze[MAX][MAX];
int dp[MAX][MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }
}

void solve() {
    dp[1][1] = maze[1][1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + maze[i][j]; 
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
    init();
    solve();
}