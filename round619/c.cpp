#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T=0; T<t; T++)
    {
        ll n, m;
        cin >> n >> m;
        ll x = n*(n+1)/2;

        ll y = (n-m) / (m+1);
        ll r = (n-m) % (m+1);

        x -= r * (y+1)*(y+2)/2;
        x -= (m+1-r) * y * (y+1)/2;

        cout << x << "\n";


    }
}
