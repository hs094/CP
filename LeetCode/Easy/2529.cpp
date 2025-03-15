class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lo = lower_bound(nums.begin(), nums.end(), 0)-nums.begin(), hi = upper_bound(nums.begin(), nums.end(), 0)-nums.begin();
        return max(lo, (int)nums.size()-hi);
    }
};