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

int findLongestBefore(int idx) {
    int longest = 0;
    for(int i = 1; i < idx; i++) {
        if(arr[i] > arr[idx] && dp[i] > longest) {
            longest = dp[i];
        }
    }
    return longest;
}

void findLongestArr() {
    int longestLength = 0;
    for(int i = 1; i <= sizee; i++) {
        if(dp[i] > longestLength) {
            longestLength = dp[i];
        }
    }
    printf("%d\n", longestLength);
}

void solve() {
    for(int i = 1; i <= sizee; i++) {
        dp[i] = findLongestBefore(i) + 1;
    }
    findLongestArr();
}

int main() {
    init();
    solve();
}   