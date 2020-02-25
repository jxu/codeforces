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
        int n, m;
        cin >> n >> m;
        vi a(n);
        vector<bool> s(n, false);
        
        for (int i=0; i<n; i++)
            cin >> a[i]; 
        
        for (int i=0; i<m; i++)
        {
            int pi; cin >> pi;
            s[pi-1] = true; 
        }

        vi as = a;
        sort(as.begin(), as.end());
       
        bool bad = false;
        for (int i=0; i<n; i++)
        {
            if (a[i] == as[i]) continue;
            if (a[i] > as[i]) 
            {
                for (int j = i+1; j<n; j++)
                {
                    if (!s[j-1]) bad = true;
                    if (a[i] == as[j]) break;
                }
            } 
            else
            {
                for (int j = i-1; j>=0; j--)
                {
                    if (!s[j]) bad = true;
                    if (a[i] == as[j]) break;
                }
            }
        }

        cout << ((bad) ? "NO" : "YES") << endl;
    }
}
