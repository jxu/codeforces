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
        int a, b; cin >> a >> b;

        if (a == b)
        {
            cout << "0\n";
            continue;
        }

        if (a < b) 
        {
            cout << (((b - a) % 2) ? 1 : 2) << endl;
            

        } 
        else
        {
            cout << (((a - b) % 2) ? 2 : 1) << endl;
        }

    }
}
