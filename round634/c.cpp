#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<bool> vb;
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
        vi c(n+1);
        for (int i=0; i<n; i++)
        {
            int ai; cin >> ai;
             c[ai]++;
        }

        int s = 0, d = 0;
        for (int i=1; i<=n; i++)
        {
            if (c[i]) d++;

        }
        int x = 0;

        for (int i=1;i<=n; i++)
        {
            int x0 = min(d, c[i]-1);
            int x1 = min(d-1, c[i]);

            x = max(x, max(x0, x1));

        }

        cout << x << endl;
    }
    



}
