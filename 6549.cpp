#include <iostream>
#include <algorithm>
#include <stack>
#include<memory.h>
#define endl '\n'

using namespace std;

int n;
long long ans, h[100002];
stack<int> st;

void solve() {
	while(true) {
		cin >> n;
		if(n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++) {
        	cin >> h[i];
    	}
		st.push(0);
		for (int i = 1; i <= n + 1; i++) {
			while (!st.empty() && h[st.top()] > h[i]) {
				int check = st.top();
            	long long vertical = h[check];
				st.pop();
				long long horizontal = i-1 - st.top();
				ans = max(ans, (long long)(vertical * horizontal));
			}
			st.push(i);
		}
		cout << ans << endl;
		st = stack<int> ();
		ans = 0;
		memset(h, 0, 100000); // h[n+1]에 0이 들어가있어야 마지막 i에서도 while문 안에 들어가 최대값을 구할 수 있음
	}

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
    solve();
}

// 시간초과
// #include <iostream>
// #include <stack>
// #include <vector>
// #define MAX 100001
// #define endl '\n'

// using namespace std;

// long long histogram[MAX];
// stack<long long> leftS, rightS;
// vector<long long> answer;
// int maxArea;

// void findMaxSquare(int num) {
//     for(int i = 0; i < num; i++) {
//         long long leftwidth = 0;
//         long long rightwidth = 0;
//         long long height = rightS.top();
//         stack<long long> tmpleft = leftS;
//         stack<long long> tmpright = rightS;
//         while(!tmpleft.empty() && tmpleft.top() >= height) {
//             leftwidth++;
//             tmpleft.pop();
//         }
//         while(!tmpright.empty() && tmpright.top() >= height) {
//             rightwidth++;
//             tmpright.pop();
//         }
//         if((leftwidth+rightwidth) * height > maxArea) {
//             maxArea = (leftwidth+rightwidth) * height;
//         }
//         leftS.push(rightS.top());
//         rightS.pop();
//         // cout << height << " " << leftwidth << " " << rightwidth << " " << maxArea << endl;
//     }
// }

// void solve() {
//     int num;
//     while(true) {
//         cin >> num;
//         if(num == 0) {
//             break;
//         }
//         else {
//             for(int i = 0; i < num; i++) {
//                 cin >> histogram[i];
//             }
//             for(int i = num-1; i >= 0; i--) {
//                 rightS.push(histogram[i]);
//             }
//             findMaxSquare(num);
//         }
//         answer.push_back(maxArea);
//         maxArea = 0;
//     }
//     // cout << answer.size() << endl;
//     for(int i = 0; i < answer.size(); i++) {
//         cout << answer[i] << endl;
//     }
// }

// int main() {
//     solve();
// }