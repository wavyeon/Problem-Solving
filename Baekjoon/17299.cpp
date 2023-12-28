#include <iostream>
#include <stack>
#define MAX 1000001

using namespace std;

int n;
int arr[MAX];
int freq[MAX];
int ans[MAX];
stack<int> st;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
}

void solve() {
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && freq[arr[i]] >= freq[st.top()]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    init();
    solve();
}
