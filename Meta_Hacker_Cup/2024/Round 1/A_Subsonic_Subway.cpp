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
// #define max(a,b) a > b ? a : b
// #define min(a,b) a > b? b : a
#define ipt(n,r) forn(i,n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;


ld solve(){
    ll n;
    ll a,b;
    cin >> n;
    pair<ld,ld> ans;
    cin >> a >> b;
    ans.first = (ld)(1.0) / (ld)(1.0 * b);
    ans.second = (a == 0) ? 1e18 :  (ld)(1.0) / (ld)(1.0 * a);
    // cout << ans.first << " " << ans.second << endl;
    forn(i,n-1) {
        cin >> a >> b;
        ld lo = 0;
        ld hi = 1e18;
        if(a != 0) {
            hi = (ld)(i+2) / (ld)a;
        }
        lo = (ld)(i+2) / (ld)b;
        if(lo < ans.first && hi < ans.first) {
            return -1;
        }
        if(lo > ans.second && hi > ans.second) {
            return -1;
        }
        ans.first = max(lo, ans.first);
        ans.second = min(hi, ans.second);
        if(ans.second < ans.first) return -1;
        // cout << lo << " " << hi << " ";
        // cout << ans.first << " " << ans.second << endl;
    }
    // cout << ans.first << " " << ans.second << endl;
    return (ans.first == INF) ? -1 : ans.first; 
}

int main()
{   
 fast_cin();
 freopen("subsonic_subway_input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    cout << "Case " << "#" << it << ": " << solve() << endl;
 }
 return 0;
}