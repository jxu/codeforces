#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;


int main() 
{
    int q; cin >> q;

    for (int Q=0; Q<q; Q++) 
    {
    
        int k, n; cin >> n >> k;
        vector<int> t(n, 2e9);
        vector<int> a(n);
        vector<int> p(k);

        for (int i=0;i<k;i++) {
            cin >> p[i]; --p[i];
        }

        for (int i=0; i<k;i++) {
            cin >> t[p[i]]; 
            
        }

        int b = 2e9;
    
        for (int i=0; i<n; i++) {
            if (t[i]) {
                b = min(t[i], b);
    
            }
                a[i] = b;

            ++b;
        }

        b = 2e9;

        for (int i=n-1; i>=0; i--) {
            if (t[i]) {
                b = min(t[i], b);
            }
            a[i] = min(a[i], b);
            ++b;
        }
        
        for (int x: a) {
            cout << x << " ";
        }
        cout << endl;
    }


}
