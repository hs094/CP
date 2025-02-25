class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            mp[nums[i]-i]++;
        }
        long long cnt = ((long long)n * (long long)(n-1))/2;
        for(auto it: mp) {
            cnt -= ((long long)it.second * (long long)(it.second-1)) / 2;
        } 
        return cnt;
    }
};