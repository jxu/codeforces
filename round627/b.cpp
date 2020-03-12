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
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        bool ok = false;
        for (int i=0; i<n; i++)
        {
            for (int j=i+2; j<n; j++) 
            {
                if (a[i] == a[j]) ok = true;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;

    }
}
