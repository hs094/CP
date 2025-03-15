// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        multiset<int, greater<int>> mst;
        for(int i=0;i<k;i++) {
            mst.insert(arr[i]);
        }
        vector<int> ans;
        ans.push_back(*mst.begin());
        for(int i=k;i<arr.size();i++) {
            mst.erase(mst.find(arr[i-k]));
            mst.insert(arr[i]);
            ans.push_back(*mst.begin());
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends