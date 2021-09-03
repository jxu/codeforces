#include <stdio.h>
#include <stdbool.h>

#define N_MAX 200000

int  seq [N_MAX+1];
bool seen[N_MAX+1];
char pw  [N_MAX+1];

int main() 
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &(seq[i]));
        seen[i] = false;
    }

    // create letter chains
    char cur_letter = 'a';
    int letters = 0;

    for (int i=1; i<=n; i++)
    {
        if (seen[i]) continue; // i = chain start
        
        letters++;
        if (letters > 26) // too many letters
        {
            printf("-1\n");
            return 0;
        }

        int j = i;

        // follow chain
        while (true)
        {
            //printf("j=%d %c\n", j, cur_letter);
            seen[j] = true;
            pw[j] = cur_letter;
            
            if (seq[j] == n+1) break; // end chain
            if (seen[seq[j]] || seq[j] <= j) // must have a_j > j 
            {
                printf("-1\n");
                return 0;
            }
            
            j = seq[j];   
        }

        cur_letter++;
    }

    // print password pw[1] to pw[n]
    printf("%.*s\n", n, pw+1);

    return 0;
}
