#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 4000001

using namespace std;

int n, cnt;
bool eratosthenes[MAX];
vector<int> primeNum;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 2; i <= MAX; i++) {
        if(eratosthenes[i] == false) {
            primeNum.push_back(i);
        }
        else {
            continue;
        }
        int cur = i * 2;
        while(cur <= n) {
            eratosthenes[cur] = true;
            cur += i;
        }
    }
}

void solve() {
    vector<int>::iterator start = primeNum.begin();
    vector<int>::iterator end = primeNum.begin() + 1;
    int sum = *start + *end;
    while(*start <= n) {
        // cout << *start << " " << *end << " " << sum << endl;
        if(start == end) {
            end++;
            sum -= *start;
            sum += *end;
        }
        if(sum > n) { // 이미 목표치 넘김, 
            sum -= *start;
            start++;
        }
        else if(sum == n) { // 딱 목표치임, 
            cnt++;
            // cout << "카운트" << " " << *start << " " << *end << endl;
            start++;
            sum -= *start;
        }
        else { // 아직 목표치 못옴, 
            end++;
            if(end == primeNum.end()) {
                break;
            }
            sum += *end;
        }
    }
    auto it = find(primeNum.begin(), primeNum.end(), n);
    if(it != primeNum.end()) {// n이 소수이면 자기 자신으로 표현되는 경우 1가지 추가
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}
