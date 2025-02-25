//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool> (target+1, false));
        for(int i=0;i<n;i++) {
            dp[i][0] = true;
            if(arr[i] <= target)
                dp[i][arr[i]] = true;
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<=target;j++) {
                if(j - arr[i] <= target && j-arr[i]>=0) {
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i]]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        bool t = false;
        for(int i=0;i<n;i++)
            t = (t || dp[i][target]); 
        return t;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends