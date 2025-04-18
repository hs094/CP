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
#define ys cout << "Yes" << endl;
#define no cout << "No" << endl;

bool binary(vector<ll> &w, ll t, ll start, ll end) {
    while(start <= end) {
        ll mid = start + (end-start)/2;
        if(w[mid] == t) return true;
        else if(w[mid] < t) start = mid+1;
        else end = mid-1;
    }
    return false;
}
void solve(){
    ll n,sum;
    cin >> n >> sum;
    vector<ll> v(n);
    ll sum_a = 0;
    forn(i,n) {
        cin >> v[i];
        sum_a += v[i];
    }
    vector<ll> w = v;
    forn(i,n) w.push_back(v.at(i));
    vector<ll> p = w;
    forsn(i,1,2*n) w[i] += w[i-1];
    rforsn(i, 2*n-2, 0) p[i] += p[i+1];
    reverse(all(p));
    if(sum <= 2*sum_a) {
        forsn(i,0,2*n) {
            bool find = binary(w, w[i]-sum, 0, i-1);
            if(find || w[i] == sum) {
                ys;
                return;
            }   
        }
    }
    else {
        sum %= (2*sum_a);
        if(sum == 0) {
            ys;
            return;
        }
        forn(i,2*n) {
            if(sum-w[i] < 0) break;
            bool find = binary(p, sum-w[i], 0, 2*n);
            if(find || w[i] == sum) {
                ys;
                return;
            }
        }   
        forn(i,2*n) {
            if(sum-p[i] < 0) break;
            bool find = binary(w, sum-p[i], 0, 2*n);
            if(find || p[i] == sum) {
                ys;
                return;
            }
        } 
    }
    no;
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