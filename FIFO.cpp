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

    unordered_set<int> s;
    queue<int> q;
    int pageFaults = 0;

    for (int i = 0; i < n; i++)
    {
        // If page is not present in the current set
        if (s.find(pages[i]) == s.end())
        {
            // If memory is full
            if (s.size() == capacity)
            {
                int oldest = q.front();
                q.pop();

                s.erase(oldest);
            }
            // Add new page
            s.insert(pages[i]);
            q.push(pages[i]);
            pageFaults++;
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}
