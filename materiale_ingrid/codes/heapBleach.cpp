#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream f("/codes/bleach.in"); // BLEACH
ofstream g("/codes/bleach.out");

// heap min
const int NMAX = 1000000;
const int KMAX = 1000;
int H[KMAX + 1];
int heapSize = 0;

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
    while (K > 1 && H[K] < H[father(K)]) {
        swap(H[K], H[father(K)]);
        K = father(K);
    }
}

// Performs the HeapDown operation (from top to bottom) to maintain the heap property
void HeapDown(int K) {
    while (true) {
        int son = 0;
        if (left_son(K) <= heapSize) {
            son = left_son(K);
            if (right_son(K) <= heapSize && H[right_son(K)] < H[son]) {
                son = right_son(K);
            }
        }
        if (son && H[son] < H[K]) {
            swap(H[son], H[K]);
            K = son;
        } else {
            break;
        }
    }
}

// Inserts a value into the heap and maintains the heap property
void insert(int value) {
    H[++heapSize] = value;
    HeapUp(heapSize);
}

// Returns the minimum value in the heap
int find_min() {
    return H[1];
}

// Extracts the minimum value from the heap and maintains the heap property
void extract_min() {
    swap(H[1], H[heapSize]);
    heapSize--;
    HeapDown(1);
}

int main() {
    int n, k;
    f >> n >> k;

    int enemyPowers[NMAX];
    for (int i = 0; i < n; ++i) {
        f >> enemyPowers[i];
    }

    int minPower = 1;
    for (int i = 0; i < n; ++i) {
        if (i > k) {
            insert(enemyPowers[i - k - 1]);
        }
        if (heapSize > 0 && find_min() < enemyPowers[i]) {
            minPower = max(minPower, enemyPowers[i] - find_min() + 1);
        }
        insert(enemyPowers[i]);
    }

    g << minPower << endl;

    return 0;
}
