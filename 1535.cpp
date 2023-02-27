#include <iostream>
#include <cmath>

using namespace std;

int people, output;
int hp[21];
int plz[21];
int dp[21][101];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> people;
    for(int i = 1; i <= people; i++) {
        cin >> hp[i];
    }
    for(int i = 1; i <= people; i++) {
        cin >> plz[i];
    }
}   

void solve() {
    for(int i = 1; i <= people; i++) {
        for(int j = 1; j < 100; j++) {
            if(j < hp[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max( dp[i-1][j - hp[i]] + plz[i],
                                dp[i-1][j] );
            }
        }
    }
    for(int i = 1; i < 100; i++) {
        output = max(output, dp[people][i]);
    }
    cout << output << endl;
}

int main() {
    init();
    solve();
}