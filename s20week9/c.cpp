#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; char c;
    cin >> n;

    ll res = n * (n-1) * (n-2) / 6;

    for (int i=0; i<n; i++)
    {
        int outdeg = 0;
        for (int j=0; j<n; j++)
        {
            cin >> c;
            if (c == 'Y') ++outdeg;
        }
        res -= outdeg * (outdeg-1) / 2;
    }
    cout << res << endl;
}
