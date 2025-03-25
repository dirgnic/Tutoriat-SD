#include <bits/stdc++.h>
using namespace std;
// heap min
const int NMAX = 1e5;
int H[NMAX + 1];

int father(int nod) {
    return nod / 2;
}

int left_son(int nod) {
    return nod * 2;
}

int right_son(int nod) {
    return nod * 2 + 1;
}

void HeapUp(int K) { // (de jos in sus)
    while(K > 1 && H[K] < H[father(K)]) {
        swap(H[K], H[father(K)]);
        K = father(K);
    }
}

void HeapDown(int N, int K) { //(de sus in jos)
    while(true) {
        int son = 0;
        if(left_son(K) <= N) {
            son = left_son(K);
            if(right_son(K) <= N && H[right_son(K)] < H[son]) {
                son = right_son(K);
            }
        } // cel m mic fiu (stang sau dept)
        if(son && H[son] < H[K]) {
            swap(H[son], H[K]);
            K = son;
        } else {
            break;
        }
    }
}

void insert(int &N, int value) {
    H[++N] = value;
    HeapUp(N);
}

int find_min() {
    return H[1];
}

void extract_min(int &N) {
    swap(H[1], H[N]);
    N--;
    HeapDown(N, 1);
}

void build(int N) {
    for (int i = N / 2; i >= 1; i--) {
        HeapDown(N, i);
    }
}

void Delete(int& N, int K) {
    swap(H[K], H[N]);
    N--;
    if ((K > 1) && (H[K] < H[father(K)])) {
        HeapUp(K);
    } else {
        HeapDown(N, K);
    }
}

void decrease_key(int K, int value) {
    H[K] -= value;
    HeapUp(K);
}

void increase_key(int N, int K, int value) {
    H[K] += value;
    HeapDown(N, K);
}


int main() {
    return 0;
}

// heapsort, lastk, interclasari, bleach