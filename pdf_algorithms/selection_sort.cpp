/*
 selection_sort.cpp
 Time Complexity: O(n^2)
 Repeatedly selects the minimum element and places it at the front.
*/
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for(int j = i+1; j < n; ++j)
            if(arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    vector<int> v = {64,25,12,22,11};
    selectionSort(v);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}