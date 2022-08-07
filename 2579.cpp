#include <iostream>
#include <algorithm>
#define MAX_STAIR 302

using namespace std;

int stair[MAX_STAIR];
int dp[MAX_STAIR];
int numOfStair;

void init() {
    scanf("%d", &numOfStair);
    for(int i = 1; i <= numOfStair; i++) {
        scanf("%d", &stair[i]);
    }
}

void solve() {
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    for(int i = 1; i <= numOfStair; i++) {
        dp[i] = max( (dp[i-3] + stair[i-1] + stair[i]), (dp[i-2] + stair[i]) );
    }
    // XOO dp[i-3] + stair[i-1] + stair[i]
    // OXO dp[i-2] + stair[i]
    // OOX 마지막 계단 밟아야하므로 고려 X
    cout << dp[numOfStair] << endl;
}

int main() {
    init();
    solve();
}