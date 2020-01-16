#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    vector<int> v;

    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int k=30; k>=0; k--)
    {
        //cout << k << ":";
        int mask = 1 << k;
        vector<int> c;

        for (int x : v)
        {
            if (x & mask)
            {
                c.push_back(x);
            }

        }

        if (c.size() >= 2) 
        {
            v = c;

        }

        //for (int x : c)
        //    cout << x << ' ';
        //cout << '\n';
    
    }

    cout << (v[0] & v[1]) << '\n';

}
