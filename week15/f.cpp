#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


#define MOD 1000000007

vi sieve(int n) 
{
    vb nums(n, false);
    for (int i=2; i*i < n; i++) 
    {
        if (!nums[i]) 
        {
            for (int j=i*i; j < n; j += i) 
                nums[j] = true;
        }
    }

    vi primes;
    for (int i = 2; i < n; i++) 
    {
        if (!nums[i]) 
            primes.push_back(i);
    }

    return primes;
}


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


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    //vi n_primes = sieve(n+1);
    vi m_primes = sieve(m+1);

    ll res = 1;

    for (int i = 1; i <= n; i++) 
    {
        res = (res * i) % MOD;

    }

    for (int p : m_primes) 
    {
        res = (res * (p-1)) % MOD;
        res = (res * mul_inv(p, MOD)) % MOD;
    }

    cout << res << endl;

}
