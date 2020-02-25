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

        int bestA, bestB, bestC;
        int best_res = INT_MAX;

        for (int A=1; A <= 10000; A++)
        {
            for (int B=A; B <= 15000; B += A)
            {
                int C = (c / B) * B;
                if ((c - C) > B/2) C += B; 
                int res = abs(a - A) + abs(b - B) + abs(c - C);
                
                if (res < best_res)
                {
                    best_res = res;
                    bestA = A; bestB = B; bestC = C;
                }
            }
        }

        cout << best_res << endl ;
        cout << bestA << " " << bestB << " " << bestC << endl;
    }
}
