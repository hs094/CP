#include <iostream>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define rep(x, start, end) for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); ((start) < (end) ? x++ : x--))
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
#define ipt(n, r) forn(i, n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

bool comp(pair<string, ll> &a, pair<string, ll> &b)
{
    return a.first < b.first;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<vector<ll>, ll>> v;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        vector<ll> vh;
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            vh.push_back(x);
        }
        sort(all(vh));
        v.push_back({vh, i + 1});
    }
    sort(v.begin(), v.end(), [](const pair<vector<ll>, ll> &a, const pair<vector<ll>, ll> &b) {
            if (a.first == b.first) {
                return a.second < b.second; // Compare indices if vectors are equal
            }
            return lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end()); 
    });
    bool flag = true;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if ((v[i].first[j]) != i + j * n)
            {
                flag = false;
                break;
            }
        }
        // cout << "\n";
    }
    if (flag)
    {
        for (auto it : v)
            cout << it.second << " ";
        cout << "\n";
    }
    else
        cout << -1 << "\n";
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}