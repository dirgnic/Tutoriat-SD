/*
 heap_sort.cpp
 Time Complexity: O(n log n)
 Builds a max-heap, then extracts max element repeatedly.
*/
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i, l=2*i+1, r=2*i+2;
    if(l<n && a[l]>a[largest]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;
    if(largest!=i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for(int i=n/2-1; i>=0; --i) heapify(a,n,i);
    for(int i=n-1; i>0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> v = {4,10,3,5,1};
    heapSort(v);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}