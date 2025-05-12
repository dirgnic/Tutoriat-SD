/*
 counting_sort.cpp
 Time Complexity: O(n + k)
 Counts occurrences and computes positions to sort.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& a) {
    int n = a.size();
    if(n==0) return;
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    vector<int> cnt(mx-mn+1), out(n);
    for(int x: a) cnt[x-mn]++;
    for(int i=1; i<cnt.size(); ++i) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; --i) {
        out[cnt[a[i]-mn]-1] = a[i];
        cnt[a[i]-mn]--;
    }
    a = out;
}

int main() {
    vector<int> v = {4,2,2,8,3,3,1};
    countingSort(v);
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}