#include <iostream>
#include <stack>
#define MAX_VALUE 1001
#define MAX_NOW 0
#define SIZE_NOW 1

using namespace std;

int arraySize, output, lastIdx;
int input[MAX_VALUE];
int dp[2][MAX_VALUE];
stack<int> st;

void solve(int idx) {
    int maxNow = input[idx];
    int sizeNow = 0;
    dp[MAX_NOW][idx] = maxNow;
    dp[SIZE_NOW][idx] = 1;
    for(int i = 0; i < idx; i++) {
        if(dp[MAX_NOW][i] < maxNow && dp[SIZE_NOW][i] >= dp[SIZE_NOW][idx]) {
            dp[SIZE_NOW][idx] = dp[SIZE_NOW][i] + 1;
        }
    }
}

void print() {
    int tmpIdx = lastIdx;
    int tmpSize = output-1;
    st.push(input[lastIdx]);
    for(int i = lastIdx-1; i >= 0; i--) {
        if(dp[SIZE_NOW][i] == tmpSize && input[i] < input[tmpIdx]) {
            st.push(input[i]);
            tmpIdx = i;
            tmpSize--;
        }
    }
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
}

int main() {
    cin >> arraySize;
    for(int i = 0; i < arraySize; i++) {
        scanf("%d", &input[i]);
    }
    for(int j = 0; j < arraySize; j++) {
        solve(j);
    }
    for(int k = 0; k < arraySize; k++) {
        if(dp[SIZE_NOW][k] > output) {
            output = dp[SIZE_NOW][k];
            lastIdx = k;
        }
    }
    cout << output << endl;
    print();
}