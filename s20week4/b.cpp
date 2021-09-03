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

    int n;
    cin >> n;
    vi opt(n), rest(n), gym(n), con(n);

    for (int i=0; i<n; i++)
        cin >> opt[i];

    int m = 1 << 30;

    for (int i=0; i<n; i++)
    {
        if (i == 0)
        {
            rest[i] = 1;
            gym[i] = (opt[i] >= 2) ? 0 : m;
            con[i] = (opt[i] % 2) ? 0 : m;
        } else
        {
            rest[i] = min({rest[i-1], gym[i-1], con[i-1]}) + 1;
            gym[i] = (opt[i] >= 2) ? min(rest[i-1], con[i-1]) : m;
            con[i] = (opt[i] % 2) ? min(rest[i-1], gym[i-1]) : m;

            
        }

        //cout << "r g c " << rest[i] << " " << gym[i] << " " << con[i] << endl;


    }

    cout << min({rest[n-1], gym[n-1], con[n-1]}) << endl;

}
