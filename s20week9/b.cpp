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

// lazy method
int mul_inv(int n, int p)
{
    return powmod(n, p-2, p);

}

// todo: optimize
ll choose(int n, int k, int mod)
{
    if (k > n) return 0;
    if (k == n) return 1;

    ll result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % mod;
    
    for (int i = 1; i <= k; i++)
        result = (result * mul_inv(i, mod)) % mod;
    
    for (int i = 1; i <= n-k; i++)
        result = (result * mul_inv(i, mod)) % mod;

    return result;

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int mod = 1000000007;
    
    cout << choose(n+k-1, k-1, mod) << endl;

}
