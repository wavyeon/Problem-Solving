#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define MAX 5001

using namespace std;

int n;
long long solution[MAX];
int ans[3];

void init() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> solution[i];
    }
    sort(solution, solution + n);
}

void solve() { // 세 포인터 X, 하나 고정하고 두 포인터 이용
    long long chrVal = 3000000001;
    for(int fix = 0; fix < n-2; fix++) { // fix는 가장 왼쪽에서부터 한 칸씩 오른쪽으로 이동하며, 칸마다 두 포인터 이용
        int left = fix + 1;
        int right = n - 1;
        while(left < right) {
            long long threeSum = solution[fix] + solution[left] + solution[right]; 
            if(abs(threeSum) < chrVal) {
                chrVal = abs(threeSum);
                ans[0] = solution[fix];
                ans[1] = solution[left];
                ans[2] = solution[right];
            }
            if(threeSum >= 0) {
                right--;
            }
            else if(threeSum < 0) {
                left++;
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    init();
    solve();
}