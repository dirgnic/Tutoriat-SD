/*
 * counting_sort.cpp
 * Implements Counting Sort algorithm.
 * Time Complexity: O(n + k), where k is the range of the input.
 * Description: Counts occurrences of each distinct element and
 * computes positions to sort the array.
 */

#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> count(range), output(n);
    for (int i = 0; i < n; ++i)
        count[arr[i] - min_val]++;
    for (int i = 1; i < range; ++i)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

int main() {
    vector<int> data = {4, 2, 2, 8, 3, 3, 1};
    countingSort(data);
    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    cout << endl;
    return 0;
}
