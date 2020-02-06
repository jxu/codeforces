#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int m = 1000000007;

vector<unordered_map<int, int> > memo(51);

int f(int n, int k)
{
    //cout << "f " << n << " " << k << endl; 
    if (n == 1) return (k < 10);  

    if (memo[n].count(k)) return memo[n][k];
    
    int s = 0;
    for (int d=1; d<10; d++)
    {
        if (k % d == 0)
        {
            s = (s + f(n-1, k/d)) % m;
        }
    }

    memo[n][k] = s;
    return s;

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;


    if (k == 0)
    {
        ll a = 1, b = 1;
        for (int i=0; i<n; i++)
        {
            a = (a * 10) % m;
            b = (b * 9) % m;

        }
        
        cout << (a - b + m) % m << endl;

    }
    else
    {

        cout << f(n, k) << endl;
    }
}
