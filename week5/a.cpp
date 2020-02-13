#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi& a, vvi& visit, int i, int j, int& k)
{
    //cout << "dfs " << i << j << endl;
    int n = (int)(a.size());
    int m = (int)(a[0].size());
    
    visit[i][j] = 1;
    bool any_nb = false;

    // recurse on neighbors
    for (int di : {-1, 0, 1}) // fancy loop 
    {
        int ni = i + di;
        for (int dj : {-1, 0, 1})
        {
            int nj = j + dj;
            if ((di == 0) + (dj == 0) != 1) // only grid neighbors
                continue;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) 
                continue;

            if (a[ni][nj] == 0 && visit[ni][nj] == 0)
            {
                dfs(a, visit, ni, nj, k);
                if (a[ni][nj] == 0) any_nb = true; // check if leaf pruned
            }
        }
    }
    if (!any_nb && k > 0)
    {
        //cout << "kill " << i << j << endl;
        --k;
        a[i][j] = 2; // set cell to pruned
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    int start_i=0, start_j=0;
    cin >> n >> m >> k;

    vvi a(n, vi(m, 0));
    vvi visit(n, vi(m, 0));

    char c;
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<m; j++) 
        {
            cin >> c;
            if (c == '#') 
                a[i][j] = 1;
            else
            {
                start_i = i;
                start_j = j;
            }
        }
    }

    dfs(a, visit, start_i, start_j, k);
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (a[i][j] == 1) cout << "#";
            else if (a[i][j] == 2) cout << "X";
            else cout << ".";
        }
        cout << "\n";
    }
}
