#include <iostream>

using namespace std;

void solve() {
    int i = 0;
    int E, S, M;
    cin >> E >> S >> M;
    while(true) {
        int year = 28 * i + S;
        if( (year-E) % 15 == 0 && (year - M) % 19 == 0 ) {
            cout << year << endl;
            break;
        }
        i++;
    }
}

int main() {
    solve();
}