#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int burst;
    int priority; // Lower number = higher priority
    int completion;
    int turnaround;
    int waiting;
};

// Sort by priority (lower = higher)
bool comparePriority(Process a, Process b)
{
    return a.priority < b.priority;
}

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    // Input burst and priority
    for (int i = 0; i < n; ++i)
    {
        p[i].pid = i + 1;
        cout << "Process " << p[i].pid << " Burst Time: ";
        cin >> p[i].burst;
        cout << "Process " << p[i].pid << " Priority (lower = higher): ";
        cin >> p[i].priority;
    }

    // Sort by priority
    sort(p.begin(), p.end(), comparePriority);

    int current_time = 0;
    float total_TAT = 0, total_WT = 0;

    for (int i = 0; i < n; ++i)
    {
        p[i].waiting = current_time;
        p[i].completion = current_time + p[i].burst;
        p[i].turnaround = p[i].completion;
        current_time = p[i].completion;

        total_TAT += p[i].turnaround;
        total_WT += p[i].waiting;
    }

    // Output
    cout << "\nPID\tBurst\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i)
    {
        cout << p[i].pid << "\t" << p[i].burst << "\t" << p[i].priority << "\t\t"
             << p[i].completion << "\t" << p[i].turnaround << "\t" << p[i].waiting << "\n";
    }

    cout << "\nAverage Turnaround Time: " << total_TAT / n;
    cout << "Average Waiting Time: " << total_WT / n << endl;

    return 0;
}
