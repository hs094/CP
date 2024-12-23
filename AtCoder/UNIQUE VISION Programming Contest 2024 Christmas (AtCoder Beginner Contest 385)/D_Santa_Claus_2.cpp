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

struct House {
    ll x, y;
};

bool compareHousesByX(const House& a, const House& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool compareHousesByY(const House& a, const House& b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

class FenwickTree {
public:
    FenwickTree(ll n) : n(n), tree(n + 1, 0) {}

    void update(ll idx, ll delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    ll query(ll idx) {
        ll sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    ll rangeQuery(ll left, ll right) {
        return query(right) - query(left - 1);
    }

private:
    ll n;
    vector<ll> tree;
};

void solve(){
    ll n,m;
    pair<ll,ll> s;
    cin >> n >> m >> s.first >> s.second;
    vector<House> houses(n);
    forn(i,n) {
        cin >> houses[i].x >> houses[i].y;
    }
    // Coordinate compression
    set<ll> x_coords, y_coords;
    for (const auto& house : houses) {
        x_coords.insert(house.x);
        y_coords.insert(house.y);
    }
    x_coords.insert(s.first);
    y_coords.insert(s.second);

    map<ll, ll> x_compressed, y_compressed;
    ll idx = 1;
    for (const auto& x : x_coords) {
        x_compressed[x] = idx++;
    }
    idx = 1;
    for (const auto& y : y_coords) {
        y_compressed[y] = idx++;
    }

    // Update house coordinates to compressed values
    for (auto& house : houses) {
        house.x = x_compressed[house.x];
        house.y = y_compressed[house.y];
    }
    s.first = x_compressed[s.first];
    s.second = y_compressed[s.second];

    // Fenwick Tree for counting unique houses
    FenwickTree fenwickTreeX(x_compressed.size());
    FenwickTree fenwickTreeY(y_compressed.size());

    set<pair<ll, ll>> uniqueHouses;
    for (const auto& house : houses) {
        uniqueHouses.insert({house.x, house.y});
    }

    for (const auto& house : uniqueHouses) {
        fenwickTreeX.update(house.first, 1);
        fenwickTreeY.update(house.second, 1);
    }

    ll cnt = 0;
    while (m--) {
        char ch;
        ll c;
        cin >> ch >> c;
        if (ch == 'U') {
            ll lower = s.second;
            ll upper = y_compressed[s.second + c];
            cnt += fenwickTreeY.rangeQuery(lower, upper);
            s.second += c;
        } else if (ch == 'D') {
            ll lower = y_compressed[s.second - c];
            ll upper = s.second;
            cnt += fenwickTreeY.rangeQuery(lower, upper);
            s.second -= c;
        } else if (ch == 'L') {
            ll lower = x_compressed[s.first - c];
            ll upper = s.first;
            cnt += fenwickTreeX.rangeQuery(lower, upper);
            s.first -= c;
        } else if (ch == 'R') {
            ll lower = s.first;
            ll upper = x_compressed[s.first + c];
            cnt += fenwickTreeX.rangeQuery(lower, upper);
            s.first += c;
        }
    }
    cout << s.first << " " <<  s.second << " " << cnt << endl;
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