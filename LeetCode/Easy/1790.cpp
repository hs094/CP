class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int> idx;
        for(int i=0;i<n;i++) {
            if(s1[i] != s2[i]) {
                idx.push_back(i);
            }
        }
        if(idx.size() == 0) return true;
        if(idx.size() != 2) return false;
        else {
            return (s1[idx[0]] == s2[idx[1]] && s1[idx[1]] == s2[idx[0]]);
        }
    }
};