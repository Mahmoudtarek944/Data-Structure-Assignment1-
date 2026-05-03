#include <iostream>
#include <vector>

using namespace std;

int rotatedBinarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;
        if (arr[mid] == target) {
            cout << "Total element-to-element comparisons: " << comparisons << endl;
            return mid + 1;
        }

        comparisons+=2;
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        comparisons++;
        if (arr[low] <= arr[mid]) {
            //left half is sorted
            comparisons+=2;
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            //right half is sorted
            comparisons+=2;
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    cout << "Total element-to-element comparisons: " << comparisons << endl;
    return -1;
}

int main() {
    // vector<int> arr = {5, 6, 7, 1, 1, 1, 2, 3};
    // int target = 6;
    vector<int> arr = {5, 6, 7, 7, 7, 1, 2, 3, 4};
    int target = 2;

    int result = rotatedBinarySearch(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}