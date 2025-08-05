#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Free holes (sizes in MB)
    vector<int> holes = {15, 25, 10, 13, 17};
    // Processes (sizes in MB)
    vector<int> proc = {20, 12, 15, 10, 14};

    vector<int> result(proc.size(), -1); // which hole each Pi got (-1 = not allocated)

    cout << "First-Fit Allocation\n\n";
    for (int i = 0; i < (int)proc.size(); i++)
    {
        int need = proc[i];
        int chosen = -1;

        // pick the first hole that fits
        for (int h = 0; h < (int)holes.size(); h++)
        {
            if (holes[h] >= need)
            {
                chosen = h;
                break;
            }
        }

        if (chosen == -1)
        {
            cout << "P" << i + 1 << " (" << need << " MB) -> Not allocated\n";
        }
        else
        {
            cout << "P" << i + 1 << " (" << need << " MB) -> Hole "
                 << chosen + 1 << " (was " << holes[chosen] << " MB)"
                 << "  leftover = " << (holes[chosen] - need) << " MB\n";
            holes[chosen] -= need;
            result[i] = chosen;
        }
    }

    cout << "\nFinal hole sizes (after allocations):\n";
    for (int h = 0; h < (int)holes.size(); h++)
    {
        cout << "Hole " << h + 1 << ": " << holes[h] << " MB\n";
    }

    cout << "\nSummary\n";
    for (int i = 0; i < (int)proc.size(); i++)
    {
        if (result[i] == -1)
            cout << "P" << i + 1 << " not allocated\n";
        else
            cout << "P" << i + 1 << " -> Hole " << result[i] + 1 << "\n";
    }
}
