#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool seen[1000];

int main() 
{
    int N;
    cin >> N;

    vector<int> pots;

    for (int i=0; i<N; i++)
    {

        int p;
        cin >> p;
        pots.push_back(p);
        seen[i] = false;
    }

    sort(pots.begin(), pots.end());

    int r = 0;
    for (int i=0; i<N; i++)
    {
        if (seen[i]) continue;
        r++;
        int c = pots[i];
        for (int j=i+1; j<N; j++)
        {
            if (!seen[j] && pots[j] > c)
            {
                seen[j] = true;
                c = pots[j];
            }
        }

    }

    cout << r << '\n'; 

}
