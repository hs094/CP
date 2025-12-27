#include <bits/stdc++.h>
using namespace std;

signed main() {

  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a==b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
