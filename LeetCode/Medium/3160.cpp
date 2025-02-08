class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> colours;
        map<int,int> index;
        vector<int> ans;
        for(int i=0;i<queries.size();i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            colours[y]++;
            if(index.count(x)) {
                colours[index[x]]--;
                if(colours[index[x]] == 0) 
                    colours.erase(index[x]);
            }
            index[x] = y;
            ans.push_back(colours.size());
        }   
        return ans;
    }
};