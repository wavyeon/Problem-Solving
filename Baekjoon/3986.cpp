#include <iostream>
#include <stack>
#define endl '\n'
using namespace std;

int n, cnt;
string word;

void solve() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> word;
        stack<char> st;
        for(int j = 0; j < word.length(); j++) {
            if(!st.empty() && st.top() == word[j]) {
                st.pop();
            }
            else {
                st.push(word[j]);
            }
        }
        if(st.empty()) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    solve();
}