#include <iostream>
#include <set>

using namespace std;

multiset<int> dualPQ;
int testcase, inst, value;
char type;

void test() {
    cin >> inst;
    for(int i = 0; i < inst; i++) {
        cin >> type >> value;
        if(type == 'I') {
            dualPQ.insert(value);
        }
        else if(type == 'D') {
            if(dualPQ.empty()) {
                continue;
            }
            if(value == -1) {
                dualPQ.erase(dualPQ.begin());
            }
            else if(value == 1) {
                auto it = dualPQ.end();
                it--;
                dualPQ.erase(it);
            }
        }
    }
    if(dualPQ.empty()) {
        cout << "EMPTY" << "\n";
    }
    else {
        auto it = dualPQ.end();
        it--;
        cout << *it << " " << *dualPQ.begin() << "\n";
    }
    dualPQ.clear();
}

void solve() {
    cin >> testcase;
    for(int i = 0; i < testcase; i++) {
        test();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
}