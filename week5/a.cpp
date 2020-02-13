#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(int n, int m, vvi& a, vvi& visited, int i, int j,
         int& t, int si, int sj)
{

    //cout << "dfs " << i << j << endl;

    visited[i][j] = 1;
    int nb = 0;

    if (i-1 >= 0 && a[i-1][j] == 0 && visited[i-1][j] == 0)
    {
        dfs(n, m, a, visited, i-1, j, t, si, sj);
        if (a[i-1][j] == 0) nb++;
    }
    if (i+1 < n && a[i+1][j] == 0 && visited[i+1][j] == 0) 
    {
        dfs(n, m, a, visited, i+1, j, t, si, sj);
        if (a[i+1][j] == 0) nb++;
    }
    if (j-1 >= 0 && a[i][j-1] == 0 && visited[i][j-1] == 0)
    {
        dfs(n, m, a, visited, i, j-1, t, si, sj );
        if (a[i][j-1] == 0) nb++;
    }
    if (j+1 < m && a[i][j+1] == 0 && visited[i][j+1] == 0) 
    {
        dfs(n, m, a, visited, i, j+1,t, si, sj);
        if (a[i][j+1] == 0) nb++;
    }

    // count nb
    // 
    /*
    if (i-1 >= 0 && a[i-1][j] == 0)
    {
        ++nb;
    }
    if (i+1 < n && a[i+1][j] == 0) 
    {
        ++nb;
    }
    if (j-1 >= 0 && a[i][j-1] == 0)
    {
        ++nb;
    }
    if (j+1 < m && a[i][j+1] == 0) 
    {
        ++nb;
    }

    */

    if (nb == 0)
    {
        visited[i][j] = 2;
        //cout << "leaf " << i << j << endl;

        if (t > 0 && !(i == si && j == sj))
        {
            //cout << "kill " << i << j << endl;
            --t;
            a[i][j] = 2;

        }
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
    vvi visited(n, vi(m, 0));

    char c;
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<m; j++) 
        {
            cin >> c;
            if (c == '#') 
            {
                a[i][j] = 1;
            } else
            {
                start_i = i;
                start_j = j;
            }

            //cout << a[i][j];

        }
        //cout << endl;
    }

    while (k) 
    {
        //cout << "k " << k << endl;

        dfs(n, m, a, visited, start_i, start_j, k, start_i, start_j);
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                visited[i][j] = 0;
            }
        }
        break;
    }

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
