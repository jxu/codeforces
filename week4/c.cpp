#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vi c(n+1, 0);
    //vvi g(n+1, vi(k+1, 0));
    vvi op(n+1, vi(k+1, 0));



    for (int i=0; i<n; i++)
    {
         cin >> c[i];
    }

    int best_n = 0;
    int last = 0;

    op[0][0] = 1;

    for (int i=1; i<n; i++)
    {
        for (int j=0; j <= k; j++)
        {
           
            if (j-c[i-1] >= 0 && op[i-1][j-c[i-1]] != 0) 
            {
                op[i][j] = 1;
            }

            if (j+c[i-1] <= k && op[i-1][j+c[i-1]] != 0)
            {
                op[i][j] = -1;
            }


            cout << op[i][j] << " " ;
        }
        cout << endl;
    }
    best_n += 2;
    cout << best_n << endl;

    vi ind;

    for (int i=best_n-1; i>=0; i--)
    {
        


    }
        

}
