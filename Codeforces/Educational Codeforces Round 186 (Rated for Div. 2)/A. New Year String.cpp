#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long

signed main() {
  int tc=0;
  cin >> tc;
  while(tc-- > 0) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    bool have_26 = false;
    int have_25 = 0;
    for(int i=0;i<n-3;i++) {
      if(s[i]=='2' && s[i+1]=='0' && s[i+2]=='2') {
        if(s[i+3]=='5') have_25++;
        else if(s[i+3]=='6') {
          have_26 = true;
          break;
        }
      }
    }
    if(have_26) cout << 0 << "\n";
    else if(have_25) cout << 1 << "\n";
    else cout << 0 << "\n";
  }
}
