#include <bits/stdc++.h>
using namespace std;

int main()
{
    int process, instance;
    cout << "Enter Number of Process\n";
    cin >> process;

    cout << "Enter number of Instances\n";
    cin >> instance;

    int allocation[process][instance];
    cout << "Enter allocations:\n";
    for (int i = 0; i < process; i++)
        for (int j = 0; j < instance; j++)
            cin >> allocation[i][j];

    int maxNeed[process][instance];
    cout << "Enter Maximum Need:\n";
    for (int i = 0; i < process; i++)
        for (int j = 0; j < instance; j++)
            cin >> maxNeed[i][j];

    int available[instance];
    cout << "Enter Available Resources:\n";
    for (int i = 0; i < instance; i++)
        cin >> available[i];

    int need[process][instance];
    for (int i = 0; i < process; i++)
        for (int j = 0; j < instance; j++)
            need[i][j] = maxNeed[i][j] - allocation[i][j];

    int finish[process] = {0}, safeSeq[process], ind = 0;

    for (int count = 0; count < process; count++)
    {

        for (int p = 0; p < process; p++)
        {
            if (!finish[p])
            {
                bool possible = true;
                for (int j = 0; j < instance; j++)
                {
                    if (need[p][j] > available[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    for (int j = 0; j < instance; j++)
                        available[j] += allocation[p][j];

                    safeSeq[ind++] = p;
                    finish[p] = 1;
                }
            }
        }
    }

    for (int i = 0; i < process; i++)
    {
        cout << "P" << safeSeq[i];
        if (i != process - 1)
            cout << " --> ";
    }
    cout << "\n";
}


//OK