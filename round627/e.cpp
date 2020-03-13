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

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    
    vi a(n);
    for (int i=0; i<n; i++) 
        cin >> a[i];

    vvi dp(n+1, vi(h));

    for (int t=0; t<h; t++) 
        dp[0][t] = (t == 0) ? 0 : -10000;

    for (int d=1; d <= n; d++)
    {
        for (int t=0; t<h; t++)
        {
            int t0 = (t - a[d-1] + h) % h;
            int t1 = (t0 + 1) % h;

            dp[d][t] = max(dp[d-1][t0], dp[d-1][t1]);

            if (l <= t && t <= r) dp[d][t]++;

        }
    }
    
    int g = 0;
    for (int t=0; t<h; t++)
        g = max(g, dp[n][t]);

    cout << g << endl;
}
