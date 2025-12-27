#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;
int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  vector<int> prefB(m), sufB(m);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int j = 0; j < m; j++) {
    cin >> b[j];
  }
  sort(b.begin(), b.end());
  for(int i=0;i<m;i++) {
    prefB[i] = (i == 0 ? b[i] : (prefB[i-1] + b[i]) % MOD);
  }
  for(int i=m-1;i>=0;i--) {
    sufB[i] = (i == m-1 ? b[i] : (sufB[i+1] + b[i]) % MOD);
  }
  long long ans = 0;

for(int i = 0; i < n; i++) {
    int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    long long leftSum = (pos > 0 ? prefB[pos - 1] : 0);
    long long rightSum = (pos < m ? sufB[pos] : 0);

    long long sum =
    (
        (1LL * a[i] % MOD) *
        ( ((2LL * pos) % MOD - m + MOD) % MOD )
        - leftSum
        + rightSum
        + MOD
    ) % MOD;

    ans = (ans + sum) % MOD;
}
   cout << ans << endl;
  return 0;
}
