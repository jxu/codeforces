#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

typedef long long ll;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vvi adj(n+1);
    vpi edges(n-1);

    for (int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = pi(u, v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int v3 = 0;  // vertex with deg >= 3
    for (int i=1; i<=n; i++)
    {
        if (adj[i].size() >= 3) 
            v3 = i;
    }

    int l3 = 0, lo = 0;
    if (v3) lo = 3;

    for (pi e : edges)
    {
        // write 0, 1, 2 to edge adjacent to vertex v3
        if (l3 < 3 && (e.first == v3 || e.second == v3))
        {
            cout << l3 << endl;
            l3++;
        }
        else
        {
            cout << lo << endl;
            lo++;
        }
    }


}
