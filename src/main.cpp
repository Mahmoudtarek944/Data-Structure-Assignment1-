#include <iostream>
#include <bits/stdc++.h>

#include "Bitonic_array.h"
#include "Sort.h"
#include "Search.h"

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


using namespace std;



void view() {
    cout<<"Enter Size Array :"<<endl;
    int n;
    cin>>n;



}


int main() {
    FASTER
    Search search;
    Bitonic_array bitonic_array;
    int arr[4]={4, 2, 1, 3};
    vector<int>answer=bitonic_array.Bitonic(arr,4);
    for(int i=0;i<answer.size();i++) {
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    cout<<bitonic_array.get_Compare()<<endl;
    cout<<bitonic_array.get_Swap()<<endl;

    return 0;
}