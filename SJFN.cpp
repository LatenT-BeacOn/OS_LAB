#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
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
    }

    int current_time = 0, completed = 0;
    float total_TAT = 0, total_WT = 0;

    while (completed < n)
    {
        int idx = -1;
        int min_burst = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (!p[i].done && p[i].arrival <= current_time && p[i].burst < min_burst)
            {
                min_burst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1)
        {
            current_time++; // If no process has arrived yet
        }
        else
        {
            p[idx].completion = current_time + p[idx].burst;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].done = true;

            total_TAT += p[idx].turnaround;
            total_WT += p[idx].waiting;
            current_time = p[idx].completion;
            completed++;
        }
    }

    // Output
    cout << "\nPID\tArrival\tBurst\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; ++i)
    {
        cout << p[i].pid << "\t" << p[i].arrival << "\t" << p[i].burst << "\t"
             << p[i].completion << "\t" << p[i].turnaround << "\t" << p[i].waiting << "\n";
    }

    cout << "\nAverage Turnaround Time: " << total_TAT / n;
    cout << "\nAverage Waiting Time: " << total_WT / n << endl;

    return 0;
}


// OK
