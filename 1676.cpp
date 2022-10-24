#include <iostream>
#include <math.h>
#define endl '\n'

using namespace std;

int n, two, five;
int facto = 1;
int squareOfTwo = 1;
int squareOfFive = 1;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(pow(2, squareOfTwo) <= n) {
        two += (n / pow(2,squareOfTwo) );
        squareOfTwo++;
    }
    while(pow(5, squareOfFive) <= n) {
        five += (n / pow(5,squareOfFive) );
        squareOfFive++;
    }
    cout << min(two, five) << endl;
}

int main() {
    solve();    
}