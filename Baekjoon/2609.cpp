#include <iostream>

using namespace std;

void solve() {
    int a, b, mul;
    int gcd, lcm;
    cin >> a >> b;
    mul = a * b;
    if(a < b) {
        int c;
        c = a;
        a = b;
        b = c;
    }
    while(a % b != 0) {
        int q, r;
        q = a / b;
        r = a % b;
        a = b;
        b = r;
    }
    gcd = b;
    lcm = mul / gcd;
    cout << gcd << endl << lcm << endl;
}

int main() {
    solve();
}