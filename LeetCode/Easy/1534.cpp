#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> v32;
typedef vector<ll> v64;
typedef vector<vector<int>> vv32;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define all(x) (x).begin(), (x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

class Solution {
public:

    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++) {
                if(abs(arr[i]-arr[j])<=a) {
                    for(int k=j+1;k<arr.size();k++) {
                        if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
    
    void solve() {
        // Implement logic here
        int n;
        cin >> n;
        vector<int> arr(n);
        forn(i, n) cin >> arr[i];
        int a, b, c;
        cin >> a >> b >> c;
        cout << countGoodTriplets(arr, a, b, c) << endl;
    }

    void runTests() {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    }
};

int main() {
    fast_cin();
    Solution sol;
    sol.runTests();
    return 0;
}