#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

bool f(string s, vi r, int n, int d) 
{
    bool visited = true ;
    while (visited) 
    {
        //for (int x : r) 
        //    cout << x;
        //cout << endl;

        visited = false;

        for (int i=0; i<n+1; i++) 
        {
            if (r[i] == 1) 
            {
                visited = true;
                r[i] = 2;

                if (i > 0 && s[i-1] == 'L') 
                {
                    for (int j=max(0,i-d); j <= i-1; j++)
                    {
                        if (r[j] == 0) {
                            r[j] = 1; 
                        }
                    }

                }
                else // i == 0 
                {
                    for (int j=i+1; j <= min(n+1, i+d); j++)
                    {
                        if (r[j] == 0) 
                        {
                            r[j] = 1;
                        }
                    }

                }

            }

        }

        if (r[n+1] >= 1) return true;

    }

    return false;


}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        string s;
        cin >> s;
        int n = (int)s.size();

        vi r(n+2, 0);
        r[0] = 1;
        
      
        int lo = 0, hi = n+1;

        while (hi - lo > 1) 
        {
            int mid = (lo + hi)/2;

            if (f(s, r, n, mid)) 
                hi = mid;
            else
                lo = mid;

        }
            cout << hi << endl;

        //break;
    }

}
