/*
 merge_sort.cpp
 Time Complexity: O(n log n)
 Divide and conquer: split, sort subarrays, and merge.
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    vector<int> L(a.begin()+l, a.begin()+m+1), R(a.begin()+m+1, a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    vector<int> v = {12,11,13,5,6,7};
    mergeSort(v, 0, v.size()-1);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}