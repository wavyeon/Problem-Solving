#include <iostream>
#include <stack>
#include <vector>
#define MAX 100001
#define endl '\n'

using namespace std;

int len, stIdx;
int answer[MAX];
stack<int> st;
vector<char> output;
bool isPushed[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> len;
    for(int i = 0; i < len; i++) {
        cin >> answer[i];
    }
}

void solve() {
    int lastPush = 0;
    for(int i = 0; i < len; i++) {
        if(isPushed[answer[i]] == false) {
            for(int j = lastPush + 1; j <= answer[i]; j++) {
                if(isPushed[j] == false) {
                    st.push(j);
                    isPushed[j] = true;
                    output.push_back('+');
                }
            }
            st.pop();
            output.push_back('-');
            lastPush = answer[i];
        }
        else {
            if(st.top() == answer[i]) {
                st.pop();
                output.push_back('-');
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << endl;
    }
}

int main() {
    init();
    solve();
}