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
    ll n, w;
    cin >> n >> w;
    vector<ll> W(n), V(n);
    forn(i, n) cin >> W[i] >> V[i];
    vector<vector<ll>> dp(n, vector<ll>(w + 1, 0));
    if(W[0] <= w)
        dp[0][W[0]] = V[0];
    ll ans = dp[0][W[0]];
    for(ll i = 1; i < n; i++) {
        for(ll j = 0; j <= w; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= W[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]] + V[i]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    fast_cin();
    solve();
    return 0;
}