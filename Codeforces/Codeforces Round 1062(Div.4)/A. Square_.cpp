#include <bits/stdc++.h>
using namespace std;

signed main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==b && b==c && c==d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
