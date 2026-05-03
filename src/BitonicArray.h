#ifndef BITONIC_ARRAY_H
#define BITONIC_ARRAY_H

#include <vector>
#include <iostream>

using namespace std;

class BitonicArray {
private:
    vector<int> array;
    int comparisonCount;
    int swapCount;

    void bubbleSortAscending(int left, int right);
    void selectionSortDescending(int left, int right);

public:
    BitonicArray(const vector<int>& inputArray);

    void sortBitonic();
    int linearSearch(int target);
    int getComparisonCount() const;
    int getSwapCount() const;
    void printArray() const;
};

#endif
