#include <iostream>
#define MAX_SCOPE 11

using namespace std;

void solve(int testCase) {
    int DP[MAX_SCOPE+1] = {0, };
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for(int i = 4; i <= MAX_SCOPE; i++) {
        DP[i] = DP[i-3] + DP[i-2] + DP[i-1];
    }
    int output[testCase+1];
    for(int j = 0; j < testCase; j++) {
        cin >> output[j];
    }
    for(int k = 0; k < testCase; k++) {
        cout << DP[output[k]] << endl;
    } 
}

int main() {
    int testCase;
    cin >> testCase;
    solve(testCase);
}