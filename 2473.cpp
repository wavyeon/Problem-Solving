#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define MAX 5001

using namespace std;

int n;
long long solution[MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> solution[i];
    }
    sort(solution, solution + n);
}

void solve() {
    int first, second, third;
    int start = 0;
    int end = n-1;
    long long chrVal = 3000000001;
    while(start != end) {
        long long twoSum = solution[start] + solution[end];
        long long threeSum;
        for(int i = start + 1; i < end; i++) {
            threeSum = twoSum + solution[i];
            if(abs(threeSum) < chrVal) {
                chrVal = abs(threeSum);
                first = solution[start];
                second = solution[i];
                third = solution[end];
            }
        }
        if(threeSum >= 0) {
            end--;
        }
        else if(threeSum < 0) {
            start++;
        }
    }
    cout << first << " " << second << " " << third << endl;
}

int main() {
    init();
    solve();
}