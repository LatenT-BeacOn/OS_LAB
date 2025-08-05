#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    int capacity = 3;

    unordered_set<int> str;
    int pageFaults = 0;

    for (int i = 0; i < n; i++)
    {
        // If page is not in memory
        if (str.find(pages[i]) == str.end())
        {
            // If memory is full
            if (str.size() == capacity)
            {
                int farthest = i + 1, indexToRemove = -1;
                int maxIndex = -1;
                for (int f : str)
                {
                    int j;
                    for (j = i + 1; j < n; j++)
                    {
                        if (pages[j] == f)
                            break;
                    }
                    if (j > maxIndex)
                    {
                        maxIndex = j;
                        indexToRemove = f;
                    }
                }
                str.erase(indexToRemove);
            }
            // Insert new page
            str.insert(pages[i]);
            pageFaults++;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}
