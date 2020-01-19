#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// test if subset size s is valid using sliding window and median
bool valid_subset_size(const vector<int>& a, int n, int s, long long B)
{
    int lo = 0, m = (s-1)/2, hi = s-1;
    long long cost = 0;
    for (int i=lo; i<=hi; i++)
    {
        cost += abs(a[i] - a[m]);
    }

    for ( ; hi <= n-1; lo++, hi++, m++)
    {
        //cout << "cost: " << cost << '\n';
        if (cost <= B) return true;
        
        if (hi < n-1) 
        {
            cost += a[lo] + a[hi+1] - a[m+1] - (s%2 ? a[m] : a[m+1]);
        }
    }
    return false;
}

int main() 
{
    int n, L;
    long long B;
    vector<int> a, d;

    cin >> n >> L >> B;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());


    // binary search s
    int s_lo = 1, s_hi = n, s_mid;

    while (s_lo < s_hi) 
    {
        s_mid = (s_lo + s_hi + 1)/2;
        //cout << s_lo << " " << s_mid << " " << s_hi << '\n';
        //cout << valid_subset_size(a, n, s_mid, B) <<'\n';
        if (valid_subset_size(a, n, s_mid, B))
        {
            s_lo = s_mid;
        } else
        {
            s_hi = s_mid - 1;
        }
    }

    cout << s_lo << '\n';

    return 0;
}
