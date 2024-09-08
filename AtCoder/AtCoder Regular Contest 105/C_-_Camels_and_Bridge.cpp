#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
bool cmp(const pair<int,int> a, const pair<int,int> b)
{
    return (a.second > b.second || a.first > b.first);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M;
    cin >> N >> M;
    vector<int> w(N);
    sort(w.begin(), w.end());
    vector<pair<int,int>> v(M);
    for(int i=0; i<M; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    int flag = 0;
    
    if(flag) cout << -1 << endl;
    else cout << ans << endl;   
    return 0;
}