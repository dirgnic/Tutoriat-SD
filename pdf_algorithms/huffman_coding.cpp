/*
 huffman_coding.cpp
 Builds Huffman Tree for optimal prefix coding.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f): ch(c), freq(f), left(NULL), right(NULL) {}
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string s, unordered_map<char,string>& codes) {
    if(!root) return;
    if(!root->left && !root->right) codes[root->ch] = s;
    buildCodes(root->left, s+"0", codes);
    buildCodes(root->right, s+"1", codes);
}

int main() {
    vector<pair<char,int>> freq = {{'a',5},{'b',9},{'c',12},{'d',13},{'e',16},{'f',45}};
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(auto p: freq) pq.push(new Node(p.first, p.second));
    while(pq.size()>1) {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();
        Node* top = new Node('$', l->freq+r->freq);
        top->left = l; top->right = r;
        pq.push(top);
    }
    Node* root = pq.top();
    unordered_map<char,string> codes;
    buildCodes(root, "", codes);
    for(auto p: codes)
        cout << p.first << ": " << p.second << endl;
    return 0;
}