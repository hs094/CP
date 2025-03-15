// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        vector<int>ans(n+1,INT_MIN), pre(n,-1), nex(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty())
                pre[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty()) nex[i] = st.top();
            st.push(i);
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int siz = nex[i] - pre[i] - 1;
            ans[siz] = max(ans[siz],arr[i]);
            mini = min(mini,arr[i]);
        }
        ans[n] = mini;
        for(int i=n-1;i>=0;i--)
           ans[i] = max(ans[i],ans[i+1]);
        return vector<int>(ans.begin()+1,ans.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends