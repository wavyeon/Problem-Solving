#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

string s;
stack<char> st;
vector<char> answer;

void input() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    getline(cin, s);
}

void solve() {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '<') {
            if(st.size() != 0) {
                while(!st.empty()) {
                    answer.push_back(st.top());
                    st.pop();
                }
            }
            while(s[i] != '>') {
                answer.push_back(s[i]);
                i++;
            }
            answer.push_back('>');
        }
        else {
            if(s[i] == ' ') {
                while(!st.empty()) {
                    answer.push_back(st.top());
                    st.pop();
                }
                answer.push_back(' ');
            }
            else {
                st.push(s[i]);
            }
        }
    }
    if(st.size() != 0) {
        while(!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
    }
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
    cout << endl;
}

int main() {
    input();
    solve();
}