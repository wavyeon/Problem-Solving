#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack<char> op;
const int MAX = 101;
string exp;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> exp;
}

void solve() {
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] >= 'A' && exp[i] <= 'Z') {
            cout << exp[i];
        }
        else { // +-  */  ()
            if(exp[i] == '(') {
                op.push('(');
            }
            else if(exp[i] == ')') {
                while(op.top() != '(') {
                    cout << op.top();
                    op.pop(); 
                }
                op.pop();
            }
            else if(exp[i] == '+' || exp[i] == '-') {
                while(!op.empty() && op.top() != '(') {// 만나서 멈출 수 있는 건 ( 밖에 없음!
                    cout << op.top();
                    op.pop();
                }
                op.push(exp[i]);
            }
            else if(exp[i] == '*' || exp[i] == '/') {
                while(!op.empty() && (op.top() == '*' || op.top() == '/')) {
                    cout << op.top();
                    op.pop();
                }
                op.push(exp[i]);
            }
        }
    }
    while(!op.empty()) {
        cout << op.top();
        op.pop();
    }
}

int main() {
    init();
    solve();
}