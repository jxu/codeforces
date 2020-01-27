#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

// inclusive bounds [lb, hb]
ll compute_seg_sum(const vector<ll>& prefix_sum, int lb, int ub)
{
    return prefix_sum[ub] - ((lb > 0) ? prefix_sum[lb-1] : 0); 
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n), destroyed(n, false);
    vector<ll> prefix_sum(n);
    
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
        prefix_sum[i] = v[i] + ((i == 0) ? 0 : prefix_sum[i-1]);
    }

    map<int, ll> seg_sum;
    multiset<ll> sums; // allow multiple equal seg sums
    seg_sum[n] = prefix_sum[n-1];
    sums.insert(prefix_sum[n-1]);

    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        --x;

        destroyed[x] = true;
        int seg_in = (*(seg_sum.upper_bound(x))).first;
       
        seg_sum[x] = seg_sum[seg_in] - 
            compute_seg_sum(prefix_sum, x+1, seg_in-1) - v[x]; 

        // erase once 
        sums.erase(sums.lower_bound(seg_sum[seg_in]));

        seg_sum[seg_in] -= seg_sum[x] + v[x];
        sums.insert(seg_sum[x]);
        sums.insert(seg_sum[seg_in]);
   
        #ifdef DEBUG
        cout << endl;

        for (int j=0; j<n; j++)
        {
            if (destroyed[j]) cout << "* ";
            else cout << v[j] << " ";
        }
        cout << endl;

        cout << "x:" << x << " seg in:" << seg_in << endl;

        for (auto p : seg_sum)
            cout << p.first << ":" << p.second << " ";
        cout << endl << "sums ";

        for (int s : sums)
            cout << s << " ";
        cout << endl;
        #endif 

        cout << *(sums.rbegin()) << "\n";
    }
}
