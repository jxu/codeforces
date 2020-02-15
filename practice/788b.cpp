#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

void dfs(const vvi& edge_list, vb& visited, int i, int& edges)
{
    visited[i] = true;
    for (int j : edge_list[i]) 
    {
        if (!visited[j]) 
            dfs(edge_list, visited, j, edges);

        if (j >= i) ++edges;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v;
    cin >> n >> m;
    vvi edge_list(n), edge_list_loops(n);
    vb visited(n, false);
    ll nonloops = 0, loops = 0;
    int start = 0;

    for (int i=0; i<m; i++)
    {
        cin >> u >> v;
        --u; --v;
        start = u;
        if (u != v)
        {
            edge_list[u].push_back(v);
            edge_list[v].push_back(u);
            edge_list_loops[u].push_back(v);
            edge_list_loops[v].push_back(u);
            ++nonloops;
        } else 
        {
            edge_list_loops[u].push_back(v);
            ++loops;
        }
    }

    int edges = 0;

    dfs(edge_list_loops, visited, start, edges);

    ll good_paths = 0;

    for (int i=0; i<n; i++)
    {
        ll deg = (ll)edge_list[i].size();
        if (deg >= 2) 
            good_paths += (deg)*(deg-1)/2;
    }

    good_paths += loops*nonloops + (loops)*(loops-1)/2;

    if (edges < m)
    {
        cout << "0\n";
        return 0;
    }

    cout << good_paths << "\n"; 
}
