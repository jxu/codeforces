// 2 pointers linear time algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n, L;
    long long B;
    vector<int> a, d;

    cin >> n >> L >> B;
    for (int i=0; i<n; i++)
    {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }

    sort(a.begin(), a.end());

    int lo = 0, m = 0, hi = 0;
    int best_s = 1;
    long long cost = 0;

    while (hi+1 < n)
    {
        // march m if subset size changes even -> odd
        if ((hi - lo + 1) % 2 == 0)
            ++m;
        
        if (cost + (a[hi+1] - a[m]) <= B)
        {
            cost += a[hi+1] - a[m];
            ++hi;
        }
        else
        {
            cost -= a[m] - a[lo];
            ++lo;
            // may have case lo == hi+1 ("subset size 0")
        }

        /*
        for (int i=lo; i<=hi; i++)
        {
            cout << a[i];
            if (i == m) cout << '*';
            cout << ' ';
        }
        cout << "cost " << cost << endl;
        */

        best_s = max(best_s, (hi - lo + 1));
    }

    cout << best_s << endl;

    return 0;
}
