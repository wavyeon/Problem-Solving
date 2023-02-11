// 기존의 배낭 문제와 조금 다름!! 매우 중요!!
// 기존 문제에서의 무게 -> 이번 문제에서의 비용 (X축)
// 기존 문제에서의 가치 -> 이번 문제에서의 메모리 (값)
// 기존 문제에서는 무게에 제한이 있을 때 최대의 가치를 뽑아내는 경우를 찾는 것이 목표
// 이번 문제에서는 최소의 비용으로 목표량 이상의 메모리를 뽑아내는 경우를 찾는 것이 목표
// dp 값의 의미가 다름 (i번째 앱까지 고려했을 때, j의 비용으로 얻을 수 있는 최대 메모리)
#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define MAX 101

using namespace std;

int app, memory, costSum;
int resource[MAX];
int cost[MAX];
int dp[MAX][10001];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> app >> memory;
    for(int i = 1; i <= app; i++) {
        cin >> resource[i];
    }
    for(int i = 1; i <= app; i++) {
        cin >> cost[i];
        // 기존의 문제와 달리 무게에 제한이 있는 것이 아니라 최소의 비용을 찾는 문제임
        // x축의 범위인 무게 최대값이 없으므로 비용의 합을 구해 비용 최대값을 찾아줌
        costSum += cost[i];
    }
}

void solve() {
    for(int i = 1; i <= app; i++) {
        for(int j = 0; j <= costSum; j++) {
            if(cost[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max( resource[i] + dp[i-1][j-cost[i]],
                                dp[i-1][j] );
            }
        }
    }
    // 기존 문제와의 다른 점
    // DP 2차원 배열 오른쪽 끝의 값을 뽑아내는 것이 아님
    // 모든 앱을 체크했을 때 (dp[app][]) 낮은 cost부터 높은 cost까지 탐색하며 최초로 메모리 목표량 이상을 뽑아내는 경우를 찾음
    for(int i = 0; i <= costSum; i++) {
        if(dp[app][i] >= memory) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    init();
    solve();
}