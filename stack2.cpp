#include <bits/stdc++.h>
using namespace std;
int main() {
    int n ; 
    cin >> n ;
    int arr[n] ;
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    
    for (int i = 0 ; i < n ; i++){
        int resNum = -1 ;
        int currNum = arr[i] ; 
        for (int j = 1 ; j < n ; j++){
            int circular = ( i + j ) % n ;
            if(currNum < arr[circular]  ){
                resNum = arr[circular] ;
                break; 
            }
        }
        cout << resNum << " " ;
    }

}