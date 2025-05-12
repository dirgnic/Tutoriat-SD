#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapsort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> a;
    int x;
    cout << "Introduceti elementele (EOF pentru terminare):\n";
    while (cin >> x) a.push_back(x);
    heapsort(a);
    cout << "Vector sortat: ";
    for (int v : a) cout << v << " ";
    cout << "\n";
    return 0;
}
