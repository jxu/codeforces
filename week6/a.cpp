#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

typedef struct { int vertex; ll weight; } vw;
typedef vector<vector<vw>> Adj;

// Dijkstra specific 
typedef struct { ll element; ll priority; } ep;
struct greater_ep { bool operator()(const ep& a, const ep& b) { 
        return a.priority > b.priority; } };


// assume graphs have integer vertices [1,n]
void dijkstra(int n, const Adj& adj, vll& dist, int source) 
{
    // min priority queue
    priority_queue<ep, vector<ep>, greater_ep> pq;
    dist = vll(n+1);

    for (int i=1; i<=n; i++)
        dist[i] = (i == source) ? 0 : LLONG_MAX;

    pq.push({source, dist[source]});

    while (!pq.empty()) 
    {
        ep x = pq.top(); pq.pop();
        int u = (int)x.element;
        if (dist[u] < x.priority) continue;

        for (vw vwp : adj[u]) 
        {
            int v = vwp.vertex;
            ll weight = vwp.weight;
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

    Adj adj(n+1);

    for (int M=0; M<m; M++)
    {
        int u, v; ll w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vll dist1, dist2;
    dijkstra(n, adj, dist1, 1);
    dijkstra(n, adj, dist2, n);

    ll best_dist = LLONG_MAX;

    for (int i=1; i<=n; i++) 
    {
        best_dist = min(best_dist, abs(dist1[i] - dist2[i]));
    }

    cout << best_dist << endl;
}
