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
typedef pair<ll,ll> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<ll> v32;
typedef vector<vector<ll> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = pow(2,30);
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

ll no_of_divisors(ll n)
{
    ll cnt = 1;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll c = 0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            cnt*=(c+1);
        }
    }
    if(n > 1)
        cnt*=2;
    return cnt;
}
void solve(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll cnt = 0;
    for(ll i=1;i<=a;i++)
    {
        for(ll j=1;j<=b;j++)
        {
            for(ll k=1;k<=c;k++)
            {
                cnt+=no_of_divisors(i*j*k);
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
 fast_cin();
 ll t;
 {
    solve();
 }
//  cout << no_of_divisors(11) << endl;
 return 0;
}