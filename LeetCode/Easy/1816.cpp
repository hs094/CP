class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0, i;
        for(i=0;i<s.size();i++) {
            cnt += s[i] == ' ';
            if(cnt == k) break;
        }
        return s.substr(0, i);
    }
};