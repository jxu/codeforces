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


        if (m <= k) 
        {
            for (int i=0; i < m; i++)
            {
                int ii = m-1-i;
                x = max(x, max(a[i], a[n-1-ii])); 

            }
        }

        else
        {

            for (int i=0; i <= k; i++)
            {
                int ii = k-i;
                //cout << "my front/back " << i << " " << n-1 - ii << endl;
                int best_m = 1 << 30;

                for (int j=0; j<=m-k-1; j++)
                {
                    int jj = m-k-1-j;

                    //cout << "nature front/back " << i+j << " " << n-1-ii - jj << endl;
                    best_m = min(best_m, max(a[i+j], a[n-1-ii-jj]));


                }

                //cout << "best m " << best_m << endl;

                x = max(x, best_m);

            }
        }
        cout << x << endl;



    }

}
