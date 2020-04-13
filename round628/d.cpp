#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ull;

bool f(ull u, ull v, bool carry, int i, ull& a, ull &b, ull &c)
{
    bool ub = (u >> i) & 1, vb = (v >> i) & 1;
    //cout << ub << " " << vb << " " << carry << endl;
    
    ull ab, bb, cb;

    // special case: c = 1
    if (i == 0 && vb && ub && carry)
    {
        a |= 1; b |= 1; c = 1;
        return true;
    }

    if (vb == 0 && ub == 0 && carry == 0)
        ab = 0, bb = 0, cb = 0;
    else if (vb == 1 && ub == 0 && carry == 0)
        ab = 0, bb = 0, cb = 1;
    else if (vb == 1 && ub == 1 && carry == 0)
        ab = 0, bb = 1, cb = 0;
    else if (vb == 0 && ub == 1 && carry == 1)
        ab = 0, bb = 1, cb = 1;
    else if (vb == 0 && ub == 0 && carry == 1)
        ab = 1, bb = 1, cb = 0;
    else if (vb == 1 && ub == 0 && carry == 1)
        ab = 1, bb = 1, cb = 1;
    else if (vb == 1 && ub == 1 && carry == 1 && i == 0)
        ab = 1, bb = 1, cb = 1;
    else
        return false;

    a |= (ab << i);
    b |= (bb << i);

    if (i == 0) 
    {
        return (cb == 0);
    }

    return f(u, v, cb, i-1, a, b, c);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull u, v;
    cin >> u >> v;

    if (v == 0)
    {
        cout << "0\n";
        return 0;
    }

    if (u == v)
    {
        cout << "1\n" << u << endl;
        return 0;
    }


    ull a = 0, b = 0, c = 0;
    bool valid;

    valid = f(u, v, 0, 63, a, b, c);

    if (!valid)
    {
        cout << "-1\n";
        return 0;
    }

    if (c == 0)
        cout << "2\n" << a << " " << b << endl;
    else
        cout << "3\n" << a << " " << b << " " << c << endl;

}
