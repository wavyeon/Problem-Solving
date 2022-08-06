#include <iostream>

using namespace std;

void solve(int num) {
    long long sum = 0;
    for(int i = 1; i <= num; i++) {
        sum += (num / i) * i;
    }
    cout << sum << endl;
}

int main() {
    int num;
    cin >> num;
    solve(num);
}