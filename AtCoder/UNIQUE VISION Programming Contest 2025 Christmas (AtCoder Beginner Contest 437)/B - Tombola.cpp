#include <ios>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<set<int>> rows(h);
  vector<int> count(n, 0);
  vector<vector<int>> grid(h, vector<int>(w, 0));
  for (int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> grid[i][j];
      rows[i].insert(grid[i][j]);
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    count[i] = a;
  }
  for(int i = 0; i < h; i++) {
    int cnt = 0;
    for(int j = 0; j < n; j++) {
      if(rows[i].count(count[j])) {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
