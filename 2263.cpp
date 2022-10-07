#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int left = 0;
    int right = 0;
} node;

const int MAX = 100001;
int n, num, originalRoot;
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
    originalRoot = postorder[n-1];
}

void reverse_traveresal(int startIdx, int rootIdx) {
    int root = postorder[rootIdx];
    auto it = find(inorder.begin(), inorder.end(), root);
    int mid = it - inorder.begin();    
    if(mid > startIdx) { // left 있음
        tree[root].left = postorder[mid-1];
        reverse_traveresal(0,mid-1);
    }
    if(mid < rootIdx) { // right 있음
        tree[root].right = postorder[n-2];
        reverse_traveresal(mid+1, n-2);
    }
}

void preorder_traversal(int parent) {
    if(parent == 0) {
        return;
    }
    cout << parent << " ";
    preorder_traversal(tree[parent].left);
    preorder_traversal(tree[parent].right);

}

void solve() {
    reverse_traveresal(0, n-1);
    preorder_traversal(originalRoot);
}

int main() {
    init();
    solve();
}