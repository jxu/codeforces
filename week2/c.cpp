#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> X;
    int n; cin >> n;
    
    for (int i=0; i<n; i++)
    {
        int y; cin >> y;
        X.insert(y);
    }

    while (true)
    {
        int Xmax = *(X.rbegin());
        int x = Xmax;

        while (X.count(x)) 
            x /= 2;

        if (x == 0) // no place for x
            break;
        else
        {
            X.erase(Xmax); 
            X.insert(x);
        }
    }

    for (int x : X)
        cout << x << " ";
    cout << "\n";
}
