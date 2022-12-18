#include <iostream>
#include <stack>
#define MAX 500001
#define endl '\n'

using namespace std;

typedef struct {
    int height;
    int index;
} tower;

int num;
int towers[MAX];
stack<tower> st;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> num;
    for(int i = 1; i <= num; i++) {
        cin >> towers[i];
    }
}

void solve() {
    for(int i = 1; i <= num; i++) {
        if(st.empty()) {
            cout << 0 << " ";
        }
        else {
            if(towers[i] > st.top().height) {
                while(!st.empty() && st.top().height < towers[i]) {
                    st.pop();
                }
                if(st.empty()) {
                     cout << 0 << " ";
                }
                else {
                    cout << st.top().index << " ";
                }
            }
            else if(towers[i] < st.top().height) {
                cout << st.top().index << " ";
            }
        }
        tower t = {towers[i], i};
        st.push(t);
    }
}


int main() {
    init();
    solve();
}