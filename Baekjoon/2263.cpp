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
int rootIdxWithoutFindFunc[MAX];

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        inorder.push_back(num);
        rootIdxWithoutFindFunc[num] = i; // find 함수를 쓰지 않기 위해 inorder에서 root의 index를 입력과 동시에 저장!!
    }
    for(int i = 0; i < n; i++) {
        cin >> num;
        postorder.push_back(num);
    }
    originalRoot = postorder[n-1];
}

void reverse_traveresal(int postStart, int postEnd, int inStart, int inEnd) {
    if(postStart > postEnd && inStart > inEnd) {  // left와 right가 존재하지 않음
        return;
    }
    else {
        int root = postorder[postEnd];
        int mid = rootIdxWithoutFindFunc[root];
        int leftSide = mid - inStart;
        int rightSide = inEnd - mid;
        cout << root << " ";
        reverse_traveresal(postStart, postStart + leftSide - 1, mid - leftSide, mid - 1); //left
        reverse_traveresal(postStart + leftSide, postStart + leftSide + rightSide - 1, mid + 1, mid + rightSide); //right
    }
    
    
}


// void reverse_traveresal(int startIdx, int rootIdx) {
//     int root = postorder[rootIdx];
//     cout << startIdx << " " << rootIdx << endl;
//     // auto it = find(inorder.begin(), inorder.end(), root);
//     // int mid = it - inorder.begin();
//     int mid = rootIdxWithoutFindFunc[root]; 
//     if(mid > startIdx) { // left 있음
//         tree[root].left = postorder[mid-1];
//         // cout << 0 << " " << mid-1 << endl;
//         reverse_traveresal(0,mid-1);
//     }
//     if(mid < rootIdx) { // right 있음
//         tree[root].right = postorder[n-2];
//         // cout << mid+1 << " " << n-1 << endl;
//         reverse_traveresal(mid, n-1);
//     }
// }

// void preorder_traversal(int parent) {
//     if(parent == 0) {
//         return;
//     }
//     cout << parent << " ";
//     preorder_traversal(tree[parent].left);
//     preorder_traversal(tree[parent].right);
// }

void solve() {
    reverse_traveresal(0, n-1, 0, n-1);
    // preorder_traversal(originalRoot);
}

int main() {
    init();
    solve();
}