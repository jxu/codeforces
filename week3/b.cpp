#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll f(ll n, ll x, ll y, ll t)
{
    ll a = 1 + 2*(t+1)*t;
    ll uy = n-y, dy = y-1;
    ll rx = n-x, lx = x-1;
    ll uuy = t-uy, ddy = t-dy;
    ll rrx = t-rx, llx = t-lx;

    //printf("%lld %lld %lld %lld\n", uuy, ddy, rrx, llx);

    if (uuy > 0) a -= uuy*uuy;
    if (ddy > 0) a -= ddy*ddy;
    if (rrx > 0) a -= rrx*rrx;
    if (llx > 0) a -= llx*llx;

    ll uurr = uuy-rx-1, uull = uuy-lx-1;
    ll ddrr = ddy-rx-1, ddll = ddy-lx-1;

    //printf("%lld %lld %lld %lld\n", uurr, uull, ddrr, ddll);
    
    if (uurr > 0) a += uurr*(uurr+1)/2;
    if (uull > 0) a += uull*(uull+1)/2;
    if (ddrr > 0) a += ddrr*(ddrr+1)/2;
    if (ddll > 0) a += ddll*(ddll+1)/2;

    return a;
}

int main() 
{

    ll n, x, y, c;
    scanf("%lld %lld %lld %lld", &n, &x, &y, &c);
    ll lo = -1; // allow t=0 answer
    ll hi = 2*n;

    /*
    for (ll t=0; t<20; t++) 
    {
    
       printf("t:%lld %lld\n", t, f(9, 3, 8, t));
    }

    return 0;
    */

    while (hi - lo > 1)
    {
        ll mid = (lo + hi)/2;
        //printf("%lld %lld %lld\n", lo, mid, hi);

        if (f(n, x, y, mid) >= c)
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
