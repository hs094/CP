class Solution {
public:
    string convertToBase7(int num) {
        int p = abs(num);
        string ans="";
        while(p >= 7) {
            ans.push_back('0'+p % 7);
            p = p / 7;
        }
        ans.push_back('0'+p);
        if(num < 0) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};