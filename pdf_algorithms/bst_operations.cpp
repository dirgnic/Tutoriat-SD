/*
 bst_operations.cpp
 Binary Search Tree: insertion, search, inorder & preorder traversal.
*/
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k): key(k), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int k) {
    if(!root) return new Node(k);
    if(k < root->key) root->left = insert(root->left, k);
    else root->right = insert(root->right, k);
    return root;
}

bool search(Node* root, int k) {
    if(!root) return false;
    if(root->key == k) return true;
    return search((k < root->key? root->left: root->right), k);
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if(!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {50,30,20,40,70,60,80};
    for(int k: arr) root = insert(root, k);
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Search 40: " << (search(root,40)? "Found":"Not Found") << endl;
    return 0;
}