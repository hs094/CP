// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int cnt = 0, pos = -1, prod = 1;
        for(int i=0;i<arr.size();i++) {
            if(arr[i] == 0) {
                cnt++;
                pos = i;
            }
            else prod *= arr[i];
        }
        vector<int> ans(arr.size(), 0);
        if(cnt >= 2) return ans;
        else if(cnt == 1) {
            ans[pos] = prod;
            return ans;
        }
        else {
            for(int i=0;i<arr.size();i++) {
                ans[i] = prod/arr[i];
            }
        }
        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends