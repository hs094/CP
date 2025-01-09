// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        for(int i=1;i<n;i++)
            arr[i] += arr[i-1];
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int start = i, end = n-1, t = target+((i>=1) ? arr[i-1]:0);
            while(start <= end) {
                int mid = start + (end-start)/2;
                if(arr[mid] == t) {
                    ans = {i+1, mid+1};
                    return ans;
                }
                else if(arr[mid] < t) start = mid+1;
                else end = mid-1;
            }
        }
        ans = {-1};
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends