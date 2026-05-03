#include "RotatedBinarySearch.h"

RotatedBinarySearch::RotatedBinarySearch(const vector<int>& inputArray) {
    array = inputArray;
    comparisonCount = 0;
}

int RotatedBinarySearch::search(int target) {
    comparisonCount = 0;

    int low  = 0;
    int high = static_cast<int>(array.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        ++comparisonCount;
        if (array[mid] == target) {
            return mid;
        }

        ++comparisonCount;
        if (array[low] == array[mid] && array[mid] == array[high]) {
            ++low;
            --high;
            continue;
        }

        ++comparisonCount;

        if (array[low] <= array[mid]) {
            ++comparisonCount;
            if (array[low] <= target && target < array[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            ++comparisonCount;
            if (array[mid] < target && target <= array[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int RotatedBinarySearch::getComparisonCount() const {
    return comparisonCount;
}

void RotatedBinarySearch::printArray() const {
    cout << "[ ";
    for (size_t i = 0; i < array.size(); ++i) {
        cout << array[i];
        if (i + 1 < array.size()) cout << ", ";
    }
    cout << " ]\n";
}