#define ll long long
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(left <= right) {
            ll mid = (left+right)/2;
            ll cnt = 0;
            for(int x: candies) cnt += x/mid;
            if(cnt >= k) {
                ans = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return ans;
    }
};