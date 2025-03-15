class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> hash(n*n,0);
        vector<int> ans(2,0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                hash[grid[i][j]-1]++;
                if(hash[grid[i][j]-1] == 2) 
                    ans[0] = grid[i][j];
            }
        }
        for(int i=0;i<n*n;i++) {
            if(hash[i] == 0) {
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
};