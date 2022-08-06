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
    dp[numOfStair] = stair[numOfStair];
    dp[numOfStair-1] = stair[numOfStair] + stair[numOfStair-1];
    for(int i = numOfStair-2; i >= 1; i--) {
        dp[i] = max({ (dp[i+3] + stair[i+1] + stair[i]), (dp[i+2] + stair[i]), (dp[i+1]) });
    }
    // XOO
    // OXO
    // OOX
    cout << dp[1] << endl;
}

int main() {
    init();
    solve();
}