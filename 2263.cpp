#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int n, num, root;
vector<int> inorder;
vector<int> postorder;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        inorder.push_back();
    }
    for(int i = 0; i < n; i++) {
        cin >> num;
        postorder.push_back();
    }
}

void solve() {
    root = postorder[postorder.size()-1];
    reverseFromLeft();
}

int main() {
    init();
    solve();
}