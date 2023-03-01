#include <iostream>
#include <algorithm>
#define COLOR 3
#define MAX 1001
#define INF 2147483647

using namespace std;

int house;
int cost[COLOR][MAX];
int redStart[COLOR][MAX];
int greenStart[COLOR][MAX];
int blueStart[COLOR][MAX];

enum RGB {
    RED, GREEN, BLUE
};

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> house;
    for(int i = 1; i <= house; i++) {
        cin >> cost[RED][i] >> cost[GREEN][i] >> cost[BLUE][i];
    }

    redStart[RED][2] = INF;
    redStart[GREEN][2] = cost[RED][1] + cost[GREEN][2];
    redStart[BLUE][2] = cost[RED][1] + cost[BLUE][2];

    greenStart[RED][2] = cost[GREEN][1] + cost[RED][2];
    greenStart[GREEN][2] = INF;
    greenStart[BLUE][2] = cost[GREEN][1] + cost[BLUE][2];

    blueStart[RED][2] = cost[BLUE][1] + cost[RED][2];
    blueStart[GREEN][2] = cost[BLUE][1] + cost[GREEN][2];
    blueStart[BLUE][2] = INF;
}

void findAnswer(int idx) { // 마지막 집과 시작 집이 다른 색인 경우만 고려!
    cout << min({redStart[GREEN][idx], redStart[BLUE][idx], 
                greenStart[RED][idx], greenStart[BLUE][idx],
                blueStart[RED][idx], blueStart[GREEN][idx]}) << endl;
}

void solve() {
    if(house == 2) {
        findAnswer(2);
        return;
    }
    else {
        for(int i = 3; i <= house; i++) {

            redStart[RED][i] = min(redStart[GREEN][i-1], redStart[BLUE][i-1]) + cost[RED][i];
            redStart[GREEN][i] = min(redStart[RED][i-1], redStart[BLUE][i-1]) + cost[GREEN][i];
            redStart[BLUE][i] = min(redStart[RED][i-1], redStart[GREEN][i-1]) + cost[BLUE][i];

            greenStart[RED][i] = min(greenStart[GREEN][i-1], greenStart[BLUE][i-1]) + cost[RED][i];
            greenStart[GREEN][i] = min(greenStart[RED][i-1], greenStart[BLUE][i-1]) + cost[GREEN][i];
            greenStart[BLUE][i] = min(greenStart[RED][i-1], greenStart[GREEN][i-1]) + cost[BLUE][i];

            blueStart[RED][i] = min(blueStart[GREEN][i-1], blueStart[BLUE][i-1]) + cost[RED][i];
            blueStart[GREEN][i] = min(blueStart[RED][i-1], blueStart[BLUE][i-1]) + cost[GREEN][i];
            blueStart[BLUE][i] = min(blueStart[RED][i-1], blueStart[GREEN][i-1]) + cost[BLUE][i];

        }
        findAnswer(house);
        return;
    }
    
}

int main() {
    init();
    solve();
}