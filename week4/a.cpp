#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vvll h(2, vll(n));
    vvll b(2, vll(n));

    for (int j=0; j<2; j++)
    {    
        for (int i=0; i<n; i++)
        {
            cin >> h[j][i];
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<2; j++)
        {
            b[j][i] = h[j][i];
            if (i == 1) b[j][i] += b[1-j][i-1];
            else if (i >= 2)
            {
                b[j][i] += max(b[1-j][i-1], b[1-j][i-2]);
            }

            //cout << j << i << " " << b[j][i] << endl;

        }

    }

    cout << max(b[0][n-1], b[1][n-1]) << endl;

}
