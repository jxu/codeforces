#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() 
{
    int n;
    cin >> n;

    double s = 0;
    for (int t=1; t<=n; t++)
        s += 1.0/t;

    cout << s << '\n';

}
