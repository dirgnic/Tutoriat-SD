/*
 * heap_sort.cpp
 * Implements Heap Sort algorithm.
 * Time Complexity: O(n log n)
 * Description: Builds a max-heap and repeatedly extracts the maximum element
 * and rebuilds the heap.
 */

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    // Extract elements one by one
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> data = {4, 10, 3, 5, 1};
    heapSort(data);
    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}
