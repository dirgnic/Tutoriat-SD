/*
 * selection_sort.cpp
 * Implements Selection Sort algorithm.
 * Time Complexity: O(n^2)
 * Description: Repeatedly selects the minimum element from the unsorted portion
 * and moves it to the sorted portion.
 */

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        // Find index of minimum element in remaining unsorted array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> data = {64, 25, 12, 22, 11};
    selectionSort(data);
    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}
