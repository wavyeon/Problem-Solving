#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define MAX 1000001

using namespace std;
 
int n;
int arr[MAX];
vector<int> ans;

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
        }
    }
    cout << ans.size() << endl;
}

int main() {
    init();
    solve(); 
}
