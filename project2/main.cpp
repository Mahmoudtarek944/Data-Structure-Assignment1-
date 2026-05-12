#include <iostream>
#include <bits/stdc++.h>
#include "Emergency_Room_Priority_System.h"
using namespace std;
int main() {


        Emergency_Room_Priority_System er;

        er.insert({1, "Ahmed", 5, 1});
        er.insert({2, "Ali", 9, 2});
        er.insert({3, "Sara", 9, 1});

        er.print();

        cout << endl;

        er.View_Next_Patient();

        cout << endl;

        er.Treat_Next_Patient();

        cout << endl;

        er.print();

    return 0;
}