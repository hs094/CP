class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX/2;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                int l = j+1;
                int r = nums.size()-1;
                while(l <= r) {
                    int mid = (l+r)/2;
                    int curr = nums[mid]+nums[i]+nums[j];
                    if(abs(curr-target) < abs(ans-target))
                        ans = curr;
                    if(curr < target)
                        ++l;
                    else if(curr > target)
                        --r;
                    else
                        return ans;
                }
            }
        }
        return ans;
    }
};