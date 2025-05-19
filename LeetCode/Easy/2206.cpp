class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mp;
        for(auto x: nums) mp[x]++;
        for(auto it: mp) {
            if(it.second % 2) return false;
        }
        return true;
    }
};