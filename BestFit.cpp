#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Free holes (sizes in MB) as in the diagram's right-side numbers: 15,25,10,13,17
    vector<int> holes = {15, 25, 10, 13, 17};
    // Processes: P1=20, P2=12, P3=15, P4=10, P5=14  (taken from the left list)
    vector<int> proc = {20, 12, 15, 10, 14};

    // Keep original hole sizes for printing
    vector<int> original_holes = holes;

    // result[i] = hole index (0-based) where Pi was placed, or -1 if not allocated
    vector<int> result(proc.size(), -1);

    cout << "=== Best-Fit Allocation ===\n\n";
    for (int i = 0; i < (int)proc.size(); ++i)
    {
        int need = proc[i];
        int best = -1;
        int bestSize = INT_MAX;

        for (int h = 0; h < holes.size(); ++h)
        {
            if (holes[h] >= need && holes[h] < bestSize)
            {
                bestSize = holes[h];
                best = h;
            }
        }

        if (best == -1)
        {
            cout << "P" << i + 1 << " (" << need << " MB) -> **Not allocated**\n";
        }
        else
        {
            cout << "P" << i + 1 << " (" << need << " MB) -> Hole "
                 << best + 1 << " (was " << holes[best] << " MB)"
                 << "  leftover = " << (holes[best] - need) << " MB\n";
            holes[best] -= need;
            result[i] = best;
        }
    }

    cout << "\nFinal hole sizes (after allocations):\n";
    for (int h = 0; h < (int)holes.size(); ++h)
    {
        cout << "Hole " << h + 1 << ": " << holes[h] << " MB\n";
    }

    cout << "\nSummary mapping (Pi -> Holej):\n";
    for (int i = 0; i < (int)proc.size(); ++i)
    {
        if (result[i] == -1)
            cout << "P" << i + 1 << " not allocated\n";
        else
            cout << "P" << i + 1 << " -> Hole " << result[i] + 1 << "\n";
    }
}
