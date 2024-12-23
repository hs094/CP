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

#define MAXN 3000
vector<ll> spf(MAXN + 1, 1);
vector<set<ll>> factors(MAXN + 1);

void sieve()
{
    spf[0] = 0;
    for (ll i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (ll j = i; j <= MAXN; j += i) {
                if (spf[j] == 1) 
                    spf[j] = i;
            }
        }
    }
}

void getFactorization()
{
    for (ll x = 1; x <= MAXN; x++) {
        set<ll> ret;
        ll temp = x; 
        for(ll i=1;i*i<=x;i++) {
            if(x%i == 0) {
                ret.insert(i);
                ret.insert(x/i);
            }
        }
        factors[x] = ret; 
    }
}
ll longestAP(vector<ll>& arr) {
    ll n = arr.size();
    if (n <= 2) return n;
    vector<vector<ll>> dp(n, vector<ll>(n, 2));
    ll maxLength = 2;
    for (ll j = n - 2; j >= 0; j--) {
        ll i = j - 1, k = j + 1;
        while (i >= 0 && k < n) {
            if (arr[i] + arr[k] < 2 * arr[j]) {
                k++;
            } else if (arr[i] + arr[k] > 2 * arr[j]) {
                dp[i][j] = 2;
                i--;
            } else {
                dp[i][j] = dp[j][k] + 1;
                maxLength = max(maxLength, dp[i][j]);
                i--;
                k++;
            }
        }
        while (i >= 0) {
            dp[i][j] = 2;
            i--;
        }
    }
    return maxLength;
}
void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    forn(i,n) cin >> v[i];
    map<ll,vector<ll>> mp;
    forn(i,n) {
        mp[v[i]].push_back(i);
    }
    ll ans = 0;
    for(auto x: mp) {
        ans = max(ans,longestAP(x.second));
    }
    cout << ans << endl;
}

int main()
{
 fast_cin();
 ll t;
 t = 1;
//  sieve();
//  getFactorization();
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}