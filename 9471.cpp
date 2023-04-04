#include <iostream>
#include <vector>

using namespace std;

int test, idx, mod;
int ans[1001];

int findCycle(int mod) { // 0과 1이 다시 나오면 그후는 이전과 같을 수 밖에 없으므로!!
    vector<int> pibonacci;
    pibonacci.push_back(0);
    pibonacci.push_back(1);
    while(true) {
        int cur = (pibonacci[pibonacci.size()-2] % mod + pibonacci[pibonacci.size()-1] % mod) % mod;
        if(pibonacci[pibonacci.size()-1] == 0 && cur == 1) {
            return pibonacci.size()-1;
        }
        pibonacci.push_back(cur);        
    }
}

void solve() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> test;
    for(int i = 0; i < test; i++) {
        cin >> idx >> mod;
        ans[idx] = findCycle(mod);
    }
    for(int i = 1; i <= test; i++) {
        cout << i << " " << ans[i] << endl;
    }
}

int main() {
    solve();
}