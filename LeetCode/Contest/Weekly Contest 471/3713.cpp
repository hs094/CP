#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestBalanced(string s) {
    int n = s.size();
    vector<vector<int>> v(n, vector<int>(26, 0));
    vector<int> f(26, 0), c;
    for (int i = 0; i < n; i++) {
      f[s[i] - 'a']++;
      v[i] = f;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        c = v[j];
        int val = -1;
        bool flag = true;
        for (int k = 0; k < 26; k++) {
          c[k] -= v[i][k];
          if (val == -1) {
            val = c[k];
          } else {
            if (c[k] != val) {
              flag = false;
              break;
            }
          }
        }
        if (flag)
          ans = max(ans, j - i + 1);
      }
    }
    return ans;
  }
};

int main() {
  int tc;
  cin >> tc;
  Solution* obj = new Solution();
  while(tc--) {
    string s;
    cin >> s;
    cout << obj->longestBalanced(s) << endl;
  }
  return 0;
}
