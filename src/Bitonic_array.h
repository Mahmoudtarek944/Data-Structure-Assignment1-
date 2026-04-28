
#ifndef BITONIC_ARRAY_H
#define BITONIC_ARRAY_H
#include <bits/stdc++.h>
using namespace std;

class Bitonic_array {
    private:
    int Swap;
    int Compare;




    public:
    Bitonic_array():Swap(0),Compare(0){}
    vector<int> Bitonic(int arr[], int n);



    int get_Compare() {return Compare;}
    int get_Swap() {return Swap;}



};



#endif //BITONIC_ARRAY_H
