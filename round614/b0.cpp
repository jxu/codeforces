#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double a[100001];

int main() 
{
    int n;
    cin >> n;

    a[0]  = 0.0;

    for (int s=1; s <= n; s++) 
    {
        a[s] = 0.0;
        for (int t=1; t <= s; t++)
        {
            a[s] = max(a[s], a[s-t] + t/(double)s);
        }
    }

    cout << a[n] << '\n';

}
