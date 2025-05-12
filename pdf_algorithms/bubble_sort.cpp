/*
 * bubble_sort.cpp
 * Implements Bubble Sort algorithm.
 * Time Complexity: O(n^2)
 * Description: Repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in the wrong order.
 */

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    // Outer loop for passes
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no swaps happened, the array is already sorted
        if (!swapped) break;
    }
}

int main() {
    vector<int> data = {5, 1, 4, 2, 8};
    bubbleSort(data);
    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}
