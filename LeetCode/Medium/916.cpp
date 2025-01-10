class Solution {
public:
    vector<string> wordSubsets(vector<string>& words2, vector<string>& words1) {
        vector<string> ans;
        vector<int> hash(26,0);
        for(int j=0;j<words1.size();j++) {
            map<int,int> mp;
            for(int i=0;i<words1[j].size();i++)
                mp[words1[j][i]-'a']++;
            for(int i=0;i<26;i++)
                if(mp.count(i))
                    hash[i] = max(hash[i], mp[i]);
        }

        for(int j=0;j<words2.size();j++) {
            bool flag = true;
            map<int,int> mp;
            for(int i=0;i<words2[j].size();i++) 
                mp[words2[j][i]-'a']++;
            for(int i=0;i<26;i++) {
                if(mp[i] < hash[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(words2[j]);
        }
        return ans;
    }
};