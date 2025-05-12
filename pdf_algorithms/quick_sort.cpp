/*
 * quick_sort.cpp
 * Implements Quick Sort algorithm.
 * Time Complexity: Average O(n log n), Worst O(n^2)
 * Description: Picks a pivot, partitions array around pivot,
 * and recursively sorts subarrays.
 */

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    quickSort(data, 0, data.size() - 1);
    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}
