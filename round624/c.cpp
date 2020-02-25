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
        vi endc(n,0), countc(n,0);
        vi letter(26, 0);

        for (int i=0; i<n; i++)
            cin >> s[i];
        
        for (int i=0; i<m; i++)
        {
            int pi;
            cin >> pi;
            endc[pi-1]++;
        }
        endc[n-1]++; // full combo!

        int r = 0;
        for (int i=n-1; i>=0; i--)
        {
            r += endc[i];
            countc[i] = r;
        }

        for (int i=0; i<n; i++)
        {
            letter[s[i] - 'a'] += countc[i];
        }

        for (int x : letter)
            cout << x << " ";
        cout << endl;
    }
}
