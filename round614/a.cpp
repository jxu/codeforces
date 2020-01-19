#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


int main() 
{
    int t;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        int n, s, k;
        cin >> n >> s >> k;

        unordered_set<int> R;

        for (int k_=0; k_<k; k_++) 
        {
           int f;
           cin >> f;
           R.insert(f);
        }

        int floor_up = 0, floor_down = 0;
        int res_up = 10000, res_down = 10000;

        for ( ; s + floor_up <= n; floor_up++) 
        {
            if (!R.count(s + floor_up)) 
            {
                res_up = floor_up;
                break;
            }
        }

        for ( ; s - floor_down >= 1; floor_down++)
        {
            if (!R.count(s - floor_down)) 
            {
                res_down = floor_down;
                break;
            }
        }

        cout << min(res_up, res_down) << '\n';

    }


}
