#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m, k;
    cin >> t;
    for (int T=0; T<t; T++)
    {
        cin >> n >> m >> k;
        vi a(n);

        for (int i=0; i<n; i++)
            cin >> a[i];

        int x = 0;

        if (m <= k) // we fix m-1 people, then our pick 
        {
            for (int i=0; i < m; i++) // i from front, ii from back
            {
                int ii = m-1-i;
                x = max(x, max(a[i], a[n-1-ii])); 
            }
        }
        else // we fix k people, nature fixes m-k-1, we pick last
        {
            for (int i=0; i <= k; i++)
            {
                int ii = k-i;
                int y = 1 << 30;

                for (int j=0; j<=m-k-1; j++)
                {
                    int jj = m-k-1-j;
                    int my = max(a[i+j], a[n-1-ii-jj]); // our pick
                    y = min(y, my); // nature minimizes
                }

                x = max(x, y); // we maximize
            }
        }
        cout << x << endl;
    }
}
