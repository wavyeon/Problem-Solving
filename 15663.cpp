#include <iostream>
#include <set>

using namespace;

int n, m;, x
const int MAX = 9;
multiset<int> arr;
multiset<int>::iterator it;
int ourput[MAX];
bool isSelected[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        set.insert(x);
    }
}

void solve(int idx) {
    if(idx > m) {
        for(int i = 0; i < m; i++) {
            cout << output[i] << " ";
        }
        cout << "\n";
    }
    else {
        for(it = arr.begin(); it != arr.end(); it++) { // 직전의 아웃풋과 같으면 패스하는 식으로 중복 거르자
            if()
        }
    }
}

int main() {
    init();
    solve(0);



}