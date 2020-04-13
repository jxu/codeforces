#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int counts[27][2000];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        int n; cin >> n;
        vi aa(n);
        for (int i=0;i<n;i++)
        {
            cin >> aa[i];

            for (int j=1; j<=26; j++)
            {
                counts[j][i] = (aa[i] == j);
                if (i > 0) counts[j][i] += counts[j][i-1];

                //cout << counts[j][i] << " ";
            }
            //cout << endl;
        }
    
        // ???
        //
        int best = 0;
        
        for (int a=1; a<=26; a++)
        {
            for (int b=a; b<=26; b++)
            {
                for (int j=0; j<n; j++)
                {
                    for (int k=j+1; k<n; k++)
                    {
                        
                        int x0 = counts[a][j];
                        int y = counts[b][k];
                        y -= counts[b][j];
                        
                        
                        int x1 = counts[a][n-1];
                        x1 -= counts[a][k];

                        if (0 && (x0 || y || x1)) 
                        {
                            cout << "a " << a << " b " << b << " ";
                            cout << " j " << j << " k " << k << " ";
                            cout << x0 << " " << y << " " << x1 << endl;
                        }
                        int x = min(x0, x1);
                        best = max(best, x+y+x);


                    }



                }


            }


        }

        if (n == 1) best = 1;

        cout << best << endl;

        //break;

    }
}
