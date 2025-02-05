class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0, n = nums.size();
        int cnt = 0;
        for(int i=0;i<n-1;i++) {
            if(nums[i] > nums[i+1]) cnt++;
        }
        return cnt == 0 || (cnt == 1 && nums[0] >= nums[n-1]);
    }
};