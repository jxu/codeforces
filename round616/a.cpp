#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k=0; k < t; k++)
    {
        int n;
        cin >> n;
        int digit_sum = 0;
        bool success = false;


        string raw;
        cin >> raw;
        vi digits(n);
        vector<bool> deleted(n, false);
        int rem = n;
        //int last = n-1;
        //int first  = 0;

        for (int i=0; i < n; i++)
        {
            digits[i] = raw[i] - '0';
            digit_sum += digits[i];
            //cout << digit_sum << endl;
        }
        
        for (int i=0; i<n; i++)
        {
            if (digits[i] % 2 == 0)
            {
                deleted[i] = true;
                digit_sum -= digits[i];
                rem--;
            }

        }


        if (rem <= 0) 
        {
            cout << "-1\n";
            continue;
        }


        if (digit_sum % 2 == 0)
        {
            for (int i=0; i < n; i++)
            {
                if (!deleted[i])
                    cout << digits[i];
            }
            cout << "\n";
            continue;
        }

        else if (rem == 1)
        {
            cout << "-1\n";
            continue;

        } else
        {

            for (int i=0; i < n; i++)
            {
                if (!deleted[i])
                {
                    deleted[i] = true;
                    rem--;
                    digit_sum -= digits[i];
                    break;
                }
            }
            for (int i=0; i < n; i++)
            {
                if (!deleted[i])
                    cout << digits[i];
            }
            cout << "\n";
            continue;

        }
    }
}
