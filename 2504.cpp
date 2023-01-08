#include <iostream>
#include <stack>

using namespace std;

string bracket;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> bracket;
}

void solve() {
    for(int i = 0; i < bracket.length(); i++) {
        if(bracket[i] == '(') {
            stack<char>
        }
    }
}

int main() {
    init();
    solve();
}

// ( () [ [] ] ) ( [] ) = 28
// 2*2 + 6*3 + 2*3 = 4 + 18 + 6
