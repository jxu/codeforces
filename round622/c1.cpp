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
    vi m(n);
    for (int i=0; i<n; i++)
    {
        cin >> m[i];
    }

    ll best = 0;
    vi best_m;
    for (int p=0; p<n; p++)
    {
        vi mm = m;
        
        if (p > 0 )
        {
            for (int i=p-1; i >= 0; i--) 
            {
                mm[i] = min(mm[i+1], mm[i]);  

            }

        }

        if (p-1 < n)
        {
            for (int i=p+1; i < n; i++)
            {
                mm[i] = min(mm[i], mm[i-1]);
            }
        }

        ll s = 0;
        for (int x : mm)
        {
            s += x;
        }

        if (s > best) 
        {
            best = s;
            best_m = mm;
        }
    }

    for (int x : best_m)
    {
        cout << x << " ";
    }
    cout << endl;
}
