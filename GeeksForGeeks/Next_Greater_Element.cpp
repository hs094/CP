//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(arr[n-1]);
        int i = n-2;
        while(i >= 0) {
            if(i+1 < n && arr[i+1] > arr[i]) {
                ans[i] = arr[i+1];
            }
            else {
                while(!st.empty() && st.top() <= arr[i]) st.pop();
                if(!st.empty()) {
                    ans[i] = st.top();
                }
            }
            st.push(arr[i]);
            i--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends