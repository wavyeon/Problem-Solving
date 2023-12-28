#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, m, x;
const int MAX = 9;
multimap<int, bool> arr;
int output[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        arr.insert(make_pair(x, false));
    }
}

void solve(int idx) {
    if(idx == m) {
        for(int i = 0; i < m; i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
    }
    else {
        int prev = 0;
        multimap<int,bool>::iterator it;
        for(it = arr.begin(); it != arr.end(); it++) { // 직전의 아웃풋과 같으면 패스하는 식으로 중복 거르자
            if(it->second == false && prev != it->first) {
                prev = it->first;
                output[idx] = it->first;
                it->second = true;
                solve(idx+1);
                it->second = false;
            }
        }
    }
}

int main() {
    init();
    solve(0);
}