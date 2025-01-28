#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int i, int j, int &sum) {
        visited[i][j] = 1;
        sum += grid[i][j];
        for(int x=0;x<4;x++) {
            int X = i + dx[x], Y = j + dy[x];
            if(X >= 0 && Y >= 0 && X < m && Y < n && grid[X][Y] > 0) {
                dfs(grid, visited, m, n, X, Y, sum);
            }
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] && !visited[i][j]) {
                    int sum = 0;
                    dfs(grid, visited, m, n, i, j, sum));
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};

signed main() {
    Solution* obj = new Solution();
    int tc;
    cin >> tc;
    while(tc--) {
        int m,n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<ll>(n));
        cout << obj->findMaxFish(grid) << endl;
    }
}