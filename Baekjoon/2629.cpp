#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int weight, marble, weightSum;
int weights[31];
int marbles[8];
bool dp[40001];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> weight;
    for(int i = 0; i < weight; i++) {
        cin >> weights[i];
        weightSum += weights[i];
    }
    cin >> marble;
    for(int i = 0; i < marble; i++) {
        cin >> marbles[i];
    }
}

void solve() {
    for(int i = 0; i < weight; i++) {
        int check = weights[i];
        bool tmpdp[40001];
        // 배열 복사 -> copy 함수
        copy(begin(dp), end(dp), begin(tmpdp));
        for(int i = 1; i <= weightSum; i++) {
            if(dp[i]) {
                tmpdp[check+i] = true;
                tmpdp[abs(check-i)] = true;
            }
        }
        tmpdp[check] = true;
        copy(begin(tmpdp), end(tmpdp), begin(dp));
    }
    for(int i = 0; i < marble; i++) {
        if(dp[marbles[i]]) {
            cout << "Y" << " ";
        }
        else {
            cout << "N" << " ";
        }
    }
}

int main() {
    init();
    solve();
}