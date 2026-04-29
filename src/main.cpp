#include <iostream>
#include <bits/stdc++.h>
#include "circular_array.h"
#include "Bitonic_array.h"
#include "Sort.h"
#include "Search.h"

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


using namespace std;






int main() {
    // FASTER
    // Search search;
    // Bitonic_array bitonic_array;
    // int n;
    // cout << "Enter number of elements: ";
    // cin >> n;
    //
    // int arr[n];
    //
    // cout << "Enter elements:";
    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // int Target;
    // cout << "Enter Target: ";
    // cin >> Target;
    // vector<int> answer = bitonic_array.Bitonic(arr, n);
    //
    // cout << "--- Bitonic Array Result ---\n";
    // for(int i = 0; i < answer.size(); i++) {
    //     cout << answer[i] << " ";
    // }
    // cout << endl;
    // cout << "Comparisons: " << bitonic_array.get_Compare() << endl;
    // cout << "Swaps: " << bitonic_array.get_Swap() << endl;
    // int Index=search.Linear_Search(answer,Target);
    // cout << "--- Linear Search Result ---\n";
    // cout<<"Is it available? "<<search.get_flag()<<" || "<<"Index :"<<Index;



    vector<int>v1={1,2,3,4,3};

    circular_array circular_array;
    vector<int> vec;
    vec=circular_array.solve(v1);
    for (auto i : vec) {
        cout<<i<<" ";
    }






    return 0;
}