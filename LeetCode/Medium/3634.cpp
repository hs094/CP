// https://leetcode.com/problems/minimum-removals-to-balance-array/description/
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0, j = 0;
        for(int i=0;i<n;i++) {
            while( (long) nums[i] >  (long)nums[j] * k)
                j++;
            ans = max(ans, i - j + 1); 
        }
        return n - ans;
    }
};
