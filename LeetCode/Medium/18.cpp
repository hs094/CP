class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for(int a=0;a<n;a++) {
            for(int b=a+1;b<n;b++) {
                for(int c=b+1;c<n;c++) {
                    int l = c+1;
                    int r = n-1;
                    while(l <= r) {
                        int mid = (l+r)/2;
                        long sum = (long)nums[a]+(long)nums[b]+(long)nums[c]+(long)nums[mid];
                        if(sum == target) {
                            ans.insert({nums[a], nums[b], nums[c], nums[mid]});
                            l = mid+1;
                        }
                        else if(sum < target)
                            l = mid+1;
                        else
                            r = mid-1;
                    }
                }
            }
        }
        vector<vector<int>> s;
        for(auto it: ans) {
            s.push_back(it);
        }
        return s;
    }
};