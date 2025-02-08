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

ll mx = 1e5+1;
pair<ll,ll> ret(ll a, ll b) {
    return {min(a,b), max(a,b)};
}
void solve(){
    ll n;
    cin >> n;
    vector<set<pair<ld, ll>, greater<pair<ld, ll>>>> v(mx);
    for(ll i=0;i<n;i++) {
        ll k,x;
        cin >> k;
        map<ll,ll> mp;
        for(ll i=0;i<k;i++) {
            cin >> x;
            mp[x]++;
        }
        for(auto it: mp) {
            v[it.first].insert({(ld)it.second/(ld)k, i});
        }
    }
    ld ans = 0.0;
    map<pair<ll,ll>, ld> mp;
    for(int i=1;i<mx;i++) {
        if(v[i].size() >= 2) {
            auto it = v[i].begin();
            auto it1 = it;
            ++it1;
            ld prob = (*it).first * (*it1).first;
            ll Z = min((*it).second, (*it1).second);
            ll Z1 = max((*it).second, (*it1).second);
            mp[{Z, Z1}] += prob;
        }
        else if(v[i].size() >= 3) {
            auto it = v[i].begin();
            auto it1 = it;
            ++it1;
            auto it2 = it;
            ++it2;
            mp[ret((*it).second, (*it1).second)] += (*it).first * (*it1).first;
            mp[ret((*it1).second, (*it2).second)] += (*it1).first * (*it2).first;
            mp[ret((*it).second, (*it2).second)] += (*it).first * (*it2).first;
        }
    }
    for(auto it: mp) {
        ans = max(ans, it.second);
    }
    cout << fixed << setprecision(15) << ans << endl;
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