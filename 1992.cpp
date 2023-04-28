#include <iostream>
#define endl '\n'
#define MAX 65

using namespace std;

int n;
int video[MAX][MAX];

void init() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%1d", &video[i][j]);
        }
    }
}

bool check(int x, int y, int sz) {
    int rep = video[y][x];
    for(int i = y; i < y + sz; i++) {
        for(int j = x; j < x + sz; j++) {
            if(rep != video[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void quadTree(int x, int y, int sz) {
    if(check(x, y, sz)) {
        cout << video[y][x];
    }
    else {
        cout << "(";
        int dist = sz / 2;
        quadTree(x, y, dist);
        quadTree(x + dist, y, dist);
        quadTree(x, y + dist, dist);
        quadTree(x + dist, y + dist, dist);
        cout << ")";
    }
}

void solve() {
    quadTree(1, 1, n);
}

int main() {
    init();
    solve();
}