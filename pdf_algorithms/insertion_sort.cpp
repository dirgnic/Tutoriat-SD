/*
 insertion_sort.cpp
 Time Complexity: O(n^2)
 Builds the sorted array one element at a time by insertion.
*/
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    for(int i = 1; i < arr.size(); ++i) {
        int key = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    vector<int> v = {5,2,9,1,5,6};
    insertionSort(v);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}