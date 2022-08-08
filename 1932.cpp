#include <iostream>
#define MAX_VALUE 501

using namespace std;

int triangle[MAX_VALUE][MAX_VALUE];
int dp[MAX_VALUE][MAX_VALUE];
int sizee;

void init() {
    scanf("%d", &sizee);
    for(int i = 0; i < sizee; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }
}

void findMaxSum() {
    int maxSum = 0;
    for(int i = 0; i < sizee; i++) {
        if(dp[sizee-1][i] > maxSum) {
            maxSum = dp[sizee-1][i];
        }
    }
    printf("%d\n", maxSum);
}

void solve() {
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < sizee; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j]; 
            }
            else if(i == j) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    findMaxSum();
}

int main() {
    init();
    solve();
}