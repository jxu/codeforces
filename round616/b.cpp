#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int k=0; k<t; k++)
    {
        int n;
        cin >> n;
        vi a(n);
        vector<bool> lofit(n);
        vector<bool> hifit(n);

        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            lofit[i] = (a[i] >= i);
            if (i > 0) lofit[i] &= lofit[i-1];
        }

        for (int i=n-1; i>=0; i--)
        {
            hifit[i] = (a[i] >= n-1-i);
            if (i < n-1) hifit[i] &= hifit[i+1];
        }

        bool success = false;
        for (int i=0; i<n; i++)
        {
            if (lofit[i] && hifit[i]) 
            {
                success = true;
                break;
            }
        }

        if (success) 
            cout << "Yes\n";
        else 
            cout << "No\n";

    }
}
