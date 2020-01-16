/* C++ iostream (with no flush): 4 sec
 * C stdio: 1.3 sec
 * lesson: C I/O is a lot faster (but "%c" is picky about newlines)
 */

#include <stdio.h>

int m[1001][1001];
int row_map[1001], col_map[1001];

inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main() 
{
    int n, k;
    scanf("%d %d\n", &n, &k);

    for (int i=1; i<=n; i++)
    {
        row_map[i] = i;
        for (int j=1; j<=n; j++)
        {
            col_map[j] = j;
            scanf("%d ", &(m[i][j]));
        }
        scanf("\n");
    }

    for (int K=1; K<=k; K++)
    {
        char c;
        int a, b;
        scanf("%c %d %d\n", &c, &a, &b);

        if (c == 'A') 
        {
            printf("%d\n", m[row_map[a]][col_map[b]]);
        }

        else if (c == 'R') 
        {
            swap(&row_map[a], &row_map[b]);
        }

        else if (c == 'C')
        {
            swap(&col_map[a], &col_map[b]);
        }
    }
}
