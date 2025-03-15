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
    ll n;
    cin >> n;
    vector<ll> v(n);
    forn(i,n) cin >> v[i];
    ll bestL = 0, bestR = 0;
    ll globalBestDelta = 0;
    bool found_improvement = false;
    forn(l,n) {
        ll currentDelta = 0, bestDeltaforL = 0, bestRforL = l;
        forsn(r, l+1, n) {
            if(v[r] > v[l]) {
                currentDelta++;
            }
            else if(v[r] < v[l]) {
                currentDelta--;
            }
            if(currentDelta < bestDeltaforL) {
                bestDeltaforL = currentDelta;
                bestRforL = r;
            }
        }
        if(bestDeltaforL < globalBestDelta) {
            globalBestDelta = bestDeltaforL;
            bestL = l;
            bestR = bestRforL;
            found_improvement = true;
        }
    }
    if(!found_improvement) {
        cout << 1 << " " << 1 << ln;
    }
    else {
        cout << bestL+1 << " " << bestR+1 << ln;
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