#include<iostream>
#include<string>
#include<algorithm>
#define MAX 1001

using namespace std;

int dp[MAX][MAX];
string a, b;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
}

void solve() {
    for (int i = 1; i <= a.length(); i++) { //인덱싱 유의
        for (int j = 1; j <= b.length(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }
    cout << dp[a.length()][b.length()] << "\n";
}

int main() {
    init();
    solve();
}