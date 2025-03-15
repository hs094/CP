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
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a > b) ? b : a
#define ipt(n, r) forn(i, n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

void solve()
{
    ll n,x,k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    if(x == 0) {
        cout << k << endl;
        return;
    }
    ll disp = 0;
    int cnt = 0;
    for(char c: s) {
        disp += (c == 'L') ? -1 : 1;
        cnt++;
        if(x + disp == 0) {
            break;
        }
    }
    if(cnt == n && x + disp != 0) {
        cout << 0 << endl;
    }
    else {
        ll left_sec = k-cnt, cnt1 = 0, disp = 0;
        for(char c: s) {
            disp += (c == 'L') ? -1 : 1;
            cnt1++;
            if(disp == 0) {
                break;
            }
        }
        if(cnt1 == n && disp != 0) {
            cout << 1 << endl;
        }
        else {
            cout << 1 + (left_sec/cnt1) << endl;
        }
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