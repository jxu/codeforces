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
        string s; cin >> s;
        int n = (int)s.size();

        s.insert(0, "R");
        s.push_back('R');
        int d = 0, j = 0;
        for (int i = 0; i <= n+1; i++)
        {
            ++j;
            if (s[i] == 'R')
            {
                d = max(d, j);
                j = 0;
            }
        }

        cout << d << endl;
    }
}
