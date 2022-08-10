#include <iostream>

using namespace std;

void solve(int n) {
    int num = 1;
    int digit = 1;
    while(true) {
        if(num % n == 0) {
            cout << digit << endl;
            break;
        }
        else {
            num = num * 10 + 1;
            num %= n;
            digit++;
        }
    }
}

int main() {
    int n;
    while(cin >> n) {
        solve(n);
    }
}