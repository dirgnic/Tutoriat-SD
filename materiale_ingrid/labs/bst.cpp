#include <bits/stdc++.h>

using namespace std;

struct nod {
    int info;
    nod* st;
    nod* dr;
};

void inserare(nod* &r, int x) {
    if(r == NULL) {
        r = new nod;
        r -> info = x;
        r -> st = NULL;
        r -> dr = NULL;
    } else {
        if(r -> info > x) {
            inserare(r -> st, x);
        } else {
            inserare(r -> dr, x);
        }
    }
}

bool cautare(nod* r, int x) {
    if(r == NULL) {
        return false;
    } else {
        if(r -> info == x) {
            return true;
        } else {
            if(r -> info > x) {
                return cautare(r -> st, x);
            } else {
                return cautare(r -> dr, x);
            }
        }
    }
}

void stergereAux(nod* &p, nod* &r) {
    if(p -> dr) {
        stergereAux(p -> dr, r);
    } else {
        r -> info = p -> info;
        nod* aux = p;
        p = p -> st;
        delete aux;
    }
}
// function stergereAux is used to 
//delete a node from a BST. It finds the rightmost
// node in the subtree rooted at p and replaces the value of 
//the node to be deleted with the value of the rightmost node.
void stergere(nod* &r, int x) {
    if(r != NULL) {
        if(r -> info == x) {
            if(r -> st == NULL && r -> dr == NULL) {
                r = NULL;
                //cout << "DA\n";
                delete r;
            } else {
                if(r -> dr == NULL) {
                    nod* aux = r;
                    r = r -> st;
                    delete aux;
                } else {
                    if(r -> st == NULL) {
                        nod* aux = r;
                        r = r -> dr;
                        delete aux;
                    } else {
                        stergereAux(r -> st, r);
                    }
                }
            }
        } else {
            if(r -> info > x) {
                stergere(r -> st, x);
            } else {
                stergere(r -> dr, x);
            }
        }
    }
}

void inordine(nod *r) {
    if(r != NULL) {
        inordine(r -> st);
        cout << r -> info << ' ';
        inordine(r -> dr);
    }
}

/* INORDINE
First, the left subtree is traversed recursively.
Then, the right subtree is traversed recursively.
Finally, the current node is visited.
*/

void preordine(nod *r)
{
     if(r != NULL) {
        cout << r -> info << ' ';
        inordine(r -> st);
        inordine(r -> dr);
    }
}

/* PREORDEr
First, the current node is visited.
Then, the left subtree is traversed recursively.
Finally, the right subtree is traversed recursively.*/

void postordine(nod *r)
{
     if(r != NULL) {
        inordine(r -> st);
        cout << r -> info << ' ';
        inordine(r -> dr);
    }
}
     // suma val care sunt intre l si h
      void getSum(nod* r, int l, int h, int &sum) {
        if (r->info >= l && r->info <= h) {
            sum += r->info;
        }
        
        if (r->info > l) {
           getSum(r->st, l, h, sum);
        }
        
        if (r->info < h) {
          getSum(r->dr, l, h, sum);
        }     
    }
    //max depth of a binary tree
    int maxDepth(nod* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->st);
        int rightDepth = maxDepth(root->dr);
        return max(leftDepth, rightDepth) + 1;
    }

int main() {
    nod* r = NULL;
    inserare(r, 3);
    inserare(r, 4);
    inserare(r, 2);
    inserare(r, 10);
    inserare(r, 8);
    //inserare(r, 4);
    //inordine(r);
   // stergere(r, 2);
    // inordine(r);
    preordine(r);
    int sum =0;
    getSum(r, 2, 8, sum);
    cout << sum;
    return 0;
}

/*
https://www.pbinfo.ro/probleme/3010/bst
https://leetcode.com/problems/binary-tree-preorder-traversal/
https://leetcode.com/problems/binary-tree-postorder-traversal/
https://leetcode.com/problems/range-sum-of-bst/description/
https://leetcode.com/problems/maximum-depth-of-binary-tree/
https://leetcode.com/problems/balanced-binary-tree/

*/

/*

 bool isBalanced(TreeNode* root) {
      return isBalanced1(root)!=-1;
    }

     int isBalanced1(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = isBalanced1(root->left);
        if(leftDepth==-1)
        return -1;
        int rightDepth = isBalanced1(root->right);
        if(rightDepth==-1)
        return -1;
        
        if(abs(leftDepth - rightDepth) > 1)
         return -1;
        return max(leftDepth, rightDepth) + 1; //IMPORTANT,fac maxim inaltimi + 1
    }
    // verifica daca un arbore binar este echilibrat -- adica daca intre cele doua subarbori 
    //diferenta de inaltime este de cel mult 1
    */