#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

Node* buildBalanced(const vector<int>& a, int l, int r) {
    if (l > r) return nullptr;
    int m = (l + r) / 2;
    Node* root = new Node(a[m]);
    root->left  = buildBalanced(a, l, m - 1);
    root->right = buildBalanced(a, m + 1, r);
    return root;
}

void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->key);
    inorder(root->right, out);
}

Node* mergeBST(Node* A, Node* B) {
    vector<int> va, vb, merged;
    inorder(A, va);
    inorder(B, vb);
    int i=0, j=0;
    while (i<va.size() && j<vb.size()) {
        if (va[i] < vb[j]) merged.push_back(va[i++]);
        else merged.push_back(vb[j++]);
    }
    while (i<va.size()) merged.push_back(va[i++]);
    while (j<vb.size()) merged.push_back(vb[j++]);
    return buildBalanced(merged, 0, (int)merged.size()-1);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> v1 = {1,3,5,7};
    vector<int> v2 = {2,4,6,8,9};
    Node* A = buildBalanced(v1, 0, v1.size()-1);
    Node* B = buildBalanced(v2, 0, v2.size()-1);
    Node* M = mergeBST(A, B);
    cout << "Preorder merged BST: ";
    preorder(M);
    cout << "\n";
    return 0;
}
