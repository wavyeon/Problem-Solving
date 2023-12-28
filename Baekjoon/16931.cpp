#include <iostream>
#include <algorithm>
#define MAX 101
#define endl '\n'

using namespace std;

int n, m, outerWidth, horSide, verSide;
int block[MAX][MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            cin >> block[i][j];
        }
    }
}

void countSide(int i, int j) {
    // 위 
    if(i == 0) {
        verSide += block[i][j];
    }
    else {
        if(block[i-1][j] < block[i][j]) {
            verSide += (block[i][j] - block[i-1][j]);
        }
    }
    // 아래
    if(i == n-1) {
        verSide += block[i][j];
    }
    else {
        if(block[i+1][j] < block[i][j]) {
            verSide += (block[i][j] - block[i+1][j]);
        }
    }
    // 왼쪽
    if(j == 0) {
        horSide += block[i][j];
    }
    else {
        if(block[i][j-1] < block[i][j]) {
            horSide += (block[i][j] - block[i][j-1]);
        }
    }
    // 오른쪽
    if(j == m-1) {
        horSide += block[i][j];
    }
    else {
        if(block[i][j+1] < block[i][j]) {
            horSide += (block[i][j] - block[i][j+1]);
        }
    }
}

void solve() {
    outerWidth += n*m*2; // 윗면 아랫면
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            countSide(i, j); // 옆면
        }
    }
    outerWidth += (horSide + verSide);
    cout << outerWidth << endl;
}

int main() {
    init();
    solve();
}