#include <iostream>
#define MAX_VALUE 41
#define MAX_TESTCASE 1000000
#define zeroCount 0
#define oneCount 1

using namespace std;

int testCase;
int fibo[MAX_VALUE];
int count[2][MAX_VALUE];
int output[2][MAX_TESTCASE];

void solve() {
    count[zeroCount][0] = 1;
    count[oneCount][0] = 0;
    count[zeroCount][1] = 0;
    count[oneCount][1] = 1;
    for(int i = 2; i < MAX_VALUE; i++) {
        count[zeroCount][i] = count[zeroCount][i-2] + count[zeroCount][i-1];
        count[oneCount][i] = count[oneCount][i-2] + count[oneCount][i-1];
    }
}

int main() {
    scanf("%d", &testCase);
    solve();
    for(int i = 0; i < testCase; i++) {
        int num;
        scanf("%d", &num);
        output[0][i] = count[0][num];
        output[1][i] = count[1][num];
    }
    for (int i = 0; i < testCase; i++) {
        printf("%d %d\n", output[0][i], output[1][i]);
    }
}