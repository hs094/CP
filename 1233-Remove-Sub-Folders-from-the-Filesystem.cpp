class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string,int> st;
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for(int i=0;i<folder.size();i++) {
            string t = folder.at(i);
            bool flag = true;
            for(int j=0;j<t.size();j++) {
                if(t[j] == '/') {
                    if(st.count(t.substr(0,j)) != 0)  {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                ans.push_back(t);
                st[t]=1;
            }
        }
        return ans;
    }
};