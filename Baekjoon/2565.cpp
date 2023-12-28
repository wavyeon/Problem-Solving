// LIS (가장 긴 증가하는 부분 수열) 문제와 같음
#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAX 101

using namespace std;
 
struct line {
    int left;
    int right;
};
 
int n;
int dp[MAX];
line lines[MAX];
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void init() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> lines[i].left >> lines[i].right;
    }
}
 
bool cmp(line A, line B) {
    if (A.left < B.left) { // 왼쪽 전봇대 기준으로 정렬
        return true; // true => 순서바꾸지 않아도 됨
    }
    else {
        return false; // false => 순서 바꿔야 함
    }
}
 
void solve() {
    int goodWire = 0;
    sort(lines + 1, lines + n + 1, cmp); // 왼쪽 전봇대 기준으로 정렬
    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if(lines[i].right > lines[j].right) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        goodWire = max(goodWire, dp[i]); // 가장 긴 증가하는 부분수열의 길이
    }
    cout << n - goodWire << endl;
}
 
int main(void) {
    init();
    solve();
}
