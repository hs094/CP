#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        map<int,int> mp;
        for(int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }
        string ans = "";
        for(int i=0;i<s.size();i++) {
            {
                int j = i+1;
                if(s[i] != s[j] && mp[s[i]] == s[i]-'0' && mp[s[j]] == s[j]-'0') {
                    ans.push_back(s[i]);
                    ans.push_back(s[j]);
                    return ans;
                }
            }
        }
        return ans;
    }
};