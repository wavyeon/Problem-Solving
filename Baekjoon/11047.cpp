#include <iostream>

using namespace std;

const int MAX = 1000001;
int coinType, targetValue;
int coin[MAX];

void init() {
    scanf("%d %d", &coinType, &targetValue);
    for(int i = 0; i < coinType; i++) {
        scanf("%d", &coin[i]);
    }
}

void solve(int targetValue, int idx, int numOfCase) {
    for(int i = idx; i >= 0; i--) {
        if(targetValue / coin[i] > 0) {
            for(int j = targetValue / coin[i]; j > 0; j--) {
                if(targetValue - (coin[i]*j) == 0) {
                    printf("%d\n", numOfCase+j);
                    exit(0);
                }
                solve(targetValue - (coin[i]*j), idx-1, numOfCase+j);
            }
        }
    }
}

int main() {
    init();
    solve(targetValue, coinType-1, 0);
}