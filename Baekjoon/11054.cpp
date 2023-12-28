#include <iostream>
#define MAX_VALUE 1001

using namespace std;

int sizee;
int arr[MAX_VALUE];
int dp_inc[MAX_VALUE];
int dp_dec[MAX_VALUE];

void init() {
    scanf("%d", &sizee);
    for(int i = 1; i <= sizee; i++) {
        scanf("%d", &arr[i]);
    }
}

int findLongestIncreaseBefore(int idx) {
    int longest = 0;
    for(int i = 1; i < idx; i++) {
        if(arr[i] < arr[idx] && dp_inc[i] > longest) {
            longest = dp_inc[i];
        }
    }
    return longest;
}

int findLongestDecreaseAfter(int idx) {
    int longest = 0;
    for(int i = sizee; i > idx; i--) {
        if(arr[i] < arr[idx] && dp_dec[i] > longest) {
            longest = dp_dec[i];
        }
    }
    return longest;
}


int findLongestBitonicArr() {
    int longestLength = 0;
    for(int i = 1; i <= sizee; i++) {
        if(dp_inc[i] + dp_dec[i] - 1 > longestLength) {
            longestLength = dp_inc[i] + dp_dec[i] - 1;
        }
    }
    return longestLength;
}

void solve() {
    for(int i = 1; i <= sizee; i++) {
        dp_inc[i] = findLongestIncreaseBefore(i) + 1;
    }
    for(int i = sizee; i >= 1; i--) {
        dp_dec[i] = findLongestDecreaseAfter(i) + 1;
    }
    int output = findLongestBitonicArr();
    printf("%d\n", output);
}

int main() {
    init();
    solve();
}   