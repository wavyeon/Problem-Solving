#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 51
#define endl '\n'

using namespace std;

int n, m, cnt;
deque<int> dq;
int target[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    for(int i = 0; i < m; i++) {
        cin >> target[i];
    }
}

void solve() {
    int cur;
    int siz = m;
    for(int i = 0; i < m; i++) {
        cur = target[i];
        auto it = find(dq.begin(), dq.end(), cur);
        int left = it - dq.begin();
        int right = dq.end() - it;
        if(left <= right) { // 왼쪽으로 가는게 유리 -> 2번 연산
            for(int j = 0; j < left; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else { // 오른쪽으로 가는게 유리 -> 3번 연산
            for(int j = 0; j < right; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        dq.pop_front();
    }
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}