#include <bits/stdc++.h>
using namespace std;

signed main() {
  int tc, n;
  cin >> tc;
  while(tc--) {
    int o = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
      cin >> v[i];
      if(v[i] % 2) o++;
    }
    if(o == 0 || o == n) {
      for(int i=0;i<n;i++) cout << v[i] << " ";
      cout << "\n";
    }
    else {
      sort(v.begin(), v.end());
      for(int i=0;i<n;i++) cout << v[i] << " ";
      cout << "\n";
    }
  }
}
