#include <iostream>
#include <algorithm>
#define MAX_VALUE 100001

using namespace std;

int n;
int arr[MAX_VALUE];
int originalDP[MAX_VALUE];
int passedDP[MAX_VALUE];

void init() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void findMaxConnectedSum() {
    originalDP[0] = arr[0];
    for(int i = 1; i < n; i++) {
        originalDP[i] = max(arr[i], originalDP[i-1] + arr[i]);
    }
}
void findMaxConnectedSumWithPass() {
    passedDP[0] = arr[0];
    passedDP[1] = arr[1];
    for(int i = 1; i < n; i++) {
        passedDP[i] = max(originalDP[i-2], passedDP[i-1]) + arr[i];
    }
}

void findMaxSum() {
    int output = 0;
    for(int i = 0; i < n; i++) {
        if(originalDP[i] > output) {
            output = originalDP[i];
        }
        if(passedDP[i] > output) {
            output = passedDP[i];
        }
    }
    cout << output << endl;
}

int main() {
    init();
    findMaxConnectedSum();
    findMaxConnectedSumWithPass();
    findMaxSum();
}