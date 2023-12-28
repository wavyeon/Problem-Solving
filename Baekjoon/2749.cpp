// 피사노 주기 이용
// 피보나치 수를 임의의 수로 나눈 나머지는 주기를 이룸!! 
#include <iostream>
#include <vector>
#define MOD 1000000

using namespace std;

long long n;
int pisanoPeriod;
vector<int> pibonacci;

int findCycle() { // 0과 1이 다시 나오면 그후는 이전과 같을 수 밖에 없으므로!!
    pibonacci.push_back(0);
    pibonacci.push_back(1);
    while(true) {
        int cur = (pibonacci[pibonacci.size()-2] % MOD + pibonacci[pibonacci.size()-1] % MOD) % MOD;
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
    cin >> n;
    pisanoPeriod = findCycle();
    cout << pibonacci[n % pisanoPeriod] % MOD << endl;
}

int main() {
    solve();    
}