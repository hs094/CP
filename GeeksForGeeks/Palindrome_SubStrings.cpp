//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int cnt = 0, n = s.size();
        for(int i=0;i<n;i++) {
            int l = i-1;
            int r = i+1;
            while(l>=0 && r<n && s[l] == s[r]) {
                l--;
                r++;
                cnt++;
            } 
            if(i>0 && s[i-1] == s[i]) {
                cnt++;
                int l = i-2;
                int r = i+1;
                while(l>=0 && r<n && s[l] == s[r]) {
                    l--;
                    r++;
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends