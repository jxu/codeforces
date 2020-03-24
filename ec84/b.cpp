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
        int n, k; cin >> n;
        vb p(n+1, 0), q(n+1, 0); // princess and prince

        for (int i = 1; i <= n; i++) 
        {
            cin >> k;
            
            for (int j = 1; j <= k; j++) 
            {
                int g; cin >> g;
                if (!q[g] && !p[i])
                {
                    q[g] = true; p[i] = true;
                }
            }
        }

        bool f = false;
        for (int i = 1; i <= n; i++)
        {
            if (!p[i])
            {
                int j = 1;
                while (q[j]) ++j; 
                cout << "IMPROVE\n" << i << " " << j << "\n";
                f = true;
                break;
            }
        }

        if (!f) cout << "OPTIMAL\n";
    }
}
