#include <iostream>
#include <set>

using namespace std;

int n, m, x;
const int MAX = 9;
set<int> arr;
int output[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.insert(x);
    }
}

void solve(int digit, int prev) {
    if(digit == m) {
        for(int i = 0; i < m; i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
    }
    else {
        set<int>::iterator it;
        for(it = arr.begin(); it != arr.end(); it++) {
            if(*it >= prev) {
                output[digit] = *it;
                solve(digit+1, *it);
            }
        }
    }
}

int main() {
    init();
    solve(0, 0);
}