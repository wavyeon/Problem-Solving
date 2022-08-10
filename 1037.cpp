#include <iostream>
#include <algorithm>

using namespace std;

void solve(int n) {
    int* d = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d, d+n);
    cout << d[0] * d[n-1] << endl;
}

int main() {
    int n;
    cin >> n;
    solve(n);
}