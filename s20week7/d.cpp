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

    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        ll n, r=0;
        cin >> n;
        for (int i=0; i<n; i++) 
        {
            double p; cin >> p;
            if (p != 0.5) ++r; 
        }

        ll s = (1ll << n) - (1ll << r);
        cout << s << endl;

    }
}
