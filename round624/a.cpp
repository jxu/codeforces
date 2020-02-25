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
        int a, b; 
        cin >> a >> b;

        if (a == b)
            cout << "0" << endl;
        else
            cout << 1 + ((a < b) != (abs(a - b) % 2)) << endl;  
    }
}
