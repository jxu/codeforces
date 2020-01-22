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
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());

        //cout << v[0] << v[1] << v[2] << endl;

        int r = v[2] - v[0] + v[2] - v[1];

        if (n >= r && (n-r) % 3 == 0) 
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    
    }


}
