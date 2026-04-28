#include "Search.h"
using namespace std;


// O(log(n)) and must be Sort
int Search::Binary_Search(int arr[],int size,int val ) {
    int l=0,r=size-1;

    int index=-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(arr[mid]==val) {
            index=mid;
            return index;
        }
        else if(arr[mid]>val) {
            r=mid-1;
        }
        else if(arr[mid]<val) {
            l=mid+1;
        }

    }
    return -1;





}

// O(n)  no be Sort
int Search::Linear_Search(vector<int>& arr, int val) {

    for(int i=0;i<arr.size();i++) {
        Comparison++;
        if(arr[i]==val) {
            return i;
        }
    }
    return -1;

}




/*
arr = [5, 6, 7, 1, 2, 3, 4]
val=3

arr = [5, 6, 7, 1, 2, 3, 4]
val = 10


arr = [1, 2, 3, 4, 5, 6, 7]
val = 4




arr = [2, 2, 2, 3, 4, 2]
val = 3

 */
/*


 normal senior O(log (n))
 worst senior O( n )



 */


// 5,6,7,1,2,3,4
 int Search::Rotated_Search(int arr[], int size, int val) {
    int l=0,r=size-1;
    int index=-1;
    while(l<=r) {
        int mid=(l+r)/2;


        if (arr[l] == arr[mid] && arr[mid] == arr[r]) {
            l++;
            r--;
            continue;
        }
        if(arr[mid]==val){
            index=mid;
            return index;
        }
        if(arr[mid]>=arr[l]) {
            Comparison++;

            if(arr[l]<=val && val<arr[mid]) {

                r=mid-1;
            }
            else {
                l=mid+1;
            }

        }
         else {
            Comparison++;
            if(arr[mid]<val && val<=arr[r]) {
                l=mid+1;
            }
            else {
                r=mid-1;
            }

        }


    }
    return -1;
}
#include "Search.h"
