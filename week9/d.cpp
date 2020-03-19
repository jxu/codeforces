#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vi mi(10007);

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
ll _choose(int n, int k, int mod)
{
    if (n < 0 || k < 0) return 0;
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    if (n-k < k) k = n-k;

    ll result = 1;
    for (int i = n-k+1; i <= n; i++)
        result = (result * i) % mod;
    
    for (int i = 1; i <= k; i++)
        result = (result * mi[i%mod]) % mod;
    
    return result;
}

// Lucas???
ll choose(int m, int n, int p)
{
    ll result = 1;
    while (m || n)
    {
        result = (result * _choose(m % p, n % p, p)) % p;
        m /= p;
        n /= p;
    }
    return result; 
}


int f(const vi& a, int i, int n, int new_m, int mod, int sign)
{

    if (i == a.size()) return 0;
    if (new_m - a[i] < 0) return 0;

    cout << "newm " << sign << " " << new_m - a[i]  << endl;


    int result = ((sign)*choose(new_m - a[i] -1, n-1,mod) + mod) % mod;


    result = (result + f(a, i+1, n, new_m, mod, sign) + mod) % mod;

    result = (result + f(a, i+1, n, new_m - a[i], mod, sign * -1) + mod) % mod;


    return result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    const int mod = 10007;

    mi[1] = 1;
    for (int i=2; i<mod; i++)
        mi[i] = (mod - (mod/i) * mi[mod%i] % mod) % mod;

    
    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        int n, p, q, m;
        cin >> n >> p >> q >> m;

        vi a(p+q);
        vi b(p);

        for (int i=0; i<p+q; i++)
            cin >> a[i];

        for (int i=0; i<p; i++)
            b[i] = a[i] + 1;

        for (int i=p; i<p+q; i++)
            m -= a[i]-1;

        int result = choose(m-1, n-1, mod) + f(a, 0, n, m, mod, -1);
        
        result = (result % mod + mod) % mod;

        cout << result << endl;

    }
}
