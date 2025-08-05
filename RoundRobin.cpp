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
    bool inQueue = false;
};

int main()
{
    int n, quantum;
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

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    int current_time = 0, completed = 0;
    queue<int> q;
    float total_TAT = 0, total_WT = 0;

    // Sort by arrival time initially
    sort(p.begin(), p.end(), [](Process a, Process b)
         { return a.arrival < b.arrival; });

    q.push(0);
    p[0].inQueue = true;

    while (completed < n)
    {
        if (q.empty())
        {
            for (int i = 0; i < n; ++i)
            {
                if (!p[i].inQueue && p[i].remaining > 0 && p[i].arrival <= current_time)
                {
                    q.push(i);
                    p[i].inQueue = true;
                    break;
                }
            }
            if (q.empty())
            {
                current_time++;
                continue;
            }
        }

        int idx = q.front();
        q.pop();

        int time_slice = min(quantum, p[idx].remaining);
        current_time = max(current_time, p[idx].arrival) + time_slice;
        p[idx].remaining -= time_slice;

        // Enqueue any new arrivals during the time slice
        for (int i = 0; i < n; ++i)
        {
            if (!p[i].inQueue && p[i].remaining > 0 && p[i].arrival <= current_time)
            {
                q.push(i);
                p[i].inQueue = true;
            }
        }

        if (p[idx].remaining == 0)
        {
            completed++;
            p[idx].completion = current_time;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            total_TAT += p[idx].turnaround;
            total_WT += p[idx].waiting;
        }
        else
        {
            q.push(idx); // Put back for next round
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
    cout << "Average Waiting Time: " << total_WT / n << endl;

    return 0;
}


//ok - RoundRobin With arrival Time