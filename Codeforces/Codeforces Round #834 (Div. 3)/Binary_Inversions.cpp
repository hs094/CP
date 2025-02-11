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
    ll cnt_0_after = 0;
    forn(i,n) {
        cin >> v[i];
        if(v[i]==0) cnt_0_after++;
    }
    pair<ll,ll> r = {0,0};
    vector<pair<ll,ll>> st(n,r);
    ll cnt0 = 0;
    ll cnt1 = 0;
    ll cnt_1_before = 0;
    ll ini_val = 0;
    for(ll i=0;i<n;i++)
    {   
        if(v[i]==0)
        {
            cnt_0_after--;
            r = {cnt_0_after, cnt_1_before};
            st[i] = r;
        }
        else
        {
            ini_val += cnt_0_after;
            r = {cnt_0_after,cnt_1_before};
            cnt_1_before++;
            st[i] = r;
        }
    }
    // cout << ini_val << endl;
    ll mx = ini_val;
    for(int i=0;i<n;i++) {
        // cout << it.first << " " << it.second << endl;
        if(v[i]==0)
        {
            mx = max(mx,ini_val+st[i].first-st[i].second);
        }
        else
        {
            mx = max(mx,ini_val-st[i].first+st[i].second);
        }
    }
    cout << mx << endl;
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