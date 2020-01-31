#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


double det(double a, double b, double c, double d, double x)
{
    double d1 = (a+x)*(d+x) - (b+x)*(c+x);
    double d2 = (a+x)*(d+x) - (b-x)*(c-x);
    double d3 = (a-x)*(d-x) - (b+x)*(c+x);
    double d4 = (a-x)*(d-x) - (b-x)*(c-x);


    
    return (a+x)*(d+x) - (b-x)*(c-x);
}

int main() 
{
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    double hi = pow(10, 11);
    double lo = -pow(10, 11);
    double eps = pow(10, -9);

    for (int k=0; k<1000; k++)
    {
        double mid = (lo + hi)/2;
        //printf("%lf %lf %lf %lf\n", lo, mid, hi, det(a, b, c, d, mid));

        if (det(a, b, c, d, mid) >= 0)
        {
            hi = mid;
        }
        else 
        {
            lo = mid;

        }


    }

    printf("%lf\n", fabs(lo));

}
