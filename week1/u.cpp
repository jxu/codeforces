#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n, L;
    long long B;
    vector<int> v, d;

    cin >> n >> L >> B;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int p = v[v.size() / 2];
    
    for (int x : v)
    {
        d.push_back(abs(x - p));
        cout << abs(x-p) << ' ';
        cout << '\n';
    }

    sort(d.begin(), d.end());

    int s = 0;
    long long b = 0;

    for (int i=0; i<n; i++)
    {
        if (b + d[i] > B) break;
        s++;
        b += d[i];

    }

    cout << s << '\n';
    
}
