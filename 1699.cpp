#include <iostream>
#define MAX_SCOPE 100001

using namespace std;

long long num, biggestSquareNum;
long long dp[MAX_SCOPE];

// long long findBiggestSquareNum(long long num) {
//     for(int i = 1; i <= num; i++) {
//         if(i*i > num) {
//             break;
//         }
//         biggestSquareNum = i*i;
//     }
//     return biggestSquareNum;
// }

void solve(long long num) {
    for(int i = 1; i <= num; i++) {
        dp[i] = 2147483647;
        for(int j = 1; j <= i; j++) {
            long long squareNum = j*j; 
            if(squareNum > i) {
                break;
            }
            if(dp[i] > dp[i - squareNum] + 1) {
                dp[i] = dp[i - squareNum] + 1;
            }
        }
    }
}

// void solve(long long num) {
//     for(int i = 1; i <= num; i++) {
//         dp[i] = dp[i-findBiggestSquareNum(i)] + 1;
//     }
// }

int main() {
    cin >> num;
    solve(num);
    cout << dp[num] << endl;
}