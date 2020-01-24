#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int y;
        cin >> y;
        s.insert(y);
    }

    bool reduced = false;

    for (auto it=s.rbegin(); it != s.rend(); it++)
        cout << *it << " ";
    cout << endl;

    do 
    {
        reduced = false;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            int y = *it;
            int y_new = (y > 1) ? (y - (y%2)) / 2 : y;

            if (!s.count(y_new))
            {
                cout << "reduce " << y << " to " << y_new << "\n";
                s.erase(y);
                s.insert(y_new);
                reduced = true;

                for (int yi : s)
                    cout << yi << " ";
                cout << "\n";

                break;
            }

        }

    } while (reduced);

    for (int y : s)
        cout << y << " ";
    cout << "\n";

}
