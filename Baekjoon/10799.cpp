#include <iostream>
#include <stack>

using namespace std;

string input;
int cnt;
stack<char> st;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> input;
}

void solve() {
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '(' && input[i+1] == ')') {  // 레이저 일때
            cnt +=  st.size();
            i++;     
        }
        else if(input[i] == '(') { // 막대기 시작
            st.push('(');
        }
        else if(input[i] == ')') {// 막대기 끝
            st.pop();
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}