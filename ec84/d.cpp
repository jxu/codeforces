// https://codeforces.com/blog/entry/75082#comment-592145
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

        vi p(n+1), c(n+1);
        vb seen(n+1, false);

        for (int i=1; i<=n; i++)
            cin >> p[i];

        for (int i=1; i<=n; i++)
            cin >> c[i];

        int best_k = n;

        for (int s=1; s<=n; s++)
        {
            if (seen[s]) continue;
            int y = s;
            vi cycle;
            
            do // build cycle 
            {
                seen[y] = true;
                cycle.push_back(c[y]); // cycle colors
                y = p[y];
            } while (y != s);

            int k, l = (int)cycle.size();

            for (k = 1; k <= l; k++)
            {
                if (l % k) continue;
                bool ok_k = false;

                // try to find seq with step k
                for (int i=0; i<k; i++)
                {
                    bool ok_seq = true;
                    for (int j=i; j < l; j+=k)
                    {
                        if (cycle[j] != cycle[i]) ok_seq = false;
                    }

                    if (ok_seq) ok_k = true;
                }
                
                if (ok_k) 
                    best_k = min(best_k, k);
            }
        }

        cout << best_k << endl;
    }
}
