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

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src) {
    visited[src] = true;
    for (int i : adj[src])
        if (!visited[i])
            dfs(adj, visited, i);
}

int makeConnected(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    unordered_set<string> edgeSet;
    vector<vector<int>> extraEdges;
    int redundantEdges = 0;
    for (auto v : connections) {
        if (v[0] == v[1]) {
            redundantEdges++;
            continue; // Ignore self-loops
        }
        string edgeKey = to_string(min(v[0], v[1])) + "-" + to_string(max(v[0], v[1]));
        if (edgeSet.find(edgeKey) == edgeSet.end()) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            edgeSet.insert(edgeKey);
        } else {
            extraEdges.push_back(v); // Store duplicate edges
        }
    }
    
    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, i);
            components++;
        }
    }
    
    redundantEdges += extraEdges.size();
    int neededEdges = components - 1;
    if (redundantEdges < neededEdges)
        return -1;
    
    cout << "Operations performed to connect components:" << endl;
    int moveCount = 0;
    
    for (int i = 0; i < n && neededEdges > 0; i++) {
        if (!visited[i]) {
            vector<int> edge = extraEdges[moveCount++];
            cout << "Move edge from " << edge[0] << " to " << edge[1] << endl;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            dfs(adj, visited, i);
            neededEdges--;
        }
    }
    
    return components - 1;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> connections;
    set<pair<ll,ll>> st;
    forn(i,m) {
        int x,y;
        cin >> x >> y;
        connections.push_back({x, y});
        // st.insert(make_pair(x,y));
        // st.insert(make_pair(y,x));
    }
    cout << makeConnected(n, connections) << endl;
}

int main()
{
 fast_cin();
 ll t;
 t = 1;
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}