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
        ll n, k;
        cin >> n >> k;
        bool f = (n >= k*k && (n%2 == k%2));
        cout << (f ? "YES" : "NO") << "\n";

    }
}
