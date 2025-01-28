#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll sum1 = accumulate(grid[0].begin(), grid[0].end(), 0LL), sum2 = 0;
        ll ans = LLONG_MAX;
        for(int i=0;i<n;i++) {
            sum1 -= grid[0][i];
            ans = min(ans, max(sum1, sum2));
            sum2 += grid[1][i];
        }
        return ans;
    }
};