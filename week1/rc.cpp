#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m[1001][1001];

int main() 
{
    int n, k;
    cin >> n >> k;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin >> m[i][j];
            //cout << m[i][j] << ' ';
        }
        //cout << '\n';
    }

    for (int K=1; K<=k; K++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'A') 
        {
            cout << m[a][b] << '\n';
        }

        else if (c == 'R') 
        {
            for (int j=1; j<=n; j++)
            {
                swap(m[a][j], m[b][j]);

            }

        }

        else if (c == 'C')
        {
            for (int i=1; i<=n; i++)
            {
                swap(m[i][a], m[i][b]);

            }
        }

    }

}
