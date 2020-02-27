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

    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        int n; cin >> n;
        vi s(n), e(n), d(n);
        for (int i=0; i<n; i++)
        {
            cin >> s[i] >> e[i] >> d[i];
        }

        ll lo=0, hi=LLONG_MAX;
        while (hi - lo > 1) 
        {
            ll mid = lo + (hi-lo) / 2;
            ll x = 0;
            for (int i=0; i<n; i++) 
            {
                if (e[i] <= mid) 
                    x += (e[i] - s[i]) / d[i] + 1;
                else
                    x += (mid - s[i]) / d[i] + 1;
            }

            if (x % 2 == 0) 
                lo = mid;
            else
                hi = mid;

        }

        if (hi == LLONG_MAX) 
            cout << -1 << endl;
        else 
            cout << hi << endl;



    }
}
