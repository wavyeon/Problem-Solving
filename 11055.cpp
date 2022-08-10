#include <iostream>
#define MAX_VALUE 1001

using namespace std;

int sizee;
int arr[MAX_VALUE];
int dp[MAX_VALUE];

void init() {
    scanf("%d", &sizee);
    for(int i = 1; i <= sizee; i++) {
        scanf("%d", &arr[i]);
    }
}

int findBiggestBefore(int idx) {
    int biggest = 0;
    for(int i = 1; i < idx; i++) {
        if(arr[i] < arr[idx] && dp[i] > biggest) {
            biggest = dp[i];
        }
    }
    return biggest;
}

void findMaxSum() {
    int maxSum = 0;
    for(int i = 1; i <= sizee; i++) {
        if(dp[i] > maxSum) {
            maxSum = dp[i];
        }
    }
    printf("%d\n", maxSum);
}

void solve() {
    for(int i = 1; i <= sizee; i++) {
        dp[i] = findBiggestBefore(i) + arr[i];
    }
    findMaxSum();
}

int main() {
    init();
    solve();
}   