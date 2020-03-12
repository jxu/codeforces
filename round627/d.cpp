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
    vi a(n), b(n);
    vi ab(n), ba(n);

    for (int i=0; i<n; i++)
    {
        cin >> a[i];

    }

    for (int i=0; i<n; i++)
    {
        cin >> b[i];
    }

    for (int i=0; i<n; i++)
    {
        ab[i] = a[i] - b[i];
        ba[i] = b[i] - a[i];
    }

    sort(ba.begin(), ba.end());
    ba.push_back(INT_MAX);
    ll s = 0;

    for (int i=0; i<n; i++)
    {
        int lo = -1, hi = n+1;
        
        while (hi - lo > 1) 
        {
            int mid = (lo + hi)/2;

            if (ba[mid] >= ab[i])
                hi = mid;
            else
                lo = mid;

        }

        //cout << ab[i] << " " << lo << endl;
        s += lo;
        if (ab[i] <= 0) s++;

    }

    cout << s/2 << endl;


}
