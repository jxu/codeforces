#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<bool> vb;
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
        int s[9][9];
        char c;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9; j++)
            {
                cin >> c;
                s[i][j] = c - '0';

            }

        }
        
        int q[9] = {0,3,6,1,4,7,2,5,8};

        for (int i=0;i<9;i++)
        {
            int j = q[i];
            if (s[i][j] == 9) s[i][j] = 8;
            else s[i][j]++;

        }

        for (int i=0;i<9;i++)
        {
            for (int j=0; j<9; j++)
            {
                cout << s[i][j];

            }
            cout << '\n';

        }


    }
}
