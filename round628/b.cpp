#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

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

        set<int> s;

        for (int i=0; i<n; i++)
        {
            int ai;
            cin >> ai;
            s.insert(ai);

        }

            cout << s.size() << endl;

    }
}
