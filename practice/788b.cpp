#include <iostream>
#include <vector>
#include <stack>
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

    int n, m, u, v;
    cin >> n >> m;
    
    vi deg_noloop(n, 0); 
    vvi edge_list(n);
    vb visited(n, false);
    ll nonloops = 0, loops = 0, good_paths = 0;
    int start = 0, edges = 0;

    for (int i=0; i<m; i++)
    {
        cin >> u >> v;
        --u; --v;
        start = u;
        if (u != v)
        {
            edge_list[u].push_back(v);
            edge_list[v].push_back(u);
            ++deg_noloop[u];
            ++deg_noloop[v];
            ++nonloops;
        } else 
        {
            edge_list[u].push_back(v);
            ++loops;
        }
    }

    // dfs
    stack<int> S; S.push(start);

    while (!S.empty()) 
    {
        int i = S.top(); S.pop();
        if (visited[i]) continue; 
        visited[i] = true;
        for (int j : edge_list[i]) 
        {
            if (!visited[j])
                S.push(j); // may have multiple copies of neighbor

            if (j >= i) ++edges;
        }
    }


    for (int i=0; i<n; i++)
    {
        ll deg = deg_noloop[i];
        if (deg >= 2) 
            good_paths += (deg)*(deg-1)/2;
    }

    good_paths += loops*nonloops + (loops)*(loops-1)/2;

    if (edges < m) good_paths = 0;
    
    cout << good_paths << "\n"; 
}
