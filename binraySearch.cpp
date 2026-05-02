#include <bits/stdc++.h>
using namespace std;

int searchRotated(vector<int>& arr, int target, int& comparisons) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid =( left + right)/ 2;
        comparisons++;
        if (arr[mid] == target)
            return mid;
        if (arr[left] == arr[mid] && arr[mid] == arr[right]) { // duplicates
            left++;
            right--;
        }
        else if (arr[left] <= arr[mid]) { // left sorted
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if (arr[left] > arr[mid]) { // right sorted
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n ; cin >> n ;
    vector<int> v ;
    for (int i =0 ; i < n ; i++){
        cin >> v[i]; 
    }
    int target ;
    cin >> target ;
    int comparisons = 0;
    int idx = searchRotated(v, target, comparisons);
    cout << "Index: " << idx << endl;
    cout << "# of Comparisons: " << comparisons << endl;
    return 0 ;
}
