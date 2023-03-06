#include <iostream>

using namespace std;

int testcase, building, order;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> testcase;
}

void solve() {
    for(int i = 0; i < testcase; i++) {
        cin >> building >> order;
        int* delay = new int[1001];
        for(int i = 1; i <= building; i++) {
            cin >> delay[i];
        }
    }
}

int main() {
    init();
    solve();
}