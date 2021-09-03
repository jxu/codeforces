#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<ll> prefix_sum(n);
    
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
        prefix_sum[i] = v[i];
        if (i > 0) prefix_sum[i] += prefix_sum[i-1];
    }

    map<int, ll> segmap;
    multiset<ll> segsum; // allow multiple equal seg sums
    segmap[n] = prefix_sum[n-1];
    segsum.insert(prefix_sum[n-1]);

    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x; --x;

        int seg_in = (*(segmap.upper_bound(x))).first;

        // erase once
        segsum.erase(segsum.lower_bound(segmap[seg_in]));
        
        ll hi_segsum = prefix_sum[seg_in-1];
        if (x > 0) hi_segsum -= prefix_sum[x-1];

        segmap[x] = segmap[seg_in] - hi_segsum; 
        segmap[seg_in] -= segmap[x] + v[x];
        
        segsum.insert(segmap[x]);
        segsum.insert(segmap[seg_in]);
   
        #ifdef DEBUG
        cout << endl;

        for (int j=0; j<n; j++)
        {
            if (segmap.count(j)) cout << "* ";
            else cout << v[j] << " ";
        }
        cout << endl;

        cout << "x:" << x << " seg in:" << seg_in << endl;

        for (auto p : segmap)
            cout << p.first << ":" << p.second << " ";
        cout << endl << "segsum ";

        for (ll s : segsum)
            cout << s << " ";
        cout << endl;
        #endif 

        cout << *(segsum.rbegin()) << "\n";
    }
}
