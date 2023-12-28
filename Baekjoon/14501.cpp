#include <iostream>
#define MAX_DAYS 16
#define finishDay 0
#define profit 1

using namespace std;

int day;
int input[MAX_DAYS];
int dp[2][MAX_DAYS];

void init() {
    int period, price;
    for(int i = 1; i <= day; i++) {
        scanf("%d %d", &period, &price);
        input[i] = price;
        dp[finishDay][i] = i + period - 1;
    }
}

int checkFinishedMeeting(int now) {
    int maxProift = 0;
    for(int i = 1; i < now; i++) {
        if(dp[finishDay][i] < now && dp[profit][i] > maxProift) {
            maxProift = dp[profit][i];
        }
    }
    return maxProift;
}

void solve() {
    for(int i = 1; i <= day; i++) {
        dp[profit][i] = input[i] + checkFinishedMeeting(i);
    }
    int output = 0;
    for(int i = 1; i <= day; i++) {
        if(dp[profit][i] >= output && dp[finishDay][i] <= day) {
            output = dp[profit][i];
        }
    }
    cout << output << endl;
}

int main() {
    cin >> day;
    init();
    solve();
}