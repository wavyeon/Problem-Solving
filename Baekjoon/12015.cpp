// LIS 문제에서 증가란 이전 값보다 다음 값이 큰 것을 의미하는 듯함 (같거나 큰 것 아님)
// upper bound가 아니라 lower bound를 사용해야 함!!
// 이미 lis에 포함된 값(중복된 값)이 들어왔을 때, upper bound 탐색을 하면 lis에 같은 값이 연속되서 들어갈 수 있음(증가란 같거나 큰 것 아님, 무조건 큰 것)  
#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int n;
int arr[MAX];
vector<int> ans;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    ans.push_back(0);
    for(int i = 0; i < n; i++) {
        if(arr[i] > ans[ans.size()-1]) {
            ans.push_back(arr[i]);
        }
        else {
            int low = 0;
            int high = ans.size(); // ans.size()-1 아님!!
            while(low < high) { // lower bound 
                int mid = low + (high - low) / 2;
                // while(low < high)
                // high = mid
                // low = mid + 1
                // 이진탐색 기본 구조!!!!
                if(arr[i] <= ans[mid]) {
                    high = mid; 
                }
                else {
                    low = mid + 1;
                }
            }
            ans[low] = arr[i];
        }
    }
    ans.erase(ans.begin());
    cout << ans.size() << endl;
}

int main() {
    init();
    solve();    
}