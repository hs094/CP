class Solution {
public:
    int minimumLength(string s) {
       vector<int> v(26,0);
       for(int i=0;i<s.size();i++) {
            v[s[i]-'a']++;
       }
       int cnt = 0;
       for(int i=0;i<26;i++) {
        if(v[i] > 0) {
            if(v[i] % 2) cnt+=1;
            else cnt += 2;
        }
       }
       return cnt;
    }
};