
#ifndef SEARCH_H
#define SEARCH_H
#include "Bitonic_array.h"


class Search {
private:
        int Comparison;
        bool flag;
public:
        Search( ):Comparison(0),flag(false){}
        int Binary_Search(int arr[],int size,int val);
        int Linear_Search(vector<int>& arr,int val);
        int Rotated_Search(int arr[],int size,int val);



        int get_Comparison() const {return Comparison;}
        string get_flag() const {
                if (flag) return "true";
                else return "false";
        }





};



#endif
