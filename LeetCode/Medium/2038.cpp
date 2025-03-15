#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<vector<int>> vv32;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define all(x) (x).begin(), (x).end()
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        
    }
    void solve()
    {
        // Implement logic here
        string s;
        cin >> s;
        cout << winnerOfGame(s) << endl;
    }

    void runTests()
    {
        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }
    }
};

int main()
{
    fast_cin();
    Solution sol;
    sol.runTests();
    return 0;
}