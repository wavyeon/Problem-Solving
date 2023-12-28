#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX 1000001

using namespace std;
 
int n;
int arr[MAX];
int lowerBoundIdx[MAX];
vector<int> ans;
vector<int> lis;

void init() {
    cin.tie();
    cout.tie();
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(ans.size() == 0 || arr[i] > ans[ans.size()-1]) {
            ans.push_back(arr[i]);
            lowerBoundIdx[i] = ans.size()-1;
        }
        else {
            int low = 0;
            int high = ans.size();
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(arr[i] > ans[mid]) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
            ans[low] = arr[i];
            lowerBoundIdx[i] = low;
        }
    }
    cout << ans.size() << endl;
    int curIdx = ans.size()-1;
    for(int i = n; i >= 1; i--) {
        if(lowerBoundIdx[i] == curIdx) {
            lis.push_back(arr[i]);
            curIdx--;
        }
    }
    for(int i = lis.size()-1; i >= 0; i--) {
        cout << lis[i] << " ";
    }
}

int main() {
    init();
    solve(); 
}
