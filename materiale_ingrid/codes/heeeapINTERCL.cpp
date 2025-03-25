#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream f("interclasari.in");
ofstream g("interclasari.out");

struct Photo {
    int val, echip, index;
} p;

// heap min
const int NMAX = 1e5;
Photo H[NMAX + 1];

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
    while (K > 1 && H[K].val < H[father(K)].val) {
        swap(H[K], H[father(K)]);
        K = father(K);
    }
}

// Performs the HeapDown operation (from top to bottom) to maintain the heap property
void HeapDown(int N, int K) {
    while (true) {
        int son = 0;
        if (left_son(K) <= N) {
            son = left_son(K);
            if (right_son(K) <= N && H[right_son(K)].val < H[son].val) {
                son = right_son(K);
            }
        }
        if (son && H[son].val < H[K].val) {
            swap(H[son], H[K]);
            K = son;
        } else {
            break;
        }
    }
}

// Inserts a value into the heap and maintains the heap property
void insert(int& N, Photo p) {
    H[++N] = p;
    HeapUp(N);
}

// Returns the minimum value in the heap
Photo find_min() {
    return H[1];
}

// Extracts the minimum value from the heap and maintains the heap property
void extract_min(int& N) {
    swap(H[1], H[N]);
    N--;
    HeapDown(N, 1);
}

// Structure for storing photos
struct {
    int val, n;
} v[1000][100];

int main() {
    int k, T = 0, N = 0, n, x;

    f >> k;

    for (int i = 0; i < k; i++) {
        f >> n;
        T += n;
        for (int j = 0; j < n; j++) {
            f >> x;
            v[i][j].val = x;
            v[i][j].n = n;
        }
    }

    for (int i = 0; i < k; i++) {
        if (v[i][0].n > 0) {
            p = {v[i][0].val, i, 0};
            insert(N, p);
        }
    }

    g << T << endl;

    while (N) {
        Photo x = find_min();
        g << x.val << " ";
        extract_min(N);
        if (x.index + 1 < v[x.echip][0].n) {
            insert(N, {v[x.echip][x.index + 1].val, x.echip, x.index + 1});
        }
    }

    return 0;
}
