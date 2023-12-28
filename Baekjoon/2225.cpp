#include <iostream>
#define MAX_SUM 201
#define MAX_CASE 201

using namespace std;

int sum, numOfCase;
long long dp[MAX_CASE][MAX_SUM];

void init() {
    cin >> sum >> numOfCase;
    for(int i = 0; i <= sum; i++) {
        dp[1][i] = 1;
    }
    for(int j = 0; j <= numOfCase; j++) {
        dp[j][0] = 1;
    }
}

void solve() {
    for(int i = 1; i <= sum; i++) {
        for(int j = 2; j <= numOfCase; j++) {
            for(int k = 0; k <= i; k++) {
                dp[j][i] += (dp[j-1][k] % 1000000000);
            }
        }
    }
}

int main() {
    init();
    solve();
    cout << dp[numOfCase][sum] % 1000000000 << endl;
}

// dp[k][n] = dp[k-1][0] + dp[k-1][1] +  + dp[k-1][n]