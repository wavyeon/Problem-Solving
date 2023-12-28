// dp[][]의 의미: i번째 도시까지 따져보았을 때 j명의 고객을 유치하기 위해 필요한 최소한의 비용
#include <iostream>
#include <cmath>

using namespace std;

int target, city; 
int cost[21];
double custom[21];
int dp[21][1001];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> target >> city;
    for(int i = 1; i <= city; i++) {
        cin >> cost[i] >> custom[i];
    }
}

void solve() {
    for(int j = 1; j <= target; j++) {
        dp[1][j] = ceil(((double)j / custom[1])) * cost[1]; // 1번째 도시만 고려했을 때 (1번째 도시에만 홍보하는 경우)
    }
    for(int i = 2; i <= city; i++) {
        for(int j = 1; j <= target; j++) {
            dp[i][j] = ceil(((double)j / custom[i])) * cost[i]; // i번째 도시만 고려했을 때 (i번째 도시에만 홍보하는 경우)
            int maxAd = j / custom[i]; 
            for(int k = 0; k <= maxAd; k++) {
                dp[i][j] = min( dp[i][j], dp[i-1][j - k * (int)custom[i]] + k * cost[i] );
            }
        }
    }
    cout << dp[city][target] << endl;
}

int main() {
    init();
    solve();
}