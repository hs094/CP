class Solution {
    string ans;
    set<string> st;
public:
    void generate(string s, int i) {
        if(ans.size() > 0) return;
        if(i == s.size()) {
            if(!st.count(s)) {
                ans = s;
            }
            return;
        }
        s[i] = '0';
        generate(s, i+1);
        s[i] = '1';
        generate(s, i+1);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        st.clear();
        ans = "";
        for(string s: nums) st.insert(s);
        string r = string(nums.size(), '0');
        generate(r, 0);
        return ans;
    }
};