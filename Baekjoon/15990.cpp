#include <iostream>
#define MAX_VALUE 100001

using namespace std;

int testCase, n;
long long dp[4][MAX_VALUE];
int output[MAX_VALUE];

void setDp() {
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[1][3] = 1;
    dp[2][3] = 1;
    dp[3][3] = 1;
    for(int i = 4; i < MAX_VALUE; i++) {
        dp[1][i] = ( (dp[2][i-1] % 1000000009) + (dp[3][i-1] % 1000000009) ) % 1000000009;
        dp[2][i] = ( (dp[1][i-2] % 1000000009) + (dp[3][i-2] % 1000000009) ) % 1000000009;
        dp[3][i] = ( (dp[1][i-3] % 1000000009) + (dp[2][i-3] % 1000000009) ) % 1000000009;
    }
}

int main() {
    setDp();
    cin >> testCase;
    for(int i = 0; i < testCase; i++) {
        scanf("%d", &n);
        output[i] = (dp[1][n] + dp[2][n] + dp[3][n]) % 1000000009;
    }
    for(int i = 0; i < testCase; i++) {
        printf("%d\n", output[i]);
    }
}