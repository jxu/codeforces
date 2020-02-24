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
        vector<char> s(n);
        vi p(m+1);
        vi countp(n,0), countpp(n,0);
        vi letter(26, 0);

        for (int i=0; i<n; i++)
        {
            cin >> s[i];
        }
        for (int i=0; i<m; i++)
        {
            cin >> p[i];
            p[i]--;
            countp[p[i]]++;
        }
        p[m] = n-1;
        countp[n-1]++;
        //sort(p.begin(), p.end());
       
        //for (int x : countp) cout << x;
        //cout << endl;

        int r = 0;
        for (int i=n-1; i>=0; i--)
        {
            r += countp[i];
            countpp[i] = r;
            /*
            int lo = 0; int hi = m+1;
            while (hi - lo > 1) 
            {
                int mid = (lo + hi)/2;
                if (i < p[mid])
                    hi = mid;
                else
                    lo = mid;
            }

            cout << i << " " << lo << endl;
            */
        }

        //for (int x : countpp) cout << x;
        //cout << endl;

        //for (char c : s) cout << c;
        //cout << endl;

        for (int i=0; i<n; i++)
        {
            char c = s[i];
            letter[(int)(c - 'a')] += countpp[i];
        }

        for (int x : letter)
            cout << x << " ";
        cout << endl;
    }
}
