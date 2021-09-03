#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool overlap(double a, double b, double c, double d, double x)
{
    double ad0 = (a+x)*(d+x);
    double ad1 = (a+x)*(d-x);
    double ad2 = (a-x)*(d+x);
    double ad3 = (a-x)*(d-x);

    double max_ad = max({ad0, ad1, ad2, ad3});
    double min_ad = min({ad0, ad1, ad2, ad3});

    double bc0 = (b+x)*(c+x);
    double bc1 = (b+x)*(c-x);
    double bc2 = (b-x)*(c+x);
    double bc3 = (b-x)*(c-x);

    double max_bc = max({bc0, bc1, bc2, bc3});
    double min_bc = min({bc0, bc1, bc2, bc3});

    //printf("ad [%lf,%lf] bc [%lf,%lf]\n", min_ad, max_ad, min_bc, max_bc);

    return (min_ad <= min_bc && max_ad >= min_bc) || 
           (min_bc <= min_ad && max_bc >= min_ad);
}

int main() 
{
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    double hi = max({abs(a), abs(b), abs(c), abs(d)});
    double lo = 0;

    for (int k=0; k<100; k++)
    {
        double mid = (lo + hi)/2;
        //printf("%lf %lf %lf\n", lo, mid, hi);

        if (overlap(a, b, c, d, mid))
            hi = mid;
        else 
            lo = mid;
    }

    printf("%.9f\n", lo);
}
