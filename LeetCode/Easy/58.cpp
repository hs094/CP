class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for(int i=0;i<s.size();i++) {
            int j = i;
            while(j < s.size() && s[j] != ' ')
            {
                j++;
            }
            if(j-i > 0) cnt = j-i;
            i = j;
        }
        return cnt;
    }
};