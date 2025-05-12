/*
 bubble_sort.cpp
 Time Complexity: O(n^2)
 Repeatedly compare and swap adjacent elements until the array is sorted.
*/
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for(int i = 0; i < n - 1; ++i) {
        swapped = false;
        for(int j = 0; j < n - 1 - i; ++j) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main() {
    vector<int> v = {5,1,4,2,8};
    bubbleSort(v);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}