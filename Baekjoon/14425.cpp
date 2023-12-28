#include <iostream>
#include <set>
#define endl '\n'

using namespace std;

int word, test;
set<string> strings;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> word >> test;
    string tmp;
    for(int i = 0; i < word; i++) {
        cin >> tmp;
        strings.insert(tmp);
    }
}

void solve() {
    int cnt = 0;
    string check;
    for(int i = 0; i < test; i++) {
        cin >> check;
        if(strings.find(check) != strings.end()) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}