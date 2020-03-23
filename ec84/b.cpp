#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        int n, k;
        cin >> n;

        vi found(n+1, 0), mar(n+1, 0);
        int lo = 1;

        for (int i = 1; i <= n; i++) 
        {
            cin >> k;
            
            for (int j = 1; j <= k; j++) 
            {
                int g;
                cin >> g;

                if (!mar[g] && !found[i])
                {
                    mar[g] = 1;
                    found[i] = 1;
                    //cout << g << " " << i << endl;
                }

                //cout << g << " ";

            }
            //cout << endl;
            /*
            for (int j = 1; j <= n; j++)
                cout << mar[j];
            cout << " ";
            
            for (int j = 1; j <= n; j++)
                cout << found[j];
            cout << endl;
            */

        }

        bool f = false;
        for (int i = 1; i <= n; i++)
        {
            if (!found[i])
            {
                cout << "IMPROVE" << endl;
                int j;
                for (j = 1; mar[j]; j++)
                    ;

                cout << i << " " << j << endl;
                f = true;
                break;

            }
        }

        if (!f) cout << "OPTIMAL" << endl;

        //break;
    }
}
