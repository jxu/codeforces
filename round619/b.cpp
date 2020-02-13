#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    for (int T=0; T<t; T++)
    {
        cin >> n;
        vi a(n);
        int hin = 0, lon = 1000000000;
        bool any = false;

        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        for (int i=0; i<n; i++)
        {
            if (a[i] == -1)
            {
                if (i > 0 && a[i-1] != -1) 
                {
                    any = true;
                    hin = max(hin, a[i-1]);
                    lon = min(lon, a[i-1]);
                }
                if (i+1 < n && a[i+1] != -1) 
                {
                    any = true;
                    hin = max(hin, a[i+1]);
                    lon = min(lon, a[i+1]);

                }
            }
        }
        //cout << lon << " " << hin << endl;

        int k = (any) ? (lon + hin) / 2 : 42;
        int m = 0;

        for (int i=0; i<n; i++) 
        {
            if (a[i] == -1) a[i] = k;
            if (i > 0) m = max(m, abs(a[i] - a[i-1]));

        }

        cout << m << " " << k << endl;

    }

}
