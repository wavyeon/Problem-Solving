#include <iostream>
#define MAX 101
#define endl '\n'
#define weight 0
#define value 1
using namespace std;

int load, capacity;
int info[MAX][2];
int dp[MAX];

void solve() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> load >> capacity;
    for(int i = 0; i < load; i++) {
        cin >> info[i][weight] >> info[i][value];
    }
    for(int i = 0; i < load; i++) { // dp 배열 초기화
        if(info[i][value] > dp[info[i][weight]]) {
            dp[info[i][weight]] = info[i][value]
        }
    }
    for(int i = 0; i < )

}

int main() {
    solve();
}