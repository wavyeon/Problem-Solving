#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'

using namespace std;

int load, capacity;
vector<pair<int,int>> loads;
int dp[101][100001];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> load >> capacity;
    int tmpWeight, tmpValue;
    loads.push_back({-1,-1}); // index 조절용
    for(int i = 0; i < load; i++) {
        cin >> tmpWeight >> tmpValue;
        loads.push_back({tmpWeight, tmpValue});
    }
    for(int i = 0; i < load; i++) { // 공간이 없는 경우 -> 0
        dp[i][0] = 0;
    }
    for(int j = 0; j < capacity; j++) { // 짐이 없는 경우 -> 0
        dp[0][j] = 0;
    }
}

void solve() { 
    for(int i = 1; i <= load; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(loads[i].first > j) { // 배낭 공간보다 i번째 짐의 무게가 큰 경우 (넣을 수 없음) 
                dp[i][j] = dp[i-1][j]; // 같은 배낭 공간일 때 i-1번째 짐까지 넣은 경우와 같음
            }
            else { // 배낭 공간보다 i번째 짐의 무게가 작거나 같은 경우 (넣을 수 있음)
                dp[i][j] = max( (dp[i-1][j-loads[i].first] + loads[i].second), // i번째 짐을 넣은 경우
                                (dp[i-1][j]) ); // i번째 짐을 넣지 않은 경우
            }
        }
    }
    cout << dp[load][capacity] << endl;
}

int main() {
    init();
    solve();
}