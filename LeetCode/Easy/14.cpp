class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++) {
            string t = strs[i];
            int j = 0;
            for(;j<min(ans.size(), t.size());j++) {
                if(ans[j] != t[j])
                    break;
            }
            ans = ans.substr(0, j);
            if(ans.size() <= 0) break;
        }   
        return ans;
    }
};
