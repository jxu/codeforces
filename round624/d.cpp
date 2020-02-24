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

        for (int A=1; A <= 2000; A++)
        {
            for (int B=A; B <= 2000; B += A)
            {
                int C1 = (c / B) * B;
                int C2 = C1 + B;
                
                int C = C2;
                if (c - C1 < C2 - c) 
                {
                    C = C1;
                }

                if (c < B) C = B;

                int res = abs(a - A) + abs(b - B) + abs(c - C);
                if (res < best_res)
                {
                    best_res = res;
                    bestA = A;
                    bestB = B;
                    bestC = C;
    
                }


            }
        }

            cout << best_res << endl ;
            cout << bestA << " " << bestB << " " << bestC << endl;


    }
}
