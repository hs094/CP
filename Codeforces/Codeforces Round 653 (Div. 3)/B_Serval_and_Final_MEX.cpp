#include <bits/stdc++.h>
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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define ipt(n, r) forn(i, n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    forn(i,n) cin >> v[i];
    ll disp = 0;
    vector<pair<ll,ll>> op;
    forn(i,n) 
    {
        if(v[i] == 0) {
            if(i != n-1) {
                op.push_back({i+1-disp, i+2-disp});
            }
            else {
                op.push_back({i-disp, i+1-disp});
            }
            disp++;
            i++;
        }
    }
    op.push_back({1, n-disp});
    cout << op.size() << endl;
    for(auto x : op) {
        cout << x.first << " " << x.second << endl;
    }
} 

signed main()
{
    fast_cin();
    ll t;
    cin >> t;
    forsn(it, 1, t + 1)
    {
        solve();
    }
    return 0;
}