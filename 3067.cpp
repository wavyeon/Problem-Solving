#include <iostream>
#include <cmath>
#include <vector>
#define endl '\n'

using namespace std;

int testcase, coinType, target;
// int coins[21];
vector<int> coins;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> testcase;
}

void solve() {
    for(int i = 0; i < testcase; i++) {
        coins.clear();
        int dp[21][10001];
        cin >> coinType;
        coins.push_back(-1);
        for(int j = 1; j <= coinType; j++) {
            int value;
            cin >> value;
            coins.push_back(value);
        }
        cin >> target;
        for(int j = 1; j <= coinType; j++) {
            dp[j][0] = 1;
        }
        for(int j = 1; j <= target; j++) {
            dp[0][j] = 0;
        }
        for(int j = 1; j <= coinType; j++) {
            for(int k = 1; k <= target; k++) {
                if(coins[j] > k) {
                    dp[j][k] = dp[j-1][k];
                }
                else {
                    dp[j][k] = dp[j-1][k] + dp[j][k-coins[j]];
                }
                
            }
        }
        cout << dp[coinType][target] << endl;
    }
}

int main() {
    init();
    solve();
}