#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
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
#define max(a,b) (a > b) ? a : b
#define min(a,b) (a > b) ? b : a
#define ipt(n,r) forn(i,n) cin >> r[i];
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;

vector<set<ll>> sets;
map<ll,ll> nest_to_set;
map<ll,ll> pigeon_to_nest;
void print() {
    cout << "Sets" << endl;
    forn(i,sets.size()) {
        cout << i << ":: ";
        for(auto y: sets[i]) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << "nest_to_set" << endl;
    for(auto it: nest_to_set) {
        cout << it.first << " " << it.second << endl;
    }
    cout << "pigeon_to_nest" << endl;
    for(auto it: pigeon_to_nest) {
        cout << it.first << " " << it.second << endl;
    }
    cout << "\n\n";
}

void solve(){
    ll n,q;
    cin >> n >> q;
    forn(i,n) {
        sets.pb({i});
        nest_to_set[i] = i;
        pigeon_to_nest[i] = i;
    }
    forn(x,q) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll a,b;
            cin >> a >> b;
            a--;
            b--;
            ll A = nest_to_set[pigeon_to_nest[a]];
            sets[nest_to_set.find(pigeon_to_nest[a])->second].erase(a);
            sets[b].insert(a);
            pigeon_to_nest[a] = b;
            print();
        } else if(op == 2) {
            ll a,b;
            cin >> a >> b;
            a--;
            b--;;
            ll A = nest_to_set[a], B = nest_to_set[b];
            nest_to_set[A] = B;
            nest_to_set[B] = A;
            print();
        } else {
            ll a;
            cin >> a;
            a--;
            cout << nest_to_set[pigeon_to_nest[a]]+1 << endl;
        }
        
    }
}

signed main()
{
 fast_cin();
 solve();
 return 0;
}