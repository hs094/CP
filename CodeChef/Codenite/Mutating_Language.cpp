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
#define max(a, b) a > b ? a : b
#define min(a, b) a > b ? b : a
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

bool prime[200005];
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> v;
    int j = 0;
    for (int i = 0; i < 10001 && v.size() != 28; i++)
    {
        if (prime[i])
        {
            v[i] = j;
            j++;
        }
    }
    string ans = "";
    bool period = false;
    for (int i = 0; i < 3*n; i += 3)
    {
        if (period)
        {
            ll k = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');
            k = v[k];
            k = ((k-1)%28+28)%28;
            if (k == 27)
            {
                period = true;
                ans.push_back('.');
            }
            else if(k==26)
                ans.push_back(',');
            else 
                ans.push_back((char)('a'+k));
        }
        else
        {
            ll k = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');
            k = v[k];
            if (k == 27)
            {
                period = true;
                ans.push_back('.');
            }
            else if(k==26)
                ans.push_back(',');
            else 
                ans.push_back((char)('a'+k));
        }
    }
    cout << ans << endl;
}

int main()
{
    SieveOfEratosthenes(120);
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}