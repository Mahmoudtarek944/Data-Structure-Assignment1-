#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include <vector>
#include <queue>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

class Round_Robin {
public:
    void print_queue(queue<int> q);
    void run(int TQ, vector<Process>& v);
};

#endif