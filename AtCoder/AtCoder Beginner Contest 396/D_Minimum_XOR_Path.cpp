#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a > b) ? b : a
#define ipt(n, r) forn(i, n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

vector<bool> vis;
ull ans;

void dfs(ull node, ull n, vector<vector<pair<ull,ull>>> &graph, ull xo) {
    if(node == n-1) {
        ans = min(ans, xo);
        return;
    }
    for(auto [u,w] : graph[node]) {
        if(!vis[u]) {
            vis[u] = 1;
            dfs(u, n, graph, xo ^ w);
            vis[u] = 0;
        }
    }
}

void solve()
{
    ull n,m,u,v,w;
    cin >> n >> m;
    vector<vector<pair<ull,ull>>> graph(n);
    while(m--) {
        cin >> u >> v >> w;
        u--;v--;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    ans = ULLONG_MAX;
    vis.resize(n, false);
    vis[0] = 1;
    dfs(0, n, graph, 0);
    cout << ans << endl;
}

signed main()
{
    fast_cin();
    solve();
    return 0;
}