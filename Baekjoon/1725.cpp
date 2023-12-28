#include <iostream>
#include <algorithm>
#include <stack>
#define endl '\n'

using namespace std;

int n, ans, h[100002];
stack<int> st;

void solve() {
    cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
	st.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (!st.empty() && h[st.top()] > h[i]) {
			int check = st.top();
            int vertical = h[check];
			st.pop();
            int horizontal = (i-1 - st.top());
			ans = max(ans, vertical * horizontal);
		}
		st.push(i);
	}
	cout << ans;
}

int main() {
    solve();
}

