#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int id_relation[150001];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    for (int i=1; i<=n; i++)
    {
        cin >> id_relation[i];
    }

    // log search, insertion, removal
    set<int> best;

    for (int i=0; i<q; i++)
    {
        int q, id;
        cin >> q >> id;
        int relation = id_relation[id];
        if (q == 1)
        {
            best.insert(relation);

            if ((int)best.size() > k) 
                best.erase(*best.begin()); // lowest relation
        } 
        else
        {
            if (best.find(relation) != best.end())
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
