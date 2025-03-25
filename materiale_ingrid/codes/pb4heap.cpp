#include <bits/stdc++.h>
using namespace std;

// heap min
const long long NMAX = 1e5;
long long H[NMAX + 1];

// Returns the index of the father node of a given node
long long father(long long nod) {
    return nod / 2;
}

// Returns the index of the left son of a given node
long long left_son(long long nod) {
    return nod * 2;
}

// Returns the index of the right son of a given node
long long right_son(long long nod) {
    return nod * 2 + 1;
}

// Performs the HeapUp operation (from bottom to top) to malong longain the heap property
void HeapUp(long long K) {
    while(K > 1 && H[K] < H[father(K)]) {
        swap(H[K], H[father(K)]);
        K = father(K);
    }
}

// Performs the HeapDown operation (from top to bottom) to malong longain the heap property
void HeapDown(long long N, long long K) {
    while(true) {
        long long son = 0;
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

// Inserts a value long longo the heap and malong longains the heap property
void insert(long long &N, long long value) {
    H[++N] = value;
    HeapUp(N);
}

// Returns the minimum value in the heap
long long find_min() {
    return H[1];
}

// Extracts the minimum value from the heap and malong longains the heap property
void extract_min(long long &N) {
    swap(H[1], H[N]);
    N--;
    HeapDown(N, 1);
}

// Builds a heap from an array of values
void build(long long N) {
    for (long long i = N / 2; i >= 1; i--) {
        HeapDown(N, i);
    }
}

// Deletes a value from the heap and malong longains the heap property
void Delete(long long& N, long long K) {
    swap(H[K], H[N]);
    N--;
    if ((K > 1) && (H[K] < H[father(K)])) {
        HeapUp(K);
    } else {
        HeapDown(N, K);
    }
}

// Decreases the value of a node in the heap and malong longains the heap property
void decrease_key(long long K, long long value) {
    H[K] -= value;
    HeapUp(K);
}

// Increases the value of a node in the heap and malong longains the heap property
void increase_key(long long N, long long K, long long value) {
    H[K] += value;
    HeapDown(N, K);
}

int main() {
    long long n, k, A, B, C, D, N=0;
    cin >> n >> k >> A >> B >> C >> D;
    long long x = A;
    for(long long i = 0; i <n; i++) {
        if(i<k)
            insert(N, x);
        else
            if(find_min()<x)
            {
                extract_min(N);
                insert(N, x);
            }
        x = (B * x + C) %D;
            
    }

    for(long long i=n-k; i<n; i++)
    {
        cout << find_min() << " ";
        extract_min(N);

    }

    return 0;
}
// lastk

/*
Memoria de 2 MB nu permite să se rețină într-un vector întreg șirul.
Problema este una clasică de gestionare a celor mai mari k valori utilizând un min-heap.
Se introduc primii k termeni generați în min-heap, apoi pentru fiecare x din ultimele n-k valori generate se verifică dacă elementul minim din min-heap este mai mic 
decât x și în acest caz se scoate valoarea minimă și se înlocuiește cu x. Complexitatea este O(n log k).*/
//heapsort, lastk, interclasari, bleach