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
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll min_idx = -1;
    ll max_idx = -1;
    ll mx = LLONG_MIN;
    ll mn = LLONG_MAX;
    forn(i,n) {
        cin >> v[i];
        if(v[i]>mx)
        {
            mx = v[i];
            max_idx = i;
        }
        if(v[i]<mn)
        {
            mn = v[i];
            min_idx = i;
        }
    }
    vector<ll> x;
    x.push_back(max(min_idx+1,max_idx+1));
    x.push_back(max(n-min_idx,n-max_idx));
    if(min_idx < max_idx)
        x.push_back(min_idx+1+n-max_idx);
    else
        x.push_back(max_idx+1+n-min_idx);
    mn = LLONG_MAX;
    for(ll i=0;i<x.size();i++)
    {
        mn = min(mn,x[i]);
    }
    cout << mn << endl;
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