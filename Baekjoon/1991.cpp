#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    char left;
    char right;
} node;

vector<node> tree(26);
int num;

void init() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio;
    cin >> num;
    char alphabet, left, right;
    for(int i = 0; i < num; i++) {
        cin >> alphabet >> left >> right;
        tree[alphabet-'A'].left = left;
        tree[alphabet-'A'].right = right;
    }
}

void preorder_traversal(char cur) {
    cout << cur;
    if(tree[cur-'A'].left != '.') {
        preorder_traversal(tree[cur-'A'].left);
    }
    if(tree[cur-'A'].right != '.') {
        preorder_traversal(tree[cur-'A'].right);
    }
}

void inorder_traversal(char cur) {
    if(tree[cur-'A'].left != '.') {
        inorder_traversal(tree[cur-'A'].left);
    }
    cout << cur;
    if(tree[cur-'A'].right != '.') {
        inorder_traversal(tree[cur-'A'].right);
    }
}

void postorder_traversal(char cur) {
    if(tree[cur-'A'].left != '.') {
        postorder_traversal(tree[cur-'A'].left);
    }
    if(tree[cur-'A'].right != '.') {
        postorder_traversal(tree[cur-'A'].right);
    }
    cout << cur;
}

int main() {
    init();
    preorder_traversal('A');
    cout << "\n";
    inorder_traversal('A');
    cout << "\n";
    postorder_traversal('A');
    cout << "\n";
}