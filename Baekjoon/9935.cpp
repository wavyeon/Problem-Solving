#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

string str, bomb;
vector<char> answer;
stack<char> st;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> str;
    cin >> bomb;
}

void solve() {
    char target = bomb[bomb.length()-1];
    for(int i = 0; i < str.length(); i++) {
        st.push(str[i]);
        if(st.size() >= bomb.size() && st.top() == target) {
            // 반례의 핵심!! (seg fault)
            // bomb이 str보다 길 때에는 따져볼 필요가 없음 (따지면 seg fault 발생)
            // 정확하게는 문자열을 stack에 push/pop하면서 bomb이 stack보다 커지는 경우에 따지면 안되는 것. 따라서 첫번째 조건을 추가해야함
            stack<char> tmp; // stack에서 뺐다 넣을려면 다른 stack에 임시 저장하는 방식 사용!!
            for(int j = bomb.length()-1; j >= 0; j--) {
                if(st.top() == bomb[j]) {
                    tmp.push(st.top());
                    st.pop();
                }
                else {
                    while(!tmp.empty()) {
                        st.push(tmp.top());
                        tmp.pop();
                    }
                }
            }
        }
    }
    if(st.empty()) {
        cout << "FRULA" << endl;
    }
    else {
        int sz = st.size();
        for(int i = 0; i < sz; i++) {
            answer.push_back(st.top());
            st.pop();
        }
        for(int i = answer.size()-1; i >= 0; i--) {
            cout << answer[i];
        }
    }
}

int main() {
    init();
    solve();
}
