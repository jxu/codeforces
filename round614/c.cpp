#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cell[2][100001] = {};

int main() 
{
    int n, q;
    cin >> n >> q;

    int blocked = 0;

    for (int i=0; i<q; i++)
    {
        int r,c;
        cin >> r >> c;
        --r; --c;
        int r_ = 1-r;

        cell[r][c] = !cell[r][c]; // toggle

        int db = (cell[r][c]) ? 1 : -1;

        if (c-1 >= 0 && cell[r_][c-1])
            blocked += db;

        if (cell[r_][c]) 
            blocked += db;

        if (c+1 < n && cell[r_][c+1])
            blocked += db;

        cout << (blocked ? "No" : "Yes") << '\n';
    }
}
