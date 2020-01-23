#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

/*
class priority_queue_container : priority_queue
{
    public:
        vector<int> get_c { return c;}

}
*/

int main() 
{
    /*
    map<int, string> m;
    m[1] = "Jason";
    m.insert({3, "Adam"});
    m.insert({2, "Test"});

    // traversal
    for (const auto &pair : m)
        cout << pair.first << ": " << pair.second << "\n";
    */

    map<int, int> m;

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> id_relation(n+1);
    map<int, int> relation_id;
    vector<int> relation_priority;
    set<int> relations;

    for (int i=1; i<=n; i++)
    {
        int relation;
        cin >> relation;
        id_relation[i] = relation;
        relation_id[relation] = i; // unique 
    }

    vector<int> best; // bad bad

    for (int i=0; i<q; i++)
    {
        int q, id;
        cin >> q >> id;
        if (q == 1)
        {
            m[id] = id_relation[id];

            best.push_back(id_relation[id]);

            if (best.size() > k) // horrible 
                best.erase(min_element(best.begin(), best.end()));

            /*
            cout << "New map: ";
            for (const auto &pair : m)
                cout << pair.first << ": " << pair.second << " ";
            cout << "\n";

            cout << "Relations: ";
            for (int x : relations)
                cout << x << ' ';
            cout << "\n";

            
            for (int j = 0; j < relation_priority.size(); j++)
                cout << relation_priority[j] << " ";
            cout << "\n";
            */
            

        } 
        else
        {
            int relation = id_relation[id];
            if (find(best.begin(), best.end(), relation) != best.end())
            {
                    cout << "YES\n";
            } 
            else
            {
                cout << "NO\n";
            }
            
        }
    }

}
