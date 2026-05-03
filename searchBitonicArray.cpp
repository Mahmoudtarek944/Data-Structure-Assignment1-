#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& arr, int start, int end, int& comps, int& swaps) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start); j++) {
            comps++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void selectionSort(vector<int>& arr, int start, int end, int& comps, int& swaps) {
    for (int i = start; i <= end; i++) {
        int maxIdx = i;
        for (int j = i + 1; j <= end; j++) {
            comps++;
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(arr[i], arr[maxIdx]);
            swaps++;
        }
    }
}

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i + 1;
    }
    return -1;
}

void processBitonicArray(vector<int>& arr) {
    int n = arr.size();
    int comps = 0, swaps = 0;
    int mid = n / 2;

    if (mid > 0) {
        bubbleSort(arr, 0, mid - 1, comps, swaps);
    }

    if (mid < n) {
        selectionSort(arr, mid, n - 1, comps, swaps);
    }

    cout << "Bitonic Array:" << endl;
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Sorting Metrics: Comparisons = " << comps << ", Swaps = " << swaps << endl;
}

int main() {
    vector<int> arr = {15, 3, 7, 7, 12, 1, 9};
    processBitonicArray(arr);

    // Test Case 1: Target at bitonic point (transition area)
    int target = 15;
    cout << "Found " << target << " at index: " << linearSearch(arr, target) << endl;

    // Test Case 2: Target in the left half (ascending)
    target = 3;
    cout << "Found " << target << " at index: " << linearSearch(arr, target) << endl;

    // Test Case 3: Target in the right half (descending)
    target = 9;
    cout << "Found " << target << " at index: " << linearSearch(arr, target) << endl;

    // Test Case 4: Target not present
    target = 5;
    cout << "Found " << target << " at index: " << linearSearch(arr, target) << endl;

    // Test Case 5: Array with duplicate elements
    target = 7;
    cout << "Found " << target << " at index: " << linearSearch(arr, target) << endl;

    return 0;
}