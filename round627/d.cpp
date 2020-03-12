#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vi a(n), b(n), ba(n);

    for (int i=0; i<n; i++)
        cin >> a[i];

    for (int i=0; i<n; i++)
    {
        cin >> b[i];
        ba[i] = b[i] - a[i];
    }

    sort(ba.begin(), ba.end());
    ll s = 0;

    for (int i=0; i<n; i++)
    {
        int lo = -1, hi = n;
        
        while (hi - lo > 1) 
        {
            int mid = (lo + hi)/2;

            if (ba[mid] >= -ba[i])
                hi = mid;
            else
                lo = mid;
        }

        //cout << -ba[i] << " " << hi << endl;
        s += hi;
        if (-ba[i] > 0) s--;
    }

    cout << s/2 << endl;
}
