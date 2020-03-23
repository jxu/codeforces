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

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=0; i<k; i++)
    {
        int sx, xy; cin >> sx >> xy;

    }

    for (int i=0; i<k; i++)
    {
        int fx, fy; cin >> fx >> fy;
    }

    cout << n-1 + m-1 + n*m << endl;

    for (int i=0; i<n-1; i++) 
        cout << "U";
    
    for (int i=0; i<m-1; i++)
        cout << "L";

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m-1; j++)
        {
            cout << (i%2 ? "L" : "R");
        }
        cout << "D";

    }

    cout << endl;
}
