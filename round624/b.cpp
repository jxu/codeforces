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
        int n, m;
        cin >> n >> m;
        vi a(n), s(n, 0);
        for (int i=0; i<n; i++)
        {
            cin >> a[i]; 
        }

        for (int i=0; i<m; i++)
        {
            int pi;
            cin >> pi;
            s[pi-1] = 1; 
        }

        vi as = a;
        sort(as.begin(), as.end());

       
        bool bad = false;
        for (int i=0; i<n; i++)
        {
            int j=i;
            if (a[i] >= as[i]) 
            {
                for (; j<n; j++)
                {
                    if (j > i && !s[j-1]) bad = true;
                    if (a[i] == as[j]) break;
                }
            } 
            else
            {
                for (; j >= 0; j--)
                {
                    if (j < i && !s[j]) bad = true;
                    if (a[i] == as[j]) break;
                }
            }

            //cout << "i j " << i << j << endl;


        }

        cout << ((bad) ? "NO" : "YES") << endl;

    }
}
