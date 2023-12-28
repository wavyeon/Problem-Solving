#include <iostream>
#define MAX_VALUE 1001

using namespace std;

int num;
long long output;
long long dp[10][MAX_VALUE];

int main() {
    cin >> num;
    fill(&dp[0][0], &dp[9][MAX_VALUE], 1);
    dp[0][1] = 0;
    dp[0][2] = 1;
    dp[1][2] = 1;
    for(int i = 2; i < 9; i++) {
        dp[i][2] = 2;
    }
    dp[9][2] = 1;
    for(int i = 3; i <= num; i++) {
        for(int j = 1; j < 9; j++) {
            dp[j][i] = (dp[j-1][i-1] % 1000000000 + dp[j+1][i-1] % 1000000000) % 1000000000;
        }
        dp[0][i] = dp[1][i-1] % 1000000000;
        dp[9][i] = dp[8][i-1] % 1000000000;
    }
    for(int i = 0; i <= 9; i++) {
        output += (dp[i][num] % 1000000000);
    }
    cout << output % 1000000000 << endl;
}   