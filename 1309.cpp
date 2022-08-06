#include <iostream>
#define MAX_VALUE 100001
#define blank 0
#define left 1
#define right 2

using namespace std;

int dp[3][MAX_VALUE];
int numOfCase;
int main() {
    cin >> numOfCase;
    dp[blank][0] = 1;
    for(int i = 1; i <= numOfCase; i++) {
        dp[blank][i] = (dp[blank][i-1] + dp[left][i-1] + dp[right][i-1]) % 9901;
        dp[left][i] = (dp[blank][i-1] + dp[right][i-1]) % 9901;
        dp[right][i] = (dp[blank][i-1] + dp[left][i-1]) % 9901;
    }
    cout << (dp[blank][numOfCase] + dp[left][numOfCase] + dp[right][numOfCase]) % 9901 << endl;
}

