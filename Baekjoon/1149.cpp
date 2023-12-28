#include <iostream>
#include <algorithm>
#define COLOR 3
#define MAX_HOUSE 1001

using namespace std;

int numOfHouse;
int red, green, blue;
int input[COLOR][MAX_HOUSE];
int dp[COLOR][MAX_HOUSE];

enum RGB {
    RED, GREEN, BLUE
};

void init() {
    scanf("%d", &numOfHouse);
    for(int i = 0; i < numOfHouse; i++) {
        scanf("%d %d %d", &input[RED][i], &input[GREEN][i], &input[BLUE][i]);
    }
    
}

int selectBigger(int x, int y) {
   int output = (x >= y) ? y : x;
   return output;   
}

void solve() {
    dp[RED][0] = input[RED][0];
    dp[GREEN][0] = input[GREEN][0];
    dp[BLUE][0] = input[BLUE][0];
    for(int i = 1; i < numOfHouse; i++) {
        dp[RED][i] = selectBigger(dp[GREEN][i-1], dp[BLUE][i-1]) + input[RED][i];
        dp[GREEN][i] = selectBigger(dp[RED][i-1], dp[BLUE][i-1]) + input[GREEN][i]; 
        dp[BLUE][i] = selectBigger(dp[RED][i-1], dp[GREEN][i-1]) + input[BLUE][i]; 
    }
}

void findMinCost() {
    cout << min({dp[RED][numOfHouse-1], dp[GREEN][numOfHouse-1], dp[BLUE][numOfHouse-1]}) << endl;
}

int main() {
    init();
    solve();
    findMinCost();
}