#include <iostream>
#include <algorithm>

using namespace std;

int numOfPeople;
const int MAX = 1001;
int timeCost[MAX];
int waitingTimeEach, waitingTimeSum;

void init() {
    scanf("%d", &numOfPeople);
    for(int i = 0; i < numOfPeople; i++) {
        scanf("%d", &timeCost[i]);
    }
    sort(timeCost, timeCost+numOfPeople);
}

void solve() {
    for(int i = 0; i < numOfPeople; i++) {
        waitingTimeEach += timeCost[i];
        waitingTimeSum += waitingTimeEach;
    }
    printf("%d\n", waitingTimeSum);
}

int main() {
    init();
    solve();
}