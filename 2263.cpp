#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int left;
    int right;
} node;

const int MAX = 100001;
int n, num;
vector<int> inorder;
vector<int> postorder;
node tree[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        inorder.push_back(num);
    }
    for(int i = 0; i < n; i++) {
        cin >> num;
        postorder.push_back(num);
    }
}

void reverse_traveresal(int rootIdx) {
    int root = postorder[rootIdx];
    auto it = find(inorder.begin(), inorder.end(), root);
    int mid = it - inorder.begin();
    if(mid != 0) { // left 있음
        
    }
    if(mid != inorder.size()-1) { // right 있음

    }
}

void solve() {
    reverse_traveresal(n-1);
}

int main() {
    init();
    solve();
}