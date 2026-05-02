#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int l, int r, int& comp, int& swaps) {
    for (int i = l; i < r; i++) {
        bool flag = true ;
        for (int j = l; j < r - (i - l); j++) {
            comp++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swaps++;
                flag = false ;
            }
        }
        if(flag){
            break;
        }
    }
}
void selectionSort(vector<int>& arr, int l, int r, int& comp, int& swaps) {
    for (int i = l; i <= r; i++) {
        int maxIdx = i;
        for (int j = i+1; j <= r; j++) {
            comp++;
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        }
        if (i != maxIdx) {
            swap(arr[i], arr[maxIdx]);
            swaps++;
        }
    }
}
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main() {
    int n ; cin >> n ;
    vector<int> v ;
    for (int i = 0 ; i < n ; i++){
        cin >> v [i] ;
    }
    int mid = n/2;
    int comp = 0, swaps = 0;

    bubbleSort(v, 0, mid-1, comp, swaps);
    selectionSort(v, mid, n-1, comp, swaps);

    int target ;
    cin >>target ;
    int idx = linearSearch(v, target);

    cout << "array: ";
    for (int x : v) cout << x << " ";
    cout << "\n";

    cout << "Index: " << idx << endl;
    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;
}