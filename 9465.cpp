#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int sticker[2][MAX];
int dp[2][MAX];
int test, col;
vector<int> output;

void solve() {
    cin >> test;
    for(int i = 0; i < test; i++) {
        cin >> col;
        for(int i = 0; i < col; i++) {
            cin >> sticker[0][i];
        }
        for(int i = 0; i < col; i++) {
            cin >> sticker[1][i];
        }
        dp[0][0] = sticker[0][0];  dp[0][1] = sticker[1][0] + sticker[0][1];
        dp[1][0] = sticker[1][0];  dp[1][1] = sticker[0][0] + sticker[1][1];
        for(int i = 2; i < col; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        output.push_back(max(dp[0][col-1], dp[1][col-1]));
    }
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << "\n";
    }
}

int main() {
    solve();
}