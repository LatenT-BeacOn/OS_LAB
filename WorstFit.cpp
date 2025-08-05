#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Free holes (MB)
    vector<int> holes = {15, 25, 10, 13, 17};
    // Processes (MB)
    vector<int> proc = {20, 12, 15, 10, 14};

    vector<int> result(proc.size(), -1); // which hole each Pi got (-1 = not allocated)

    cout << "\n Worst-Fit Allocation \n\n";
    for (int i = 0; i < (int)proc.size(); i++)
    {
        int need = proc[i];
        int worst = -1;
        int worstSize = -1;

        for (int h = 0; h < (int)holes.size(); h++)
        {
            if (holes[h] >= need && holes[h] > worstSize)
            {
                worstSize = holes[h];
                worst = h;
            }
        }

        if (worst == -1)
        {
            cout << "P" << i + 1 << " (" << need << " MB) -> Not allocated\n";
        }
        else
        {
            cout << "P" << i + 1 << " (" << need << " MB) -> Hole "
                 << worst + 1 << " (was " << holes[worst] << " MB)"
                 << "  leftover = " << (holes[worst] - need) << " MB\n";
            holes[worst] -= need;
            result[i] = worst;
        }
    }

    cout << "\nFinal hole sizes after allocations:\n";
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
