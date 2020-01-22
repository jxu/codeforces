#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() 
{
    int q, x;
    cin >> q >> x;

    vector<int> bcount(x, 0);
    int bcount_min = 0;
    vector<bool> bcount_over_min(x, false);
    int bcount_over_min_count = 0;
    int coming_bucket = 0; // heh

    for (int j=0; j<q; j++)
    {
        int yj;
        cin >> yj;
        yj = yj % x;

        bcount[yj]++;

        if (bcount[yj] > bcount_min && !bcount_over_min[yj])
        {
            bcount_over_min_count++;
            bcount_over_min[yj] = true;
        }

        // recalculate
        if (bcount_over_min_count == x) 
        {
            bcount_min++;
            coming_bucket = 0;

            // slow?
            bcount_over_min_count = 0;
            for (int k=0; k<x; k++)
            {
                if (bcount[k] > bcount_min) 
                    bcount_over_min_count++;
                bcount_over_min[k] = bcount[k] > bcount_min;
            }

        }

        
        while (bcount_over_min[coming_bucket]) 
            coming_bucket++;
       
        /*
        cout << "bcount ";
        for (int z : bcount) 
            cout << z << ' ';
        cout << endl;

        for (int z : bcount_over_min) 
            cout << z << ' ';
        cout << endl;

        cout << "bcount_over_min_count " << bcount_over_min_count <<
            " bcount_min " << bcount_min << 
            " cbucket " << coming_bucket << endl;

        cout << "MEX ";
        */


        cout << x * bcount_min + coming_bucket << '\n';

   }



}
