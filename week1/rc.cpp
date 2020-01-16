#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m[1001][1001];
int row_map[1001], col_map[1001];

int main() 
{
    int n, k;
    cin >> n >> k;

    for (int i=1; i<=n; i++)
    {
        row_map[i] = i;
        for (int j=1; j<=n; j++)
        {
            col_map[j] = j;
            cin >> m[i][j];
        }
    }

    for (int K=1; K<=k; K++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'A') 
        {
            cout << m[row_map[a]][col_map[b]] << '\n';
        }

        else if (c == 'R') 
        {
            swap(row_map[a], row_map[b]);
        }

        else if (c == 'C')
        {
            swap(col_map[a], col_map[b]);
        }
    }
}
