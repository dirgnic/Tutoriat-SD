/*
 * insertion_sort.cpp
 * Implements Insertion Sort algorithm.
 * Time Complexity: O(n^2)
 * Description: Builds the sorted array one element at a time,
 * by inserting each new element into its correct position.
 */

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> data = {5, 2, 9, 1, 5, 6};
    insertionSort(data);
    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}
