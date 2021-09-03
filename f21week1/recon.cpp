#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n; cin >> n;

    vector<int> v(n);


    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    int best_h = 100000;
    int best_i;
    for (int i=0; i<n; i++) 
    {
        int h = abs(v[i] - v[(i+1)%n]);
        if (h < best_h) 
        {
            best_h = h;
            best_i = i;
        }
    }

    cout << (best_i+1) << " " << (best_i+1)%n + 1 << endl;

}
