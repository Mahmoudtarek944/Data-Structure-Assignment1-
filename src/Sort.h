
#ifndef SORT_H
#define SORT_H


class Sort {


    public:
    void Selection_Sort(int arr[], int n);
    void Insertion_Sort(int arr[], int n);
    void Merge_Sort(int arr[], int l, int r);
    void Marge(int arr[], int l, int r);
    int  Partition(int arr[], int l, int r);
    void Shell_Sort(int arr[], int n);
    void Bubble_Sort(int arr[], int n);
    void Quick_Sort(int arr[],int low,int high);


};



#endif //SORT_H
