#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int priority; // Lower number = higher priority
    int completion;
    int turnaround;
    int waiting;
    bool done = false;
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input
    for (int i = 0; i < n; ++i)
    {
        p[i].pid = i + 1;
        cout << "Process " << p[i].pid << " Arrival Time: ";
        cin >> p[i].arrival;
        cout << "Process " << p[i].pid << " Burst Time: ";
        cin >> p[i].burst;
        cout << "Process " << p[i].pid << " Priority (lower = higher priority): ";
        cin >> p[i].priority;
    }

    int current_time = 0, completed = 0;
    float total_TAT = 0, total_WT = 0;

    while (completed < n)
    {
        int idx = -1;
        int best_priority = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (!p[i].done && p[i].arrival <= current_time)
            {
                if (p[i].priority < best_priority)
                {
                    best_priority = p[i].priority;
                    idx = i;
                }
                else if (p[i].priority == best_priority)
                {
                    // Tie-breaker: earlier arrival time
                    if (p[i].arrival < p[idx].arrival)
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1)
        {
            current_time++; // CPU idle
        }
        else
        {
            p[idx].completion = current_time + p[idx].burst;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].done = true;

            current_time = p[idx].completion;
            completed++;

            total_TAT += p[idx].turnaround;
            total_WT += p[idx].waiting;
        }
    }

    // Output
    cout << "\nPID\tArrival\tBurst\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i)
    {
        cout << p[i].pid << "\t" << p[i].arrival << "\t" << p[i].burst << "\t"
             << p[i].priority << "\t\t" << p[i].completion << "\t"
             << p[i].turnaround << "\t" << p[i].waiting << "\n";
    }

    cout << "\nAverage Turnaround Time: " << total_TAT/n<<'\n';
    cout << "Average Waiting Time: " << total_WT/n <<'\n';

    return 0;
}
//ok-Prority-N
