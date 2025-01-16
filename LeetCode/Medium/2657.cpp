class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> hashA(n+1,0), hashB(n+1,0);
        vector<int> ans;
        for(int i=0;i<n;i++) {
            hashA[A[i]]++;
            hashB[B[i]]++;
            int cnt = 0;
            for(int i=1;i<=n;i++) cnt += (hashA[i] == 1 && hashB[i] == 1);
            ans.push_back(cnt);
        }
        return ans;
    }
};