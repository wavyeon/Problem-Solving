#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int n, k; 
vector<int> lan;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> k >> n;
    int tmp;
    for(int i = 0; i < k; i++) {
        cin >> tmp;
        lan.push_back(tmp);
    }
    sort(lan.begin(), lan.end()); // 블로그에 기록
}

void solve() {
    long long min = 1;
    // long long max = lan[0]; // 반례 있음!!
    long long max = lan[k-1];
    long long ans = 0;
    while(min <= max) {
        long long mid = (min + max) / 2; // 자료형 의심하는 습관 가지자!!
        int cable = 0;
        for(int i = 0; i < k; i++) {
            cable += (lan[i] / mid);
        }
        if(cable >= n) { // 랜선이 충분하거나 많음 -> 길이를 짧게 잡음 
            min = mid + 1;
            if(ans < mid) {
                ans = mid;
            }
        }
        else if(cable < n) { // 랜선이 부족함 -> 길이를 길게 잡음
            max = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    init();
    solve();
}