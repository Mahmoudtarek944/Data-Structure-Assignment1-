#include "Sort.h"
#include <algorithm>
using namespace std;



// best O(n)  <>   worst  O(n*n)
void Sort::Selection_Sort(int arr[], int n) {


    for (int i = 0; i < n-1; i++) {
        int l=i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[l]) {
                l=j;
            }

        }
        if (l != i) {
            swap(arr[i], arr[l]);
        }
    }
}


// best O(n)  <>   worst  O(n*n)
void Sort::Insertion_Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j=i;
        for (; j > 0 && arr[j-1]>arr[j]; j--) {
            swap(arr[j], arr[j-1]);
        }
    }
}



// best O(n log(n) )  <>   worst  O(n*n)
void Sort::Shell_Sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            int temp = arr[i];
            while (j >= gap && arr[j-gap] > temp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
        }
    }

}

// best O(n*n)  <>   worst  O(n*n)
void Sort::Bubble_Sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }

        }
    }
}


// best O(n log(n))  <>   worst  O(n log(n))

void Sort::Marge(int arr[], int l, int r) {
    int mid = (l + r) / 2;

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++)
        arr1[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        arr2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }

    while (i < n1)
        arr[k++] = arr1[i++];

    while (j < n2)
        arr[k++] = arr2[j++];
}


void Sort::Merge_Sort(int arr[], int l, int r) {
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    Merge_Sort(arr, l, mid);
    Merge_Sort(arr, mid + 1, r);

    Marge(arr, l, r);
}



// best O(n log(n))  <>   worst  O(n*n)

int Sort::Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[i]);
    return i;
}

void Sort::Quick_Sort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int pi = Partition(arr, low, high);

    Quick_Sort(arr, low, pi - 1);
    Quick_Sort(arr, pi + 1, high);
}