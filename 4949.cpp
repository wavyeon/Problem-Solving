#include <iostream>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

string sentence;

void solve() {
    while(true) {
        getline(cin, sentence);
        // cin.ignore();
        stack<char> st;
        if(sentence == ".") {
            break;
        }
        for(int i = 0; i < sentence.length(); i++) {
            if(sentence[i] == '(') {
                st.push('(');
            }
            else if(sentence[i] == '[') {
                st.push('[');
            }
            else if(sentence[i] == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(')');
                }
            }
            else if(sentence[i] == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    st.push(']');
                }
            }
            else {
                continue;
            }
        }
        if(st.empty()) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}

int main() {
    solve();
}