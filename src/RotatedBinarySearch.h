#ifndef ROTATED_BINARY_SEARCH_H
#define ROTATED_BINARY_SEARCH_H

#include <vector>
#include <iostream>

using namespace std;

class RotatedBinarySearch {
private:
    vector<int> array;
    int comparisonCount;

public:
    RotatedBinarySearch(const vector<int>& inputArray);

    int search(int target);
    int getComparisonCount() const;
    void printArray() const;
};

#endif