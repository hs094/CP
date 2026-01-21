#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int a,b;
    cin >> a >> b;
    int p1 = log(3*a+1)/log(4), p2=log((3*b+1)/2)/log(4);
    int p1_ = log((3*a+1)/2)/log(4), p2_=log((3*b+1)/2)/log(4);
    int r1 = min(p1,p2), r2=min(p1_,p2_);
    set<int, greater<int>> t;
    cout << p1 << " " << p2 << " " << p1_ << " " << p2_ << " " << r1 << " " << r2 << "\n";
    if(p1==p2) {
      t.insert(2*r1);
    }
    else if(p1_==p2_) {
      t.insert(2*r2);
    }
    else {
      t.insert(2*r1+1);
      t.insert(2*r2+1);
    }
    cout << *t.begin() << "\n";
  }
}
