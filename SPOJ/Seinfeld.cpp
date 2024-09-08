#include <bits/stdc++.h>  
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
#define ys cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve(){
    string s;
    int i = 1;
    while(true)
    {
        cin >> s;
        bool flag = true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '-')
            {
                flag = false;
                break;
            }
        }
        if(flag) break;
        cout << i << ". ";
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{')
                st.push(i);
            else if(s[i]=='}')
            {
                if(!st.empty() && s[st.top()]=='{')
                    st.pop();
                else
                    st.push(i);
            }
            else
                continue;
        }
        string p = "";
        while(!st.empty())
        {
            p.push_back(s[st.top()]);
            st.pop();
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='}')
                cnt1++;
            else if(p[i]=='{')
                cnt2++;
        }
        cout << (cnt1+1)/2+(cnt2+1)/2 << endl;
        // cout << p.size() << endl;
        i++;
    }
}

int main()
{
 fast_cin();
 ll t = 1;
 //cin >> t;
 for(int it=1;it<=t;it++) {
    solve();
 }
 return 0;
}