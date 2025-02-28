#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
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


void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll mx = LLONG_MIN;
    forn(i,n) {
        cin >> v[i];
        mx = max(mx,v[i]); 
    }
    // {a[i], 2a[i]}
    // 5,5,5,5
    // 4,8
    // 100
    // 1000 
    vector<ll> ans;
    forn(i,n)
        ans.push_back(mx-v[i]);
    ll cnt = 0;
    vector<pair<ll,ll>> ans1;
    ans1.clear();
    forn(i,n)
    {
        while(v[i] <= ans[i])
        {
            // cout << 
            ans1.push_back({i+1,v[i]});
            ans[i] -= v[i];
            v[i] = 2*v[i];
        }
        if(ans[i])
            ans1.push_back({i+1,ans[i]});
    }
    cout << ans1.size() << endl;
    forn(i,n)
    {
        cout << ans1[i].first << " " << ans1[i].second <<  endl;
    }
}

int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    cout << "Case " << it << ": " << endl;
    solve();
 }
 return 0;
}