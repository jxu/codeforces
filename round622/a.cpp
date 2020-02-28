#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

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
        int a, b, c;
        cin >> a >> b >> c;

        int s = 0;
        if (a) { ++s; --a;}
        if (b) { ++s; --b;}
        if (c) { ++s; --c;}

        if (a >= 2 && b >= 2 && c >= 2) 
        {
            a -= 2; b -= 2; c -=2;
            s += 3;
        }
        else if (a && b >= 2 && c)
        {
            a--; b -= 2; c--;
            s += 2;
        }
        else if (a >= 2 && b && c)
        {
            a -= 2; b--; c--;
            s += 2;
        }
        else if (a && b && c >= 2)
        {
            a--; b--; c -= 2;
            s += 2;
        }
        else if (a && b) {++s; --a; --b;}
        else if (b && c) {++s; --b; --c;}
        else if (a && c) {++s; --a; --c;}

        if (a && b && c) ++s;

        cout << s << endl;
    }
}
