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
    // 현재의 연속합은 start부터 end전까지라고 생각하면 됨!
    // 초기에는 start와 end 모두 맨 처음을 가리킴
    vector<int>::iterator start = primeNum.begin();
    vector<int>::iterator end = primeNum.begin();
    // 포인터가 옮겨갈 때 기존에 가리키고 있던 값이 적용됨 (더하거나 빼짐)
    // 초기에는 sum 0으로 시작
    int sum = 0;
    while(true) {
        if(sum > n) { // 이미 목표치 넘김
            sum -= *start;
            if(*start >= n) {
                break;
            }
            start++;
        }
        else if(sum == n) { // 딱 목표치임
            cnt++;
            sum -= *start;
            if(*start >= n) {
                break;
            }
            start++;
        }
        else if(sum < n) { // 아직 목표치 못옴
            sum += *end;
            end++;
        }
    }
    cout << cnt << endl;
}

int main() {
    init();
    solve();
}
