#include <iostream>
#include <set>
#define endl '\n'

using namespace std;

set<int> a, b, ab;
int asize, bsize;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> asize >> bsize;
    int tmp;
    for(int i = 0; i < asize; i++) {
        cin >> tmp;
        a.insert(tmp);
        ab.insert(tmp);
    }
    for(int i = 0; i < bsize; i++) {
        cin >> tmp;
        b.insert(tmp);
        ab.insert(tmp);
    }
}

void solve() {
    int answer = ((ab.size() - a.size()) + (ab.size() - b.size()));
    cout << answer << endl; 
}

int main() {
    init();
    solve();
}