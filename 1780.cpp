#include <iostream>
#include <cmath>
#define MAX 2188

using namespace std;

int n, paperSize, minus, zero, plus;
int paper[MAX][MAX];

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
}

int cutPaper(int x, int y, int sz) {
    if(sz == 1) {
        return paper[y][x];      
    }
    int dist = sz / 3;
    int slice[3][3];
    for(int i = y; i < y + sz; i += dist) {
        for(int j = x; j < x + sz; j += dist) {
            slice[i][j] = cutPaper(j, i, dist);
            
        }
    }
}

void solve() {
    cutPaper(0, 0, n);
}

int main() {
    init();
    solve();
}