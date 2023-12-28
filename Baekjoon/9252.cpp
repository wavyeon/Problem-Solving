	#include <iostream>
	#include <algorithm>
	#include <string>
	#define endl '\n'

	using namespace std;

	string a, b;
	int dp[1001][1001];

	void init() {
		cin.tie(0);
		cout.tie(0);
		ios::sync_with_stdio(false);
		cin >> a >> b;
	}

	void solve() {
		for(int i = 1; i <= b.size(); i++) {
			for (int j = 1; j <= a.size(); j++) {
				if (a[j - 1] == b[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		
		int aSize = a.size();
		string reverseAns;
		
		for(int i = b.size(); i > 0; i--) {
			if (dp[i][aSize] == 0) { // 다음 탐색하려는 dp값이 0 (탐색 더이상 의미 없음)
				break;
			}
			for(int j = aSize; j > 0; j--) {
				// 왼쪽이나 위에 같은 값 있는지 먼저 판단
				if(dp[i][j] == dp[i-1][j]) { 
					break;
				}
				if(dp[i][j] == dp[i][j-1]) {
					continue;
				}
				// 같은 값 없다면 1 더해진 것 (현재 같은 문자라는 뜻)
				reverseAns += a[j-1];
				aSize = j - 1;
				break;
			}
		}

		cout << dp[b.size()][a.size()] << endl;
		if (dp[b.size()][a.size()] == 0) {
			return;
		}
		for (int i = reverseAns.size() - 1; i >= 0; i--) {
			cout << reverseAns[i];
		}
		cout << endl;
	}

	int main() {
		init();
		solve();
	}