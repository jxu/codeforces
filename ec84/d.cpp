#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

bool cycle_k(vi& cycle, int k)
{
    //cout << "k " << k << endl;
    int l = (int)cycle.size();
    if (k == 0 || l % k) return false;

    for (int i=0; i<k; i++)
    {
        

        bool ok_k = true;
        //cout << "i " << i << " ";
        for (int j=i; j < l; j+=k)
        {
            //cout << "j" << j << " ";
            if (cycle[j] != cycle[i]) ok_k = false;
        }
        //cout << endl;

        if (ok_k) return true;
    }

    return false;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int T=0; T<t; T++)
    {
        int n; cin >> n;

        vi p(n+1), c(n+1);
        vb seen(n+1, false);

        for (int i=1; i<=n; i++)
            cin >> p[i];

        for (int i=1; i<=n; i++)
            cin >> c[i];

        int best_k = n;

        for (int s=1; s<=n; s++)
        {
            if (seen[s]) continue;
            int y = s;
            vi cycle;
            //cout << "cycle ";
            do 
            {
                //cout << c[y] << " ";
                seen[y] = true;
                cycle.push_back(c[y]);
                y = p[y];
            } while (y != s);

            //cout << endl;

            int l=(int)cycle.size();

            int k;
            for (k = 1; k <= l; k++)
            {
                if (l % k) continue;
                if (cycle_k(cycle, k)) break;
            }


            best_k = min(best_k, k);
        }

        //cout << "best k " << best_k << endl;
        cout << best_k << endl;
    }
}
