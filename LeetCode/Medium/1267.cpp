class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> r, c;
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] && (r[i] >= 2 || c[j] >= 2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};