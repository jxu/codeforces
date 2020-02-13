#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string a, b, c;

    cin >> t;
    for (int T=0; T<t; T++) 
    {
        cin >> a >> b >> c;
        bool f = true;
        for (int i=0; i<a.size(); i++)
        {
            if (!(a[i] == c[i] || b[i]==c[i])) 
                f = false;

        }

        if (f) cout << "YES\n";
        else cout << "NO\n";

    }

}
