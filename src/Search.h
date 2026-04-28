
#ifndef SEARCH_H
#define SEARCH_H
#include "Bitonic_array.h"


class Search {
private:
        int Comparison;
public:
        Search( ):Comparison(0){}
        int Binary_Search(int arr[],int size,int val);
        int Linear_Search(vector<int>& arr,int val);
        int Rotated_Search(int arr[],int size,int val);



        int get_Comparison() const {return Comparison;}





};



#endif
