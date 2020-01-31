#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;

ll f(ll n, ll k)
{
    ll v = 0;
    while (n)
    {
        ll ve = min(k, n);
        n -= ve;
        v += ve;

        n -= n/10ll;

    }

    return v ;

}

int main() 
{

    ll n;
    scanf("%lld", &n);
    ll lo = 0;
    ll hi = n;

    while (hi - lo > 1)
    {
        ll mid = (lo + hi)/2;
        //printf("%lld %lld %lld\n", lo, mid, hi);

        if (f(n, mid) >= (n+1)/2)
        {
            hi = mid;
        }
        else 
        {
            lo = mid;

        }


    }

    printf("%lld\n", hi);

}
