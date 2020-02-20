#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;

typedef pair<int, ll> pil;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;

typedef vector<vector<pil>> Edges;

struct greater_pil
{
    bool operator()(const pil& a, const pil& b) 
    {
        return a.second > b.second;
    }
};


void dijkstra(const Edges& edge, vl& dist, int n, int source) 
{
    priority_queue<pil, vector<pil>, greater_pil> pq;
    dist = vl(n);

    for (int i=0; i<n; i++)
    {
        if (i == source) dist[i] = 0;
        else dist[i] = 1e18;
    }

    pq.push({source, dist[source]});

    while (!pq.empty()) 
    {
        int u; 
        u = pq.top().first; pq.pop();
        for (pil p : edge[u]) 
        {
            int v = p.first;
            ll weight = p.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});

            }
        }


    }

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; 
    cin >> n >> m;

    vector<vector<pil>> edge(n);


    for (int T=0; T<m; T++)
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        --u, --v;

        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
        
    }

    vl dist1, dist2;
    dijkstra(edge, dist1, n, 0);
    dijkstra(edge, dist2, n, n-1);

    ll best_dist = 1e18;

    for (int i=0; i<n; i++) 
    {
        //cout << i << " " << dist1[i] << " " << dist2[i] << endl;
        ll x = abs(dist1[i] - dist2[i]);
        if (x < best_dist) 
        {
            best_dist = x;
        }
    }

    cout << best_dist << endl;


}
