class Solution {
    bool check(string a, string b) {
        if(a.size() <= b.size()) {
            string pre = b.substr(0, a.size());
            string suf = b.substr(b.size()-a.size());
            return pre == a && a == suf;
        }
        else 
            return false;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                cnt += check(words[i], words[j]);
            }
        }
        return cnt;
    }
};