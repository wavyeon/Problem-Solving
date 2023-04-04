#include <iostream>
#define MAX 91

using namespace std;

int n;
long long pibonacci[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    pibonacci[1] = 1;
}

void solve() {
    for(int i = 2; i <= n; i++) {
        pibonacci[i] = pibonacci[i-2] + pibonacci[i-1];
    }
    cout << pibonacci[n] << endl;
}

int main() {
    init();
    solve();
}