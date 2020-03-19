#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int powmod(ll base, ll exp, int mod)
{
    base %= mod;
    ll result = 1;
    while (exp) 
    {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll m; ll n;
    cin >> m >> n;
    int mod = 100003;
    
    ll result = (powmod(m, n, mod) - m * powmod(m-1, n-1, mod)) % mod;
    result = (result + mod) % mod;

    cout << result << endl;

}
