    #include <iostream>
#define MAX_SCOPE 100001

using namespace std;

int n;
int maxSum = -2147483648;
int input[MAX_SCOPE];
int dp[MAX_SCOPE];

void solve() {
    dp[0] = input[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(input[i], dp[i-1]+input[i]);
    }
    for(int j = 0; j < n; j++) {
        if(dp[j] > maxSum) {
            maxSum = dp[j];
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    solve();
    cout << maxSum << endl;
    
}