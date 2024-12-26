class Solution {
    void rec(vector<int> &nums, int i, int cur, int &ans, int &target) {
        if(i == nums.size()) {
            if(cur == target) ans++;
            return;
        }
        rec(nums, i+1, cur+nums.at(i), ans, target);
        rec(nums, i+1, cur-nums.at(i), ans, target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        rec(nums, 0, 0, ans, target);
        return ans;
    }
};