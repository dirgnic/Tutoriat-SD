#include <iostream>
#include <vector>
#include <cmath>    
using namespace std;

// Bubble Sort
// Algoritmul parcurge vectorul repetat și compară elementele adiacente.
// Dacă un element este mai mare decât următorul, ele sunt interschimbate.
// Procesul continuă până când vectorul este sortat.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
// Algoritmul găsește cel mai mic element din vector și îl mută la început.
// Procesul se repetă pentru fiecare poziție până când vectorul este sortat.
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Insertion Sort
// Algoritmul inserează fiecare element în poziția corectă în partea sortată a vectorului.
// Se compară elementul curent cu cele dinaintea lui și se mută în poziția corectă.
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
// Algoritmul împarte vectorul în jumătăți până când fiecare subvector are un singur element.
// Apoi, combină (merge) subvectorii în ordine sortată.
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
// Algoritmul alege un pivot și împarte vectorul în două părți:
// elementele mai mici decât pivotul și cele mai mari.
// Apoi sortează recursiv cele două părți.
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

// Heap Sort
// Algoritmul construiește un heap maxim din vector.
// Apoi extrage elementul maxim (rădăcina heap-ului) și reconstruiește heap-ul.
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Counting Sort
// Algoritmul numără frecvența fiecărui element și reconstruiește vectorul sortat.
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());
    for (int num : arr) count[num - minVal]++; 
    for (int i = 1; i < range; ++i) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    arr = output;
}

// Bucket Sort
// Algoritmul împarte elementele în mai multe "buckets" (găleți).
// Fiecare găleată este sortată individual, apoi toate sunt combinate.
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());
    int bucketCount = n;

    vector<vector<int>> buckets(bucketCount);
    for (int num : arr) {
        int idx = (num * bucketCount) / (maxVal + 1);
        buckets[idx].push_back(num);
    }
    arr.clear();
    for (auto& bucket : buckets) {
        heapSort(bucket);
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

// Radix Sort
// Algoritmul sortează elementele pe baza cifrelor, de la cea mai puțin semnificativă la cea mai semnificativă.
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n), count(10, 0);

    for (int num : arr) count[(num / exp) % 10]++;
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    // Bubble Sort
    vector<int> bubbleArr = arr;
    bubbleSort(bubbleArr);
    cout << "Bubble Sorted: ";
    printArray(bubbleArr);

    // Selection Sort
    vector<int> selectionArr = arr;
    selectionSort(selectionArr);
    cout << "Selection Sorted: ";
    printArray(selectionArr);

    // Insertion Sort
    vector<int> insertionArr = arr;
    insertionSort(insertionArr);
    cout << "Insertion Sorted: ";
    printArray(insertionArr);

    // Merge Sort
    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "Merge Sorted: ";
    printArray(mergeArr);

    // Quick Sort
    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size() - 1);
    cout << "Quick Sorted: ";
    printArray(quickArr);

    // Heap Sort
    vector<int> heapArr = arr;
    heapSort(heapArr);
    cout << "Heap Sorted: ";
    printArray(heapArr);

    // Counting Sort
    vector<int> countingArr = arr;
    countingSort(countingArr);
    cout << "Counting Sorted: ";
    printArray(countingArr);

    // Bucket Sort
    vector<int> bucketArr = arr;
    bucketSort(bucketArr);
    cout << "Bucket Sorted: ";
    printArray(bucketArr);

    // Radix Sort
    vector<int> radixArr = arr;
    radixSort(radixArr);
    cout << "Radix Sorted: ";
    printArray(radixArr);

    return 0;
}