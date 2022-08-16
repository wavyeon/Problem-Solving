#include <iostream>
#include <algorithm>
#define MAX_SCOPE 100001

using namespace std;

long arr[MAX_SCOPE];
long target[MAX_SCOPE];
int length, tryTime;

void init() {
    scanf("%d", &length);
    for(int i = 0; i < length; i++) {
        scanf("%ld", &arr[i]);
    }
    sort(arr, arr+length);
    scanf("%d", &tryTime);
    for(int i = 0; i < tryTime; i++) {
        scanf("%ld", &target[i]);
    }
}

void binarySearch(int start, int end, int target) {
    if( (end - start) == 1) {
        if(arr[start] == target) {
            printf("1\n");
        }
        else if(arr[start] != target) {
            printf("0\n");
        }
    }
    else {
        if(target < arr[(start+end) / 2]) {
            binarySearch(start, (start+end)/2, target);
        }
        else if(target >= arr[(start+end) / 2]) {
            binarySearch((start+end) / 2, end, target);
        }
    }
}

void solve() {
    for(int i = 0; i < tryTime; i++) {
        binarySearch(0, length, target[i]);
    }
}

int main() {
    init();
    solve();
}