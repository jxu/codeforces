// 2 pointers linear time algorithm

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

int cmp_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int a[100000];

int main() 
{
    int n, L;
    long long B;
    scanf("%d %d %lld", &n, &L, &B);

    for (int i=0; i<n; i++)
        scanf("%d", &(a[i]));

    qsort(a, n, sizeof(int), cmp_ints); 

    int lo = 0, m = 0, hi = 0;
    int best_s = 1;
    long long cost = 0;

    while (hi+1 < n)
    {
        // march m if subset size changes even -> odd
        if ((hi - lo + 1) % 2 == 0)
            ++m;
        
        if (cost + (a[hi+1] - a[m]) <= B)
        {
            cost += a[hi+1] - a[m];
            ++hi;
        }
        else
        {
            cost -= a[m] - a[lo];
            ++lo;
            // may have case lo == hi+1 ("subset size 0")
        }

        /*
        for (int i=lo; i<=hi; i++)
        {
            printf("%d", a[i]);
            if (i == m) printf("*");
            printf(" ");
        }
        printf("cost %lld\n", cost);
        */

        best_s = MAX(best_s, (hi - lo + 1));
    }

    printf("%d\n", best_s);

    return 0;
}
