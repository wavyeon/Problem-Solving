#include <iostream>
#include <stack>
#include <vector>

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
    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        if(!st.empty() && st.top() == bomb[count]) {
            count++;
            cout << i << " 시작" << endl;
            cout << count << " " << bomb.length() << endl;
            if(count == bomb.length()) {
                for(int j = 0; j < bomb.length(); j++) {
                    st.pop();
                }
                continue;
            }
        }
        else {
            count = 0;
            if(!st.empty() && st.top() == bomb[count]) {
                count = 1;
            }
        }
        st.push(str[i]);
    }
   

    // int tmp = st.size();
    //         for(int i = 0; i < tmp; i++) {
    //             answer.push_back(st.top());
    //             st.pop();
    //         }
    //         for(int i = tmp; i >= 0; i--) {
    //             cout << answer[i];
    //         }    


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
