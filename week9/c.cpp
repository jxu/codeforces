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

    ll n; char c;
    cin >> n;

    vvi adj(n, vi(n, 0));

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> c;
            if (c == 'Y') adj[i][j] = 1;
            //cout << adj[i][j];
        }
        //cout << endl;

    }

    vi indeg(n, 0);

    ll res = n * (n-1) * (n-2) / 6;

    for (int j=0; j<n; j++)
    {
        for (int i=0; i<n; i++)
            if (adj[i][j]) ++indeg[j];

        //cout << indeg[j] << endl;
        
        res -= indeg[j] * (indeg[j]-1) / 2;
    }


    cout << res << endl;


}
