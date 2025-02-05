class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;
        for(int i=0;i<n;i++) {
            int cnt = 1;
            for(int j=i+1;j<n;j++) {
                if(nums[j] > nums[j-1]) cnt++;
                else break;
            }
            mx = max(mx, cnt);
            cnt = 1;
            for(int j=i+1;j<n;j++) {
                if(nums[j] < nums[j-1]) cnt++;
                else break;
            }
            mx = max(mx, cnt);
        }      
        return mx;
    }
};