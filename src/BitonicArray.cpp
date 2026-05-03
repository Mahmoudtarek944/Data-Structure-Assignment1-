#include "BitonicArray.h"

BitonicArray::BitonicArray(const vector<int>& inputArray) {
    array = inputArray;
    comparisonCount = 0;
    swapCount = 0;
}

void BitonicArray::bubbleSortAscending(int left, int right) {
    for (int i = left; i < right; i++) {
        for (int j = left; j < right - (i - left); j++) {
            ++comparisonCount;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                ++swapCount;
            }
        }
    }
}

void BitonicArray::selectionSortDescending(int left, int right) {
    for (int i = left; i < right; i++) {
        int maxIndex = i;
        for (int j = i + 1; j <= right; j++) {
            ++comparisonCount;
            if (array[j] > array[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(array[i], array[maxIndex]);
            ++swapCount;
        }
    }
}

void BitonicArray::sortBitonic() {
    comparisonCount = 0;
    swapCount = 0;

    int mid = array.size() / 2;

    bubbleSortAscending(0, mid);
    selectionSortDescending(mid + 1, array.size() - 1);
}

int BitonicArray::linearSearch(int target) {
    for (int i = 0; i < (int)array.size(); i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int BitonicArray::getComparisonCount() const {
    return comparisonCount;
}

int BitonicArray::getSwapCount() const {
    return swapCount;
}

void BitonicArray::printArray() const {
    cout << "[ ";
    for (size_t i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i + 1 < array.size()) cout << ", ";
    }
    cout << " ]\n";
}
