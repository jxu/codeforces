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
        
        //bool ab, bc, ac = true;
        bool done = false;

        if (a >= 2 && b >= 2 && c >= 2) 
        {
            a -= 2; b -= 2; c -= 2;
            //ab = false; bc = false; ac = false;
            done = true;
            s += 3;
        }

        if (!done && a && b >= 2 && c)
        {
            a -= 1; b -= 2; c -= 1;
            done = true;
            s += 2;
        }

        if (!done && a >= 2 && b && c)
        {
            a -= 2; b -= 1; --c;
            done = true;
            s += 2;
        }

        if (!done && a && b && c >= 2)
        {
            --a; --b; c -= 2;
            done = true;
            s += 2;
        }

        if (!done && a && b) {++s; --a; --b;};
        if (!done && b && c) {++s; --b; --c;};
        if (!done && a && c) {++s; --a; --c;};

        if (a && b && c) ++s;

        cout << s << endl;

        

    }
}
