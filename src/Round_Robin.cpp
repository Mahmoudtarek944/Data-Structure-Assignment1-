#include <iostream>
#include <iomanip>
#include "Round_Robin.h"
using namespace std;

void Round_Robin::print_queue(queue<int> q) {
    if (q.empty()) {
        cout << "[ Empty ]" << endl;
        return;
    }
    cout << "[ ";
    while (!q.empty()) {
        cout << "P" << q.front() + 1;
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << " ]" << endl;
}

void Round_Robin::run(int TQ, vector<Process>& v) {
    int n = v.size();

    queue<int> q;
    vector<bool> in_queue(n, false);
    int time = 0;

    time = v[0].arrival_time;

    for (int i = 0; i < n; i++) {
        if (v[i].arrival_time <= time && !in_queue[i]) {
            q.push(i);
            in_queue[i] = true;
        }
    }

    auto has_remaining = [&]() {
        for (int i = 0; i < n; i++)
            if (v[i].remaining_time > 0) return true;
        return false;
    };

    while (!q.empty() || has_remaining()) {
        if (q.empty()) {
            print_queue(q);

            for (int i = 0; i < n; i++) {
                if (v[i].remaining_time > 0) {
                    time = v[i].arrival_time;
                    q.push(i);
                    in_queue[i] = true;
                    break;
                }
            }
        }

        print_queue(q);

        int curr = q.front();

        int run_time = min(TQ, v[curr].remaining_time);
        v[curr].remaining_time -= run_time;
        time += run_time;

        for (int i = 0; i < n; i++) {
            if (v[i].arrival_time <= time && !in_queue[i] && v[i].remaining_time > 0) {
                q.push(i);
                in_queue[i] = true;
            }
        }

        q.pop();

        if (v[curr].remaining_time == 0) {
            v[curr].completion_time = time;
            v[curr].turnaround_time = time - v[curr].arrival_time;
            v[curr].waiting_time = v[curr].turnaround_time - v[curr].burst_time;
        } else {
            q.push(curr);
        }
    }

    print_queue(q);

    cout << "\nProcess\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    float total_waiting = 0;

    for (int i = 0; i < n; i++) {
        cout << "P" << v[i].id + 1 << "\t"
             << v[i].completion_time << "\t\t"
             << v[i].turnaround_time << "\t\t"
             << v[i].waiting_time << "\n";
        total_waiting += v[i].waiting_time;
    }

    cout << "\nAverage Waiting Time: "
         << fixed << setprecision(3)
         << total_waiting / n << "\n";
}