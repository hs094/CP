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
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
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
#define max(a,b) a > b ? a : b
#define min(a,b) a > b? b : a
#define ipt(n,r) forn(i,n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int cnt, vector<int>& component) {
    visited[node] = true;
    component[node] = cnt;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, cnt, component);
        }
    }
}

vector<int> findConnectedComponents(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n, false);
    vector<int> connectedComponents(n, -1);
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, cnt, connectedComponents);
        }
    }
    return connectedComponents;
}

void solve(){
    ll n,m1,m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> f(n), g(n);
    for(int i=0;i<m1;i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        f[x].push_back(y);
        f[y].push_back(x);
    }
    for(int i=0;i<m2;i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> fc = findConnectedComponents(n, f), gc = findConnectedComponents(n, g);
    map<>
    for(ll i=0;i<n;i++) {
        if(fc[i] != gc[i]) {

        }
    }
}

int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}