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
    int t;
    cin >> t;
    for (int k=0; k<t; k++)
    {
        int n;
        cin >> n;
        vi a(n);
        vector<bool> lofit(n);
        vector<bool> hifit(n);

        vi lofitsum(n);
        vi hifitsum(n);

        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            lofit[i] = a[i] >= i;
            hifit[i] = a[i] >= n-1-i;

            lofitsum[i] = lofit[i];
            if (i > 0) lofitsum[i] += lofitsum[i-1];

        }

        for (int i=n-1; i>=0; i--)
        {
            hifitsum[i] = hifit[i];
            if (i < n-1) hifitsum[i] += hifitsum[i+1];

        }

        /*
        for (int i=0; i<n; i++)
        {
            cout << lofitsum[i] << " ";

        }

        cout << endl;

        for (int i=0; i<n; i++)
        {
            cout << hifitsum[i] << " ";
        }

        cout << endl;
        */

        bool success = false;
        for (int i=0; i<n; i++)
        {
            if (lofitsum[i] >= i+1  && hifitsum[i] >= n-i) 
            {
                success = true;
                break;
            }
        }

        if (success) 
            cout << "Yes\n";
        else 
            cout << "No\n";

    }

}
