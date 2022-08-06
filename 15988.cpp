#include <iostream>
#define MAX_VALUE 1000001

using namespace std;

int testcase, num;
long long output[MAX_VALUE];
long long dp[MAX_VALUE];
long long MOD_NUM = 1000000009;

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < MAX_VALUE; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD_NUM ;    
    }
    scanf("%d", &testcase);
    for(int j = 0; j < testcase; j++) {
        scanf("%d", &num);
        output[j] = dp[num];
    }
    for(int k = 0; k < testcase; k++) {
        printf("%lld\n", output[k]);
    }
}