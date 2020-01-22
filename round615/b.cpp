#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void f(vvi points)
{
    vi origin = {0, 0};
    points.push_back(origin);
    int n = points.size(); // bigger than original n 
    sort(points.begin(), points.end());


    for (int j=0; j<n-1; j++)
    {
        //vi point = points[j];   
        //cout << point[0] << ' ' << point[1] << endl;
        //cout << endl;
        
        
        /*
        for (int k=0; k<n; k++)
        {
            vi p1 = points[j];
            vi p2 = points[k];

            if (p1[0] > p2[0] && p1[1] < p2[1])
            {
                cout << "NO\n";
                return;
            }

        }
        */

        vi p1 = points[j];
        vi p2 = points[j+1];

        if (p1[1] > p2[1])
        {
            cout << "NO\n";
            return;
        }

    }

    cout << "YES\n";

    for (int j=0; j<n-1; j++)
    {

        vi p1 = points[j];
        vi p2 = points[j+1];


        for (int k=0; k < p2[0] - p1[0]; k++)
            cout << "R";
        for (int k=0; k < p2[1] - p1[1]; k++)
            cout << "U";

    }
    cout << "\n";
}

int main() 
{
    int t;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        vvi points(n);
        for (int j=0; j<n; j++)
        {
            int x, y;
            cin >> x >> y;
            vi point = {x, y};
            points[j] = point;
            
        }
        f(points);   
    }

}
