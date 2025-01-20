class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r = mat.size(), c = mat[0].size();
        vector<int> row(r, 0), col(c, 0);
        unordered_map<int,int> mp;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                mp[mat[i][j]] = {i * c + j};
        for(int i=0;i<arr.size();i++) 
        {
            int x = mp[arr[i]]/c, y = mp[arr[i]]%c;
            row[x]++;
            col[y]++;
                if(row[x] == c || col[y] == r)
                    return i;
                mp.erase(arr[i]);
        }
        return -1;
    }
};