// alternate version not using map seg bound -> seg sum
// but recalculate seg sum using seg bounds every time 

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

// inclusive bounds [lb, ub]
ll calc_segsum(const vector<ll>& prefix_sum, int lb, int ub)
{
   #ifdef DEBUG
    cout << "css " << lb << " " << ub << endl;
    #endif
    
    int n = (int)prefix_sum.size();
    if (ub < 0 || lb > n-1) return 0; // sloppy input bounds
    
    return prefix_sum[ub] - ((lb > 0) ? prefix_sum[lb-1] : 0); 
}

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
        prefix_sum[i] = v[i] + ((i == 0) ? 0 : prefix_sum[i-1]);
    }
    
    set<int> destroyed;
    multiset<ll> segsums; // allow multiple equal seg sums
    destroyed.insert(n); // initial upper bound
    destroyed.insert(-1); // initial lower bound 
    segsums.insert(prefix_sum[n-1]);

    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        --x;

        // inclusive
        int ub = *(destroyed.upper_bound(x)) - 1;
        int lb = *prev(destroyed.upper_bound(x)) + 1;

        ll old_segsum = calc_segsum(prefix_sum, lb, ub); 
        ll new_segsum_lo = calc_segsum(prefix_sum, lb, x-1);
        ll new_segsum_hi = calc_segsum(prefix_sum, x+1, ub);


        // erase once 
        segsums.erase(segsums.lower_bound(old_segsum));
        segsums.insert(new_segsum_lo);
        segsums.insert(new_segsum_hi);
        destroyed.insert(x);

        #ifdef DEBUG
        cout << endl;

        for (int j=0; j<n; j++)
        {
            if (destroyed.count(j)) cout << "* ";
            else cout << v[j] << " ";
        }
        cout << endl;

        cout << "x:" << x;
        cout << " [" << lb << "," << ub << "]" << endl;
        cout << old_segsum << " " << new_segsum_lo << " " <<
            new_segsum_hi << endl;
        for (ll s : segsums)
            cout << s << " ";
        cout << endl;
        #endif 

        cout << *(segsums.rbegin()) << "\n";
    }
}
