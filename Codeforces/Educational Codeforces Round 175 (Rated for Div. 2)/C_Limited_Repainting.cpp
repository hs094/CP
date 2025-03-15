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
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(n);
    priority_queue<vector<ll>> pq;
    vector<ll> r_penalty(n,0), total_penalty(n,0);
    forn(i,n) {
        cin >> v[i];
        if(s[i] == 'R') {
            r_penalty[i] = v[i];
        }
        total_penalty[i] = v[i];
    }
    forn(i,n) {
        if(i > 0)
            total_penalty[i] += total_penalty[i-1];
        if(i > 0)
            r_penalty[i] += r_penalty[i-1];
    }
    for(ll i=0;i<n;i++) {
        ll j = i;
        ll penalty = 0;
        while(j<n && s[j] == 'B') {
            penalty += v[j];
            j++;
        }
        if(j >= i+1) {
            pq.push({penalty, i, j-1});
        }
        i = j;
    }
    ll ans = 0;
    while(!pq.empty() && k > 0) {
        ll start = -1, end = -1, cost_B = 0, cost_R = 0;
        while(!pq.empty() && cost_B >= cost_R) {
            auto y = pq.top();
            pq.pop();
            if(start == -1) {
                start = y[1];
                end = y[2];
                cost_B = y[0];
                cost_R = y[0];
            }
            else {
                ll l = -1, h = -1, cost = 0;
                if(y[2] < start) {
                    l = y[2]+1;
                    h = start-1;
                }
                else if(y[1] > end) {
                    l = end+1;
                    h = y[1]-1;
                }
                if(l > 0) {
                    cost += r_penalty[h] - ((l > 0) ? r_penalty[l-1] : 0);
                }
                else {
                    cost += r_penalty[h];
                }
                if(cost_B >= cost) {
                    end = y[2];
                    cost_R += cost;
                    cost_B += y[0];
                    cout << cost_R << " " << cost_B << endl;
                }
                else {
                    cout << cost_R << " " << cost_B << endl;
                    break;
                }
            }
        }
        ans += cost_R-cost_B;
        k--; 
    }
    cout << ans << "\n";
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