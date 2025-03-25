/**
 * Calculates the greatest common divisor (GCD) of two numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The GCD of the two numbers.
 */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * Calculates the least common multiple (LCM) of two numbers.
 * @param a The first number.
 * @param b The second number.
 * @return The LCM of the two numbers.
 */
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

/**
 * Sorts an array of integers using the bubble sort algorithm.
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

#include <vector>

/**
 * Calculates the prime factors of a given number.
 * @param n The number to calculate the prime factors for.
 * @return An array containing the prime factors of the number.
 */
int* primeFactors(int n, int& size) {
    int* factors = new int[n];
    int index = 0;
    while (n % 2 == 0) {
        factors[index++] = 2;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[index++] = i;
            n /= i;
        }
    }
    if (n > 2) {
        factors[index++] = n;
    }
    size = index;
    return factors;
}

/**
 * Checks if a number is prime.
 * @param n The number to check.
 * @return True if the number is prime, false otherwise.
 */
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

/**
 * Performs a binary search on a sorted array.
 * @param arr The sorted array to search in.
 * @param l The leftmost index of the search range.
 * @param r The rightmost index of the search range.
 * @param x The value to search for.
 * @return The index of the value if found, -1 otherwise.
 */
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

/**
 * Merges two sorted subarrays into a single sorted array.
 * @param arr The array to be merged.
 * @param l The leftmost index of the first subarray.
 * @param m The rightmost index of the first subarray.
 * @param r The rightmost index of the second subarray.
 */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

/**
 * Sorts an array of integers using the merge sort algorithm.
 * @param arr The array to be sorted.
 * @param l The leftmost index of the array.
 * @param r The rightmost index of the array.
 */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/**
 * Partitions the array and returns the index of the pivot element.
 * @param arr The array to be partitioned.
 * @param low The leftmost index of the array.
 * @param high The rightmost index of the array.
 * @return The index of the pivot element.
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/**
 * Sorts an array of integers using the quick sort algorithm.
 * @param arr The array to be sorted.
 * @param low The leftmost index of the array.
 * @param high The rightmost index of the array.
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Sorts an array of integers using the insertion sort algorithm.
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/**
 * Sorts an array of integers using the selection sort algorithm.
 * @param arr The array to be sorted.
 * @param n The size of the array.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

/**
 * Calculates the nth Fibonacci number.
 * @param n The index of the Fibonacci number to calculate.
 * @return The nth Fibonacci number.
 */
int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/**
 * Calculates the nth Fibonacci number recursively.
 * @param n The index of the Fibonacci number to calculate.
 * @return The nth Fibonacci number.
 */
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/**
 * Calculates the factorial of a number.
 * @param n The number to calculate the factorial for.
 * @return The factorial of the number.
 */
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Calculates the factorial of a number recursively.
 * @param n The number to calculate the factorial for.
 * @return The factorial of the number.
 */
int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

/**
 * Performs a linear search for a value in an array.
 * @param arr The array to search in.
 * @param n The size of the array.
 * @param x The value to search for.
 * @return The index of the value if found, -1 otherwise.
 */
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}
