//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
class Solution {
  public:
    int getMaxArea(vector<int> &heights) {
        // Your code here
        int n = heights.size(), mx = 0, start;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++) {
            start = i;
            while(!st.empty() && st.top().second > heights[i]) {
                mx = max(mx, st.top().second * (i-st.top().first));
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        while(!st.empty()) {
            mx = max(mx, st.top().second * (n-st.top().first));
            st.pop();
        }
        return mx;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends