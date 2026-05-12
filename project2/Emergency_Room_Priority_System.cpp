#include "Emergency_Room_Priority_System.h"

void Emergency_Room_Priority_System::print() {
    if (heap.empty()) {

        cout << "No Patients\n";
        return;
    }

    for (Patient p : heap) {
        cout << "ID: " << p.id
             << " Name: " << p.name
             << " Severity: " << p.severity
             << " Arrival: " << p.arrivalTime
             << endl;
    }
}

void Emergency_Room_Priority_System::insert(Patient p) {
    heap.push_back(p);
    heapify_MAX(heap.size()-1);
}

bool Emergency_Room_Priority_System::higherPriority(Patient a, Patient b) {
    if (a.severity > b.severity)
        return true;

    if (a.severity == b.severity &&
        a.arrivalTime < b.arrivalTime)
        return true;

    return false;
}

void Emergency_Room_Priority_System::heapify_MAX(int index) {
    while (index > 0) {
        int parent=(index-1)/2;
        if (higherPriority(heap[index],heap[parent])) {
            swap(heap[index],heap[parent]);
            index = parent;
        }
        else break;
    }

}



void Emergency_Room_Priority_System::heapify_MIN(int index) {
    int size = heap.size();

    while (true) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int largest = index;

        if (left < size &&
            higherPriority(heap[left], heap[largest])) {

            largest = left;
            }

        if (right < size &&
            higherPriority(heap[right], heap[largest])) {

            largest = right;
            }

        if (largest != index) {

            swap(heap[index], heap[largest]);

            index = largest;
        }
        else {
            break;
        }
    }
}
// remove the first pirority
void Emergency_Room_Priority_System::Treat_Next_Patient() {
    if (heap.empty()) {
        cout << "No Patients\n";
        return;
    }

    cout << "Treating: "<< heap[0].name << endl;

    heap[0] = heap.back();

    heap.pop_back();

    if (!heap.empty()) {
        heapify_MIN(0);
    }
}


void Emergency_Room_Priority_System::Update_Severity(int id, int newSeverity) {

    for (int i = 0; i < (int)heap.size(); i++) {

        if (heap[i].id == id) {

            int oldSeverity = heap[i].severity;

            heap[i].severity = newSeverity;

            if (newSeverity > oldSeverity)
                heapify_MAX(i);

            else
                heapify_MIN(i);

            return;
        }
    }

    cout << "Patient not found\n";
}
void Emergency_Room_Priority_System::View_Next_Patient() {

    if (heap.empty()) {

        cout << "No Patients\n";
        return;
    }

    Patient p = heap[0];

    cout << "Next Patient:\n";

    cout << "ID: " << p.id << endl;
    cout << "Name: " << p.name << endl;
    cout << "Severity: " << p.severity << endl;
    cout << "Arrival: " << p.arrivalTime << endl;
}
