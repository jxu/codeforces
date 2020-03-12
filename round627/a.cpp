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
        int n; cin >> n;
        vi a(n);
        for (int i=0;i<n;i++) 
        {
            cin >> a[i];
        }

        int p = a[0] % 2;

        bool ok = true;
        for (int i=0; i<n; i++) 
        {
            if (a[i] % 2 != p) ok = false;

        }

        cout << (ok ? "YES" : "NO") << endl;

    }
}
