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
#define fast_cin()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define ipt(n, r) forn(i, n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

void solve()
{
    ll n,a,b,c;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll> (3,0));
    forn(i,n) {
        cin >> a >> b >> c;
        if(i==0) {
            dp[0][0] = a;
            dp[0][1] = b;
            dp[0][2] = c;
        }
        else {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
        }
    }
    cout << *max_element(dp[n-1].begin(), dp[n-1].end())<< endl;
}

signed main()
{
    fast_cin();
    solve();
    return 0;
}