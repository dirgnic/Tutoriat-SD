/*
 quick_sort.cpp
 Average Time: O(n log n), Worst: O(n^2)
 Picks a pivot and partitions array recursively.
*/
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high], i=low-1;
    for(int j=low; j<high; ++j) {
        if(a[j] < pivot) swap(a[++i], a[j]);
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(vector<int>& a, int low, int high) {
    if(low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int main() {
    vector<int> v = {10,7,8,9,1,5};
    quickSort(v, 0, v.size()-1);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}