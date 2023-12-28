#include <iostream>
#include <stack>
#include <cmath>
#define endl '\n'

using namespace std;

string bracket;
stack<char> small;
stack<char> big;
int value, tmp;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> bracket;
}

void solve() {
    for(int i = 0; i < bracket.length(); i++) {
        if(bracket[i] == '(') {
            small.push('(');
        }
        else if(bracket[i] == '[') {
            big.push('[');
        }
        else if(bracket[i] == ')') {
            if(!small.empty()) {
                small.pop();
                if(bracket[i-1] == '(') {
                    value += pow(2, small.size()) * pow(3, big.size()) * 2;
                }
            }
            else {
                cout << 0 << endl;
                return;
            }
        }
        else if(bracket[i] == ']') {
            if(!big.empty()) {
                big.pop();
                if(bracket[i-1] == '[') {
                    value += pow(2, small.size()) * pow(3, big.size()) * 3;
                }
            }
            else {
                cout << 0 << endl;
                return;
            }
        }
    }
    if(!small.empty() || !big.empty()) {
        cout << 0 << endl;
    }
    else {
        cout << value << endl;
    }
}

int main() {
    init();
    solve();
}

// ( () [ [] ] ) ( [] ) = 28
// 2*2 + 6*3 + 2*3 = 4 + 18 + 6
