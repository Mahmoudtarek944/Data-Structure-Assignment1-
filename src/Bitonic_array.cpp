#include "Bitonic_array.h"

#include <iostream>


vector<int> Bitonic_array::Bitonic(int arr[], int n)   {

    int mid = (n) / 2;

    //bubble sort
    for (int i = 0; i < mid-1; i++) {
        for (int j = 0; j < mid-i-1; j++) {
            Compare++;
            if (arr[j] > arr[j+1]) {
                Swap++;
                swap(arr[j], arr[j+1]);
            }

        }
    }

    //selection sort
    for (int i = mid; i < n-1; i++) {
        int k=i;
        for (int j = i+1; j < n; j++) {
            Compare++;
            if (arr[j] > arr[k]) {
                k=j;
            }

        }
        if (k != i) {
            swap(arr[i], arr[k]);
            Swap++;
        }

    }


    vector<int> answer(arr,arr+n);
    return answer;
}





#include "Bitonic_array.h"
