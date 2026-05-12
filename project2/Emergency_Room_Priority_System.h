
#ifndef EMERGENCY_ROOM_PRIORITY_SYSTEM_H
#define EMERGENCY_ROOM_PRIORITY_SYSTEM_H

#include <bits/stdc++.h>
using namespace std;
struct Patient {
    int id;
    string name;
    int severity;
    int arrivalTime;
};


class Emergency_Room_Priority_System {
    public:
    vector<Patient> heap;


    bool higherPriority(Patient a, Patient b);

    void heapify_MAX(int index);

    void heapify_MIN(int index);


    void insert(Patient patient);

    void Treat_Next_Patient ();

    void  View_Next_Patient ();

    void  Update_Severity (int id, int newSeverity);

    void print();



};


#endif //EMERGENCY_ROOM_PRIORITY_SYSTEM_H
