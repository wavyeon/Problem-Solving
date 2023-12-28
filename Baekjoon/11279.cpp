#include <iostream>
#include <queue>

using namespace std;

int times, inst;
priority_queue<int> pq;

void solve() {
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> inst;
        if(inst == 0) {
            if(pq.empty()) {
                cout << "0" << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(inst);
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
}