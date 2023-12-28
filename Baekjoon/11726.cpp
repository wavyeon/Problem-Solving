#include <iostream>
#define MAX_VALUE 1002

using namespace std;

int n;
int dp[MAX_VALUE];

int main() {
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < MAX_VALUE; i++) {
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    }
    cin >> n;
    cout << dp[n] % 10007 << endl; 
}
