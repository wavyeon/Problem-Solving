#include <iostream>
#define MAX_VALUE 1001
using namespace std;

int num;
long long dp[10][MAX_VALUE];

void init() {
    cin >> num;
    for(int i = 0; i < 10; i++) {
        dp[i][1] = 1;
    }
}

void solve() {
    for(int i = 2; i <= num; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k <= j; k++) {
                dp[j][i] = (dp[j][i] + dp[k][i-1]) % 10007;
            }
        }
    }
    int output = 0;
    for(int m = 0; m < 10; m++) {
        output = (output + dp[m][num]) % 10007;
    }
    cout << output << endl;
}

int main() {
    init();
    solve();    
}