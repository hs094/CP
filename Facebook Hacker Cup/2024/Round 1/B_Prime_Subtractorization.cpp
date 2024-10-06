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

ll MAX_N = 10000000;
set<int> primesList;
vector<bool> prime(MAX_N + 1, true);
void sieveOfEratosthenes() {
    prime[0] = prime[1] = false; 
    for (int p = 2; p * p <= MAX_N; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAX_N; i += p) {
                prime[i] = false;
            }
        }
    }
     primesList.insert(2);
    for (ll p = 3; p <= MAX_N; p+=2) {
        if (prime[p])
            primesList.insert(p); 
    }  
}
ll solve(){
    ll N;
    cin >> N;
    if(N < 5) return 0;
    else {
        ll cnt = 2;
        for(auto it: primesList) {
            if(it <= 5) continue;
            if(it > N) break;
            if(it >= 7 && primesList.count(it-2)) cnt++;
        }
        return cnt;
    }
}

int main()
{
 fast_cin();
//  freopen("prime_subtractorization_input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
 sieveOfEratosthenes();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
    cout << "Case " << "#" << it << ": " << solve() << endl;
 }
 return 0;
}