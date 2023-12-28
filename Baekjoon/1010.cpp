#include <iostream>
#include <algorithm>
#define MAX 31
#define endl '\n'

using namespace std;

int testcase, n, m;
int dp[MAX][MAX];

void solve() {
    int output = 0;
    cin >> n >> m;
    fill(&dp[0][0], &dp[MAX][0], 0);
    for(int i = 1; i <= m; i++) {
        dp[i][1] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k < j; k++) {
                dp[j][i] += dp[k][i-1];
            }
        }
    }
    for(int i = n; i <= m; i++) {
        output += dp[i][n];
    }
    cout << output << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> testcase;
    while(testcase--) {
        solve();
    }
}