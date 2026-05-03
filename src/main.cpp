#include "RotatedBinarySearch.h"
#include "BitonicArray.h"


// === Start Rotated Binary Search ===

// void printResultRotatedBinarySearch(RotatedBinarySearch& searcher, int target) {
//     searcher.printArray();
//     cout << "Target: " << target << "\n";
//
//     int resultIndex = searcher.search(target);
//
//     if (resultIndex != -1) {
//         cout << "Found at index " << resultIndex << "\n";
//     } else {
//         cout << "Not found\n";
//     }
//
//     cout << "Comparisons made: " << searcher.getComparisonCount() << "\n\n";
// }
// void testRotated() {
//     RotatedBinarySearch s1({5, 6, 7, 1, 2, 3, 4});
//     printResultRotatedBinarySearch  (s1, 1);
//
//     RotatedBinarySearch s2({5, 6, 7, 1, 2, 3, 4});
//     printResultRotatedBinarySearch  (s2, 7);
//
//     RotatedBinarySearch s3({5, 6, 7, 1, 2, 3, 4});
//     printResultRotatedBinarySearch  (s3, 9);
//
//     RotatedBinarySearch s4({3, 3, 1, 2, 3, 3});
//     printResultRotatedBinarySearch  (s4, 1);
//
//     RotatedBinarySearch s5({5, 5, 5, 5, 5});
//     printResultRotatedBinarySearch  (s5, 3);
//
//     cout << "Best  case : O(1)\n";
//     cout << "Average    : O(log n)\n";
//     cout << "Worst case : O(n)\n";
// }

// === End Rotated Binary Search ===
// =================================
// === Start Bitonic Array ===

// void printResultBitonic(BitonicArray& b, int target) {
//     b.printArray();
//     cout << "Target: " << target << "\n";
//
//     int index = b.linearSearch(target);
//
//     if (index != -1) {
//         cout << "Found at index " << index << "\n";
//     } else {
//         cout << "Not found\n";
//     }
//
//     cout << "Comparisons: " << b.getComparisonCount() << "\n";
//     cout << "Swaps: " << b.getSwapCount() << "\n\n";
// }
//
// void testBitonic()
// {
//     BitonicArray b1({3, 1, 8, 4, 12, 6, 9});
//     b1.sortBitonic();
//     printResultBitonic(b1, 12);
//
//     BitonicArray b2({7, 2, 9, 1, 5, 11, 4});
//     b2.sortBitonic();
//     printResultBitonic(b2, 2);
//
//     BitonicArray b3({6, 3, 10, 8, 1, 14, 5});
//     b3.sortBitonic();
//     printResultBitonic(b3, 5);
//
//     BitonicArray b4({9, 4, 7, 2, 11, 6, 3});
//     b4.sortBitonic();
//     printResultBitonic(b4, 99);
//
//     BitonicArray b5({5, 5, 3, 8, 5, 2, 8});
//     b5.sortBitonic();
//     printResultBitonic(b5, 5);
// }

// === End Bitonic Array ===


int main() {
    // testRepeated();
    // testBitonic();
    return 0;
}