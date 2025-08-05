#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; ++i)
    {
        p[i].pid = i + 1;
        cout << "Process " << p[i].pid << " Arrival Time: ";
        cin >> p[i].arrival;
        cout << "Process " << p[i].pid << " Burst Time: ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int complete = 0, current_time = 0;
    int prev = -1;
    float total_TAT = 0, total_WT = 0;

    while (complete < n)
    {
        int idx = -1;
        int min_remaining = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (p[i].arrival <= current_time && p[i].remaining > 0 && p[i].remaining < min_remaining)
            {
                min_remaining = p[i].remaining;
                idx = i;
            }
        }

        if (idx == -1)
        {
            current_time++;
            continue;
        }

        p[idx].remaining--;
        current_time++;

        if (p[idx].remaining == 0)
        {
            complete++;
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_TAT += p[idx].turnaround;
            total_WT += p[idx].waiting;
        }
    }

    // Output results
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


//ok