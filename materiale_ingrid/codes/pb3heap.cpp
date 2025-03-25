#include <bits/stdc++.h>
using namespace std;

// heap min
const int NMAX = 1e5;
int H[NMAX + 1];

// Returns the index of the father node of a given node
int father(int nod) {
    return nod / 2;
}

// Returns the index of the left son of a given node
int left_son(int nod) {
    return nod * 2;
}

// Returns the index of the right son of a given node
int right_son(int nod) {
    return nod * 2 + 1;
}

// Performs the HeapUp operation (from bottom to top) to maintain the heap property
void HeapUp(int K) {
    while(K > 1 && H[K] < H[father(K)]) {
        swap(H[K], H[father(K)]);
        K = father(K);
    }
}

// Performs the HeapDown operation (from top to bottom) to maintain the heap property
void HeapDown(int N, int K) {
    while(true) {
        int son = 0;
        if(left_son(K) <= N) {
            son = left_son(K);
            if(right_son(K) <= N && H[right_son(K)] < H[son]) {
                son = right_son(K);
            }
        }
        if(son && H[son] < H[K]) {
            swap(H[son], H[K]);
            K = son;
        } else {
            break;
        }
    }
}

// Inserts a value into the heap and maintains the heap property
void insert(int &N, int value) {
    H[++N] = value;
    HeapUp(N);
}

// Returns the minimum value in the heap
int find_min() {
    return H[1];
}

// Extracts the minimum value from the heap and maintains the heap property
void extract_min(int &N) {
    swap(H[1], H[N]);
    N--;
    HeapDown(N, 1);
}

// Builds a heap from an array of values
void build(int N) {
    for (int i = N / 2; i >= 1; i--) {
        HeapDown(N, i);
    }
}

// Deletes a value from the heap and maintains the heap property
void Delete(int& N, int K) {
    swap(H[K], H[N]);
    N--;
    if ((K > 1) && (H[K] < H[father(K)])) {
        HeapUp(K);
    } else {
        HeapDown(N, K);
    }
}

// Decreases the value of a node in the heap and maintains the heap property
void decrease_key(int K, int value) {
    H[K] -= value;
    HeapUp(K);
}

// Increases the value of a node in the heap and maintains the heap property
void increase_key(int N, int K, int value) {
    H[K] += value;
    HeapDown(N, K);
}

int main() {
    int n, N=0, k;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        insert(N, k);
    }

    while(N)
    {
        cout << find_min() << " ";
        extract_min(N);

    }

    return 0;
}
