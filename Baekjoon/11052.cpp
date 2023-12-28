#include <iostream>
#include <math.h>
#define MAX_VALUE 1001

using namespace std;

int num;
int price[MAX_VALUE];
int dp[MAX_VALUE];

int dividedBuy(int idx) {
    int maxPrice = 0;
    for(int i = 1; i <= idx/2; i++) {
        if( (dp[i] + dp[idx-i]) > maxPrice) {
            maxPrice = dp[i] + dp[idx-i];
        }
    }
    return maxPrice;
}

void solve() {
    dp[0] = 0;
    dp[1] = price[1];
    for(int i = 2; i < MAX_VALUE; i++) {
        dp[i] = max(price[i], dividedBuy(i));
    }
}

int main() {
    cin >> num;
    for(int i = 1; i <= num; i++) {
        scanf("%d", &price[i]);
    }
    solve();
    cout << dp[num];
}
