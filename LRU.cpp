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
    list<int> lru;
    int pageFaults = 0;

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];

        // If not in memory
        if (s.find(page) == s.end())
        {
            if (s.size() == capacity)
            {
                int leastUsed = lru.back();
                lru.pop_back();
                s.erase(leastUsed);
            }
            s.insert(page);
            pageFaults++;
        }
        else
        {

            lru.remove(page);
        }

        lru.push_front(page);
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}
