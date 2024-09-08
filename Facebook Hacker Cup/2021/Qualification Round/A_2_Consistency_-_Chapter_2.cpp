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

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string a;
        cin >> a;
        vector<int> hash(26,0);
        for(int j = 0; j < a.size(); j++) hash[a[i]-65]++;

        int K;
        cin >> K;
        vector<pair<int,int>> V(K);
        for(int j = 0; j < K; j++) 
            cin >> V[j].first >> V[j].second;
        
    }
    return 0;
}