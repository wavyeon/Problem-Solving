#include <iostream>
#include <algorithm>
#define MAX_VALUE 10001

using namespace std;

int num;
int wine[MAX_VALUE];
int dp[MAX_VALUE];

void solve() {
    scanf("%d", &num);
    for(int i = 1; i <= num; i++) {
        scanf("%d", &wine[i]);
    }
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    for(int i = 3; i <= num; i++) {
        dp[i] = max({ (dp[i-3] + wine[i-1] + wine[i]), (dp[i-2] + wine[i]), (dp[i-1]) });
    }
    // X O O dp[i-3] + wine[i-1] + wine[i]
    // O X O dp[i-2] + wine[i]
    // O O X dp[i-1]
    printf("%d\n", dp[num]);
}

int main() {
    solve();
}