#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(int n)
{
    for (int c=2; c*c <= n; c++)
    {
        if (n % c == 0) 
        {
            int ab = n / c;
            for (int b=2; b*b <= ab; b++)
            {
                if (ab % b == 0)
                {
                    int a = ab / b;
                    if (a != b && b != c && a != c)
                    {
                        cout << "YES\n";
                        cout << a << " " << b << " " << c << '\n';
                        return;
                    }
                }

            }


        }


    }
    cout << "NO" << '\n';
}

int main() 
{
    int t;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        f(n);
   }

}
