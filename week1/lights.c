#include <stdio.h>

int main() 
{
    int N, D;
    scanf("%d %d\n", &N, &D);
    
    for (int n=0; n<N; n++)
    {
        int x, a, g, r, cycle;
        scanf("%d %d %d %d\n", &x, &a, &g, &r);
        cycle = g + r;
        // 0 <= d <= g is green 
        if (x < a || (x - a) % cycle > g) 
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
